#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;

int nShoe, nHuman;

map <int, int> Sindex;
map <int, int> Sprice;

struct human
{
    int want;
    int money;
    int index;
    bool operator <(human u)const
    {
        return want < u.want;
    }
}H[100001];

long long dp[100001][2][2];
int next_dp_1[100001][2][2];
int next_dp_2[100001][2][2];
int next_dp_3[100001][2][2];
int buying[100001][2][2];

long long dodp(int cur, int havecur, int havelarge)
{
    if(cur > nHuman)return 0;
    if(dp[cur][havecur][havelarge] >= 0)
        return dp[cur][havecur][havelarge];
    long long ret = -100;
    int n1 = 0, n2 = 0, n3 = 0, buy = 0;
    
    // try buy nothing:
    if(dodp(cur+1, ((havecur && H[cur-1].want == H[cur].want) || (havelarge && H[cur-1].want + 1 == H[cur].want)) , (havelarge && H[cur-1].want == H[cur].want)) > ret)
    {
        
        
        buy = 0;
        n1 = cur + 1;
        n2 = ((havecur && H[cur-1].want == H[cur].want) || (havelarge && H[cur-1].want + 1 == H[cur].want));
        n3 = (havelarge && H[cur-1].want == H[cur].want);
        ret = dodp(cur+1, n2, n3);
    }
    
    // try buy cur
    if(!((havecur == true && H[cur-1].want == H[cur].want) ||(havelarge == true && H[cur-1].want + 1 == H[cur].want)))
        if(Sprice[H[cur].want] > 0)
            if(H[cur].money >= Sprice[H[cur].want])
                if(dodp(cur+1, 1, (H[cur-1].want == H[cur].want && havelarge))
                   + Sprice[H[cur].want] > ret)
                {
                    ret = dodp(cur+1, 1, (H[cur-1].want == H[cur].want && havelarge))
                    + Sprice[H[cur].want];
                    buy = H[cur].want;
                    n1 = cur + 1;
                    n2 = 1;
                    n3 = (H[cur-1].want == H[cur].want && havelarge);
                }
    
    // try buy cur+1
    if(!(havelarge == true && H[cur-1].want == H[cur].want))
        if(Sprice[H[cur].want+1] > 0)
            if(H[cur].money >= Sprice[H[cur].want+1])
                if(dodp(cur+1, ((havecur && H[cur-1].want == H[cur].want) || (havelarge == true && H[cur-1].want + 1 == H[cur].want)), 1) + Sprice[H[cur].want+1] > ret)
                {
                    ret = dodp(cur+1, ((havecur && H[cur-1].want == H[cur].want) || (havelarge == true && H[cur-1].want + 1 == H[cur].want)), 1) + Sprice[H[cur].want+1];
                    buy = H[cur].want + 1;
                    n1 = cur + 1;
                    n2 = ((havecur && H[cur-1].want == H[cur].want) || (havelarge == true && H[cur-1].want + 1 == H[cur].want));
                    n3 = 1;
                }
    
    dp[cur][havecur][havelarge] = ret;
    next_dp_1[cur][havecur][havelarge] = n1;
    next_dp_2[cur][havecur][havelarge] = n2;
    next_dp_3[cur][havecur][havelarge] = n3;
    buying[cur][havecur][havelarge] = buy;
    return ret;
}

int main()
{
    ios :: sync_with_stdio(false);
    cin >> nShoe;
    for(int i = 1; i <= nShoe; i++)
    {
        int a, b;
        cin >> a >> b;
        Sindex[b] = i;
        Sprice[b] = a;
    }
    cin >> nHuman;
    for(int i = 1; i <= nHuman; i++)
    {
        cin >> H[i].money >> H[i].want;
        H[i].index = i;
    }
    sort(H + 1, H + 1 + nHuman);
    H[0].want = -10000;
    memset(dp, 0xff, sizeof(dp));
    cout << dodp(1, 0, 0) << endl;
    vector <int> indexS, indexH;
    int p1 = 1, p2 = 0, p3 = 0;
    while(p1 <= nHuman)
    {
        
        if(buying[p1][p2][p3] > 0)
        {
            indexH.push_back(H[p1].index);
            indexS.push_back(Sindex[buying[p1][p2][p3]]);
        }
        int np1 = next_dp_1[p1][p2][p3];
        int np2 = next_dp_2[p1][p2][p3];
        int np3 = next_dp_3[p1][p2][p3];
        p1 = np1;
        p2 = np2;
        p3 = np3;
    }
    cout << indexH.size() << endl;
    for(int i = 0; i < indexH.size(); i++)
        cout << indexH[i] << " " << indexS[i] << endl;
    return 0;
}