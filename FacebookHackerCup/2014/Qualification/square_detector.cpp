#include <iostream>
using namespace std;

bool isB[25][25];
bool chk[25][25];
int main() {
	int T;
	cin>>T;

	int N;
	char ch;
	string res;

	for(int cid=1; cid <= T; cid++) {
		cin>>N;
		for(int i=0; i < N; i++)
			for(int j=0; j < N; j++) {
				cin>>ch;
				isB[i][j] = ch == '#';
				chk[i][j] = false;
			}

		bool isGood = true;
		bool foundSquare = false;
		for(int i=0; isGood && i < N; i++)
			for(int j=0; isGood && j < N; j++) {
				if(!isB[i][j] || chk[i][j]) continue;
				if(foundSquare) {
					isGood = false;
				} else {
					foundSquare = true;
					chk[i][j] = true;
					int len = 1; // the length of the current square
					while(j+len < N && isB[i][j+len]) {
						chk[i][j+len] = true;
						len++;
					}
					// chk if we actually have a sauare
					if(i + len > N) isGood = false;
					for(int r=i; isGood && r < i+len; r++)
						for(int c=j; isGood && c < j+len; c++) {
							chk[r][c] = true;
							isGood &= isB[r][c];
						}
				}
			}

		res = (isGood) ? "YES" : "NO";
		cout<<"Case #"<<cid<<": "<<res<<endl;

	}
	return 0;
}