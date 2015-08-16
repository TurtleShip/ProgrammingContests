#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;

typedef struct F{
	int up;
	int bot;
} F;

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int lcm(int a, int b) {
	return b * a / gcd(a,b);
}

F serial(const vector< F >& V) {
	F f;
	int N = V.size();
	int bot = lcm(V[0].bot, V[1].bot);
	for(int i=2; i <N; i++)
		bot = lcm(bot, V[i].bot);
	int up = 0;
	for(int i=0; i < N; i++) {
		up += V[i].up * (bot/V[i].bot);
	}
	int com = gcd(up,bot);
	up /= com;
	bot /= com;
	f.up = up;
	f.bot = bot;
	return f;
}

F parallel(const vector<F> & V) {
	vector< F > flipped(V.begin(), V.end());
	// flip all the numbers
	int N = flipped.size();
	for(int i=0;i < N; i++)
		swap(flipped[i].up, flipped[i].bot);
	F f = serial(flipped);

	swap(f.up, f.bot);
	return f;
}

string toString(F& f) {
	stringstream ss;
	ss<<f.up<<"/"<<f.bot;
	return ss.str();
}

bool isDig(char ch) {
	return '0' <= ch && ch <= '9';
}
int main() {
	string input;

	while(getline(cin,input)) {
		int idx = 0;
		string cur = "";
		int N = input.size();
		stack <string> S;
		while(idx < N) {
			char ch = input[idx];
			if(ch == ' ') {
				idx++;
				continue;
			}
			if(ch == ')') {
				// pop and canculate, and pop down
				vector< F > V;
				string cur = S.top(); S.pop();

				bool isSerial = false;
				while(cur != "(") {
					if(cur == "&" || cur == "|") {
						isSerial = cur == "&";
					} else {
						// convert back to F
						int curN = cur.size();
						int idx = 0;
						int top = 0;
						int bot = 0;
						while(cur[idx] != '/') {
							top = top*10 + (cur[idx] - '0');
							idx++;
						}
						idx++; // go past slash
						while(idx<curN) {
							bot = bot*10 + (cur[idx] - '0');
							idx++;
						}
						F f;
						f.up = top;
						f.bot = bot;
						V.push_back(f);
					}
					cur = S.top(); S.pop();
				}
				F f;
				if(isSerial) f = serial(V);
				else f = parallel(V);

				S.push(toString(f));

				idx++;
			} else if(isDig(ch)) {
				//get the num
				int nextIdx = idx+1;
				while(isDig(input[nextIdx]) || input[nextIdx] == '/')
					nextIdx++;
				S.push(input.substr(idx, nextIdx-idx));
				idx = nextIdx;
			} else {
				S.push( input.substr(idx,1) );
				idx++;
			}
		}
		cout<<S.top()<<endl;
	}
	
	return 0;
}