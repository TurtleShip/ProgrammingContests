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

    private static int n, one, two;
    private static Double[] nums;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        n = readInt();
        one = readInt();
        two = readInt();
        int small = Math.min(one, two);
        int big = Math.max(one, two);
        nums = new Double[n];

        for(int i=0; i < n; i++)
            nums[i] = readDouble();

        Arrays.sort(nums, Collections.reverseOrder());

        double first = 0.0;
        double second = 0.0;

        for(int i=0; i < small; i++)
            first += nums[i];
        for(int i=small; i < small + big; i++)
            second += nums[i];
        double res = (first / (double)(small)) + (second / (double)(big));

        pw.println(res);
        pw.close();
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
