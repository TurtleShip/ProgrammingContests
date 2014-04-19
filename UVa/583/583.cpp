#include <cstdio>
using namespace std;

int main() {
	int res;
	double H, curPos, up, F, fatigue, down;

	while(scanf("%lf %lf %lf %lf\n", &H, &up, &down, &F) && H != 0) {
		curPos = 0.0;
		fatigue = (up * (F/100));
		res = 0;

		while(curPos >= 0) {
			res++;
			curPos += (up > 0 ? up : 0);
			if(curPos > H) break;
			curPos -= down;
			up -= fatigue;
		}

		printf("%s on day %d\n", (curPos < 0) ? "failure" : "success", res);
	}
	return 0;
}
