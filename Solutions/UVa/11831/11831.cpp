#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

typedef long long ll;

int board[110][110];
int res;
char dir;
string seq;
int curR;
int curC;

int main()
{
	int R,C,S;
	string tmp;
	while(cin>>R>>C>>S) {
		if(R == 0 && C == 0 && S == 0) {
			break;
		}

		// process board
		for(int i=0; i < R; i++) {
			cin>>tmp;
			for(int j=0; j < C; j++) {
				if(tmp[j] == '.') {
					board[i][j] = 0;
				} else if(tmp [j] == '*') {
					board[i][j] = 1;
				} else if( tmp[j] == '#') {
					board[i][j] = -1;
				} else {
					// we have a bot
					board[i][j] = 0;
					dir = tmp[j];
					if(dir == 'O') {
						dir = 'L'; // 'O' is VERY confusing
					} else if (dir == 'L') {
						dir = 'R';
					}
						


					curR = i;
					curC = j;

				}
			}
		}
		// cout<<"init pos : ("<<curR<<" , "<<curC<<")"<<endl;

		// get sequence
		cin>>seq;

		// now play
		res = 0;
		for(int i=0; i < seq.size(); i++) {
			
			if(seq[i] == 'D') {
				if(dir == 'N') {
					dir = 'R';
				} else if(dir == 'S') {
					dir = 'L';
				} else if(dir == 'L') {
					dir = 'N';
				} else if(dir == 'R') {
					dir = 'S';
				}

			} else if (seq[i] == 'E') {
				if(dir == 'N') {
					dir = 'L';
				} else if(dir == 'S') {
					dir = 'R';
				} else if(dir == 'L') {
					dir = 'S';
				} else if(dir == 'R') {
					dir = 'N';
				}

			} else if ( seq[i] == 'F') {
				int nextR = curR;
				int nextC = curC;

				if(dir == 'N') {
					nextR--;
				} else if(dir == 'S') {
					nextR++;
				} else if(dir == 'L') {
					nextC--;
				} else if(dir == 'R') {
					nextC++;
				}

				// check we are still inside a board
				if(0 <= nextR && nextR < R && 0 <= nextC && nextC < C) {
					// check we are not stepping into a pillar

					// 0 = normal
					// -1 = pillar
					// 1 = sticker
					if(board[nextR][nextC] != -1) {
						if(board[nextR][nextC] == 1) {
							res++;
							board[nextR][nextC] = 0;
						}
						curR = nextR;
						curC = nextC;
					}
				}
			}
			// cout<<"(R, C, dir) = ("<<curR<<" , "<<curC<<" , "<<dir<<")"<<endl;

		}
		cout<<res<<endl;
	}
	
    return 0;

}