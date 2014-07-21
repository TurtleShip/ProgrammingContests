#include <cstdio>
#include <iostream>
#include <cmath>
typedef long long LL;

using namespace std;

int main() {
	LL a,b,w,x,c, res = 0ll;

	scanf("%lld %lld %lld %lld %lld", &a, &b, &w, &x, &c);
	if(c > a) {
		/* 
		Looks like a problem that Saketh can solve easily.

		If there is a simpler way to come up with a formula than the one I described below,
		please ping me, Daniel :-)

		'c' always gets reduced by 1
		But 'a' is reduced by 1 only when b < x. i.e. 'a' stays when b >= x
		we want to b >= x happen (c-a) times so that (c == a) satisfies.

		When b >= x, we perform below operation
		b -= x.

		when b < x, we perform the below 2 operations
			1) b = w - (x - b) = w - x + b = b + w - x
			=> b += w - x
			2) a--;

		Let res = the number of seconds passed when c == a.
		At the (res)th second,
			1) b has been substracted by x, (c-a) times.
				=> b -= x * (c - a)
			2) b has been added (w-x), (res - (c - a)) times.
				=> b += (w - x) * (res - (c - a))
			Let z = ( res - (c-a) ) for simplicity. ( i.e. b += (w-x) * z)

		Now, 'b' that we are given is the intial value of b.
		So, 'b' is the value before 1) and 2) happened.
		We can get the initial 'b' as below.
		b = x * (c - a) - (w - x) * z

		(w - x) * z = x * (c - a) - b
				  z = ((c - a) * x - b) / (w - x)

		res - (c - a) = ((c - a) * x - b) / (w - x)
				  res = (c - a) + ((c - a) * x - b) / (w - x)
				  	  = ( (w-x)(c-a) + (c-a) * x - b ) / (w - x)
				  	  = ( (c-a)(w-x + x) - b ) / (w - x)
				  	  = ( (c-a)(w) - b) / (w - x)
		*/

		res = LL(ceil(double(((c - a) * w - b)) / double(w - x)));
	}
	cout<<res<<endl;
	return 0;
}