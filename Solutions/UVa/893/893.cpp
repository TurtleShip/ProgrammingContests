#include <cstdio>
using namespace std;

int monLen[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(int year) {
	if(year % 400 == 0) return true;
	return year % 4 == 0 && year % 100 != 0;
}

void addADay(int& DD, int& MM, int& YYYY, bool isLeap, int& N) {
	N--;
	DD++;
	if(    (MM != 2 && DD > monLen[MM]) 
		|| (MM == 2 && ( (isLeap && DD > 29) || (!isLeap && DD > 28) ) )  ) {
		DD = 1;
		MM++;
	}
	
	if(MM > 12) {
		MM = 1;
		YYYY++;
	}
}

void addAYear(int& DD, int& MM, int& YYYY, int &N) {
	if(MM <= 2) {
		if(isLeapYear(YYYY)) {
			if(MM == 2 && DD == 29) {
				N -= 365;
				MM = 3;
				DD = 1;
			} else {
				N -= 366;
			}

		} else N-= 365;
	} else {
		if(isLeapYear(YYYY+1)) N -= 366;
		else N -= 365;
	}
	YYYY++;
}

int main() {
	
	int N, DD, MM, YYYY;

	while(scanf("%d %d %d %d", &N, &DD, &MM, &YYYY) && DD != 0) {
		while(N >= 366) addAYear(DD, MM, YYYY, N);
		while(N > 0) addADay(DD, MM, YYYY, isLeapYear(YYYY), N);
		printf("%d %d %d\n", DD, MM, YYYY);
	}

	return 0;
}