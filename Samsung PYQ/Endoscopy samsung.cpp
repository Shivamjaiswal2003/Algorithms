#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// Helper functions (unchanged)
bool valid(int x, int y, int row, int col) {
    return (x >= 0 && x < row && y >= 0 && y < col);
}
bool left(int x, int y, const vector<vector<int>>& map) {
    return (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 6 || map[x][y] == 7);
}
bool right(int x, int y, const vector<vector<int>>& map) {
    return (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 4 || map[x][y] == 5);
}
bool up(int x, int y, const vector<vector<int>>& map) {
    return (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 4 || map[x][y] == 7);
}
bool down(int x, int y, const vector<vector<int>>& map) {
    return (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 6 || map[x][y] == 5);
}

void solve() {
    int row, col, X, Y, L;
    cin >> row >> col >> X >> Y >> L;

    vector<vector<int>> map(row, vector<int>(col));
    // Use 'dist' array. 0 means unvisited.
    vector<vector<int>> dist(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> map[i][j];
        }
    }

    if (map[X][Y] == 0) {
        cout << 0 << endl;
        return;
    }

    // Queue now only stores {x, y} coordinates
    queue<pair<int, int>> q;

    // Push the initial state
    q.push({X, Y});
    dist[X][Y] = 1; // Starting position is at distance 1

    while (!q.empty()) {
        // Pop the front element
        pair<int, int> curr = q.front();
        q.pop();

        // Deconstruct the pair
        int cx = curr.first;
        int cy = curr.second;
        int cd = dist[cx][cy]; // Current distance

        // If we are at the max distance, we can't move further
        if (cd == L) continue;

        // Go Left
        int nx = cx;
        int ny = cy - 1;
        // Check pipe connection AND if neighbor is unvisited (dist == 0)
        if (valid(nx, ny, row, col) && left(cx, cy, map) && right(nx, ny, map) && dist[nx][ny] == 0) {
            dist[nx][ny] = cd + 1; // Set new distance
            q.push({nx, ny});
        }
        // Go Right
        nx = cx;
        ny = cy + 1;
        if (valid(nx, ny, row, col) && right(cx, cy, map) && left(nx, ny, map) && dist[nx][ny] == 0) {
            dist[nx][ny] = cd + 1;
            q.push({nx, ny});
        }
        // Go Up
        nx = cx - 1;
        ny = cy;
        if (valid(nx, ny, row, col) && up(cx, cy, map) && down(nx, ny, map) && dist[nx][ny] == 0) {
            dist[nx][ny] = cd + 1;
            q.push({nx, ny});
        }
        // Go Down
        nx = cx + 1;
        ny = cy;
        if (valid(nx, ny, row, col) && down(cx, cy, map) && up(nx, ny, map) && dist[nx][ny] == 0) {
            dist[nx][ny] = cd + 1;
            q.push({nx, ny});
        }
    }

    // Count all cells that were visited
    int ans = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (dist[i][j] > 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}