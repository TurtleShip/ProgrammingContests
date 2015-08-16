#include<iostream>
#include<set>
using namespace std;

int N, P, A;
int X, Y, Z;
char t;
set<int> p;

int hash(int x, int y, int z){
    return 101 * 101 * x + 101 * y + z;
}

bool dup(){
    return p.find(hash(X, Y, Z))!=p.end();
}

int touch(){
    return (p.find(hash(X-1, Y, Z))!=p.end())
         + (p.find(hash(X+1, Y, Z))!=p.end())
         + (p.find(hash(X, Y-1, Z))!=p.end())
         + (p.find(hash(X, Y+1, Z))!=p.end())
         + (p.find(hash(X, Y, Z-1))!=p.end())
         + (p.find(hash(X, Y, Z+1))!=p.end());
}

void add(){
    A += 6 - 2 * touch();
    p.insert(hash(X, Y, Z));
}

int main(){
    cin >> N;
    for(int n=0; n<N; n++){
        cin >> P;
        A = 0;
        p.clear();
        

        bool fail = false;
        int flid;

        cin >> X >> t >> Y >> t >> Z;
        if((X!=0) || (Y!=0) || (Z!=0)){
            fail = true;
            flid = 0;
        }
        else{ add(); }
        
        for(int p=1; p<P; p++){
            cin >> X >> t >> Y >> t >> Z;
            if(fail) continue;
            if(dup() || !touch()){
                flid = p;
                fail = true;
            }
            else add();
        }
        if(!fail) cout << n+1 << " " << A << endl;
        else cout << n+1 << " NO " << flid+1 << endl;
    }
    return 0;
}
