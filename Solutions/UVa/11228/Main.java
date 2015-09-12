import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        final int T = scanner.nextInt();

        for (int cid = 1; cid <= T; cid++) {
            final int N = scanner.nextInt();
            final int R = scanner.nextInt();

            final Graph graph = new Graph(N, R);
            for (int i = 0; i < N; i++) {
                graph.addLocation(i, scanner.nextInt(), scanner.nextInt());
            }
            writer.printf("Case #%d: %s\n", cid, graph.solve());
        }
        writer.flush();
    }
}

class Edge {
    int from, to;
    double weight;

    public Edge(int from, int to, double weight) {
        this.from = from;
        this.to = to;
        this.weight = weight;
    }
}

class Graph {
    int N;
    int R;
    int[] locX;
    int[] locY;
    PriorityQueue<Edge> edgeList;


    public Graph(int N, int R) {
        this.N = N;
        this.R = R;
        this.locX = new int[N];
        this.locY = new int[N];
        this.edgeList = new PriorityQueue<>(N, new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                return Double.compare(o1.weight, o2.weight);
            }
        });
    }

    public void addLocation(int idx, int x, int y) {
        locX[idx] = x;
        locY[idx] = y;
    }

    public String solve() {
        populateEdgeList();

        // create MST
        List<Edge> mst = createMST();

        // identify states, rails, and roads
        UnionFind uf = new UnionFind(N);
        double rails = 0;
        double roads = 0;
        for (Edge edge : mst) {
            if (edge.weight <= R) {
                roads += edge.weight;
                uf.unionSet(edge.from, edge.to);
            } else {
                rails += edge.weight;
            }
        }

        return uf.numDisjointSets() + " " + (int) Math.round(roads) + " " + (int) Math.round(rails);
    }

    private void populateEdgeList() {
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                double diffX = (double) (locX[i] - locX[j]);
                double diffY = (double) (locY[i] - locY[j]);
                double dist = Math.sqrt(diffX * diffX + diffY * diffY);
                edgeList.add(new Edge(i, j, dist));
            }
        }
    }

    private List<Edge> createMST() {
        UnionFind uf = new UnionFind(N);
        int total = 0;
        ArrayList<Edge> res = new ArrayList<>(N - 1);
        while (total < N) {
            Edge edge = edgeList.poll();
            if (uf.isSameSet(edge.from, edge.to)) continue;
            res.add(edge);
            uf.unionSet(edge.from, edge.to);
            total = uf.sizeOfSet(edge.from);
        }
        return res;
    }

}


// https://github.com/TurtleShip/ProgrammingContests/blob/master/Library/DataStructures/UnionFind.java
class UnionFind {
    //    private List<Integer> p, rank, setSize;
    private int[] p, rank, setSize;
    private int numSets;

    public UnionFind(int N) {
        p = new int[N];
        rank = new int[N];
        setSize = new int[N];
        numSets = N;
        for (int i = 0; i < N; i++) {
            p[i] = i;
            rank[i] = 0;
            setSize[i] = 1;
        }
    }

    public int findSet(int i) {
        if (p[i] == i) return i;
        return p[i] = findSet(p[i]);
    }

    public Boolean isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    public void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            numSets--;
            int x = findSet(i), y = findSet(j);
            // rank is used to keep the tree short
            if (rank[x] > rank[y]) {
                p[y] = x;
                setSize[x] += setSize[y];
            } else {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }

    public int numDisjointSets() {
        return numSets;
    }

    public int sizeOfSet(int i) {
        return setSize[findSet(i)];
    }
}