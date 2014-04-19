#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char bi[2] = {'0','1'};

int getInt(char ch) {
	return ch - '0';
}

string extra[7];

string getTime(int num) {
	string res = "";
	while(num > 0) {
		res.push_back(bi[num%2]);
		num /= 2;
	}
	res = res + extra[6-res.size()];
	reverse(res.begin(), res.end());
	return res;
}


int main() {
	int N;
	cin>>N;
	int caseId = 1;
	string T;
	extra[0] = "";
	for(int i=1; i <= 6; i++)
		extra[i] = extra[i-1] + "0";
	
	int H,M,S;
	string Hbi,Mbi,Sbi;
	string vert;
	string tmp = "abc";
	while(N--) {
		cin>>T;
		H = getInt(T[0]) * 10 + getInt(T[1]);
		M = getInt(T[3]) * 10 + getInt(T[4]);
		S = getInt(T[6]) * 10 + getInt(T[7]);
		Hbi = getTime(H);
		Mbi = getTime(M);
		Sbi = getTime(S);
		vert = "";

		for(int i=0; i <= 5; i++) {
			tmp[0] = Hbi[i];
			tmp[1] = Mbi[i];
			tmp[2] = Sbi[i];
			vert = vert + tmp;
		}
		cout<<caseId<<" "<<vert<<" "<<(Hbi+Mbi+Sbi)<<endl;
		caseId++;

	}
	return 0;
}