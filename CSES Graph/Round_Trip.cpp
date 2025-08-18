#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define fr(i, n) for (int i = 0; i < (n); i++)
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define srt(v) sort(v.begin(), v.end())
#define mxe(v) *max_element(v.begin(), v.end())
#define mne(v) *min_element(v.begin(), v.end())

using namespace std;
int MOD = 1e9 + 7;

// ===================================END Of the Life ==========================================

bool check(int node, int par, vector<int> adj[], vector<int> &vis, vector<int> &temp)
{
    vis[node] = 1;
    temp.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (check(it, node, adj, vis, temp) == true)
                return true;
        }
        else
        {

            if (it != par)
            {
                temp.push_back(it);
                return true;
            }
        }
    }
    temp.pop_back();
    return false;
}

void solve()
{

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> vis(n + 1, 0);
    vector<int> temp;

    int flag = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (check(i, -1, adj, vis, temp) == true)
            {
                flag = 1;
                break;
            }
        }
    }

    if (flag == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return ;
    }

    int cycle_start = temp.back();

    int ind = -1;

    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == cycle_start)
        {
            ind = i;
            break;
        }
    }

    vector<int> ans;
    for (int i = ind; i < temp.size(); i++)
    {
        ans.push_back(temp[i]);
    }
    cout << ans.size() << endl;

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
