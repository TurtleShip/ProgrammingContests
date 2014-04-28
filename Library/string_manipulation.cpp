#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <locale>
using namespace std;

// Readline using scanf : scanf("%[^\n]\n", input);

/*
Given string str, make str to all lowercase
and sort it. This can be useful when two words are
case insensitive anagrams.
Note that str will be mutated.
*/
void mutate(string& str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	sort(str.begin(), str.end());
}

// Removes duplicates in the given string.
void makeUnique(string &str) {
	sort(str.begin(), str.end());
	str.resize( distance(str.begin(), unique(str.begin(), str.end())));
}

// Remove all whitespace from the given string.
void eraseAllWhitespace(string& str) {
	str.erase( remove_if(str.begin(), str.end(), ::isspace), str.end() );
}

int main() {

	return 0;
}