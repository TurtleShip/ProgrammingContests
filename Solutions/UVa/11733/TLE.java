//import java.io.*;
//import java.util.Arrays;
//import java.util.Comparator;
//import java.util.StringTokenizer;
//
//public class Main {
//
//    /*
//Build a MST.
//1 airport -> cost of 1 airport + the entire MST cost.
//
//Sort the MST decreasing order. (Most expensive first).
//For each edge in MST, build an airport to cities connected by
//the edge if they don't already have MST.
//Calculate the new cost and see if it is cheaper than or equal to
//the previous cost. If so, update the number of airports
//we can use. If not, stop immediately.
//*/
//    public static void main(String[] args) throws IOException {
////        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
////        $R scanner = new $R(System.in);
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//
//        StringTokenizer token;
//        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));
//        final Edge[] edgeList = new Edge[100_010];
//
////        final int T = scanner.nextInt();
//        final int T = Integer.parseInt(br.readLine());
//        int M, N, A;
//        String temp[];
//        for (int cid = 1; cid <= T; cid++) {
////            temp = br.readLine().split(" ");
//            token = new StringTokenizer(br.readLine());
////            final int N = scanner.nextInt();
////            final int M = scanner.nextInt();
////            final int A = scanner.nextInt();
////            final int N = Integer.parseInt(temp[0]);
////            final int M = Integer.parseInt(temp[1]);
////            final int A = Integer.parseInt(temp[2]);
//            N = Integer.parseInt(token.nextToken());
//            M = Integer.parseInt(token.nextToken());
//            A = Integer.parseInt(token.nextToken());
//
//
//            for (int i = 0; i < M; i++) {
////                temp = br.readLine().split(" ");
//                token = new StringTokenizer(br.readLine());
//                edgeList[i] = new Edge(Integer.parseInt(token.nextToken()) - 1, Integer.parseInt(token.nextToken()) - 1, Integer.parseInt(token.nextToken()));
//            }
//
//            Arrays.sort(edgeList, 0, M, new Comparator<Edge>() {
//                @Override
//                public int compare(Edge o1, Edge o2) {
//                    return Integer.compare(o1.weight, o2.weight);
//                }
//            });
//            final UnionFind uf = new UnionFind(N);
//            int mstCost = 0;
//
//            int len = 0;
//            int[] costs = new int[N - 1];
//            for (int i = 0; i < M; i++) {
//                final Edge edge = edgeList[i];
//                if (uf.isSameSet(edge.from, edge.to)) continue;
//
//                costs[len++] = edge.weight;
//                mstCost += edge.weight;
//                uf.unionSet(edge.from, edge.to);
//                if (uf.numDisjointSets() == 1) break;
//            }
//
//            int best = mstCost + A * uf.numDisjointSets();
//
//            Arrays.sort(costs);
//
//            int numAirports = uf.numDisjointSets();
//            for (int i = 0; i < len; i++) {
//
//                // no need to keep going because it is getting more
//                // expensive to add an airport
//                if (costs[i] < A) break;
//                best = best - costs[i] + A;
//                numAirports++;
//            }
//
//            writer.printf("Case #%d: %d %d\n", cid, best, numAirports);
////            System.out.printf("Case #%d: %d %d\n", cid, best, numAirports);
//        }
//        writer.flush();
//    }
//}
//
//class Edge {
//    int from, to, weight;
//
//    public Edge(int from, int to, int weight) {
//        this.from = from;
//        this.to = to;
//        this.weight = weight;
//    }
//}
//
//
//// https://github.com/TurtleShip/ProgrammingContests/blob/master/Library/DataStructures/UnionFind.java
//class UnionFind {
//    private int[] p, rank, setSize;
//    private int numSets;
//
//    public UnionFind(int N) {
//        p = new int[N];
//        rank = new int[N];
//        setSize = new int[N];
//        numSets = N;
//        for (int i = 0; i < N; i++) {
//            p[i] = i;
//            rank[i] = 0;
//            setSize[i] = 1;
//        }
//    }
//
//    public int findSet(int i) {
//        if (p[i] == i) return i;
//        return p[i] = findSet(p[i]);
//    }
//
//    public Boolean isSameSet(int i, int j) {
//        return findSet(i) == findSet(j);
//    }
//
//    public void unionSet(int i, int j) {
//        if (!isSameSet(i, j)) {
//            numSets--;
//            int x = findSet(i), y = findSet(j);
//            // rank is used to keep the tree short
//            if (rank[x] > rank[y]) {
//                p[y] = x;
//                setSize[x] += setSize[y];
//            } else {
//                p[x] = y;
//                setSize[y] += setSize[x];
//                if (rank[x] == rank[y]) rank[y]++;
//            }
//        }
//    }
//
//    public int numDisjointSets() {
//        return numSets;
//    }
//}
//
//class $R {
//    InputStream in;
//    byte b;
//    byte[] buf;
//    int bi, bz;
//
//    $R(InputStream I) {
//        in = I;
//        buf = new byte[65536];
//        bi = bz = 0;
//        read();
//    }
//
//    boolean hasNext() {
//        skip();
//        return b >= 0;
//    }
//
//    void skip() {
//        while (b >= 0 && b <= 32) read();
//    }
//
//    String next() {
//        StringBuilder sb = new StringBuilder();
//        for (skip(); b > 32; read()) sb.append((char) b);
//        return sb.length() == 0 ? null : sb.toString();
//    }
//
//    String nextLine() {
//        StringBuilder sb = new StringBuilder();
//        for (; b != 10 && b != 13; read()) sb.append((char) b);
//        while (b == 10 || b == 13) read();
//        return sb.toString();
//    }
//
//    int nextInt() {
//        int ival = 0;
//        boolean isgn = false;
//        skip();
//        if (b == '-') {
//            isgn = true;
//            read();
//        }
//        for (; b > 32; read()) ival = ival * 10 + b - 48;
//        return isgn ? -ival : ival;
//    }
//
//    void read() {
//        if (bi == bz) {
//            bi = 0;
//            try {
//                bz = in.read(buf);
//            } catch (Exception e) {
//                bz = -1;
//            }
//        }
//        b = bz == -1 ? -1 : buf[bi++];
//    }
//}
////