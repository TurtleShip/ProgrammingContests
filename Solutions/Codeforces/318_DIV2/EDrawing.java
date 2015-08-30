//import java.io.BufferedInputStream;
//import java.util.*;
//
//public class EDrawing {
//
//    public static void main(String[] args) {
//        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
//
//        int N = scanner.nextInt();
//        final Graph graph = new Graph(N);
//
//        for (int i = 0; i < N - 1; i++) {
//            graph.addEdge(scanner.nextInt() - 1, scanner.nextInt() - 1);
//        }
//        boolean isGood = graph.solve();
//        System.out.println(isGood ? "Yes" : "No");
//    }
//}
//
//class Graph {
//    static int CLEAN = 0;
//    static int COMPRESSED = 1; // deleted node due to compression
//    static int YVERTICE = 2; // a node with 1 or 2 COMPRESSED nodes and 1 edge to a CLEAN node
//
//    int N;
//    List<List<Integer>> neighbors;
//    int[] status;
//
//    public Graph(int n) {
//        N = n;
//        neighbors = new ArrayList<>(N);
//        for (int i = 0; i < N; i++)
//            neighbors.add(i, new LinkedList<>());
//        status = new int[N];
//    }
//
//    public void addEdge(int x, int y) {
//        neighbors.get(x).add(y);
//        neighbors.get(y).add(x);
//    }
//
//    public boolean solve() {
//        Arrays.fill(status, CLEAN);
//
//        // compress long nodes first
//        for (int i = 0; i < N; i++) {
//            if (status[i] == CLEAN && neighbors.get(i).size() == 1) {
//                compress(i);
//            }
//        }
//
//        // mark Y-VERTICES
//        for (int i = 0; i < N; i++) {
//            if (status[i] == CLEAN && (neighbors.get(i).size() == 2 || neighbors.get(i).size() == 3)) {
//                int clean = 0;
//                boolean hasYAsNeighbor = false;
//                for (int next : neighbors.get(i)) {
//                    if (status[next] == CLEAN) {
//                        clean++;
//                    } else if (status[next] == YVERTICE) {
//                        hasYAsNeighbor = true;
//                        break;
//                    }
//                }
//                if (clean == 1 && !hasYAsNeighbor) status[i] = YVERTICE;
//            }
//        }
//
//        for (int i = 0; i < N; i++) {
//            if (status[i] == CLEAN) {
//                int clean = 0;
//                for (int next : neighbors.get(i)) {
//                    if (status[next] == CLEAN)
//                        clean++;
//                }
//
//                if (clean > 2) return false;
//            }
//        }
//
//        return true;
//    }
//
//    public void compress(int cur) {
//        status[cur] = COMPRESSED;
//        for (int next : neighbors.get(cur)) {
//            if (status[next] == CLEAN && neighbors.get(next).size() == 2)
//                compress(next);
//        }
//    }
//}