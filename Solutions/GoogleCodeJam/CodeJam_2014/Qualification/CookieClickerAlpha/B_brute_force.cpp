#include <cstdio>
using namespace std;


double getResultWithNCookies(
	double cookieCostPerFarm, double cookiesProducedPerFarm, 
	double neededNumCookies, int numFarms) {

	double rate = 2.0;
	double timeSpent = 0.0;
	double curCookies = 0.0;
	int curFarms = 0;

	for(int i=0; i < numFarms; i++) {
		timeSpent += cookieCostPerFarm / rate;
		rate += cookiesProducedPerFarm;
	}

	timeSpent += neededNumCookies / rate;
	
	return timeSpent;
}

int main() {
	int T;
	double C, F, X;

	scanf("%d", &T);

	for(int cid=1; cid <= T; cid++) {
		scanf("%lf %lf %lf", &C, &F, &X);

		double bestTime = getResultWithNCookies(C, F, X, 0);
		// keep increasing the number of farms we buy until we find the optimal
		int numFarms = 1;
		while(true) {
			double currentTime = getResultWithNCookies(C, F, X, numFarms);
			if(bestTime > currentTime) {
				bestTime = currentTime;
			} else break;
			numFarms++;
		}

		printf("Case #%d: %.7lf\n", cid, bestTime);
	}

	return 0;
}