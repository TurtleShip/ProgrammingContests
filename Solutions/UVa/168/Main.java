import java.io.*;
import java.util.*;

// UVa 168 - Theseus and the Minotaur
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=104
public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        String input;
        while (!(input = scanner.next()).equals("#")) {
            char cow = scanner.next().charAt(0);
            char me = scanner.next().charAt(0);
            int k = scanner.nextInt();

            final Maze maze = new Maze(input, k);
            List<Character> moves = maze.follow(me, cow);
            for (int i = 0; i < moves.size(); i++) {
                if (i > 0) writer.print(" ");
                if (i == moves.size() - 1) writer.print("/");
                writer.print(moves.get(i));
            }
            writer.println();
        }
        writer.flush();
    }
}

class Maze {
    /*
        Declaring these as static to save time allocating/de-allocating memory.
        Not a good practice in real life, but good for programming contests.
     */
    static int adj[][] = new int[30][30];
    static int adjLen[] = new int[30];
    static boolean[] isLit = new boolean[30]; // isLit[x] = true if room x is lit with a candle.
    int K;

    public Maze(final String maze, int K) {
        this.K = K;
        final String[] list = maze.substring(0, maze.length() - 1).split(";");
        Arrays.fill(isLit, false);
        Arrays.fill(adjLen, 0);
        for (String info : list) {
            String[] split = info.split(":");
            int cur = split[0].charAt(0) - 'A';
            int len = split[1].length();
            adjLen[cur] = len;
            for (int i = 0; i < len; i++) {
                adj[cur][i] = split[1].charAt(i) - 'A';
            }
        }

    }

    public List<Character> follow(char me, char cow) {

        // simulate comMove and then myMove
        int count = 0;
        int prevCow;
        int curCow = cow - 'A';
        int curMe = me - 'A';
        isLit[curMe] = true;
        List<Character> moves = new ArrayList<Character>();
        while (curCow != -1) {

            prevCow = curCow;
            curCow = cowMove(curCow);
            if (count == K) {
                // leave the candle
                moves.add((char) (curMe + 'A'));
                count = 0;
            } else {
                isLit[curMe] = false;
            }

            if (curCow != -1) {
                // now I follow the cow
                curMe = prevCow;
                isLit[curMe] = true;
                count++;
            } else { // the cow is trapped
                moves.add((char) (prevCow + 'A'));
            }
        }

        return moves;
    }

    // The cow (Minotaur) tries to move form the current position 'pos'
    // returns next position if it can move.
    // returns -1 if it cannot move.
    private int cowMove(int cur) {
        for (int i = 0; i < adjLen[cur]; i++) {
            int neighbor = adj[cur][i];
            if (!isLit[neighbor]) return neighbor;
        }
        return -1;
    }
}