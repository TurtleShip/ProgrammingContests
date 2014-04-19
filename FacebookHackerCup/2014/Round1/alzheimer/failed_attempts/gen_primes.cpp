#include <iostream>
#include <vector>
#include <set>
using namespace std;
int gcd(int x, int y) { return y ? gcd(y, x % y) : abs(x); }

const int N = 53; // the maximum number That an element in each coprime list can be
const int S = 20; // size limit of coprime list
bool isCoPrime[N+1][N+1];
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;

#define pb(x) push_back(x)

// coprime list
vvvi cop;
vvi emp;

void preprocess() {

	for(int i=0; i <= N; i++)
		for(int j=0; j <= N; j++) {
			if(i == 0 && j == 0) {
				isCoPrime[i][j] = false;
			} else if( i == 1 || j == 1) {
				isCoPrime[i][j] = true;
			} else if (i == 0 || j == 0) {
				isCoPrime[i][j] = false;
			} else if( i == j) {
				isCoPrime[i][j] = false;
			} else {
				isCoPrime[i][j] = gcd(i,j) == 1;
			}
		}
	

	cop.pb(emp);

	vvi p_list;
	for(int i=1; i <= N; i++) {
		vi cur;
		cur.pb(i);
		p_list.pb(cur);
	}
	cop.pb(p_list);

	for(int sz=2; sz <= S; sz++) {
		vvi entire_p_list;

		for(int i=0; i < cop[sz-1].size(); i++) {
				vi prev_p_list = cop[sz-1][i];

			for(int j=0; j <= N; j++) {
				bool isGood = true;
				for(int k=0; isGood && k < prev_p_list.size(); k++) {
					isGood = isCoPrime[j][prev_p_list[k]];
				}
				if(isGood) {
					vi cur_list = prev_p_list;
					cur_list.pb(j);
					sort(cur_list.begin(), cur_list.end() );
					entire_p_list.pb( cur_list );
				}
			}
		}
		sort(entire_p_list.begin(), entire_p_list.end());
		entire_p_list.erase( unique(entire_p_list.begin(), entire_p_list.end()), entire_p_list.end() );
		cop.pb( entire_p_list );
	}
}


int main() {
	preprocess();

	cout<<"cop = [ [[]]";
	for(int sz=1; sz <= S; sz++) {
		vvi entire_p_list = cop[sz];
		cout<<",";
		cout<<"[";
		for(int i=0; i < entire_p_list.size(); i++) {
			vi p_list = entire_p_list[i];
			if(i > 0) cout<<",";
			cout<<"[";
			for(int j=0; j < p_list.size(); j++) {
				if(j > 0) cout<<",";
				cout<<p_list[j];
			}
			cout<<"]";
		}
		cout<<"]";
	}

	cout<<"]"<<endl;

	return 0;
}