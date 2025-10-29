#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;

map<vector<int>, int> mp;

int fun(int val, int j, int i, int d, int e, int f, int dc, int ec, vector<vector<int>> &conf)
{
    int n = conf.size();
    if (i == n)
    {
        int sm = d * dc + e * ec;
        return sm;
    }
    vector<int> key = {val, j, i, d, e, f};
    if (mp.count(key))
        return mp[key];
    int tk = 0;
    if ((j == 1 || val > 0) && conf[i][0] <= d && conf[i][1] <= e && conf[i][2] <= f)
    {
        tk = conf[i][3] + fun(val - (j == 0 ? 1 : 0), 1, i, d - conf[i][0], e - conf[i][1], f - conf[i][2], dc, ec, conf);
    }
    int ntk = fun(val, 0, i + 1, d, e, f, dc, ec, conf);
    return mp[key] = max(tk, ntk);
}

void solve()
{
    int d, e, f, dc, ec;
    cin >> d >> e >> f >> dc >> ec;
    int n;
    cin >> n;
    vector<vector<int>> confgs;
    for (int i = 0; i < n; i++)
    {
        vector<int> vec;
        int di, ei, fi, pri;
        cin >> di >> ei >> fi >> pri;
        vec.push_back(di);
        vec.push_back(ei);
        vec.push_back(fi);
        vec.push_back(pri);
        confgs.push_back(vec);
    }
    mp.clear();
    int ans = fun(3, 0, 0, d, e, f, dc, ec, confgs);
    cout << ans << endl;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}