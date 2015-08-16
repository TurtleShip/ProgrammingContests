#include <cstdio>
#include <string>
using namespace std;

// ========== The begining of Support variables / functions for AddNDays
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
// ========== The end of Support variables / functions for AddNDays
/*
  Given DD/MM/YYYY, add N days to DD/MM/YYYY
  Note that leap year is defined as
  any year that is divisible by 400,
  or year that is divisible by 4 but by 100.
  Related problem:
  	UVa
  		( 893, Y3K problem)
  		( 11947, Cancer or Scorpio )
*/
void addNDays(int& DD, int& MM, int& YYYY, int N) {
	while(N >= 366) addAYear(DD, MM, YYYY, N);
	while(N > 0) addADay(DD, MM, YYYY, isLeapYear(YYYY), N);
}

typedef struct Date {
	/*
	data.first.first = year;
	data.first.second = month;
	data.second = day;
	*/
	pair< pair<int,int>, int > data;
	Date() {}

	Date(int month, int day) {
		data.first.first = -1;
		data.first.second = month;
		data.second = day;
	}

	Date(int month, int day, int year) {
		data.first.first = year;
		data.first.second = month;
		data.second = day;
	}

	bool operator<=(Date other) {
		return data <= other.data;
	}
} Date;

int getInt(char ch) {
	return ch - '0';
}

string getZodiac(Date date) {
	if(Date(1, 21) <= date && date <= Date(2, 19)) return "aquarius";
	if(Date(2, 20) <= date && date <= Date(3, 20)) return "pisces";
	if(Date(3, 21) <= date && date <= Date(4, 20)) return "aries";
	if(Date(4, 21) <= date && date <= Date(5, 21)) return "taurus";
	if(Date(5, 22) <= date && date <= Date(6, 21)) return "gemini";
	if(Date(6, 22) <= date && date <= Date(7, 22)) return "cancer";
	if(Date(7, 23) <= date && date <= Date(8, 21)) return "leo";
	if(Date(8, 22) <= date && date <= Date(9, 23)) return "virgo";
	if(Date(9, 24) <= date && date <= Date(10, 23)) return "libra";
	if(Date(10, 24) <= date && date <= Date(11, 23)) return "scorpio";
	if(Date(11, 23) <= date && date <= Date(12, 22)) return "sagittarius";
	return "capricorn";
}


int main() {
	int T;
	scanf(" %d", &T);
	int MM, DD, YYYY;
	char buf[10];
	for(int cid=1; cid <= T; cid++) {
		scanf("%s", buf);
		MM = getInt(buf[0]) * 10 + getInt(buf[1]);
		DD = getInt(buf[2]) * 10 + getInt(buf[3]);
		YYYY = getInt(buf[4]) * 1000 + getInt(buf[5]) * 100
		     + getInt(buf[6]) * 10 + getInt(buf[7]) ;

		addNDays(DD, MM, YYYY, 280);
		string zodiac = getZodiac(Date(MM, DD));
		printf("%d %02d/%02d/%d %s\n", cid, MM, DD, YYYY, zodiac.c_str());
	}

	return 0;
}