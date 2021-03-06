import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Scanner;

class Main {

    // modifies c to next permutation or returns null if such permutation does not exist
    private static Comparable[] nextPermutation(final Comparable[] c) {
        // 1. finds the largest k, that c[k] < c[k+1]
        int first = getFirst(c);
        if (first == -1) return null; // no greater permutation
        // 2. find last index toSwap, that c[k] < c[toSwap]
        int toSwap = c.length - 1;
        while (c[first].compareTo(c[toSwap]) >= 0)
            --toSwap;
        // 3. swap elements with indexes first and last
        swap(c, first++, toSwap);
        // 4. reverse sequence from k+1 to n (inclusive)
        toSwap = c.length - 1;
        while (first < toSwap)
            swap(c, first++, toSwap--);
        return c;
    }

    // finds the largest k, that c[k] < c[k+1]
    // if no such k exists (there is not greater permutation), return -1
    private static int getFirst(final Comparable[] c) {
        for (int i = c.length - 2; i >= 0; --i)
            if (c[i].compareTo(c[i + 1]) < 0)
                return i;
        return -1;
    }

    // swaps two elements (with indexes i and j) in array
    private static void swap(final Comparable[] c, final int i, final int j) {
        final Comparable tmp = c[i];
        c[i] = c[j];
        c[j] = tmp;
    }

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        String in;
        while (!(in = scanner.next()).equals("#")) {
            Character[] list = new Character[in.length()];
            for (int idx = 0; idx < in.length(); idx++) {
                list[idx] = in.charAt(idx);
            }
            Character[] res = (Character[]) nextPermutation(list);
            if (res == null) {
                System.out.println("No Successor");
            } else {
                for(char ch : res) {
                    System.out.print(ch);
                }
                System.out.println();
            }
        }
    }


}
