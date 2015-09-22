public class PaintTheRoom {
    static String YES = "Paint";
    static String NO = "Cannot paint";

    // 1 <= R,C,K <= 50
    public String canPaintEvenly(int R, int C, int K) {
        if (R == 1 && C == 1) return K == 1 ? YES : NO;
        if (K == 1) return YES;
        return ((R * C) % 2) == 0 ? YES : NO;
    }

}