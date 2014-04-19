#include <cstdio>
#include <algorithm>
using namespace std;

bool is_green[110];
int light[110];
int cycle[110];

bool is_actually_green(int idx) {
	return is_green[idx] && (cycle[idx] - light[idx]) >= 5;
}

/*
	Converts second 'sec' into HH:MM:SS format.
	Use this function, and do printf("%2d:%2d:%2d\n", HH, MM ,SS);
	Related Problems
	UVa
		( 161, Traffic Lights )
*/
void convert_sec_to_time(int sec, int& HH, int& MM, int& SS) {
	SS = sec % 60;
	sec -= SS;
	sec /= 60;
	MM = sec % 60;
	HH = sec / 60;
}

int main() {
	int num, N, cur_time, max_time = 5 * 60 * 60;
	int HH,MM,SS;

	bool is_all_green;
	while(scanf(" %d", &num) && num != 0) {
		N = 0;
		cycle[N++] = num;
		cur_time = num;

		while(scanf(" %d", &num) && num != 0) {
			cycle[N++] = num;
			cur_time = min(cur_time, num);
		}

		// start at the time when the light with the shortest cycle
		// is about to turn red
		for(int i=0; i < N; i++) {
			light[i] = cur_time;
			is_green[i] = true;
		}

		cur_time--;
		while(cur_time <= max_time) {
			// check if all lights are green
			is_all_green = true;
			for(int i=0; is_all_green && i < N; i++) {
				is_all_green &= is_actually_green(i);
			}
			if(is_all_green) break;

			// If not go to next second
			for(int i=0; i < N; i++) {
				if(light[i] == cycle[i]) {
					is_green[i] = !is_green[i];
					light[i] = 1;
				} else {
					light[i]++;
				}
			}
			cur_time++;
		}

		if(cur_time <= max_time) {
			convert_sec_to_time(cur_time, HH, MM, SS);
			printf("%02d:%02d:%02d\n", HH, MM, SS);
		} else {
			printf("Signals fail to synchronise in 5 hours\n");
		}
	}

	return 0;
}