#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a,b,c,d, ct;
	int an,bn,cn,dn;
	while(cin>>a>>b>>c>>d) {
		if( (a+b+c+d) == 0 ) break;
		ct = 0;
		while(true) {
			if( a==b && b==c && c==d) break;
			an = abs(a-b);
			bn = abs(b-c);
			cn = abs(c-d);
			dn = abs(d-a);
			a = an;
			b = bn;
			c = cn;
			d = dn;
			ct++;
		}
		cout<<ct<<endl;
	}


	return 0;

}