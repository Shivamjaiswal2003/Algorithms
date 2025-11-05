#include <bits/stdc++.h>
using namespace std;

const int MAXBIT = 30;

void build(int idx, int l, int r, const vector<int>& arr, vector<int>& t) {
    if (l == r) {
        t[idx] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2*idx, l, mid, arr, t);
    build(2*idx+1, mid+1, r, arr, t);
    t[idx] = t[2*idx] & t[2*idx+1];
}

int query(int idx, int l, int r, int lq, int rq, const vector<int>& t) {
    if (l > rq || r < lq) return (1 << MAXBIT) - 1;
    if (l >= lq && r <= rq) return t[idx];
    int mid = (l + r) / 2;
    return query(2*idx, l, mid, lq, rq, t) &
           query(2*idx+1, mid+1, r, lq, rq, t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> l(m), r(m), q(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> q[i];
        l[i]--; r[i]--;
    }

    vector<int> a(n, 0), sum(n, 0);
    vector<int> t(4*n, 0);

    // Process each bit separately
    for (int bit = 0; bit < MAXBIT; bit++) {
        fill(sum.begin(), sum.end(), 0);
        for (int i = 0; i < m; i++) {
            if ((q[i] >> bit) & 1) {
                sum[l[i]]++;
                if (r[i] + 1 < n) sum[r[i] + 1]--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i > 0) sum[i] += sum[i-1];
            if (sum[i] > 0) a[i] |= (1 << bit);
        }
    }

    // Build segment tree
    build(1, 0, n-1, a, t);

    // Validate constraints
    for (int i = 0; i < m; i++) {
        int val = query(1, 0, n-1, l[i], r[i], t);
        if (val != q[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}