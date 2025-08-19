#include <bits/stdc++.h>
using namespace std;

// Define type aliases for convenience
typedef long long ll;
typedef tuple<int, int, int> Edge;

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; // n: number of vertices, m: number of edges
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    // --- Bellman-Ford Algorithm ---

    // dist[i] stores the shortest distance from a source to vertex i
    vector<ll> dist(n + 1, 0); 
    // relaxant[i] stores the parent of vertex i in the shortest path tree
    vector<int> relaxant(n + 1, -1); 

    int x = -1; // Will store a node in the negative cycle if one exists

    // The algorithm relaxes edges n times.
    // The first n-1 iterations find shortest paths in a graph with no negative cycles.
    // The nth iteration is used to detect a negative cycle.
    for (int i = 0; i < n; ++i) {
        x = -1; // Reset on each iteration
        for (auto it : edges) {

            int u=get<0>(it);
            int v=get<1>(it);
            int w=get<2>(it);
            // Relaxation step: if a shorter path to v is found via u
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                relaxant[v] = u;
                x = v; // Mark the node that was last relaxed
            }
        }
    }

    // --- Cycle Detection and Output ---

    // If x is still -1 after n iterations, no path was shortened on the nth pass.
    // This means there is no negative cycle.
    if (x == -1) {
        cout << "NO\n";
        return 0;
    }

    // If x is not -1, a negative cycle exists.
    // The node 'x' is either in the cycle or reachable from it.
    // To find a node that is guaranteed to be IN the cycle, we backtrack n times.
    for (int i = 0; i < n; ++i) {
        x = relaxant[x];
    }

    // Now, x is definitely a node within the negative cycle.
    // We trace back from x using the relaxant array until we see x again.
    vector<int> cycle;
    for (int curr = x; ; curr = relaxant[curr]) {
        cycle.push_back(curr);
        if (curr == x && cycle.size() > 1) {
            break;
        }
    }

    // The cycle was constructed by backtracking (v -> u), so we reverse it to get the correct path order.
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (int node : cycle) {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}