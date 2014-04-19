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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define FOR(i,a,b) for(int i=a; i < b; i++)
#define FORE(i, a, b) for(int i=a; i <=b; i++)
int INF = numeric_limits<int>::max();
int nINF = numeric_limits<int>::min();
typedef long long ll;
 
class CubeRoll {
public:
	int getMinimumSteps(int initPos, int goalPos, vector <int> holePos);
};

/*Case where init and goal is surround by holes.
 This case can be solved by using Breadth First Search.
 Remember holePos has range of 1 to 100,000.
 So if there are holes on both sides, we cannot role over 1 or 100,000.
 So for each position, there are at most sqrt(100,000) values to try.
 And there are at most 100,000 such points.
 Number of holes are at most rightHole.
 So running time is O(rightHole * sqrt(rightHole)).
 At its worst case it will run O(100,000 * 316), which is fast enough. */
int boundedCase(int leftHole, int init, int goal, int rightHole)
{
    int dist[rightHole+1]; //d[i] = minimum number of staps to reach position i from position init
    fill(dist, dist+rightHole+1, INF);
    queue<int> Q;
    Q.push(init);
    dist[init] = 0;
    
    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        
        //try all values of y satisfying ( x + y*y < rightHole)
        //try removing y*y <= rightHole after confirming this solution.
        //Since x > 0 always, y*y should be unnecessary
        for(int y=1; y*y <= rightHole && (x + y*y) < rightHole; y++)
        {
            int z = x + y*y;
            if(dist[x]+1 < dist[z])
            {
                Q.push(z);
                dist[z] = dist[x]+1;
            }
        }
        
        //try all values of y satisfying (x - y*y > leftHole)
        //y*y is checked to ensure that z does not end up being negative.
        //But since leftHole > 0 always, I don't think checking y*y is necessary.
        //Try removing the condition after confirming this solution.
        for(int y=1; y*y < x && (x - y*y) > leftHole; y++)
        {
            int z = x - y*y;
            if(dist[x] + 1 < dist[z])
            {
                Q.push(z);
                dist[z] = dist[x]+1;
            }
        }
    }
    return dist[goal];
}

//Case where one of either side is bounded. Since number of holePos is at least 1,
//There is no case where both sides are unbounded.
//Cases where a hole is between initPos and goal is invalid, and already dealt with
//by returning -1.
int unboundedCase(int dist)
{
    /*call the bounded case by placing bounds just before the start and right after the goal. This will cover all the cases that result from only adding squares.
     */
    int res = boundedCase(0,1,1+dist,2+dist);
    
    /* This is unbounded case, which means we can go all the way to one direction.
     So it is possible that a*a - b*b = goal exists.
     From editorial, we know that if dist%4 != 2, 
     it takes only two steps(move by a*a, and then go back by b*b).
     If dist % 4 == 2,
     it takes only three steps. 
     1. Go to init + 1 so that dist%4 != 2.
     2. now do a*a - b*b
     
     Keep in mind that boundedCase might produce better results, like going to goal
     at 1 step, or starting at goal (init == goal)
     */
    if(dist % 4 != 2)
        res = min(res,2);
    else
        res = min(res,3);
    return res;
}

int CubeRoll::getMinimumSteps(int initPos, int goalPos, vector <int> holePos){
	int leftHole = nINF;
    int rightHole = INF;
    int init = min(initPos, goalPos);
    int goal = max(initPos, goalPos);
    
    for(int i=0; i < holePos.size(); i++)
    {
        if(holePos[i] < init)
        {
            leftHole = max(leftHole, holePos[i]);
        }
        else if(holePos[i] > goal)
        {
            rightHole = min(rightHole, holePos[i]);
        }
        else return -1;
    }
    if(leftHole == nINF || rightHole == INF)
        return unboundedCase(goal - init);
    else return boundedCase(leftHole, init, goal, rightHole);
        
}
 

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	CubeRoll *obj;
	int answer;
	obj = new CubeRoll();
	clock_t startTime = clock();
	answer = obj->getMinimumSteps(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	vector <int> p2;
	int p3;
	
	{
	// ----- test 0 -----
	p0 = 5;
	p1 = 1;
	int t2[] = {3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = -1;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 36;
	p1 = 72;
	int t2[] = {300,100,200,400};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 10;
	p1 = 21;
	int t2[] = {38,45};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 2;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 98765;
	p1 = 4963;
	int t2[] = {10,20,40,30};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 2;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 68332;
	p1 = 825;
	int t2[] = {99726,371,67,89210};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 2;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
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
