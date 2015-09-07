import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int N;
        while ((N = scanner.nextInt()) != 0) {
            Graph graph = new Graph();
            for (int i = 0; i < N; i++)
                graph.parse(scanner.next(), scanner.next(), scanner.next(), scanner.next(), scanner.nextInt());

            writer.println(graph.solve(scanner.next(), scanner.next()));
        }

        writer.flush();
    }
}

class Graph {
    static int INF = 1_000_000;
    static int TOTAL_CITY = 26;
    /*
        Input consists of uppercase characters only,
        so at most 26 cities.
     */

    int[][] myCost = new int[30][30];
    int[][] profCost = new int[30][30];

    public Graph() {
        for (int i = 0; i < TOTAL_CITY; i++)
            for (int j = 0; j < TOTAL_CITY; j++)
                myCost[i][j] = INF;

        for (int i = 0; i < TOTAL_CITY; i++)
            for (int j = 0; j < TOTAL_CITY; j++)
                profCost[i][j] = INF;

        for (int i = 0; i < TOTAL_CITY; i++)
            myCost[i][i] = profCost[i][i] = 0;
    }

    public void parse(final String who,
                      final String dir,
                      final String src,
                      final String dst,
                      final int cost) {
        final boolean canIGo = "Y".equals(who);
        final boolean isBothWay = "B".equals(dir);
        final int start = src.charAt(0) - 'A';
        final int end = dst.charAt(0) - 'A';

        if (canIGo) {
            myCost[start][end] = cost;
            if (isBothWay) myCost[end][start] = cost;
        } else {
            profCost[start][end] = cost;
            if (isBothWay) profCost[end][start] = cost;
        }
    }


    /*
        Algorithm
        1. Populate myCost
        2. Populate profCost
        3. Go through all 26 cities.
            For each city x, ( myCost[myStart][x] + profCost[profStart][x] )
             is the minimum cost to meet at the city.
     */
    public String solve(String meRaw, String profRaw) {

        int me = meRaw.charAt(0) - 'A';
        int prof = profRaw.charAt(0) - 'A';

        for (int mid = 0; mid < TOTAL_CITY; mid++)
            for (int st = 0; st < TOTAL_CITY; st++)
                for (int end = 0; end < TOTAL_CITY; end++)
                    myCost[st][end] = Math.min(myCost[st][end], myCost[st][mid] + myCost[mid][end]);

        for (int mid = 0; mid < TOTAL_CITY; mid++)
            for (int st = 0; st < TOTAL_CITY; st++)
                for (int end = 0; end < TOTAL_CITY; end++)
                    profCost[st][end] = Math.min(profCost[st][end], profCost[st][mid] + profCost[mid][end]);

        // Inefficient. But since there are less than total of 30 cities, this is good enough.
        final boolean isSamePlace = me == prof; // A special case where both of prof and I start at the same place.
        int minCost = isSamePlace ? 0 : INF;
        for (int x = 0; x < TOTAL_CITY; x++)
            minCost = Math.min(minCost, myCost[me][x] + profCost[prof][x]);

        if (minCost == INF) {
            return "You will never meet.";
        } else {
            final StringBuilder result = new StringBuilder(Integer.toString(minCost));
            for (int x = 0; x < TOTAL_CITY; x++)
                if ((isSamePlace && x == me) || (myCost[me][x] + profCost[prof][x]) == minCost)
                    result.append(" ").append((char) (x + 'A'));

            return result.toString();
        }
    }
}