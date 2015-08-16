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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define REP(i,a,b) for(int i=a; i < b; i++)
#define REPE(i, a, b) for(int i=a; i <=b; i++)
int INF = numeric_limits<int>::max();
int nINF = numeric_limits<int>::min();
typedef long long ll;
 
class ComplementMachine2D {
public:
	int largestSubmatrix(vector <string>);
};

int R,C;
vector<string> mat;
int findSubRow(int,int,int);

const int maxN = 41;

/*
 row[s][t][sid]
 = maximum number of cells that can be obtained when using
  mat[sid][s] ~ mat[sid][t-1]  as the beginning of the matching operation.
 */
int row[maxN][maxN][maxN];


int ComplementMachine2D::largestSubmatrix(vector <string> matrix) {
    mat = matrix;
	R = mat.size();
    C = mat[0].size();
    
    if(R == 1 || C == 1) return max(R,C);
    
    memset(row, -1, sizeof(row));

    int ans = 1;
    
    for(int r=0; r < R; r++)
        for(int s=0; s < C; s++)
            for(int t = s+1; t <= C; t++)
                ans = max(ans, findSubRow(r,s,t));

    return ans;
}

/*
 maximum number of cells that can be obtained when using
 mat[sid][s] ~ mat[sid][t-1] as the beginning of the matching operation.
 */
int findSubRow(int id, int s, int t)
{
    int& res = row[id][s][t];
    
    if(res != -1) return res;
    
    res = t - s; //the current row alone can always be erasable
    
    if(id == R-1) //the last row. No more row to go
        return res;
    
    bool flip = (mat[id][s] != mat[id+1][s]);
    
    bool valid = true;
    for(int c=s; c < t; c++)
    {
        if( (!flip && (mat[id][c] == mat[id+1][c])) || (flip && (mat[id][c] != mat[id+1][c])) )
            continue;
        valid = false;
        break;
    }
    
    if(valid)
        res += findSubRow(id+1,s,t);
    
    return res;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	ComplementMachine2D *obj;
	int answer;
	obj = new ComplementMachine2D();
	clock_t startTime = clock();
	answer = obj->largestSubmatrix(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <string> p0;
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"0011","0011","1100","0111"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 12;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"0011","1011","0101","1010"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 9;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"1011","0011","0101","1010"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 8;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"0000110101010","0111101010111","1110110111011"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 13;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"11000000000110101101","00111111011101101101","00110011110111100010","10011110111110000111","00111010000000110111","00001101011011010110","11010010100100101100","11101101011011000001","11000010100100111001","11011010100100101010","10110010100100110110","01100010100100111001","10110010100100110011","01110101011011001010","01111101011011001011","00001000010010101011","11100101100100110001","10100100111001010101","11111000001010011110","01110100001110011111"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 100;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!