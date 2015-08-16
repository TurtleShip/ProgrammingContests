#include <cstdio>
using namespace std;

double depPercent[110];
int main() {
	int duration, totalDep, depCount, curMonth;
	double downPayment, totalLoan, onePayment, curLoan, carValue, curDep;

	while(scanf("%d %lf %lf %d\n", &duration, &downPayment, &totalLoan, &totalDep)
			&& duration >= 0) {

      for(int i=0; i < totalDep; i++) {
        scanf("%d %lf\n", &curMonth, &curDep);
        for(int j=curMonth; j <= duration; j++) {
          depPercent[j] = curDep;
        }
      }
      onePayment = totalLoan / (double) duration;
      curMonth = 0;
      curLoan = totalLoan;
      carValue = (downPayment + totalLoan) * ( 1.0 - depPercent[0]);

      while(curLoan >= carValue) {
        curMonth++;
        curLoan -= onePayment;
        carValue = (carValue) * ( 1.0 - depPercent[curMonth]);
      }

      printf("%d %s\n", curMonth, (curMonth == 1) ? "month" : "months");
	}

	return 0;
}
