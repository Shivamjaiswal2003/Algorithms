#include "bits/stdc++.h"
#define int long long
// ... your other macros are fine ...

using namespace std;
int MOD=1e9+7;

int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
string s= "DRUL";

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char> (m));
    int i1, j1;
    int i2, j2;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
            if(v[i][j]=='A'){ i1=i; j1=j; }
            if(v[i][j]=='B'){ i2=i; j2=j; }
        }
    }

    // <-- CHANGED: The queue is now much simpler and only holds coordinates.
    queue<pair<int, int>> q;
    
    // <-- CHANGED: This grid will store the move (0..3) used to reach each cell.
    vector<vector<int>> predecessor_move(n, vector<int>(m, -1));

    q.push({i1, j1});
    v[i1][j1] = '#'; // Mark start as visited so we don't return to it.
    
    bool found = false;

    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        int i = curr.first;
        int j = curr.second;

        if(i == i2 && j == j2){
            found = true;
            break; // Found the destination, exit the BFS loop
        }

        for(int x=0; x<4; x++){
            int nr = i+dx[x];
            int nc = j+dy[x];
            
            // The check is simpler now, we just need to see if it's a valid, unvisited cell.
            if(nr<n && nr>=0 && nc<m && nc>=0 && v[nr][nc]!='#'){
                v[nr][nc] = '#'; // Mark as visited immediately
                predecessor_move[nr][nc] = x; // <-- CHANGED: Store the move
                q.push({nr, nc}); // <-- CHANGED: Push only coordinates
            }
        }
    }

    // <-- CHANGED: The result printing logic is now separate.
    if(found){
        cout << "YES" << endl;
        string path = "";
        pair<int, int> curr = {i2, j2};

        // Backtrack from B to A
        while(curr.first != i1 || curr.second != j1) {
            int move_idx = predecessor_move[curr.first][curr.second];
            path += s[move_idx];
            // Move to the previous cell by reversing the move
            curr.first -= dx[move_idx];
            curr.second -= dy[move_idx];
        }
        reverse(path.begin(), path.end()); // The path is built backwards, so reverse it.
        cout << path.length() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}