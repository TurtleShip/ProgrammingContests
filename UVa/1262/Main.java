import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.*;

class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));

        int T = Integer.parseInt(scanner.next());

        while ((T--) > 0) {
            int K = Integer.parseInt(scanner.next());

            ArrayList<String> firstRows = new ArrayList<String>(6);
            for (int i = 0; i < 6; i++) {
                firstRows.add(i, scanner.next());
            }
            ArrayList<String> secondRows = new ArrayList<String>(6);
            for (int i = 0; i < 6; i++) {
                secondRows.add(i, scanner.next());
            }

            ArrayList<Set<Character>> firstGrid = Solver.createGrid(Solver.convertRowsToColumns(firstRows));
            ArrayList<Set<Character>> secondGrid = Solver.createGrid(Solver.convertRowsToColumns(secondRows));

            final Solver solver = new Solver(K, firstGrid, secondGrid);
            System.out.println(solver.solve());
        }

    }
}

class Solver {

    private int k;
    private ArrayList<Set<Character>> firstGrid;
    private ArrayList<Set<Character>> secondGrid;

    /*
        Convert 6 rows where each row is length 5
        to
        5 columns where each column is length 6
     */
    public static List<String> convertRowsToColumns(List<String> rows) {
        List<String> columns = new ArrayList<String>(5);
        for (int col = 0; col < 5; col++) {
            StringBuilder str = new StringBuilder();
            for (int row = 0; row < 6; row++) {
                str.append(rows.get(row).charAt(col));
            }
            columns.add(str.toString());
        }
        return columns;
    }

    public static ArrayList<Set<Character>> createGrid(List<String> raw) {
        ArrayList<Set<Character>> columns = new ArrayList<Set<Character>>(5); // there are 5 columns

        for (int idx = 0; idx < raw.size(); idx++) {
            final String str = raw.get(idx);
            final HashSet<Character> set = new HashSet<Character>();
            for (char ch : str.toCharArray()) {
                set.add(ch);
            }
            columns.add(idx, set);
        }

        return columns;
    }

    public Solver(int k, ArrayList<Set<Character>> firstGrid, ArrayList<Set<Character>> secondGrid) {
        this.k = k;
        this.firstGrid = firstGrid;
        this.secondGrid = secondGrid;
    }

    public String solve() {

        // get the intersection of 'grid' and 'secondGrid'
        ArrayList<ArrayList<Character>> columns = new ArrayList<ArrayList<Character>>();
        for (int i = 0; i < firstGrid.size(); i++) {
            firstGrid.get(i).retainAll(secondGrid.get(i));
            columns.add(i, new ArrayList<Character>(firstGrid.get(i)));
            Collections.sort(columns.get(i));
        }

        BigInteger totalConfig = new BigInteger("1");
        for (ArrayList<Character> list : columns) {
            totalConfig = totalConfig.multiply(new BigInteger(list.size() + ""));
        }
        if (totalConfig.compareTo(new BigInteger(Integer.toString(k))) == -1) {
            return "NO";
        }

        /*
            Go through each column and
         */
        int first = 1;
        int firstMult = columns.get(1).size() * columns.get(2).size() * columns.get(3).size() * columns.get(4).size();
        while (first * firstMult < k) {
            first++;
        }
        k -= (first - 1) * firstMult;

        int second = 1;
        int secondMult = columns.get(2).size() * columns.get(3).size() * columns.get(4).size();
        while (second * secondMult < k) {
            second++;
        }
        k -= (second - 1) * secondMult;

        int third = 1;
        int thirdMult = columns.get(3).size() * columns.get(4).size();
        while (third * thirdMult < k) {
            third++;
        }
        k -= (third - 1) * thirdMult;

        int fourth = 1;
        int fourthMult = columns.get(4).size();

        while (fourth * fourthMult < k) {
            fourth++;
        }
        k -= (fourth - 1) * fourthMult;

        int fifth = 1 + (k - 1);

        StringBuilder res = new StringBuilder()
            .append(columns.get(0).get(first - 1))
            .append(columns.get(1).get(second - 1))
            .append(columns.get(2).get(third - 1))
            .append(columns.get(3).get(fourth - 1))
            .append(columns.get(4).get(fifth - 1));

        return res.toString();
    }
}