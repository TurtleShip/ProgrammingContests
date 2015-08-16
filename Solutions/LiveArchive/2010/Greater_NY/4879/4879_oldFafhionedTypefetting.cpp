#include <sstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> M;
bool isLongs[1010];
void initDo() {
    M["AE"] = "[AE]";
    M["Ae"] = "[AE]";
    M["ae"] = "[ae]";
    M["OE"] = "[OE]";
    M["Oe"] = "[OE]";
    M["oe"] = "[oe]";
    M["ct"] = "[ct]";
    M["ff"] = "[ff]";
    M["fi"] = "[fi]";
    M["fl"] = "[fl]";
    M["ffi"] = "[ffi]";
    M["ffl"] = "[ffl]";
    M["s"] = "[longs]";
    M["si"] = "[longsi]";
    M["sh"] = "[longsh]";
    M["sl"] = "[longsl]";
    M["ss"] = "[longss]";
    M["st"] = "[longst]";
    M["ssi"] = "[longssi]";
    
}

bool isPunc(char ch) {
    return ch == '.' || ch == ',' || ch == '-' || ch == '"' || ch == '\'';
}

bool isLetter(char ch) {
    return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

int main() {
    initDo();
    string line;
    string cur;
    int Q,T;
    int idx = 1;
    cin>>Q;
    getline(cin,line); //get rid of '/n'
    
    while(idx <= Q) {
        getline(cin,line);
        /*stringstream ss;
        ss<<line;
        ss>>T;
        cout<<T;*/
        
        int q = 0;
        while('0' <= line[q] && line[q] <= '9') q++;
        q++;
        
        cout<<idx;
        idx++;
        
        int TER = line.size();
        cout<<" ";
        while(q < TER) {
            
            //get rid of non-letters
            while(q < TER && !isLetter(line[q])) {
                cout<<line[q];
                q++;
            }
            
            
            //get a word
            cur = "";
            while(q < TER && isLetter(line[q])) {
                cur += line[q];
                q++;
            }
            
            int N = cur.size();
            for(int i=0; i < N; i++) {
                char ch = cur[i];
                isLongs[i] = true;
                if(cur[i] == 's') {
                    if(i == N-1) isLongs[i] = false;
                    else { //i < N-1
                        char next = cur[i+1];
                        if(isPunc(next)) isLongs[i] = false;
                        if(next == 'f' || next == 'b' || next == 'k') isLongs[i] = false;
                    }
                }
            }
            int i = 0;
            while(i < N) {
                
                if(i+2 < N) {
                    if(cur[i] == 's' && cur[i+1] == 's' && cur[i+2] == 's') {
                        cout<<M["s"]<<"s";
                        i += 2;
                        isLongs[i+2] = true;
                        continue;
                    }
                }
                
                //check length three
                if(i+2 < N) {
                    string key = cur.substr(i,3);
                    if(M.count(key)) {
                        if(key[0] == 's' && key[1] == 's') {
                            if(isLongs[i] && isLongs[i+1]) {
                                cout<<M[key];
                                i += 3;
                                continue;
                            }
                        } else {
                            cout<<M[key];
                            i += 3;
                            continue;
                        }
                    }
                }
                
                //check length two
                if(i+1 < N) {
                    string key = cur.substr(i,2);
                    if(M.count(key)) {
                        if(key[0] == 's' && key[1] == 's') {
                            if(isLongs[i] && isLongs[i+1]) {
                                cout<<M[key];
                                i += 2;
                                continue;
                            }
                        } else {
                            cout<<M[key];
                            i += 2;
                            continue;
                        }
                        
                    }
                }
                
                //no valid ligature
                //cout<<"i : "<<i;
                //if(isLongs[i]) cout<<" is long";
                //cout<<endl;
                if(cur[i] == 's' && isLongs[i]) cout<<M["s"];
                else cout<<cur[i];
                i += 1;
            }
            
            //get rid of non-letters
            while(q < TER && !isLetter(line[q])) {
                cout<<line[q];
                q++;
            }
        }
        cout<<endl;
    }
    
    return 0;
}