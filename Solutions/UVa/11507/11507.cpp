#include <iostream>
#include <string>
using namespace std;

string xp = "+x", xm = "-x";
string yp = "+y", ym = "-y";
string zp = "+z", zm = "-z";
string no = "No";

string getRes(string cur, string turn) {
	if(turn == no) return cur;
	if(cur == xp)  return turn;
	if(cur == xm) {
		if(turn == yp) return ym;
		if(turn == ym) return yp;
		if(turn == zp) return zm;
		if(turn == zm) return zp;
	}
	if(cur == yp) {
		if(turn == yp) return xm;
		if(turn == ym) return xp;
		if(turn == zp || turn == zm) return cur;
	}
	if(cur == ym) {
		if(turn == yp) return xp;
		if(turn == ym) return xm;
		if(turn == zp || turn == zm) return cur;
	}
	if(cur == zp) {
		if(turn == yp || turn == ym) return cur;
		if(turn == zp) return xm;
		if(turn == zm) return xp;
	}
	if(cur == zm) {
		if(turn == yp || turn == ym) return cur;
		if(turn == zp) return xp;
		if(turn == zm) return xm;
	}
	return "wtf";
}

int main() {
	int L;
	string cur, turn;
	
	while(cin>>L && L != 0) {
		cur = xp;
		for(int i=0; i < L-1; i++) {
			cin>>turn;
			cur = getRes(cur, turn);
		}

		cout<<cur<<endl;
	}

	return 0;
}