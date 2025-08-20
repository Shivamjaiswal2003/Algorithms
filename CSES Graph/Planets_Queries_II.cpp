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
int MOD=1e9+7;     


// ===================================END Of the Life ==========================================



const int MAX_HEIGHT = 20; // Enough for 2^20 jumps (1 million nodes)
vector<vector<int>> binaryLifting; // binaryLifting[node][k] = 2^k-th ancestor
vector<int> arr; // The input graph (arr[i] is where planet i teleports to)
vector<int> len; // len[node] = distance to the cycle's entry point
vector<bool> visited; // Track visited nodes for DFS

// Depth-first search to build binary lifting table and calculate lengths
void dfs(int node) {
    if (visited[node]) return;
    visited[node] = true;
    
    // First process the parent
    dfs(arr[node]);
    
    // Set the immediate parent (2^0 ancestor)
    binaryLifting[node][0] = arr[node];
    
    // Length is parent's length + 1
    len[node] = len[binaryLifting[node][0]] + 1;
    
    // Build binary lifting table for higher powers
    for (int level = 1; level < MAX_HEIGHT; level++) {
        binaryLifting[node][level] = binaryLifting[binaryLifting[node][level-1]][level-1];
    }
}

// Jump 'dist' steps from node 'a'
int jump(int a, int dist) {
    if (dist < 0) return -1;
    
    // Use binary representation of dist to make jumps
    for (int level = 0; dist > 0; level++, dist >>= 1) {
        if (dist & 1) {
            a = binaryLifting[a][level];
        }
    }
    return a;
}


void solve(){
    
     int n, q;
    cin >> n >> q;
    
    // Initialize data structures
    arr.resize(n + 1);
    binaryLifting.assign(n + 1, vector<int>(MAX_HEIGHT));
    len.assign(n + 1, 0);
    visited.assign(n + 1, false);

    // Read input graph
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // Process each unvisited node
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Process queries
 
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        
        // Find the cycle entry point for a (end of its path)
        int cycle_entry_a = jump(a, len[a]);
        
        int answer;
        // Case 1: b is on a's path to the cycle
        if (jump(a, len[a] - len[b]) == b) {
            answer = len[a] - len[b];
        } 
        // Case 2: b is on the cycle and reachable from a's cycle entry
        else if (jump(cycle_entry_a, len[cycle_entry_a] - len[b]) == b) {
            answer = (len[cycle_entry_a] - len[b]) + len[a];
        }
        // Case 3: b is not reachable
        else {
            answer = -1;
        }
        
        cout << answer << "\n";
    }

  
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

    

















