#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxS = 4;
const int maxP = 5;

int N, P, S;
string str;
string name[maxS+1];
string num[maxS+1];

int ind[maxS+1][maxP+1]; // ind[s][p] = Ending index of product p of seller s
int val[maxS+1][maxP+1]; // val[s][p] = value of product p of seller s
bool foundRes = false;
int length(int x){
    int res = 0;
    while(x != 0) {
        x/=10;
        res++;
    }
    return res;
}


void dfs(int s, int p){
    if(foundRes) return;
    if(s==S){
            //check totals
        for(int ss = 0; ss<S; ss++)
            for(int pp = 0; pp<=P; pp++)
                val[S][pp] += val[ss][pp];
        int idx = 0;
        
//        for(int i=0; i <= P; i++)
//            cout<<val[S][i]<<" ";
//        cout<<endl;
        
        for(int pp = 0; pp<P; pp++){
            int ln = length(val[S][pp]);
            if(atoi(num[S].substr(idx, ln).c_str())!=val[S][pp]) return;
            idx += ln;
        }
        //print solution :)
        for(int q=0; q<P; q++){
            cout << "P" << q+1 << " ";
        }
        cout << "Totals" << endl;
        for(int ss=0; ss<=S; ss++){
            cout << name[ss];
            for(int pp=0; pp<=P; pp++)
                cout << " " << val[ss][pp];
            cout << endl;
        }
        
        foundRes = true;
    }
    else if(p==P){
            //check row
        int sum = atoi( (num[s].substr(0,ind[s][0])).c_str()  );
        val[s][0] = sum;
        for(int pp=1; pp<P; pp++){
            val[s][pp] = atoi(( num[s].substr(ind[s][pp-1],ind[s][pp]-ind[s][pp-1]) ).c_str());
            sum += val[s][pp];
        }
        val[s][P] = sum;
        if(sum != atoi((num[s].substr(ind[s][P-1])).c_str())) return;
        
        
//        cout << "We found a solution for the first row." << endl;
//        cout << atoi( (num[s].substr(0,ind[s][0])).c_str()  );
//        for(int pp=1; pp<P; pp++){
//            cout <<" + "<<atoi(( num[s].substr(ind[s][pp-1],ind[s][pp]-ind[s][pp-1]) ).c_str());
//        }
//        cout << " = " << sum << endl;
//        cout<<endl;
        
//        for(int pp=0; pp<P; pp++){
//            cout << inds[s][pp] << " ";
//        }
//        cout << endl; 
        dfs(s+1, 0);
    }
    else{
        int start;
        if(p==0) start = 1;
        else start = ind[s][p-1]+1;
        for(ind[s][p]=start; ind[s][p]<num[s].size(); ind[s][p]++){
            if(p==0 && ind[s][p]>=2 && num[s][0] == '0') continue;
            if(p>0 && (ind[s][p]-ind[s][p-1]>1) && num[s][ind[s][p-1]] == '0') continue;
            dfs(s, p+1);
        }
    }
}

int main(){
    cin >> N;
    while(N--) {
        foundRes = false;
        cin>>str;
        P = (str.size() - 6) / 2;
        S = 0;
        while(true) {
            cin>>str;
            int pos;
            for(int i=0; i < str.size(); i++)
                if('0' <= str[i] && str[i] <= '9') {
                    pos = i;
                    break;
                }
            
            name[S] = str.substr(0, pos);
            num[S] = str.substr(pos);
            if(name[S] == "TP") break;
            S++;
        }
        dfs(0,0);

    }
    return 0;
}