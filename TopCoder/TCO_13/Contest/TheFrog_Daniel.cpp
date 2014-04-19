#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
class TheFrog {
        public:
        vector<int> L,R;
        int N;
        bool feasible(int a, int b) {
                for (int i = 0; i < N; ++i) {
                        int l = (L[i]*b)/a;
                        int u = (R[i]*b + a - 1)/a;
                        if (u - l > 1) return false;
                }
                return true;
        }
        double getMinimum(int D, vector <int> _L, vector <int> _R) {
                L = _L; R = _R;
                N = L.size();
                double ans = D;
                for (int i = 0; i < N; ++i)
                for (int j = 1; j <= R[i]; ++j)
                        if ((double)(R[i])/j < ans && feasible(R[i], j)) ans = (double)R[i]/j;
                return ans;
        }
};