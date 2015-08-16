#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string get_palin(string str) {
	int N = str.size();
	int half = N / 2;
	for(int i=0; i < half; i++)
		str[N-1-i] = str[i];
	return str;
}

string add_one(string str) {
	int N = str.size();
	int idx = (N+1)/2 - 1;
	while(str[idx] == '9') {
		str[idx] = '0';
		idx--;
	}
	str[idx] = char(str[idx] + 1);
	return str;
}

int main() {
	string str, cur;
	int num, res;

	while(cin>>str && str.size() > 1) {
		num = atoi(str.c_str());
		res = atoi(get_palin(str).c_str());
		if(res < num) res = atoi(get_palin(add_one(str)).c_str());
		cout<<(res - num)<<endl;
	}
	return 0;
}