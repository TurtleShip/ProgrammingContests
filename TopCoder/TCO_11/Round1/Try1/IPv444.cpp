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
#define ANY -1
typedef long long ll;
 
class IPv444 {
public:
	long long getMaximumMoney(vector <string>, vector <int>);
};

struct IP
{
    int adr[4];
    int price;
};

bool sortByprice(IP a, IP b)
{
    return a.price > b.price;
}


long long IPv444::getMaximumMoney(vector <string> req, vector <int> pr) {
    
    ll res = 0ll;
    int N = req.size();
    set<int> dup[4]; //used to remove duplicates
    vector<int> part[4]; //ip consists of part[0].part[1].part[2].part[3]
    vector<IP> ip(N);
    
    for(int i=0; i < N; i++)
    {
        replace(req[i].begin(), req[i].end(), '.', ' ');
        stringstream ss(req[i]);
        for(int j=0; j < 4; j++)
        {
            char str[5];
            ss>>str;
            if(str[0] == '*')
                ip[i].adr[j] = ANY;
            else
                ip[i].adr[j] = atoi(str);

            dup[j].insert(ip[i].adr[j]);
        }
        ip[i].price = pr[i];
    }
    
    for(int i=0; i < 4; i++)
        part[i] = vector<int>(dup[i].begin() , dup[i].end());
    
    sort(ip.begin(), ip.end(), sortByprice);
    int p[4];
    for(p[0] = 0; p[0] < part[0].size(); p[0]++)
    {
        for(p[1] = 0; p[1] < part[1].size(); p[1]++)
        {
            for(p[2] = 0; p[2] < part[2].size(); p[2]++)
            {
                vector<int> matchID;
                for(int i=0; i < N; i++)
                {
                    bool isMatch = true;
                    for(int j=0; j < 3; j++)
                    {
                        if( ip[i].adr[j] != ANY && ( part[j][p[j]] == ANY || (part[j][p[j]] != ANY && ip[i].adr[j] != part[j][p[j]]) ) )
                        {
                            isMatch = false;
                            break;
                        }
                    }
                    if(isMatch)
                        matchID.push_back(i);
                }
                
                ll m = 1ll;
                for(int j=0; j < 3; j++)
                {
                    if(part[j][p[j]] == ANY)
                        m *= (1000ll - (part[j].size() - 1ll));
                }

                for(p[3]=0; p[3] < part[3].size(); p[3]++)
                {
                    ll curM = m;
                    if(part[3][p[3]] == ANY)
                        curM *= (1000ll - (part[3].size() - 1ll));
                    
                    for(int i=0; i < matchID.size(); i++)
                    {
                        int idx = matchID[i];
                        bool isMatch = !(ip[idx].adr[3] != ANY && ( part[3][p[3]] == ANY || (part[3][p[3]] != ANY && ip[idx].adr[3] != part[3][p[3]]) ));
                        
                        if(isMatch)
                        {
                            res += curM * ip[idx].price;
                            break;
                        }
                     
                        
                    }
                }
            }
            
        }
    }

	return res;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <int> p1, bool hasAnswer, long long p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	IPv444 *obj;
	long long answer;
	obj = new IPv444();
	clock_t startTime = clock();
	answer = obj->getMaximumMoney(p0, p1);
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
	vector <int> p1;
	long long p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"66.37.210.86"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {47};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 47llll;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"0.0.0.*","0.0.0.3","0.0.0.5"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,3,9};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1010llll;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"*.*.*.*","123.456.789.0","434.434.434.434","999.*.999.*"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,5,3,6};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1000005000006llll;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"*.*.999.999","888.888.999.*","888.888.*.999","777.777.777.777","777.*.*.777"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {19,33,42,777,7};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 26075718llll;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"127.0.0.1","*.0.0.*","*.*.255.255","192.68.*.*"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {999999,629851,294016,438090};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1361957076132llll;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
