/*
    Note to myself: Whenever I implement SegTree, I have a tendency to 
    segTree[idx] = Math.min(segTree[idx], newVal) during updates. This is WRONG.
    For an update, we are replacing an existing value with 'newVal'. So once we find an idx that
    corresponds to the position that we need to update, do segTree[idx] = newVal
*/

class SegMinTree {
    int N;
    int[] segTree;


    public SegMinTree(int[] arr) {
        this.N = arr.length;
        segTree = new int[4 * N + 1000];
        build(1, 0, N - 1, arr);
    }

    private void build(int idx, int left, int right, int[] arr) {
        if (left == right) {
            segTree[idx] = arr[left];
        } else {
            int mid = (left + right) / 2;
            build(left(idx), left, mid, arr);
            build(right(idx), mid + 1, right, arr);
            segTree[idx] = Math.min(segTree[left(idx)], segTree[right(idx)]);
        }
    }

    public int query(int left, int right) {
        return query(1, 0, N - 1, left, right);
    }

    private int query(int idx, int curLeft, int curRight, int targetLeft, int targetRight) {
        // Completely out of range
        if (targetRight < curLeft || curRight < targetLeft) {
            return Integer.MAX_VALUE;
        }

        if (targetLeft <= curLeft && curRight <= targetRight) {
            return segTree[idx];
        }

        int mid = (curLeft + curRight) / 2;
        return Math.min(query(left(idx), curLeft, mid, targetLeft, targetRight),
            query(right(idx), mid + 1, curRight, targetLeft, targetRight));
    }

    public void update(int pos, int val) {
        update(1, 0, N - 1, pos, val);
    }

    private void update(int idx, int left, int right, int pos, int val) {

        if (left == right) {
            if (pos == right) segTree[idx] = val;
            return;
        }

        if (left <= pos && pos <= right) {
            int mid = (left + right) / 2;
            update(left(idx), left, mid, pos, val);
            update(right(idx), mid + 1, right, pos, val);
            segTree[idx] = Math.min(segTree[left(idx)], segTree[right(idx)]);
        }
    }

    private int left(int idx) {
        return idx << 1;
    }

    private int right(int idx) {
        return (idx << 1) + 1;
    }
}


class SegMaxTree {
    int N;
    int[] segTree;


    public SegMaxTree(int[] arr) {
        this.N = arr.length;
        segTree = new int[4 * N + 1000];
        build(1, 0, N - 1, arr);
    }

    private void build(int idx, int left, int right, int[] arr) {
        if (left == right) {
            segTree[idx] = arr[left];
        } else {
            int mid = (left + right) / 2;
            build(left(idx), left, mid, arr);
            build(right(idx), mid + 1, right, arr);
            segTree[idx] = Math.max(segTree[left(idx)], segTree[right(idx)]);
        }
    }

    public int query(int left, int right) {
        return query(1, 0, N - 1, left, right);
    }

    private int query(int idx, int curLeft, int curRight, int targetLeft, int targetRight) {
        // Completely out of range
        if (targetRight < curLeft || curRight < targetLeft) {
            return Integer.MIN_VALUE;
        }

        if (targetLeft <= curLeft && curRight <= targetRight) {
            return segTree[idx];
        }

        int mid = (curLeft + curRight) / 2;
        return Math.max(query(left(idx), curLeft, mid, targetLeft, targetRight),
            query(right(idx), mid + 1, curRight, targetLeft, targetRight));
    }

    public void update(int pos, int val) {
        update(1, 0, N - 1, pos, val);
    }

    private void update(int idx, int left, int right, int pos, int val) {

        if (left == right) {
            if (left == pos) segTree[idx] = val;
            return;
        }
        if (left <= pos && pos <= right) {
            int mid = (left + right) / 2;
            update(left(idx), left, mid, pos, val);
            update(right(idx), mid + 1, right, pos, val);
            segTree[idx] = Math.max(segTree[left(idx)], segTree[right(idx)]);
        }
    }

    private int left(int idx) {
        return idx << 1;
    }

    private int right(int idx) {
        return (idx << 1) + 1;
    }
}
