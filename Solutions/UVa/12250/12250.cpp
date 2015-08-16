#include <cstdio>
#include <string>
using namespace std;
char c_word[20];
int main() {
	
	int cid = 1;
	
	while(scanf("%s", c_word)) {
		string word(c_word);
		if(word == "#") break;
		string res = "UNKNOWN";
		if(word == "HELLO") res = "ENGLISH";
		else if( word == "HOLA") res = "SPANISH";
		else if( word == "HALLO") res = "GERMAN";
		else if( word == "BONJOUR") res = "FRENCH";
		else if( word == "CIAO") res = "ITALIAN";
		else if( word == "ZDRAVSTVUJTE") res = "RUSSIAN";
		printf("Case %d: %s\n", cid++, res.c_str());
	}
	return 0;
}