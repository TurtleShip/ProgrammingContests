import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    /*
        There are at most 2000 nodes.

        The cost of edge from word X to Y is the number of letters in word Y.
        There is an edge from X to Y iff the below condition meets
        1) X and Y are in the same language set.
        2) X and Y do NOT start with the same letter.

     */
    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));


        Map<String, Integer> wordId = new HashMap<>();
        Map<String, Integer> languageId = new HashMap<>();

        int totalWord, totalLanguage, N, INF = 100_000_000;
        int[][] wordByLanguage = new int[5010][5010];
        int[] len = new int[5010];
        int[] wordLen = new int[2010];
        int[] dist = new int[2010];
        char[] firstLetter = new char[2010];
        int[][] adj = new int[2010][2010];
        int[] adjLen = new int[2010];


        String startLanguage, endLanguage, lan1Raw, lan2Raw, word;

        while ((N = scanner.nextInt()) != 0) {
            totalWord = totalLanguage = 0;

            wordId.clear();
            languageId.clear();

            startLanguage = scanner.next();
            endLanguage = scanner.next();
            languageId.put(startLanguage, totalLanguage++);

            if (!languageId.containsKey(endLanguage))
                languageId.put(endLanguage, totalLanguage++);

            Arrays.fill(len, 0);
            Arrays.fill(adjLen, 0);

            for (int i = 0; i < N; i++) {
                lan1Raw = scanner.next();
                lan2Raw = scanner.next();
                word = scanner.next();
                if (!languageId.containsKey(lan1Raw))
                    languageId.put(lan1Raw, totalLanguage++);
                if (!languageId.containsKey(lan2Raw))
                    languageId.put(lan2Raw, totalLanguage++);
                if (!wordId.containsKey(word))
                    wordId.put(word, totalWord++);
                int lan1 = languageId.get(lan1Raw);
                int lan2 = languageId.get(lan2Raw);
                int w = wordId.get(word);

                wordByLanguage[lan1][len[lan1]++] = w;
                wordByLanguage[lan2][len[lan2]++] = w;
                wordLen[w] = word.length();
                firstLetter[w] = word.charAt(0);
            }

            for (int i = 0; i < totalLanguage; i++) {
                for (int j = 0; j < len[i]; j++) {
                    for (int k = j + 1; k < len[i]; k++) {
                        int from = wordByLanguage[i][j];
                        int to = wordByLanguage[i][k];
                        if (firstLetter[from] != firstLetter[to]) {
                            adj[from][adjLen[from]++] = to;
                            adj[to][adjLen[to]++] = from;
                        }
                    }
                }
            }


            // Run Dijkstra
            Arrays.fill(dist, INF);
            /*
                Let's think that there is an imaginary single source
                that has connection to all nodes that have are in
                 startLanguage set.
             */
            PriorityQueue<Edge> Q = new PriorityQueue<>(1, new Comparator<Edge>() {
                @Override
                public int compare(Edge o1, Edge o2) {
                    return Integer.compare(o1.cost, o2.cost);
                }
            });
            int startId = languageId.get(startLanguage);
            int endId = languageId.get(endLanguage);

            for (int i = 0; i < len[startId]; i++) {
                int w = wordByLanguage[startId][i];
                dist[w] = wordLen[w];
                Q.add(new Edge(w, wordLen[w]));
            }

            while(!Q.isEmpty()) {
                Edge cur = Q.poll();

                int curWord = cur.node;
                for(int i=0; i < adjLen[curWord]; i++) {
                    int nextWord = adj[curWord][i];
                    int nextDist = dist[curWord] + wordLen[nextWord];
                    if(nextDist < dist[nextWord]) {
                        dist[nextWord] = nextDist;
                        Q.add(new Edge(nextWord, dist[nextWord]));
                    }
                }
            }

            int res = INF;
            for(int i=0; i < len[endId]; i++) {
                res = Math.min(res, dist[wordByLanguage[endId][i]]);
            }

            writer.println(res == INF ? "impossivel" : res);
        }

        writer.flush();
    }
}

class Edge {
    int node, cost;

    public Edge(int node, int cost) {
        this.node = node;
        this.cost = cost;
    }
}