#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define pb(x) push_back(x)

string noBlood = "NO";

typedef struct ABO {
	string first;
	string second;

	ABO() {}
	ABO(string comb) {
		first.pb(comb[0]);
		second.pb(comb[1]);

	}
	ABO(string _first, string _second) {
		first = _first;
		second = _second;
	}
} ABO;

typedef struct Blood {
	string type;
	bool isNegative;

	Blood() {}
	Blood(string t, bool n) {
		type = t;
		isNegative = n;
	}
} Blood;

Blood getBlood(string str) {
	return Blood(str.substr(0, str.size()-1), str[str.size()-1] == '-');
}

vector<ABO> getABOFromBlood(string blood) {
	vector<ABO> res;
	if(blood == "A") {
		res.pb(ABO("AA"));
		res.pb(ABO("AO"));

	} else if(blood == "AB") {
		res.pb(ABO("AB"));

	} else if(blood == "B") {
		res.pb(ABO("BB"));
		res.pb(ABO("BO"));

	} else { // blood == "O"
		res.pb(ABO("OO"));
	}

	return res;
}

vector<string> getBloodContainingThisBlood(string containedBlood) {
	vector<string> res;
	if(containedBlood == "A") {
		res.pb("A");
		res.pb("AB");
	} else if(containedBlood == "B") {
		res.pb("AB");
		res.pb("B");
	} else if(containedBlood == "O") {
		res.pb("A");
		res.pb("B");
		res.pb("O");
	}
	return res;
}

// Returns true if parentABO can give givingBlood to a child
bool canProduceThisBlood(vector<ABO> parentABO, string givingBlood) {
	for(ABO abo : parentABO) {
		if(abo.first == givingBlood || abo.second == givingBlood) return true;
	}
	return false;
}

string createBlood(string p1, string p2) {
	string comb = p1 + p2;
	sort(comb.begin(), comb.end());
	if(comb == "AA") return "A";
	else if(comb == "AB") return "AB";
	else if(comb == "AO") return "A";
	else if(comb == "BB") return "B";
	else if(comb == "BO") return "B";
	else if(comb == "OO") return "O";
	return noBlood;
}

set<string> findParent(string p, string c) {
	set<string> res;

	Blood parent = getBlood(p);
	Blood child = getBlood(c);

	// list of possible ABO combinations that can make this blood
	vector<ABO> possibleParents = getABOFromBlood(child.type);

	// list of possible ABOs that the parent's blood can have
	vector<ABO> possibleGivingSources = getABOFromBlood(parent.type);

	/*
		each biological parent donates one ABO allele (randomly chosen from their two) 
		and one Rh factor allele to their child. 
		Therefore 2 ABO alleles and 2 Rh factor alleles of the parents 
		determine the child's blood type.
	*/
	for(ABO abo : possibleParents) {
		string p1 = abo.first;
		string p2 = abo.second;

		if(canProduceThisBlood(possibleGivingSources, p1)) {
			vector<string> possibleP2 = getBloodContainingThisBlood(p2);
			for(string blood : possibleP2)
				res.insert(blood);
		}
		if(canProduceThisBlood(possibleGivingSources, p2)) {
			vector<string> possibleP1 = getBloodContainingThisBlood(p1);
			for(string blood : possibleP1)
				res.insert(blood);
		}
	}

	
	/*
	Someone who is ``Rh positive" or ``Rh+" has at least one + allele,
	but could have two. Someone who is ``Rh negative" always has two - alleles.
	*/
	set<string> resWithRh;

	bool canBeNegative = !( !child.isNegative && parent.isNegative );
	for(string str : res) {
		resWithRh.insert(str + "+");
		if(canBeNegative) resWithRh.insert(str + "-");
	}

	return resWithRh;
}

set<string> findChild(string p1, string p2) {
	set<string> res;
	Blood p1Blood = getBlood(p1);
	Blood p2Blood = getBlood(p2);

	vector<ABO> possibleP1 = getABOFromBlood(p1Blood.type);
	vector<ABO> possibleP2 = getABOFromBlood(p2Blood.type);

	for(ABO aboP1 : possibleP1) {
		for(ABO aboP2 : possibleP2) {
			string b1 = createBlood(aboP1.first, aboP2.first);
			string b2 = createBlood(aboP1.second, aboP2.first);
			string b3 = createBlood(aboP1.first, aboP2.second);
			string b4 = createBlood(aboP1.second, aboP2.second);
			if(b1 != noBlood) res.insert(b1);
			if(b2 != noBlood) res.insert(b2);
			if(b3 != noBlood) res.insert(b3);
			if(b4 != noBlood) res.insert(b4);
		}
	}

	set<string> resWithRh;
	bool canBePositive = !(p1Blood.isNegative && p2Blood.isNegative);
	for(string str : res) {
		if(canBePositive) resWithRh.insert(str + "+");
		resWithRh.insert(str + "-");
	}

	return resWithRh;
}

int main() {

	string p1, p2, child;
	int cid = 1;

	while(cin>>p1>>p2>>child && p1 != "E") {
		set<string> res;
		if(p1 == "?") res = findParent(p2, child);
		else if(p2 == "?") res = findParent(p1, child);
		else res = findChild(p1, p2);

		string output;
		if(res.size() == 0) output = "IMPOSSIBLE";
		else {
			bool isFirst = true;
			for(string str : res) {
				if(isFirst) isFirst = !isFirst;
				else output += ", ";
				output += str;
			}
			if(res.size() > 1) output = "{" + output + "}";
		}
		if(p1 == "?") p1 = output;
		else if(p2 == "?") p2 = output;
		else child = output;

		cout<<"Case "<<cid++<<": "<<p1<<" "<<p2<<" "<<child<<endl;
	}

	return 0;
}