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

typedef struct {
	int st;
	int end;
}range;

int main()
{
	int C;
	range xleft, ydown, xright, yup;
	int dum;
	string no = "No Overlap";


	cin>>C;

	while(C--) {
		cin>>xleft.st>>ydown.st>>xleft.end>>ydown.end>>xright.st>>yup.st>>xright.end>>yup.end;

		if(xleft.st > xright.st)
			swap(xleft, xright);

		if(ydown.st > yup.st)
			swap(ydown, yup);


		if(xleft.end <= xright.st || ydown.end <= yup.st) {
			cout<<no<<endl;

		} else {
			cout<<xright.st<<" "<<yup.st<<" "<<min(xleft.end,xright.end)<<" "<<min(yup.end, ydown.end)<<endl;
		}

		if(C > 0)
			cout<<endl;

	}
	
    return 0;

}