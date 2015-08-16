#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>
using namespace std;
char in[1000000];
int inx;
char buf[100000];
bool parse(string tag, bool has_tag) {
	while (in[inx]) {
		if (in[inx] < 32 || in[inx] > 127) return false;
		if (in[inx] == '>') return false;
		if (in[inx] == '&') {
			inx++; // consumes the '&'
			if (in[inx] == 'l' && in[inx+1] == 't' && in[inx+2] == ';') {
				inx += 3;
				continue;
			} else if (in[inx] == 'g' && in[inx+1] == 't' && in[inx+2] == ';') {
				inx += 3;
				continue;
			} else if (in[inx] == 'a' && in[inx+1] == 'm' && in[inx+2] == 'p' && in[inx+3] == ';') {
				inx += 4;
				continue;
			} else if (in[inx] != 'x') return false;
			inx++;
			int count = 0;
			for (; in[inx] && isxdigit(in[inx]); inx++) count++;
			if (count % 2) return false;
			if (in[inx] != ';') return false;
			inx++;
			continue;
		}
		if (in[inx] == '<') {
			inx++;
			bool close = in[inx] == '/';
			if (close) inx++;
			int n;
			sscanf(in+inx, "%[a-z0-9]%n", buf, &n);
			inx += n;
			bool sole = in[inx] == '/';
			if (close && sole) return false;
			if (sole) inx++;
			if (in[inx] != '>') return false;
			inx++;
			if (close) return has_tag == true && strcmp(buf, tag.c_str()) == 0;
			if (sole) continue;
			if (!parse(buf, true)) return false;
			continue;
		}
		inx++;
	}
	return has_tag == false;
}

int main() {
	while (gets(in)) {
		inx = 0;
		if (parse("", false)) printf("valid\n");
		else printf("invalid\n");
	}
	return 0;
}