import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int T = scanner.nextInt();

        for (int cid = 1; cid <= T; cid++) {
            int N = scanner.nextInt();
            int M = scanner.nextInt();
            final Graph graph = new Graph(N, M);
            for (int i = 0; i < M; i++)
                graph.addEdge(new Edge(scanner.nextInt() - 1, scanner.nextInt() - 1, scanner.nextInt()));
            writer.println(graph.solve());
        }
        writer.flush();
    }
}

class Edge {
    int from, to, weight;

    public Edge(int from, int to, int weight) {
        this.from = from;
        this.to = to;
        this.weight = weight;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Edge)) return false;

        Edge edge = (Edge) o;

        if (from != edge.from) return false;
        if (to != edge.to) return false;
        if (weight != edge.weight) return false;

        return true;
    }

    @Override
    public int hashCode() {
        int result = from;
        result = 31 * result + to;
        result = 31 * result + weight;
        return result;
    }
}

class Graph {
    int N;
    int M;
    ArrayList<Edge> edgeList;


    public Graph(int N, int M) {
        this.N = N;
        this.M = M;
        edgeList = new ArrayList<>(M);
    }

    public void addEdge(Edge edge) {
        edgeList.add(edge);
    }

    public String solve() {
        int firstMST = 0;
        int secondMST = 1_000_000_000;
        Collections.sort(edgeList, new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                return Integer.compare(o1.weight, o2.weight);
            }
        });

        UnionFind uf = new UnionFind(N);

        ArrayList<Edge> MST = new ArrayList<>(N - 1);
        Set<Edge> MSTCheck = new HashSet<>(M);
        for (final Edge edge : edgeList) {
            if (uf.isSameSet(edge.from, edge.to)) continue;
            MST.add(edge);
            MSTCheck.add(edge);
            uf.unionSet(edge.from, edge.to);
            firstMST += edge.weight;
            if (uf.numDisjointSets() == 1) break;
        }

        for (final Edge excluded : MST) {
            uf = new UnionFind(N);
            int curMST = 0;
            for (final Edge edge : MST) {
                if (edge.equals(excluded)) continue;
                uf.unionSet(edge.from, edge.to);
                curMST += edge.weight;
            }

            for (final Edge edge : edgeList) {
                if (uf.isSameSet(edge.from, edge.to)) continue;
                if (MSTCheck.contains(edge)) continue;
                uf.unionSet(edge.from, edge.to);
                curMST += edge.weight;
                if (uf.numDisjointSets() == 1) break;
            }
            if (uf.numDisjointSets() == 1)
                secondMST = Math.min(secondMST, curMST);
        }

        return String.format("%d %d", firstMST, secondMST);
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