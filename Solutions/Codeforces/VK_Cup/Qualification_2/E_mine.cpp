#include <cstring>
#include <iostream>
#include <algorithm>

#define maxN 100010
using namespace std;

//Represents a cube
struct Cube
{
    int color,height,idx;
};

//Cubes with same color
struct CubeSet
{
    int len;
    int pos;
};

Cube cubes[maxN];
CubeSet cs[maxN];
long long maxHeight[maxN]; //maxHeight[i] = The maximum height of a CubeSet using i cubes
int maxIdx[maxN]; //maxIdx[i] = The index of CubeSet that can produce maxHeight[i]
bool cubeSort(Cube , Cube);
bool colorSort(CubeSet, CubeSet);

int main()
{
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;
    
    for(int i=0; i < N; i++)
    {
        cin>>cubes[i].color;
        cin>>cubes[i].height;
        cubes[i].idx = (i+1);
    }

    sort(cubes, cubes + N, cubeSort);

    int colorLen = 0; //number of different cube colors
	int j = 0;
    int minH = maxN;

    for(int i=0; i < N; i=j)
    {
        //Save the position of the first cube of the current color
        cs[colorLen].pos = i;     

        for(j=i; j < N && cubes[j].color == cubes[i].color; j++)
			cs[colorLen].len++;

        minH = min(minH, cs[colorLen].len);
        colorLen++;
    }

    sort(cs, cs + colorLen, colorSort);

    memset(maxHeight, 0, sizeof(maxHeight));
    memset(maxIdx, 0, sizeof(maxIdx));
    
    long long ans = 0;
    int bestA_idx, bestA_len, bestB_idx, bestB_len;
    for(int i=0; i < colorLen; i++)
    {
        long long curH = 0; //total height of current color cubeses
        
        for(int j=0; j < minH-1; j++)
            curH += cubes[cs[i].pos + j].height;
        
        for(int j = minH-1; j < cs[i].len; j++)
        {
            curH += cubes[cs[i].pos + j].height; //add the current cube
            
            //Try two possible heights
            for(int k=j; k <= j+1; k++)
            {
                if(maxHeight[k] != 0 && (curH + maxHeight[k]) > ans)
                {
                    ans = curH + maxHeight[k];
                    bestA_idx = i, bestB_idx = maxIdx[k];
                    bestA_len = j+1, bestB_len = k;
                }
            }
        }
        
        /*
         We are done for this color group.
         This may be included in an optimal answer,
         so update maxHeight and maxIdx
         */
        if(curH > maxHeight[cs[i].len])
        {
            maxHeight[cs[i].len] = curH;
            maxIdx[cs[i].len] = i;
        }
    }
    
    cout<<ans<<endl;
    cout<<(bestA_len + bestB_len)<<endl;
    
    for(int i=0; i < bestA_len; i++)
    {
        cout<<cubes[cs[bestA_idx].pos + i].idx;
        if(i < bestB_len)
            cout<<" "<<cubes[cs[bestB_idx].pos + i].idx<<" ";
    }
    cout<<endl;
}

bool cubeSort(Cube a, Cube b)
{
    //sort by color
    if(a.color != b.color) return a.color < b.color;
    
    //If color is the same, sort by height in non-increasing order
    return a.height > b.height;
}

//Sort cubeSet by its length.
bool colorSort(CubeSet a, CubeSet b)
{
    return a.len < b.len;
}