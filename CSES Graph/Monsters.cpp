#include "bits/stdc++.h"
#define int long long
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
string s = "DRUL";

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> adj(n, vector<char>(m));
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    queue<pair<int, int>> q1;
    int stx = 0, sty = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j] == 'A')
            {
                stx = i;
                sty = j;
            }
            if (adj[i][j] == 'M')
            {
                dist[i][j] = 0;
                q1.push({i, j});
            }
        }
    }

    while (!q1.empty())
    {
        auto it = q1.front();
        q1.pop();
        int x=it.first;
        int y=it.second;
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && adj[nx][ny] == '.' && dist[nx][ny] > dist[x][y] + 1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q1.push({nx, ny});
            }
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push({stx, sty});
    vector<vector<int>> d2(n, vector<int>(m, 1e9));
    d2[stx][sty] = 0;
    pair<int, int> ans = {-1, -1};

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int x=it.first;
        int y=it.second;
        if (x == 0 || y == 0 || x == n - 1 || y == m - 1)
        {
            if (d2[x][y] < dist[x][y])
            {
                ans = {x, y};
                break;
            }
        }
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && adj[nx][ny] == '.' && d2[nx][ny] == 1e9)
            {
                d2[nx][ny] = d2[x][y] + 1;
                vis[nx][ny] = k;
                q.push({nx, ny});
            }
        }
    }

    if (ans.first == -1)
    {
        cout << "NO";
        return;
    }

    string S = "";
    int x = ans.first, y = ans.second;
    while (!(x == stx && y == sty))
    {
        int k = vis[x][y];
        S.push_back(s[k]);
        x -= dx[k];
        y -= dy[k];
    }
    reverse(S.begin(), S.end());
    cout << "YES" << endl
         << S.size() << endl
         << S << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    while (T--)
        solve();
}
