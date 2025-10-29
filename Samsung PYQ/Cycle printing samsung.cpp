#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> visited;
vector<int> path;
vector<vector<int>> cycles;

// Backtracking DFS to find all simple cycles that start & end at `start`
// We only visit nodes with id >= start to ensure each cycle is found once
void dfs_cycle(int start, int u) {
    for (int v : adj[u]) {
        if (v == start) {
            if (!path.empty()) {
                // record cycle nodes: start + path
                vector<int> cycle;
                cycle.push_back(start);
                for (int x : path) cycle.push_back(x);
                // Make them unique & sorted as we want set of nodes
                sort(cycle.begin(), cycle.end());
                cycle.erase(unique(cycle.begin(), cycle.end()), cycle.end());
                cycles.push_back(cycle);
            }
        } else if (!visited[v] && v > start) {
            visited[v] = 1;
            path.push_back(v);
            dfs_cycle(start, v);
            path.pop_back();
            visited[v] = 0;
        }
    }
}

// comparator placed explicitly (outside sort call)
bool comp_cycles(const vector<int>& a, const vector<int>& b) {
    int suma = accumulate(a.begin(), a.end(), 0);
    int sumb = accumulate(b.begin(), b.end(), 0);
    if (suma != sumb) return suma < sumb;
    return a < b; // lexicographical tie-break
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    if (!(cin >> N >> M)) return 0;
    adj.assign(N + 1, {});
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        if (u >= 1 && u <= N && v >= 1 && v <= N)
            adj[u].push_back(v);
    }

    // It's helpful to have deterministic neighbor order
    for (int i = 1; i <= N; ++i) sort(adj[i].begin(), adj[i].end());

    visited.assign(N + 1, 0);

    // For each possible starting node s, find cycles whose minimum node is s
    for (int s = 1; s <= N; ++s) {
        // mark start as visited
        visited[s] = 1;
        path.clear();
        dfs_cycle(s, s);
        visited[s] = 0;
    }

    if (cycles.empty()) {
        // If spec expects something else, change accordingly
        cout << "\n";
        return 0;
    }

    // Choose best cycle by sum, then lexicographically
    sort(cycles.begin(), cycles.end(), comp_cycles);

    vector<int> ans = cycles.front();
    sort(ans.begin(), ans.end()); // print in ascending order

    for (size_t i = 0; i < ans.size(); ++i) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}
