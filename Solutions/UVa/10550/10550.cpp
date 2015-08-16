#include <iostream>
using namespace std;

int turnClock(int st, int end) {
	if(end <= st) return st - end;
	return st + 40 - end;
}

int turnCounterClock(int st, int end) {
	if(end >= st) return end - st;
	return 40 - st + end;
}

int main() {
	int st, a, b, c;
	int click = 360 / 40;
	int turn = 360;
	while(cin>>st>>a>>b>>c && (a+b+c > 0)) {
		int res = 2 * turn;
		res += click * turnClock(st, a);
		res += turn;
		res += click * turnCounterClock(a, b);
		res += click * turnClock(b,c);
		cout<<res<<endl;
	}
	return 0;

}
