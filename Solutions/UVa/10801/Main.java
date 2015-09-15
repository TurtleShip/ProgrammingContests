import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int N, dst;
        int INF = 100_000_000;
        int[][] dist = new int[510][510];
        int[] len = new int[10];
        int[][] availFloors = new int[10][510];

        int[] delay = new int[10];


        while(scanner.hasNextInt()) {

            N = scanner.nextInt(); // number of elevators
            dst = scanner.nextInt(); // destination floor

            for (int e = 1; e <= N; e++)
                delay[e] = scanner.nextInt();

            int maxNode = N * 100;

            Arrays.fill(len, 0);

            scanner.nextLine();
            for (int e = 1; e <= N; e++) {
                String[] split = (scanner.nextLine()).split(" ");
                for (String raw : split) {
                    int floor = Integer.parseInt(raw);
                    availFloors[e][len[e]++] = floor;
                }
            }

            for (int i = 0; i < maxNode; i++)
                Arrays.fill(dist[i], INF);

            // doesn't cost anything to stay within an elevator
            for (int i = 0; i < maxNode; i++)
                dist[i][i] = 0;

            // connect floor within elevators
            for (int e = 1; e <= N; e++) {
                for (int i = 0; i < len[e]; i++) {
                    for (int j = 0; j < len[e]; j++) {
                        int from = availFloors[e][i];
                        int to = availFloors[e][j];
                        int cost = Math.abs(from - to) * delay[e];
                        int fromId = id(e, from);
                        int toId = id(e, to);
                        dist[fromId][toId] = dist[toId][fromId] = cost;
                    }
                }
            }

            // connect between elevators. You can only switch between elevators if both elevators
            // can stop at the same floor
            for (int e1 = 1; e1 <= N; e1++) {
                for (int e2 = e1 + 1; e2 <= N; e2++) {
                    for (int i = 0; i < len[e1]; i++) {
                        int from = availFloors[e1][i];
                        for (int j = 0; j < len[e2]; j++) {
                            int to = availFloors[e2][j];
                            if (from == to) {
                                int fromId = id(e1, from);
                                int toId = id(e2, to);
                                dist[fromId][toId] = dist[toId][fromId] = 60;
                            }
                        }
                    }
                }
            }

            // Run Floydd-Warshall
            for (int mid = 0; mid < maxNode; mid++) {
                for (int from = 0; from < maxNode; from++) {
                    for (int to = 0; to < maxNode; to++) {
                        dist[from][to] = Math.min(dist[from][to], dist[from][mid] + dist[mid][to]);
                    }
                }
            }

            // check if I reached floor 'dst' with any elevator
            int res = -1;
            for(int e1= 1; e1 <= N; e1++) {
                for (int e2 = 1; e2 <= N; e2++) {
                    int fromId = id(e1, 0);
                    int toId = id(e2, dst);
                    if (dist[fromId][toId] != INF) {
                        if (res == -1) res = dist[fromId][toId];
                        else res = Math.min(res, dist[fromId][toId]);
                    }
                }
            }

            writer.println(res == -1 ? "IMPOSSIBLE" : res);
        }
        writer.flush();
    }

    static int id(int elevator, int floor) {
        return ((elevator - 1) * 100) + floor;
    }
}
