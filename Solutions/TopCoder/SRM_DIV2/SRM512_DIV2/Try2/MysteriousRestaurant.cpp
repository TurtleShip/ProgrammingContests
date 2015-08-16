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
 
class MysteriousRestaurant {
public:
	int maxDays(vector <string>, int);
};

int getPrice(char ch)
{
    if('0' <= ch && ch <= '9')
        return int(ch - '0');
    
    if('A' <= ch && ch <= 'Z')
        return (int(ch - 'A') + 10);
    
    if('a' <= ch && ch <= 'z')
        return (int(ch - 'a') + 36);
    
    cout<<"getPrice cause error"<<endl;
    return -1;
}

/*
 number of days = N <= 50
 number of menus = M <= 50 
 
 Trying every differnt combination
 = 50^50 = 5^50 * 10^50 => Way too big
 
 How about using dp ?
 A state will store the minimum possible number that will be spent.
 A state needs how many days.
 
 dp[0] = minimum of price[0]
 dp[1] = minimum of price[1]
 ....
 dp[8] = dp[7] - dp[0] + minimum of (price[0][j] + price[8][j])
 
dp[i] = dp[i-1] - dp[i - 7*j] + minimum of (price[i-7*z][menu])
 
 Finding minimum will take 50 at most.
 This dp will take 50 * 50 = 2500. Small enough~!
*/


int MysteriousRestaurant::maxDays(vector <string> prices, int budget) {
	int N = prices.size();
    int M = prices[0].size();
    
    int dp[50];
    int menu[7];

    for(int day = 0; day < N; day++)
    {
        if(day < 7)
        {
            int minCost = 100;
            for(int m = 0; m < M; m++)
            {
                if(getPrice(prices[day][m]) < minCost)
                {
                    minCost = getPrice(prices[day][m]);
                    menu[day] = m;
                }
            }
            
            if(day == 0) dp[day] = minCost;
            else 
            {
                dp[day] = dp[day - 1];
                dp[day] += minCost;
            }            
            
        }
        else
        {
            dp[day] = dp[day - 1];
            for(int i=1; (day - 7*i) >= 0; i++)
                dp[day] -= getPrice(prices[(day-7*i)][menu[day%7]]);
            
                
            int minCost = 100 * 10;
            for(int m =0; m < M; m++)
            {
                int temp = 0;
                for(int i=0; (day - 7*i) >=0; i++)
                    temp += getPrice(prices[(day-7*i)][m]);
                
                if(temp < minCost)
                {
                    minCost = temp;
                    menu[day%7] = m;
                }
            }
            dp[day] += minCost;
        }

        if(budget < dp[day]) return day;
    }
    
    return N;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	MysteriousRestaurant *obj;
	int answer;
	obj = new MysteriousRestaurant();
	clock_t startTime = clock();
	answer = obj->maxDays(p0, p1);
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
	
	vector <string> p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"26","14","72","39","32","85","06"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 13;
	p2 = 5;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"26","14","72","39","32","85","06","91"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 20;
	p2 = 8;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"SRM","512"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	p2 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"Dear","Code","rsHa","veFu","nInT","heCh","alle","ngeP","hase","andb","ecar","eful"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 256;
	p2 = 10;
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