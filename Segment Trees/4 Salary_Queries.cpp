#include <bits/stdc++.h>
using namespace std;


int getId(const vector<int>& allVals, int x) {
    return (int)(lower_bound(allVals.begin(), allVals.end(), x) - allVals.begin()) + 1;
}

class SegmentTree {
private:
    int n;
    vector<long long> tree; // Using long long for sum to avoid overflow

    void update(int idx, int l, int r, int pos, int delta) {
        if (l == r) {
            tree[idx] += delta;
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(2 * idx + 1, l, mid, pos, delta);
        } else {
            update(2 * idx + 2, mid + 1, r, pos, delta);
        }
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    long long query(int idx, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[idx];
        int mid = l + (r - l) / 2;
        return query(2 * idx + 1, l, mid, ql, qr) +
               query(2 * idx + 2, mid + 1, r, ql, qr);
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
    }

    void add(int pos, int delta) {
        update(0, 1, n, pos, delta);
    }

    long long rangeSum(int l, int r) {
        if (l > r) return 0;
        return query(0, 1, n, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    // Collect all initial and query values for coordinate compression
    vector<tuple<char, int, int>> queries;
    vector<int> allVals;
    allVals.reserve(n + 2 * q);

    for (int val : p) {
        allVals.push_back(val);
    }

    for (int i = 0; i < q; i++) {
        char type;
        cin >> type;
        if (type == '!') {
            int k, x;
            cin >> k >> x;
            queries.emplace_back(type, k, x);
            allVals.push_back(x);
        } else {
            int a, b;
            cin >> a >> b;
            queries.emplace_back(type, a, b);
            allVals.push_back(a);
            allVals.push_back(b);
        }
    }

    // Coordinate compression
    sort(allVals.begin(), allVals.end());
    allVals.erase(unique(allVals.begin(), allVals.end()), allVals.end());

    int MAX_ID = allVals.size();
    SegmentTree st(MAX_ID);

    // Initialize frequencies in the segment tree
    vector<int> salaryId(n);
    for (int i = 0; i < n; i++) {
        salaryId[i] = getId(allVals, p[i]);
        st.add(salaryId[i], 1);
    }

    // Process queries
    // The loop now uses a single iterator 'it'
    // and std::get is used to access the tuple elements.
    for (const auto& it : queries) {
        char type = get<0>(it);
        int a = get<1>(it);
        int b = get<2>(it);

        if (type == '!') {
            int k = a;
            int x = b;
            int newId = getId(allVals, x);
            // Decrement count for the old salary
            st.add(salaryId[k - 1], -1);
            // Update to the new salary ID
            salaryId[k - 1] = newId;
            // Increment count for the new salary
            st.add(newId, 1);
        } else {
            int l_val = a;
            int r_val = b;
            int l_id = getId(allVals, l_val);
            int r_id = getId(allVals, r_val);
            cout << st.rangeSum(l_id, r_id) << "\n";
        }
    }

    return 0;
}
