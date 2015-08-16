#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	float hourInc = 360. / 12.;
	float hourMinInc = hourInc / 60.;
	float minInc = 360. / 60.;

	float hour, minute, hourAngle, minuteAngle, diff, res;

	while(scanf("%f:%f", &hour, &minute) && hour != 0) {
		hourAngle = hour * hourInc + hourMinInc * minute;
		minuteAngle = minute * minInc;
		res = max(hourAngle, minuteAngle) - min(hourAngle, minuteAngle);
		res = min(res, 360 - res);
		printf("%.3f\n", res);
	}

	return 0;
}