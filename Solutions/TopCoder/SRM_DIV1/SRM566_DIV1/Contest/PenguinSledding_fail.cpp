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

class PenguinSledding {
public:
	long long countDesigns(int numCheckpoints, vector <int> checkpoint1, vector <int> checkpoint2);
};

int groupID[55];



long long PenguinSledding::countDesigns(int numPT, vector <int> V1, vector <int> V2) {
	/*
     Observe1 : Two different paths cannot exist at the same time.
     For 2-conn : 2 ways
     For 3-conn : 3 ways
     
     Algo :
     1) Find all connected components.
     Go through each of them.
     For each one of them,
     if 2 : res += 2
     if 3 >= x : res += 3 * (x-3)
     */
    int N = V1.size();
    for(int i=1; i <= numPT; i++)
        groupID[i] = -1;
    int numGroup = 0;
    for(int i=0; i < N; i++) {
        int pt1 = V1[i];
        int pt2 = V2[i];
        if(groupID[pt1] == -1 && groupID[pt2] == -1) {
            groupID[pt1] = numGroup;
            groupID[pt2] = numGroup;
            numGroup++;
            continue;
        }
        int newID = max(groupID[pt1], groupID[pt2]);
        int oldID = min(groupID[pt1], groupID[pt2]);
        
        if(oldID == -1) {
            groupID[pt1] = newID;
            groupID[pt2] = newID;
            continue;
        }
        
        for(int j=1; j <= numPT; j++) {
            if(groupID[j] == oldID)
                groupID[j] = newID;
        }
    }
    printf("numGroup = %d\n",numGroup);
    ll res = 0ll;
    for(int id=0; id < numGroup; id++) {
        int curCt = 0;
        for(int i=1; i <= numPT; i++)
            if(groupID[i] == id)
                curCt++;
        printf("group %d has %d members\n", id, curCt);
        if(curCt <= 1) continue;
        if(curCt == 2) res += 2ll;
        if(curCt >= 3) res += 3ll * (ll(curCt) - 2ll);
    }
    
    return res;
}
 
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, bool hasAnswer, long long p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	PenguinSledding *obj;
	long long answer;
	obj = new PenguinSledding();
	clock_t startTime = clock();
	answer = obj->countDesigns(p0, p1, p2);
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
	vector <int> p1;
	vector <int> p2;
	long long p3;
	
	{
	// ----- test 0 -----
	p0 = 2;
	int t1[] = {1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 2ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 4;
	int t1[] = {1,2,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2,3,4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 6ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 6;
	int t1[] = {1,3,6};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2,4,4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 5ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 50;
	int t1[] = {40,40,40,40,40,40,40,40,40,40,40,40,50,40,40,40,23,4,24,40,22,40,8,40,40,40,34,21,40,40,38,40,40,40,40,40,28,40,40,40,40,46,13,40,40,40,47,40,40};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {45,42,20,48,12,32,25,10,26,39,16,2,19,43,37,17,19,19,19,18,19,27,19,29,11,36,19,19,1,41,19,35,14,33,49,3,19,7,5,19,31,19,19,6,9,15,19,44,30};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 68719493118ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 36;
	int t1[] = {13,24,24,20,31,16,10,36,34,32,28,5,20,29,23,2,14,4,9,5,19,21,8,1,26,27,25,15,22,30,30,6,11,7,2,35,13,29,4,12,33,18,13,14,17,35,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {10,15,27,1,29,11,5,18,33,1,9,2,31,6,19,10,33,18,6,27,3,22,4,12,31,30,34,16,7,24,3,28,15,21,22,8,26,20,14,32,25,17,35,8,36,26,23};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 162ll;
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