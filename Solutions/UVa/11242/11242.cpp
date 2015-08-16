#include <cstdio>
#include <algorithm>
using namespace std;

const double EPS = 1e-8;

/*
	returns
	-1 : if x <= y
	 0 : x == y
	 1 : x > y
*/
int cmp(const double& x, const double& y = 0, const double& tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
double front[20];
double rear[20];
double ratio[20*20];

int main() {
	int F, R, totalRatio;
	double d1, d2, res;
	while(scanf("%d %d", &F, &R) && F != 0) {

		res = 0.0;
		for(int i=0; i < F; i++)
			scanf("%lf", &front[i]);
		for(int i=0; i < R; i++)
			scanf("%lf", &rear[i]);

		// pre-calculate ratio
		totalRatio = F * R;
		for(int i=0; i < F; i++)
			for(int j=0; j < R; j++)
				ratio[i*R + j] = rear[j] / front[i]; // change this if answer doesn't match

		sort(&ratio[0], &ratio[totalRatio]);

		for(int i=1; i < totalRatio; i++)
			if(cmp(res, ratio[i]/ratio[i-1]) == -1)
				res = ratio[i] / ratio[i-1];

		printf("%.2lf\n", res);
	}
	
	return 0;
}