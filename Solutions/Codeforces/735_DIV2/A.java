import java.io.*;
import java.util.*;

/*
br = new BufferedReader(new FileReader("input.txt"));
pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
br = new BufferedReader(new InputStreamReader(System.in));
pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */

public class Main {
    private static BufferedReader br;
    private static StringTokenizer st;
    private static PrintWriter pw;

    private static boolean[] visited;
    private static int n, k;
    private static String seq;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        n = readInt();
        k = readInt();
        seq = nextToken();
        visited = new boolean[n];
        Arrays.fill(visited, false);
        boolean result = canEat(seq.indexOf("G"));

        pw.println(result ? "YES" : "NO");
        pw.close();
    }

    private static boolean canEat(int pos) {
        if(0 <= pos && pos < n && !visited[pos]) {
            visited[pos] = true;
            char ch = seq.charAt(pos);
            if(ch == '.' || ch == 'G') return canEat(pos - k) || canEat(pos + k);
            return ch == 'T';
        }
        return false;
    }

    private static void exitImmediately()	{
        pw.close();
        System.exit(0);
    }

    private static long readLong() throws IOException	{
        return Long.parseLong(nextToken());
    }

    private static double readDouble() throws IOException	{
        return Double.parseDouble(nextToken());
    }

    private static int readInt() throws IOException	{
        return Integer.parseInt(nextToken());
    }

    private static String nextToken() throws IOException	{
        while(st == null || !st.hasMoreTokens())	{
            if(!br.ready())	{
                exitImmediately();
            }
            st = new StringTokenizer(br.readLine().trim());
        }
        return st.nextToken();
    }
}
