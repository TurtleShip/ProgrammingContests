#include<iostream>
#include<string>
using namespace std;

int N;
int P, Q, R, S;
string str;

int main(){
    cin >> N;
    for(int _=0; _<N; _++){
        cin >> str;
        P = Q = R = S = 0;
        for(int c=0; c<str.length(); c++){
            if(str[c] == 'p') P = c;
            if(str[c] == 'q') Q = c;
            if(str[c] == 'r') R = c;
            if(str[c] == 's') S = c;
        }
        //up
        int start = max(S, R);
        if(start==0) cout << "<none>";
        else{
            for(int c=0; c<start; c++)
                cout << str[c];
            if(str[start]=='s') cout << 'p';
            else cout << 'q';
            for(int c=start+1; c<str.length(); c++)
                if(str[c] == 'p') cout << 's';
                else cout << 'r';
        }
        cout << " ";
        
        //down
        start = max(P, Q);
        if(start==0) cout << "<none>";
        else{
            for(int c=0; c<start; c++)
                cout << str[c];
            if(str[start]=='p') cout << 's';
            else cout << 'r';
            for(int c=start+1; c<str.length(); c++)
                if(str[c] == 's') cout << 'p';
                else cout << 'q';
        }
        cout << " ";
        
        //left
        start = max(Q, R);
        if(start==0) cout << "<none>";
        else{
            for(int c=0; c<start; c++)
                cout << str[c];
            if(str[start]=='q') cout << 'p';
            else cout << 's';
            for(int c=start+1; c<str.length(); c++)
                if(str[c] == 'p') cout << 'q';
                else cout << 'r';
        }
        cout << " ";
        
        //right
        start = max(P, S);
        if(start==0) cout << "<none>";
        else{
            for(int c=0; c<start; c++)
                cout << str[c];
            if(str[start]=='p') cout << 'q';
            else cout << 'r';
            for(int c=start+1; c<str.length(); c++)
                if(str[c] == 'q') cout << 'p';
                else cout << 's';
        }
        cout << endl;
    }
}
