#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <numeric>

using namespace std;

int get_dist(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int fun(int mask, int currnode, int &customer_mask, int total_nodes,
        vector<vector<int>> &adj, vector<vector<int>> &dp) {

    if ((mask & customer_mask) == customer_mask) {
        return adj[currnode][1];
    }

    if (dp[mask][currnode] != -1) return dp[mask][currnode];

    int ans = INT_MAX;

    for (int next_customer = 2; next_customer < total_nodes; next_customer++) {
        if ((mask & (1 << next_customer)) == 0) {
            
            int res = adj[currnode][next_customer] +
                      fun(mask | (1 << next_customer), next_customer,
                          customer_mask, total_nodes, adj, dp);

            ans = min(ans, res);
        }
    }

    return dp[mask][currnode] = ans;
}

void solve(int test_case_num) {
    int N;
    cin >> N;

    int total_nodes = N + 2;

    vector<pair<int, int>> locations(total_nodes);
    for (int i = 0; i < total_nodes; ++i) {
        cin >> locations[i].first >> locations[i].second;
    }

    vector<vector<int>> adj(total_nodes, vector<int>(total_nodes));
    for (int i = 0; i < total_nodes; ++i) {
        for (int j = 0; j < total_nodes; ++j) {
            adj[i][j] = get_dist(locations[i], locations[j]);
        }
    }

    vector<vector<int>> dp(1 << total_nodes, vector<int>(total_nodes, -1));

    int customer_mask = 0;
    for (int i = 2; i < total_nodes; i++) {
        customer_mask |= (1 << i);
    }

    int initial_mask = (1 << 0);
    
    int ans = fun(initial_mask, 0, customer_mask, total_nodes, adj, dp);

    cout << "# " << test_case_num << " " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int t = 1; t <= 10; ++t) {
        solve(t);
    }
    return 0;
}
