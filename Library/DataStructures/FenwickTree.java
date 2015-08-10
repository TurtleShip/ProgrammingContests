// source : Competitive Programming 3

class FenwickTree {
    private Vector<Integer> ft;

    private int LSOne(int S) {
        return (S & (-S));
    }

    public FenwickTree() {
    }

    // initialization: n + 1 zeroes, ignore index 0
    public FenwickTree(int n) {
        ft = new Vector<Integer>();
        for (int i = 0; i <= n; i++) ft.add(0);
    }

    public int rsq(int b) {                              // returns RSQ(1, b)
        int sum = 0;
        for (; b > 0; b -= LSOne(b)) sum += ft.get(b);
        return sum;
    }

    public int rsq(int a, int b) {                       // returns RSQ(a, b)
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
    // Note that k is 1-indexed. i.e. The first index is 1.
    void adjust(int k, int v) {                    // note: n = ft.size() - 1
        for (; k < (int) ft.size(); k += LSOne(k)) ft.set(k, ft.get(k) + v);
    }
};
}
