#include <iostream>
#include <string>

using namespace std;

#define MAXK 100010
#define MAXA 1000010

string cd[1010]; // cardinal
string od[1010]; // ordinal

int res[MAXK];
int zero = 0;
void fill_tens_card(int ten) {
    for(int i=1; i <= 9; i++)
        cd[ten+i] = cd[ten] + " " + cd[i];
}
void fill_tens_ord(int ten) {
    for(int i=1; i <= 9; i++)
        od[ten+i] = cd[ten] + " " + od[i];
}

void killme() {
    zero = 5 / zero;
}

void fill_card() {
    cd[0] = "";
    cd[1] = "one";
    cd[2] = "two";
    cd[3] = "three";
    cd[4] = "four";
    cd[5] = "five";
    cd[6] = "six";
    cd[7] = "seven";
    cd[8] = "eight";
    cd[9] = "nine";
    cd[10] = "ten";
    cd[11] = "eleven";
    cd[12] = "twelve";
    cd[13] = "thirteen";
    cd[14] = "fourteen";
    cd[15] = "fifteen";
    cd[16] = "sixteen";
    cd[17] = "seventeen";
    cd[18] = "eighteen";
    cd[19] = "nineteen";
    cd[20] = "twenty"; fill_tens_card(20);
    cd[30] = "thirty"; fill_tens_card(30);
    cd[40] = "forty"; fill_tens_card(40);
    cd[50] = "fifty"; fill_tens_card(50);
    cd[60] = "sixty"; fill_tens_card(60);
    cd[70] = "seventy"; fill_tens_card(70);
    cd[80] = "eighty"; fill_tens_card(80);
    cd[90] = "ninety"; fill_tens_card(90);
    cd[100] = "hundred";
    cd[1000] = "thousand";
}

// 0 < num < 1000
void fill_ord() {
    od[0] = "";
    od[1] = "first";
    od[2] = "second";
    od[3] = "third";
    od[4] = "fourth";
    od[5] = "fifth";
    od[6] = "sixth";
    od[7] = "seventh";
    od[8] = "eighth";
    od[9] = "ninth";
    od[10] = "tenth";
    od[11] = "eleventh";
    od[12] = "twelfth";
    od[13] = "thirteenth";
    od[14] = "fourteenth";
    od[15] = "fifteenth";
    od[16] = "sixteenth";
    od[17] = "seventeenth";
    od[18] = "eighteenth";
    od[19] = "nineteenth";
    od[20] = "twentieth"; fill_tens_ord(20);
    od[30] = "thirtieth"; fill_tens_ord(30);
    od[40] = "fortieth"; fill_tens_ord(40);
    od[50] = "fiftieth"; fill_tens_ord(50);
    od[60] = "sixtieth"; fill_tens_ord(60);
    od[70] = "seventieth"; fill_tens_ord(70);
    od[80] = "eightieth"; fill_tens_ord(80);
    od[90] = "ninetieth"; fill_tens_ord(90);
    od[100] = "hundredth";
    od[1000] = "thousandth";
}

// 0 < num < 1000
string helper(int num) {
    if(num >= 1000 || num == 0) killme();
    if(num < 100) return od[num];
    if(num % 100 == 0) return cd[num/100] + " " + od[100];
    return cd[num/100] + " " + cd[100] + " " + od[num % 100];
}

// 0 < num < 1000
string getCard(int num) {
    if(num >= 1000 || num == 0) killme();
    if(num < 100) return cd[num];
    if(num%100 == 0) return cd[num/100] + " " + cd[100];
    return cd[num/100] + " " + cd[100] + " " + cd[num%100];
}

// given a number, return its ordinal representation
string getRes(int num) {
    if(num > 1000000) killme();
    if(num < 1000) return helper(num);
    if(num % 1000 == 0) return getCard(num/1000) + " " + od[1000];
    return getCard(num/1000) + " " + cd[1000] + " " + helper(num % 1000);
}

void preprocess() {
    fill_card();
    fill_ord();
    res[1] = 1;
    res[2] = 4;

    int read = 1;
    int k = 3;
    int ak = 7;

    /*
invariant:  read <= k
     */
    while(k <= 100000) {
        string cur = getRes(res[read++]);
        int space = 0;
        for(int i=0; i < cur.size(); i++) {
            if(cur[i] == ' ') space++;
            if(cur[i] == 't') {
                res[k++] = ak+i-space;
                if(k <= 100000 && ak+i > 1000000) {
                    killme();
                }

            }
        }
        if(read >= k) killme();
        
        ak += cur.size() - space;
    }
}

int main() {
    int N;
    preprocess();
    while(cin>>N && N != 0)
        cout<<res[N]<<endl;

    return 0;
}
