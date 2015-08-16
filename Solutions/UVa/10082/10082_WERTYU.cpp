#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
map< char, char > M;

void init() {
    M['1'] = '`';
    M['2'] = '1';
    M['3'] = '2';
    M['4'] = '3';
    M['5'] = '4';
    M['6'] = '5';
    M['7'] = '6';
    M['8'] = '7';
    M['9'] = '8';
    M['0'] = '9';
    M['-'] = '0';
    M['='] = '-';
    M['W'] = 'Q';
    M['E'] = 'W';
    M['R'] = 'E';
    M['T'] = 'R';
    M['Y'] = 'T';
    M['U'] = 'Y';
    M['I'] = 'U';
    M['O'] = 'I';
    M['P'] = 'O';
    M['['] = 'P';
    M[']'] = '[';
    M['\\'] = ']';
    M['S'] = 'A';
    M['D'] = 'S';
    M['F'] = 'D';
    M['G'] = 'F';
    M['H'] = 'G';
    M['J'] = 'H';
    M['K'] = 'J';
    M['L'] = 'K';
    M[';'] = 'L';
    M['\''] = ';';
    M['X'] = 'Z';
    M['C'] = 'X';
    M['V'] = 'C';
    M['B'] = 'V';
    M['N'] = 'B';
    M['M'] = 'N';
    M[','] = 'M';
    M['.'] = ',';
    M['/'] = '.';
    M[' '] = ' ';
}
int main() {
    init();
    char in[10000];
    while(gets(in) != NULL) {
        for(int i=0; i < strlen(in); i++)
            printf("%c", M[in[i]]);
        printf("\n");
    }
    return 0;
}