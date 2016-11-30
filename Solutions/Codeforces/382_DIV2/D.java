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

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int n = readInt();
        if(isPrime(n)) pw.println(1);
        else if(n % 2 == 0) pw.println(2);
        else {
            // number is odd
            if(isPrime(n-2)) pw.println(2);
            else pw.println(3);
        }
        pw.close();
    }

    private static boolean isPrime(int n) {
        if(n <= 1) return false;
        if(n == 2) return true;
        if(n%2 == 0)return false;
        int m = (int)Math.sqrt(n);
        for(int i=3; i <=m; i+=2)
            if(n%i == 0)
                return false;
        return true;
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