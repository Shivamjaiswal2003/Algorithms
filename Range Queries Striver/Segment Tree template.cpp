#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define srt(v)  sort(v.begin(),v.end())      
#define mxe(v)  *max_element(v.begin(),v.end())     
#define mne(v)  *min_element(v.begin(),v.end())    

using namespace std;
int MOD = 1e9 + 7;

// =========================== Segment Tree Class ===============================

class SegmentTree {
    vector<int> seg;
    vector<int> a;
    int n;

public:
    SegmentTree(const vector<int>& input) {
        a = input;
        n = a.size();
        seg.resize(4 * n);
        build(0, 0, n - 1);
    }

    void build(int ind, int low, int high) {
        if (low == high) {
            seg[ind] = a[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid);
        build(2 * ind + 2, mid + 1, high);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {
        // complete overlap
        if (low >= l && high <= r) return seg[ind];

        // no overlap
        if (r < low || l > high) return INT_MAX;

        // partial overlap
        int mid = (low + high) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);

        return min(left, right);
    }

    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            a[i] = val;
            return;
        }

        int mid = (low + high) / 2;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    // Public wrappers
    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void update(int i, int val) {
        update(0, 0, n - 1, i, val);
    }
};

// =========================== Solve Function ===============================

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    fr(i, n) cin >> a[i];

    SegmentTree st(a);

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r) << endl;
        } else {
            int i, val;
            cin >> i >> val;
            st.update(i, val);
        }
    }
}

// =========================== Main ===============================

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
