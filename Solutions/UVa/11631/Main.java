import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int M, N;
        while ((M = scanner.nextInt()) != 0 & (N = scanner.nextInt()) != 0) {
            final Graph graph = new Graph(M);
            for (int i = 0; i < N; i++) {
                graph.addEdge(new Edge(scanner.nextInt(), scanner.nextInt(), scanner.nextInt()));
            }
            writer.println(graph.solve());
        }
        writer.flush();
    }
}
/*
    Kruskal Algorithm.
        - Sort all edges in non-descending order.
        - For each edge, add it to MST if it doesn't create a cycle.
 */

class Edge {
    int from, to, weight;

    public Edge(int from, int to, int weight) {
        this.from = from;
        this.to = to;
        this.weight = weight;
    }
}

class Graph {
    int N;
    int totalCost;
    PriorityQueue<Edge> edgeList;


    public Graph(int N) {
        this.N = N;
        this.totalCost = 0;
        this.edgeList = new PriorityQueue<>(N, new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                return Integer.compare(o1.weight, o2.weight);
            }
        });
    }

    public void addEdge(Edge edge) {
        edgeList.add(edge);
        totalCost += edge.weight;
    }

    public int solve() {
        UnionFind uf = new UnionFind(N);
        int minCost = 0;
        int total = 0;
        while (total < N) {
            Edge edge = edgeList.poll();
            if (uf.isSameSet(edge.from, edge.to)) continue;
            uf.unionSet(edge.from, edge.to);
            total = uf.sizeOfSet(edge.from);
            minCost += edge.weight;
        }
        return totalCost - minCost;
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

