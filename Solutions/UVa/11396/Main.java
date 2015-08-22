import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

// Uva 11396 Claw Decomposition
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2391
public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int V, x, y;
        while ((V = scanner.nextInt()) != 0) {
            final Graph graph = new Graph(V);
            while ((x = scanner.nextInt()) != 0 & (y = scanner.nextInt()) != 0) {
                x--;
                y--;
                graph.add(x, y);
            }

            boolean res = graph.isValid();
            writer.println(res ? "YES" : "NO");
        }
        writer.flush();
    }
}

/*
    I know how to solve the problem.. but I can't think of any case where
    I will actually output "YES"...
 */
class Graph {
    static int NO_COLOR = 2;
    static int CENTER = 1;

    int V; // the total number of nodes
    int[][] neighbor;
    int[] color;
    int[] len;

    public Graph(int V) {
        this.V = V;
        this.color = new int[V];
        this.neighbor = new int[V][3];
        this.len = new int[V];
        Arrays.fill(color, NO_COLOR);
        Arrays.fill(len, 0);
    }

    public void add(int x, int y) {
        neighbor[x][len[x]++] = y;
        neighbor[y][len[y]++] = x;
    }

    public boolean isValid() {
        // first, make sure UVa didn't fuck with me and gave me a node whose degree is not 3
        for (int curLen : len)
            if (curLen != 3)
                throw new RuntimeException("FUCK YOU, UVa");

        for (int i = 0; i < V; i++) {
            if (color[i] == NO_COLOR) {
                color[i] = CENTER;
                if (!check(i, CENTER)) return false;
            }
        }

        return true;
    }

    private boolean check(int x, int myColor) {
        boolean res = true;
        int nextColor = (myColor + 1) % 2;
        for (int i = 0; res && i < 3; i++) {

            // check all three neighbors
            int next = neighbor[x][i];
            if (color[next] == NO_COLOR) {
                color[next] = nextColor;
                res = check(next, nextColor);
            } else if (color[next] == myColor) {
                return false;
            }
        }
        return res;
    }
}