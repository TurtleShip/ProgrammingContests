#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int diff = 'a' - 'A';
bool myComp(const char a, const char b)
{
	bool is_a_upper = ('A' <= a && a <= 'Z');
	bool is_b_upper = ('A' <= b && b <= 'Z');

	if(is_a_upper == is_b_upper)
		return a < b;
    
    char a_low = (is_a_upper) ? (a + diff) : a;
    char b_low = (is_b_upper) ? (b + diff) : b;
    
    // An upper case letter goes before the corresponding lower case letter.
    if(a_low == b_low) 
    	return is_a_upper;
    
    return a_low < b_low;
}

// Some smart guy wrote this and I found it on Internet.
// bool myComp2(const char a, const char b) {
//     int delta = tolower(a) - tolower(b);
//     return delta ? delta < 0 : a <b;
// }

int main(){
    int T;
    cin>>T;
    while(T--){
        string str;
        cin>>str;
        sort(str.begin(), str.end(), myComp);
        do{
            cout<<str<<endl;            
        }while(next_permutation(str.begin(), str.end(), myComp));
    }
 return 0;   
}