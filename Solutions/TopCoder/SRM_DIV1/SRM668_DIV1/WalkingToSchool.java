import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;


public class WalkingToSchool {
    static String YES = "Freedom";
    static String NO = "Chores";
    static int UNVISITED = -1;

    boolean[] isVisited;
    int[] steps;
    int[] minSteps;
    int[] depths;
    int totalSteps;
    List<List<Integer>> allSCC;
    List<List<Integer>> adj;
    Stack<Integer> path;

    public String canWalkExactly(int N, int[] from, int[] to) {
        /*
            Liz house = vertex 0
            school = vertex 1

            Want to home -> school -> home

            Algorithm.

            1. Find SCC.
            2. Check if any SCC contains 0 and 1. If not, return NO.
            3. Calculate all simple cycles in the SCC that contains 0 and 1.
            4. Check if gcd of the length of all simple cycles is 1. If it is 1, return YES.
               Return NO otherwise.
         */
        isVisited = new boolean[N];
        steps = new int[N];
        minSteps = new int[N];
        path = new Stack<>();
        adj = new ArrayList<>(N);
        allSCC = new ArrayList<>();
        for (int i = 0; i < N; i++)
            adj.add(new ArrayList<>());

        // populate adj based on from, to
        for (int i = 0; i < from.length; i++) {
            adj.get(from[i]).add(to[i]);
        }

        totalSteps = 0;
        Arrays.fill(isVisited, false);
        Arrays.fill(steps, UNVISITED);
        Arrays.fill(minSteps, UNVISITED);
        tarjanSCC(0);

        // check if 0 and 1 are in the same scc
        System.out.println("CHECKING");
        boolean found = false;
        for (List<Integer> scc : allSCC) {
            if (scc.contains(0) && scc.contains(1)) {
                found = true;
                break;
            }
        }
        if (!found) return NO;
//        if(minSteps[0] != minSteps[1]) return NO;
        System.out.println("0 and 1 in the same scc");
        /*
         Check if gcd of the length of all simple cycles is 1
         by checking if it is an aperiodic graph
         https://en.wikipedia.org/wiki/Aperiodic_graph
        */
        depths = new int[N];
        Arrays.fill(depths, UNVISITED);
        depths[0] = 0;
        findDepths(0);

        int res = -1;
        for (int i = 0; i < from.length; i++) {
            int s = from[i];
            int t = to[i];
            if (depths[s] == UNVISITED || depths[t] == UNVISITED) continue;
            int len = depths[t] - depths[s] - 1;
            if (len == 0) continue;
            if (len < 0) len *= -1;
            if (res == -1) res = len;
            else res = gcd(res, len);
        }

        return res == 1 ? YES : NO;
    }

    private void findDepths(int cur) {
        for (int next : adj.get(cur)) {
            if (minSteps[next] != minSteps[0]) continue;
            if (depths[next] != UNVISITED) continue;
            depths[next] = depths[cur] + 1;
            findDepths(next);
        }
    }

    private void tarjanSCC(int curNode) {
        minSteps[curNode] = steps[curNode] = totalSteps++;
        path.push(curNode);
        isVisited[curNode] = true;
        for (int neighbor : adj.get(curNode)) {
            if (steps[neighbor] == UNVISITED)
                tarjanSCC(neighbor);
            if (isVisited[neighbor])
                minSteps[curNode] = Math.min(minSteps[curNode], minSteps[neighbor]);
        }

        if (minSteps[curNode] == steps[curNode]) {
            int tmp;
            List<Integer> curScc = new ArrayList<>();
            do {
                tmp = path.pop();
                curScc.add(tmp);
                isVisited[tmp] = false;
            } while (curNode != tmp);
            allSCC.add(curScc);
        }
    }

    private int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

}