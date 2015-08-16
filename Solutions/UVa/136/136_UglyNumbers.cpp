//printf(“The 1500′th ugly number is 859963392.\n”);
#include <stdio.h>
#include <algorithm>

int main()
{
    int a,b,c,n;
    long ugly[1502],x,y,z;
    ugly[1]=1;
    a=b=c=1;
    n=1;
    while(n!=1500)
    {
        x=2*ugly[a];
        y=3*ugly[b];
        z=5*ugly[c];
        n++;
        ugly[n]=min(x,min(y,z));
        if(ugly[n]==x)a++;
        if(ugly[n]==y)b++;
        if(ugly[n]==z)c++;
    }
    printf(“The 1500′th ugly number is %ld.\n”,ugly[1500]);
    return 0;
}


   /* int ct = 1;
    int val = 1;
    while( ct != 1500) {
        val++;
        int cur = val;
        while(cur % 2 == 0) cur /= 2;
        while(cur % 3 == 0) cur /= 3;
        while(cur % 5 == 0) cur /= 5;
        if(cur == 1) ct++;
    }
    printf("The 1500'th ugly number is 859963392.\n");
    return 0;
}
*/