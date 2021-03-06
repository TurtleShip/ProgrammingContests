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

typedef long long ll; 

class AntsMeet {
public:
	int countAnts(vector <int> x, vector <int> y, string direction);
};

bool isAlive[55];
vector<int> prevX;
vector<int> prevY;

int AntsMeet::countAnts(vector <int> x, vector <int> y, string dir) {
	/*
     At most 2000 iterations.
     50 ants.
     50x50 comparison.
     Worst = 2000 * (50 + 50*50)
     = 2000 * 3000
     = 6,000,000  
     => Small enough to simulate
     */
    int N = x.size();
    int ct = 0;
    int res = 0;
    for(int i=0; i < N; i++)
        isAlive[i] = true;
    
    for(int i=0; i < N; i++) {
        prevX.push_back(x[i]);
        prevY.push_back(y[i]);
    }
    
    // simulate 2000 steps
    while(ct++ < 2000) {
        //update
        for(int i=0; i < N; i++) {
            if(dir[i] == 'N') y[i]++;
            else if(dir[i] == 'E') x[i]++;
            else if(dir[i] == 'W') x[i]--;
            else y[i]--;
        }
        vector<int> deadAnts;
        
        for(int i=0; i < N; i++) {
            if(!isAlive[i]) continue;
            for(int j=i+1; j < N; j++) {
                if(!isAlive[j]) continue;
        
                //meet at the middle
                if(x[i] == prevX[j] && prevX[i] == x[j] && y[i] == prevY[j] &&  prevY[i] == y[j]) {
                    deadAnts.push_back(i);
                    deadAnts.push_back(j);
                }
            }
        }
        
        //update
        for(int i=0; i < deadAnts.size(); i++)
            isAlive[deadAnts[i]] = false;
        
        deadAnts.clear();
        
        for(int i=0; i < N; i++) {
            if(!isAlive[i]) continue;
            for(int j=i+1; j < N; j++) {
                if(!isAlive[j]) continue;
                
                //land at the same spot
                if(x[i] == x[j] && y[i] == y[j]) {
                    deadAnts.push_back(i);
                    deadAnts.push_back(j);
                }
            }
        }
        
        //update
        for(int i=0; i < deadAnts.size(); i++)
            isAlive[deadAnts[i]] = false;
        
        for(int i=0; i < N; i++) {
            prevX[i] = x[i];
            prevY[i] = y[i];
        }
    }
    
    for(int i=0; i < N; i++)
        if(isAlive[i]) res++;
    
    return res;
}
 
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, string p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "\"" << p2 << "\"";
	cout << "]" << endl;
	AntsMeet *obj;
	int answer;
	obj = new AntsMeet();
	clock_t startTime = clock();
	answer = obj->countAnts(p0, p1, p2);
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
	
	vector <int> p0;
	vector <int> p1;
	string p2;
	int p3;
	
	{
	// ----- test 0 -----
	int t0[] = {0,10,20,30};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,10,20,30};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "NWNE";
	p3 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {-10,0,0,10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,-10,10,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "NEWS";
	p3 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {-1,-1,-1,0,0,0,1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-1,0,1,-1,0,1,-1,0,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "ESEWNNEWW";
	p3 = 4;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {4,7,6,2,6,5,7,7,8,4,7,8,8,8,5,4,8,9,1,5,9,3,4,0,0,1,0,7,2,6,9,6,3,0,5,5,1,2,0,4,9,7,7,1,8,1,9,2,7,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,3,0,6,8,4,9,0,5,0,2,4,3,8,1,5,0,7,3,7,0,9,8,1,9,4,7,8,1,1,6,6,6,2,8,5,1,9,0,1,1,1,7,0,2,5,4,7,5,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "SSNWSWSENSWSESWEWSWSENWNNNESWSWSWWSSWEEWWNWWWNWENN";
	p3 = 25;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {478,-664,759,434,-405,513,565,-396,311,-174,56,993,251,-341,993,-112,242,129,383,513,-78,-341,-148,129,423,493,434,-405,478,-148,929,251,56,242,929,-78,423,-664,802,251,759,383,-112,-591,-591,-248,660,660,735,493};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-186,98,948,795,289,-678,948,-170,-195,290,-354,-424,289,-157,-166,150,706,-678,684,-294,-234,36,36,-294,-216,-234,427,945,265,-157,265,715,275,715,-186,337,798,-170,427,706,754,961,286,-216,798,286,961,684,-424,337};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "WNSNNSSWWWEENWESNSWSWSEWWEWEWWWNWESNSSNNSNNWWWNESE";
	p3 = 44;
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
