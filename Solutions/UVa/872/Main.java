import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.*;

// Topological sort.
// Uva 872 - Ordering
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=813
public class Main {

    public static void main(String[] args) {

        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int T = scanner.nextInt();
        scanner.nextLine();

        for (int cid = 0; cid < T; cid++) {
            if (cid > 0) writer.println();

            scanner.nextLine();
            final String sequence = scanner.nextLine();
            final Graph graph = new Graph(sequence);
            final String line = scanner.nextLine();
            for (String condition : line.split(" ")) {
                graph.addCondition(condition);
            }
            graph.solve();
            List<List<Integer>> orderings = graph.orderings;

            for (List<Integer> ordering : orderings) {
                for (int i = 0; i < ordering.size(); i++) {
                    if (i > 0) writer.print(" ");
                    writer.print((char) ('A' + ordering.get(i)));
                }
                writer.println();
            }
            if (orderings.size() == 0) writer.println("NO");
        }
        writer.flush();
    }

}


class Graph {
    Set<Integer>[] todos;
    Set<Integer> done;
    int[] nodes;
    int N;
    List<List<Integer>> orderings;
    int[] curOrdering;


    public Graph(String sequence) {
        String[] split = sequence.split(" ");
        N = split.length;
        nodes = new int[N];

        done = new HashSet<Integer>();
        for (int i = 0; i < N; i++)
            nodes[i] = num(split[i]);
        todos = new Set[30];
        for (int i = 0; i < 30; i++) {
            todos[i] = new HashSet<Integer>();
        }
        curOrdering = new int[N];
        orderings = new ArrayList<List<Integer>>();

    }

    public void addCondition(String condition) {
        int preCond = num(condition.charAt(0));
        int me = num(condition.charAt(2));
        todos[me].add(preCond);
    }

    public void solve() {
        // sort the visit order at the beginning
        Arrays.sort(nodes);
        for (int node : nodes) {
            if (todos[node].isEmpty()) {
                done.add(node);
                curOrdering[0] = node;
                findOrdering(1);
                done.remove(node);
            }
        }


    }

    private void findOrdering(int order) {
        if (order == N) {
            // This is the last order.
            final List<Integer> ordering = new ArrayList<Integer>(N);
            for (int i = 0; i < N; i++)
                ordering.add(curOrdering[i]);
            orderings.add(ordering);
        } else {
            for (int node : nodes) {
                if (done.contains(node)) continue;
                if (isFree(node)) {
                    // TODO: Take care of alphabetical order later
                    done.add(node);
                    curOrdering[order] = node;
                    findOrdering(order + 1);
                    done.remove(node);
                }

            }
        }
    }

    private boolean isFree(int node) {
        if (todos[node].isEmpty()) return true;

        for (int todo : todos[node]) {
            if (!done.contains(todo)) return false;
        }
        return true;
    }


    private int num(char ch) {
        return ch - 'A';
    }

    private int num(String str) {
        return str.charAt(0) - 'A';
    }

}