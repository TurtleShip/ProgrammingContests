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
 
class DengklekPaintingSquares {
public:
	int numSolutions(int, int);
};

ll mod = 1000000007;
    int dp[101][9][6561];

int DengklekPaintingSquares::numSolutions(int N, int M) {

    //precomputation
    int maxM = 8 + 1;
    
    //pow3[i] = 3^i
    int pow3[maxM+1];
   
    /*
     Below process can be easily understood if you think it in terms of base 10.
     For example, how would you implement get[i][j] if base is 10?
     Say i = 1234, and j = 1.
     You want (1)th digit (zero-based) in 1234.
     Obvious approach will (1234/10^1) % 10 = (123) % 10 = 3
     If j = 2,
     (1234/10^2) % 10 = 12 % 10 = 2
     
   
     
     Let's look at set[i][j][k] in base 10 also.
     Let i = 1234 , j = 1, and k = 5.
     We want to replace 30 with 50.
     1234 + (-30 + 50)
     =1234 + (-3 + 5) * 10
     */
    
    pow3[0] = 1;
    for(int i=1; i <= maxM; i++)
        pow3[i] = 3 * pow3[i-1];
    
    //get[i][j] = the (j)th digit in ternary representation of i
    int get[pow3[maxM]][maxM];

    //set[i][j][k] = i with its jth digit replaced with k
    int set[pow3[maxM]][maxM][3];
    
    for(int i=0; i < pow3[maxM]; i++)
    {        
        for(int j=0; j < maxM; j++)
        {
            get[i][j] = (i / pow3[j]) % 3;
        }
    }

    for(int i=0; i < pow3[maxM]; i++)
    {
        for(int j=0; j < maxM; j++)
        {
            for(int k=0; k < 3; k++)
            {
                set[i][j][k] = i + (k - get[i][j]) * pow3[j];
            }
        }
    }

    
//    cout<<"preDone"<<endl;
    /*
     For each square in a profile, there are three possible states
     0 : It is colored, and currently has an EVEN number of colored adjacent squares.
     1 : Is is colored, and currently has an ODD number of colored adjacent squares.
     2 : It is not colored.
     */
    
    /*
     dp[i][j][k]
     = The number of solutions to the puzzle if we are currently processing square(i,j) with profile k.
     Because there are three different states for each square, we can represent k as a number in base-3 of length M, where the n-th (0-based) digit in k denotes the state of the n-th square in the profile.
     */
    //int dp[N+1][M+1][pow3[M]];

 //   cout<<"dp initializd"<<endl;


    int startK = 0;
    
    /*
     Assume that in the initial profile, all squares in the  (-1)th row
     have state 2 : not colored
     */
    for(int j=0; j < M; j++)
    {
        startK = set[startK][j][2];
    }
        
    for(int i=0; i <= N; i++)
        for(int j=0; j <= M; j++)
            for(int k=0; k < pow3[M]; k++)
                dp[i][j][k] = 0;
    
    //Base case : unprocess board.
    dp[0][0][startK] = 1ll;

    /*
     We go through each row and each column, and try all combinations of k.
     If we are at row i , column j, dp[i][j][k] holds number of possible ways 
     that reads to current configuration k.
     It will 0 if there is no way to make the current configuration
     */
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < M; j++)
        {
            for(int k=0; k < pow3[M]; k++)
            {
                if(dp[i][j][k] == 0) continue;
                /* If the state of the square above the current square is not 1,
                 do not color the current square.
                 In other words, you can choose to leave the current square uncolored
                 as long as the square above it either has an even number of colored adjacent
                 sqaures or is not colored.
                 */
                if(get[k][j] != 1)
                {
                    dp[i][j+1][set[k][j][2]] += dp[i][j][k];
                    dp[i][j+1][set[k][j][2]] %= mod;
                }
                
                /*
                 If the state of the square above the current square is not 0,
                 you can color the current square.
                 In other words, if the sqaure above the current square either 
                 has an odd number of colored adjacent squares or is not colored,
                 you can color the current square.
                 */
                if(get[k][j] != 0)
                {
                    int newk = k;
                    
                    /*
                     We start by assuming that both above square and the left square
                     are not colored.
                     Set the state of the current square to 0
                     */
                    newk = set[newk][j][0];
                    
                    //If the top square is colored, flip the state of the current square
                    //We do have to change the state of top square since it will be discarded
                    //at the end of this iteration
                    if(get[k][j] == 1)
                    {
                        newk = set[newk][j][1 - get[newk][j]];
                    }
                    
                    //If the left square is colored, flip the state of the current square
                    //and the left square
                    if(j > 0 && get[k][j-1] != 2)
                    {
                        newk = set[newk][j][1 - get[newk][j]];
                        newk = set[newk][j-1][1 - get[newk][j-1]];
                    }
                    
                    //update the next DP state
                    dp[i][j+1][newk] += dp[i][j][k];
                    dp[i][j+1][newk] %= mod;
                }//end of an iteration
            }//end of a row
            
            
            //Move the profile in state (i,M,?) to (i+1, 0, ?)
            for(int k=0; k < pow3[M]; k++)
                dp[i+1][0][k] = dp[i][M][k];
        }
    }
    
    //All valid solutions is the state (N,0,k) where k does not contain any state 1
    int res = 0;
    
    for(int k=0; k < pow3[M]; k++)
    {
        bool isValid = true;
        for(int j=0; j < M; j++)
            if(get[k][j] == 1)
                isValid = false;
        
        if(isValid)
            res = (res + dp[N][0][k]) % mod;
    }
    
    return res;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	DengklekPaintingSquares *obj;
	int answer;
	obj = new DengklekPaintingSquares();
	clock_t startTime = clock();
	answer = obj->numSolutions(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	
	int p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 1;
	p2 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2;
	p1 = 2;
	p2 = 8;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 3;
	p2 = 5;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 47;
	p1 = 7;
	p2 = 944149920;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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
