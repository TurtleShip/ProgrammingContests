import java.io.BufferedInputStream;
import java.util.*;

class Main {
    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final String candidates = scanner.next();
        int N = Integer.parseInt(scanner.next());
        final Solver solver = new Solver(candidates);
        solver.prePopulate();
        for (int i = 0; i < N; i++) {
            char[] sequence = scanner.next().toCharArray();
            System.out.println(solver.find(sequence));
        }
    }
}

class Solver {

    private static final String NOT_MATCHED = "Not matched";
    private static final String MATCHED = "Matched %d %d";
    private String candidates;
    private Map<Character, List<Integer>> positions;

    public Solver(String candidates) {
        this.candidates = candidates;
    }

    public void prePopulate() {
        positions = new HashMap<Character, List<Integer>>();
        for (int i = 0; i < 26; i++) {
            char small = (char) ('a' + i);
            char big = (char) ('A' + i);
            positions.put(small, new ArrayList<Integer>());
            positions.put(big, new ArrayList<Integer>());
        }

        for (int idx = 0; idx < candidates.length(); idx++) {
            positions.get(candidates.charAt(idx)).add(idx);
        }
    }

    public String find(char[] sequence) {
        int pos = 0;
        int totalCandidates = candidates.length();
        int matched = 0;
        int first = -1;
        int last = -1;

        for (int idx = 0; idx < sequence.length && pos < totalCandidates; idx++) {

            final List<Integer> curPositions = positions.get(sequence[idx]);
            int cur = Collections.binarySearch(curPositions, pos);
            /*
                Note that Collections.binarySearch returns the below
                the index of the search key, if it is contained in the list; otherwise, (-(insertion point) - 1).
                The insertion point is defined as the point at which the key would be inserted into the list:
                the index of the first element greater than the key,
                or list.size() if all elements in the list are less than the specified key.
             */
            if (cur >= 0) {

                if (matched == 0) {
                    first = last = pos;
                } else {
                    last = pos;
                }
                matched++;
                pos++;
            } else {
                int insertionPoint = -cur - 1;
                if (insertionPoint >= curPositions.size()) {
                    break;
                } else {
                    pos = curPositions.get(insertionPoint);

                    if (matched == 0) {
                        first = last = pos;
                    } else {
                        last = pos;
                    }
                    matched++;
                    pos++;
                }
            }
        }

        if (matched == sequence.length) {
            return String.format(MATCHED, first, last);
        } else {
            return NOT_MATCHED;
        }
    }
}