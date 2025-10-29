#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <map> // Although vector indexing is simpler

using namespace std;

// Define a pair for Dijkstra: {cost, node_id}
// Using pair<int, int> so the priority queue sorts by cost
using pii = pair<int, int>;

/**
 * @brief Calculates the Manhattan distance between two points.
 */
int manhattan_dist(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void solve() {
    int N;
    cin >> N;

    int startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;

    // Total nodes = 2 (S/D) + 2*N (Wormhole ends)
    int total_nodes = 2 * N + 2;

    // coords[i] = {x, y} coordinates for node i
    vector<pair<int, int>> coords(total_nodes);
    coords[0] = {startX, startY};
    coords[1] = {endX, endY};

    // Store wormhole data to process after coordinates are all in
    vector<tuple<int, int, int>> wormholes;

    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2, cost;
        cin >> x1 >> y1 >> x2 >> y2 >> cost;
        
        // Node IDs for this wormhole
        int node_u = 2 * i + 2;
        int node_v = 2 * i + 3;

        coords[node_u] = {x1, y1};
        coords[node_v] = {x2, y2};
        
        // Store the wormhole info (node1, node2, cost)
        wormholes.emplace_back(node_u, node_v, cost);
    }

    // --- Build Adjacency Matrix ---
    // adj[i][j] = min cost to go from node i to node j
    vector<vector<int>> adj(total_nodes, vector<int>(total_nodes));

    // Step 1: Fill with Manhattan distances (normal travel)
    for (int i = 0; i < total_nodes; ++i) {
        for (int j = 0; j < total_nodes; ++j) {
            adj[i][j] = manhattan_dist(coords[i], coords[j]);
        }
    }

    // Step 2: Add wormhole edges (cheaper travel)
    for (const auto& w : wormholes) {
        int u, v, cost;
        tie(u, v, cost) = w;
        
        // Cost from u -> v
        adj[u][v] = min(adj[u][v], cost);
        // Cost from v -> u
        adj[v][u] = min(adj[v][u], cost);
    }

    // --- Run Dijkstra's Algorithm ---
    
    // dist[i] = min cost from Source (Node 0) to node i
    vector<int> dist(total_nodes, INT_MAX);
    
    // Min-priority queue: {cost, node}
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Start at the Source (Node 0)
    dist[0] = 0;
    pq.push({0, 0}); // {cost=0, node=0}

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If this is an old, worse path, skip it
        if (d > dist[u]) {
            continue;
        }

        // If we reached the destination, we can stop
        if (u == 1) {
            break;
        }

        // Check all neighbors
        for (int v = 0; v < total_nodes; ++v) {
            // new_dist = cost to reach u + cost from u to v
            int new_dist = d + adj[u][v];

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    // The answer is the shortest distance to the Destination (Node 1)
    cout << dist[1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}