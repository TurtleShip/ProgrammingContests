import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int T = scanner.nextInt();

        for (int cid = 1; cid <= T; cid++) {
            final int S = scanner.nextInt();
            final int N = scanner.nextInt();
            final Graph graph = new Graph(N, S);
            for (int i = 0; i < N; i++) {
                graph.addLoc(i, scanner.nextInt(), scanner.nextInt());
            }

            writer.println(graph.solve());
        }
        writer.flush();
    }
}

/*
    Approach
    1. Greedily pick 'S' number of expensive edges without creating a cycle.
    2. Greedily pick 'P-1-S' number of cheap edges without creating a cycle.
 */

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
    int S;
    double[] locX;
    double[] locY;
    LinkedList<Edge> edgeList;

    public Graph(int N, int S) {
        this.N = N;
        this.S = S;
        this.locX = new double[N];
        this.locY = new double[N];
        this.edgeList = new LinkedList<>();
    }

    public void addLoc(int idx, int x, int y) {
        locX[idx] = x;
        locY[idx] = y;
    }

    public String solve() {
        // first, populate edgeList
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++) {
                double xDiff = locX[i] - locX[j];
                double yDiff = locY[i] - locY[j];
                double dist = Math.sqrt(xDiff * xDiff + yDiff * yDiff);
                edgeList.add(new Edge(i, j, dist));
            }

        // Sort in descending order
        Collections.sort(edgeList, new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                return Double.compare(o1.weight, o2.weight);
            }
        });

        final UnionFind union = new UnionFind(N);
        int picked = 0;
        int more = N - S;

        double res = 0.0;

        // Sort in ascending order
        for (final Edge edge : edgeList) {
            if (union.isSameSet(edge.from, edge.to)) continue;
            union.unionSet(edge.from, edge.to);
            picked++;
            res = Math.max(res, edge.weight);
            if (picked == more) break;
        }

        return String.format("%.2f", res);
    }
}


// https://github.com/TurtleShip/ProgrammingContests/blob/master/Library/DataStructures/UnionFind.java
class UnionFind {
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