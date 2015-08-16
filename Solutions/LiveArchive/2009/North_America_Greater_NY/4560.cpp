#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int neigh[][7] = {
	{0,1,0,0,0,1,0},
	{1,0,1,0,0,0,1},
	{0,1,0,1,0,0,0},
	{0,0,1,0,1,0,0},
	{0,0,0,1,0,1,1},
	{1,0,0,0,1,0,0},
	{0,1,0,0,1,0,0}
};

const int dir[][2] = { {-2,1}, {-2, -1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};


set<vector<int> > visited;

int encode(const vector<int>& A) {

}

int main() {
	vector<int> target;
	for (int i = 0; i < 7; i++) target.push_back(i);

	int _; cin >> _;
	while (_--) {
		int id;
		vector<int> initial;
		cin >> id;
		string str;
		cin >> str;
		for (int i = 0; i < 6; i++) {

		}
	}

	return 0;
}