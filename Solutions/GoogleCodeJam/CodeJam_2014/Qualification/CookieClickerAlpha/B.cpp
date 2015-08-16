#include <cstdio>
#include <cmath>
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

		/*
			Do binary search on number of farms that we buy.

			Lower bound : 0  ( no farm purchased)
			Upper bound : ceiling (X / C) => Buy farms with cookies that
						  are enough to end the game.
		*/
		int lowerBound = 0;
		int upperBound = int(ceil(X / C));
		int mid;
		bool isDecreasing, isPeak;
		double midPrevVal, midVal, midNextVal;
		while(lowerBound < upperBound) {
			mid = (lowerBound + upperBound) / 2;
			midPrevVal = (mid == 0) ? 0.0 : getResultWithNCookies(C,F,X, mid - 1);
			midVal = getResultWithNCookies(C, F, X, mid);
			midNextVal = getResultWithNCookies(C,F,X, mid + 1);
			isDecreasing = midPrevVal >= midVal;
			isPeak = midVal <= midNextVal;

			if(isDecreasing && isPeak) break;

			if(isDecreasing) {
				lowerBound = mid;
			} else {
				upperBound = mid;
			}
		}

		printf("Case #%d: %.7lf\n", cid, midVal);
	}

	return 0;
}