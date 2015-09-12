import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/*
    This is a shameless copy from one of UVa discussion boards
    https://uva.onlinejudge.org/board/viewtopic.php?f=52&t=45232&hilit=11733

    My solution got TLE because of this problem has lots of input and Java
    is not as efficient as C/C++ when it comes to I/O operations.

    I saved my TLE solution under TLE class on a separate file.
 */
public class Main {
    static class Edge implements Comparable<Edge> {
        int firstNode, secondNode;
        int weight;

        public Edge(int firstNode1, int secondNode1, int d) {
            firstNode = firstNode1;
            secondNode = secondNode1;
            weight = d;
        }

        @Override
        public int compareTo(Edge edgeObject) {
            if (edgeObject.weight < weight) {
                return 1;
            } else if (edgeObject.weight == weight) {
                return 0;
            } else {
                return -1;
            }

        }
    }

    static int[] parentList;
    static ArrayList<Edge> edgeList;

    static int findParent(int i) {
        if (i == parentList[i])
            return i;
        return parentList[i] = findParent(parentList[i]);
    }

    static void connect(int i, int j) {
        parentList[findParent(i)] = parentList[findParent(j)];
    }

    static boolean isConnected(int i, int j) {
        if (findParent(i) == findParent(j))
            return true;
        return false;
    }

    public static void main(String[] args) throws NumberFormatException,
        IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));
        int n, m, airportCost;
        int first, second, len;
        int sum, cnt;
        int tc = Integer.parseInt(bf.readLine());
        for (int t = 1; t <= tc; t++) {
            StringTokenizer st = new StringTokenizer(bf.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            airportCost = Integer.parseInt(st.nextToken());
            parentList = new int[n];
            for (int i = 0; i < n; i++)
                parentList[i] = i;
            edgeList = new ArrayList<>();
            int xx = m;
            for (int i = 0; i < xx; i++) {
                StringTokenizer st1 = new StringTokenizer(bf.readLine());
                first = Integer.parseInt(st1.nextToken());
                second = Integer.parseInt(st1.nextToken());
                len = Integer.parseInt(st1.nextToken());
                if (len < airportCost) {
                    edgeList.add(new Edge(first - 1, second - 1, len));
                } else {
                    m--;
                }

            }
            Collections.sort(edgeList);
            cnt = n;
            sum = 0;
            for (int i = 0; i < m && cnt > 1; i++) {
                first = edgeList.get(i).firstNode;
                second = edgeList.get(i).secondNode;
                len = edgeList.get(i).weight;
                if (!isConnected(first, second)) {
                    cnt--;
                    sum += len;
                    connect(first, second);
                }
            }
            sum += cnt * airportCost;
            writer.printf("Case #" + t + ": " + sum + " " + cnt + "\n");

        }
        writer.flush();
    }

}