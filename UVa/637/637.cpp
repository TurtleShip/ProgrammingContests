#include <cstdio>
#include <string>
using namespace std;

int left[110];
int right[110];

int main() {
	int N, total_sheets, total_pages, num, cur_page;
	char blank[6] = "Blank";
	bool is_left;

	while(scanf(" %d", &N) && N != 0) {
		total_sheets = (N + 3) / 4;
		num = 1;
		total_pages = total_sheets * 2; // two pages per sheet
		
		printf("Printing order for %d pages:\n", N);
		// initialize
		for(int i=1; i <= total_pages; i++)
			left[i] = right[i] = -1;
		is_left = false;

		for(int i=1; i <= total_pages; i++) {
			if(is_left) left[i] = num++;
			else right[i] = num++;
			is_left = !is_left;
		}

		for(int i=total_pages; i >= 1 && num <= N; i--) {
			if(is_left) left[i] = num++;
			else right[i] = num++;
			is_left = !is_left;
		}

		for(int i=1; i <= total_pages; i++) {
			if(left[i] > N || right[i] > N) break;
			printf("Sheet %d, %s: %s, %s\n", (i+1) / 2, (i % 2) == 1 ? "front" : "back ",
			left[i] == -1 ? blank : to_string(left[i]).c_str(), 
			right[i] == -1 ? blank : to_string(right[i]).c_str());
		}

	}
	return 0;
}