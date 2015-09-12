import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int C, S, Q, cid = 1;

        while ((C = scanner.nextInt()) != 0 && (S = scanner.nextInt()) != 0 && (Q = scanner.nextInt()) != 0) {
            if (cid > 1) writer.println();
            writer.printf("Case #%d\n", cid++);
            final Graph graph = new Graph(C);

            for (int i = 0; i < S; i++) {
                graph.addEdge(new Edge(scanner.nextInt() - 1, scanner.nextInt() - 1, scanner.nextInt()));
            }

            graph.buildMST();

            for (int i = 0; i < Q; i++) {
                final String res = graph.query(scanner.nextInt() - 1, scanner.nextInt() - 1);
                writer.println(res);
            }
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
}

class NextEdge {
    int dst, weight;

    public NextEdge(int dst, int weight) {
        this.dst = dst;
        this.weight = weight;
    }
}

class Graph {
    int N;
    boolean[] isVisited;
    PriorityQueue<Edge> edgeList;
    LinkedList<NextEdge>[] neighbors;


    public Graph(int N) {
        this.N = N;
        this.edgeList = new PriorityQueue<>(N, new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                return Integer.compare(o1.weight, o2.weight);
            }
        });
        this.isVisited = new boolean[N];
        this.neighbors = new LinkedList[N];
    }

    public void addEdge(Edge edge) {
        edgeList.add(edge);
    }

    public void buildMST() {
        for (int i = 0; i < N; i++)
            neighbors[i] = new LinkedList<>();

        UnionFind uf = new UnionFind(N);

        while (!edgeList.isEmpty()) {
            Edge edge = edgeList.poll();
            if (uf.isSameSet(edge.from, edge.to)) continue;
            uf.unionSet(edge.from, edge.to);
//            System.out.printf("%d - %d with cost %d\n", edge.from, edge.to, edge.weight);
            neighbors[edge.from].add(new NextEdge(edge.to, edge.weight));
            neighbors[edge.to].add(new NextEdge(edge.from, edge.weight));
        }
    }

    public String query(int from, int to) {
        Arrays.fill(isVisited, false);
        isVisited[from] = true;
        int noise = find(from, to, -1);
        if (noise == -1) return "no path";
        return Integer.toString(noise);
    }

    private int find(int cur, int dst, int noise) {
        if (cur == dst) return noise;
        int maxNoise = -1;
        for (NextEdge next : neighbors[cur]) {
            if (isVisited[next.dst]) continue;
            isVisited[next.dst] = true;
            maxNoise = Math.max(maxNoise, find(next.dst, dst, Math.max(noise, next.weight)));
        }
        return maxNoise;
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