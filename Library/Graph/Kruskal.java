import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/*
    Kruskal Algorithm find a minimum spanning tree (MST) through greedy approach as below.
        - Sort all edges in non-descending order.
        - For each edge, add it to MST if it doesn't create a cycle.
 */
public class Kruskal {
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
    int M; // the number of edges
    List<Edge> edgeList;


    public Graph(int N, int M) {
        this.N = N;
        this.M = M;
        this.edgeList = new ArrayList<>(M);
    }

    public void addEdge(Edge edge) {
        edgeList.add(edge);
    }

    public List<Edge> findMST() {
        Collections.sort(edgeList, new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                return Double.compare(o1.weight, o2.weight);
            }
        });
        UnionFind uf = new UnionFind(N);

        ArrayList<Edge> res = new ArrayList<>(N - 1);
        for (final Edge edge : edgeList) {
            if (uf.isSameSet(edge.from, edge.to)) continue;
            res.add(edge);
            uf.unionSet(edge.from, edge.to);
            if (uf.numDisjointSets() == 1) break;
        }

        if (uf.numDisjointSets() == 1) return res;
        // we failed to find MST. It is possible that the graph is disconnected
        throw new RuntimeException("Couldn't find MST");
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
