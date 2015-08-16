import java.io.BufferedInputStream;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class LEDTest {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        String in;
        while (!(in = scanner.next()).equals("0")) {
            int N = Integer.parseInt(in);
            String[] seq = new String[N];
            for (int i = 0; i < N; i++) {
                seq[i] = scanner.next();
            }
            List<Integer> burnt = new LinkedList<Integer>();
            for (int i = 0; i < 7; i++) {
                boolean allTurnOff = true;
                for (String lights : seq) {
                    allTurnOff = lights.charAt(i) == 'N';
                    if (!allTurnOff) break;
                }
                if (allTurnOff) burnt.add(i);
            }
            boolean isMatch = LED.isCountDown(seq, burnt);
            System.out.println(isMatch ? "MATCH" : "MISMATCH");
        }

    }
}

class LED {
    private static final String[] digits = {
        "YYYYYYN", // 0
        "NYYNNNN", // 1
        "YYNYYNY", // 2
        "YYYYNNY", // 3
        "NYYNNYY", // 4
        "YNYYNYY", // 5
        "YNYYYYY", // 6
        "YYYNNNN", // 7
        "YYYYYYY", // 8
        "YYYYNYY"  // 9
    };
    private static final int ledTotal = 7;


    public static boolean isCountDown(String[] seq, List<Integer> burnt) {
        int N = seq.length;

        for (int st = 9; (st - (N-1)) >= 0; st--) {
            boolean isGood = true;
            List<Integer> additionalBurnt = new LinkedList<Integer>();

            for (int idx = 0; isGood && idx < N; idx++) {

                // seq[idx] == digits[st-idx] while ignoring burnt part
                for (int led = 0; led < ledTotal; led++) {
                    if (burnt.contains(led)) continue;
                    if (additionalBurnt.contains(led)) {
                        if (seq[idx].charAt(led) == 'Y') {
                            isGood = false;
                            break;
                        } else {
                            continue;
                        }
                    }

                    boolean isMatch = seq[idx].charAt(led) == digits[st - idx].charAt(led);
                    if (!isMatch) {
                        if (seq[idx].charAt(led) == 'N') {
                            additionalBurnt.add(led);
                        } else {
                            isGood = false;
                            break;
                        }
                    }
                }
            }
            if (isGood) return true;
        }

        return false;
    }

}