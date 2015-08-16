#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<double> vD;
vector<double> vF;
int main() {
	double dist, fuel, rate;
	double totalDist, totalFuel, res;
	int resF;

	while(cin>>dist>>fuel) {
		if(dist==-1.0 && fuel == -1.0)
			break;
		if(dist==0.0 && fuel == 0.0) {
			// do calculation
			totalDist = 0.0;
			totalFuel = 0.0;
			int N = vF.size();
			for(int i=1; i < N; i++) {
				if(vF[i] > vF[i-1]) continue;
				totalDist += vD[i] - vD[i-1];
				totalFuel += vF[i-1] - vF[i];
			}
			rate = totalDist / totalFuel;
			res = vF[N-1] * rate;
			res += 0.5;
			resF = static_cast<int>(res);
			cout<<resF<<endl;

			//prep for next
			vD.clear();
			vF.clear();
		} else {
			vD.push_back(dist);
			vF.push_back(fuel);		
		}
	}

	return 0;
}