import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.*;

// UVa 11060 - Beverages
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2001
public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int cid = 1;
        while (scanner.hasNextInt()) {

            int N = scanner.nextInt();
            String[] beverage = new String[N];
            for (int i = 0; i < N; i++)
                beverage[i] = scanner.next();
            final Drink drink = new Drink(beverage);
            int M = scanner.nextInt();

            for (int i = 0; i < M; i++) {
                String before = scanner.next();
                String after = scanner.next();
                drink.add(before, after);
            }

            String result = drink.solve();
            writer.printf("Case #%d: %s\n\n", cid++, result);
        }
        writer.flush();
    }
}

class Drink {
    static String template = "Dilbert should drink beverages in this order:";
    String[] beverage;
    int[] ordering;
    int N;
    Map<String, Set<String>> todos;
    Set<String> done;

    public Drink(String[] beverage) {
        this.beverage = beverage;
        N = beverage.length;
        ordering = new int[N];
        done = new HashSet<String>();
        todos = new HashMap<String, Set<String>>();
        for (String drink : beverage) {
            todos.put(drink, new HashSet<String>());
        }
    }

    public void add(String before, String after) {
        todos.get(after).add(before);
    }

    public String solve() {
        for (int i = 0; i < N; i++) {
            if (todos.get(beverage[i]).isEmpty()) {
                done.add(beverage[i]);
                ordering[0] = i;
                chug(1);
                break;
            }
        }
        StringBuilder res = new StringBuilder(template);
        for (int drinkId : ordering) {
            res = res.append(" ").append(beverage[drinkId]);
        }
        res = res.append(".");
        return res.toString();
    }

    // poorly written dfs :p
    private void chug(int order) {
        if (order == N) return;
        for (int i = 0; i < N; i++) {
            final String drink = beverage[i];
            if (done.contains(drink)) continue;
            if (!canDrink(drink)) continue;
            ordering[order] = i;
            done.add(drink);
            chug(order + 1);
            return;
        }
    }

    private boolean canDrink(String drink) {
        if (todos.get(drink).isEmpty()) return true;
        for (String preReq : todos.get(drink)) {
            if (!done.contains(preReq)) return false;
        }
        return true;
    }
}