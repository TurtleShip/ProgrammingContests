import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class C {

    public static void main(String[] args) {
        final Scanner sc = new Scanner(new BufferedInputStream(System.in));

        int N = sc.nextInt(); // number of vertices
        int M = sc.nextInt(); //  the maximum number of consecutive vertices with cats that is still ok for Kefa

        boolean[] hasCat = new boolean[N + 1];
        LinkedList<Integer>[] adj = new LinkedList[N + 1];
        int INF = 1_000_000;

        for (int i = 1; i <= N; i++)
            adj[i] = new LinkedList<>();

        for (int i = 1; i <= N; i++)
            hasCat[i] = sc.nextInt() == 1;

        for (int i = 0; i < N - 1; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            adj[x].add(y);
            adj[y].add(x);
        }

        int[] dist = new int[N + 1];
        Arrays.fill(dist, INF);
        dist[1] = hasCat[1] ? 1 : 0;

        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int next : adj[cur]) {
                if (dist[next] != INF) continue;
                int nextDist = hasCat[next] ? (dist[cur] + 1) : 0;
                if (nextDist > M) continue;
                if (nextDist < dist[next]) {
                    dist[next] = nextDist;
                    q.add(next);
                }
            }
        }
        int res = 0;
        for (int i = 2; i <= N; i++) {
            if (adj[i].size() == 1 && dist[i] != INF) res++;
        }

        System.out.println(res);
    }
}