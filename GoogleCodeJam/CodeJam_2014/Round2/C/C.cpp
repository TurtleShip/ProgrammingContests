#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/*
	To future Seulgi,

	This can be solved using max-flow min-cut algorithm.
	Basically we want to find the maximum flow from the bottom of the river to its top.
	However, pushing flow will take too long for lage input because H <= 10^8 and 3 <= W <= 1000

	Instead, we can find a min cut.
	We want find a cut that goes from left of the river to the right of the river.
	To make things easier, we will create two imaginary buildings - "left building" that is
	on the left side of the river (dry land, I guess), and "right building" on the right side
	of the river.
	The min-cut would be the minimum distance from the left of the building to the right of the building.
	That is, if we "block" all the water tiles that lie on the minimum distance path, then we have our
	mininum cut.
	
	For an easy example, think about a case where there is no building. Then the minimum distance will be
	the width of the river (a straight line between "left building" and "right building").
	If we block every tile on the straight line, then we have our minimum width.

	Finding distance between each building is a bit tricky, so please take a good look at the below 
	implementation.

	From past Seulgi, Tues. Jun 3rd. 2014
*/
int main() {
	int T;
	cin>>T;
	for(int cid=1; cid<=T; cid++) {
		int W, H, B;
		cin>>W>>H>>B;

		vector<int> x0(B), y0(B), x1(B), y1(B);
		for(int i=0; i < B; i++) {
			cin>>x0[i]>>y0[i]>>x1[i]>>y1[i];
		}

		/*
			dist[i][j] = distance from building i to building j
		*/
		vector< vector<int> >dist( B+2, vector<int>(B+2,0) );
		int leftBuilding = B; // imginary building that exists left to the river
		int rightBuilding = B+1; // imaginary building that exists right to the river
		dist[leftBuilding][rightBuilding] = dist[rightBuilding][leftBuilding] = W;

		for(int i=0; i < B; i++) {
			dist[i][leftBuilding] = dist[leftBuilding][i] = x0[i];
			dist[i][rightBuilding] = dist[rightBuilding][i] = W - x1[i] - 1;
		}

		// distance between the buildings
		for(int i=0; i < B; i++) {
			for(int j=i+1; j < B; j++) {
				// i is either left to the j, or right to the j.
				int distX = max(x0[j] - x1[i], x0[i] - x1[j]) - 1;

				// i is either above j, or below j.
				int distY = max(y0[i] - y1[j], y0[j] - y1[i]) - 1;

				// find the actual distance
				dist[i][j] = dist[j][i] = max(distX, distY);
			}
		}

		// Find the minimum distance from left building to the right building
		vector<bool> isVisited(B+2, false);
		// minDist[i] = the minimum distance from left Building to building i
		vector<int> minDist(B+2, -1);

		// dijkstra
		priority_queue< pair<int, int> > heap;
		heap.emplace(0, leftBuilding);
		minDist[leftBuilding] = 0;
		
		while(!heap.empty()) {
			int curBuilding = heap.top().second; heap.pop();

			// check other buildings
			for(int i=0; i <= rightBuilding; i++) {
				if(minDist[i] == -1 || (minDist[curBuilding] + dist[curBuilding][i]) < minDist[i]) {
					minDist[i] = minDist[curBuilding] + dist[curBuilding][i];
					// priority_queue is max-heap by default, but want min_heap
					// so let's do -minDist[i] instead of minDist[i]
					heap.emplace(-minDist[i], i); 
				}
			}
		}
		
		printf("Case #%d: %d\n", cid, minDist[rightBuilding]);
	}
	return 0;
}