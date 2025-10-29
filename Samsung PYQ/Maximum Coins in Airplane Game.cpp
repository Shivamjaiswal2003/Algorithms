#include <bits/stdc++.h>
using namespace std;

int N;
vector<array<int,5>> grid; // rows 0..N-1, each with 5 cols
// memo[step][col][bombIdx] where bombIdx = 0 => not used, 1..N => used at time (bombIdx-1)
vector<vector<vector<int>>> memo;
int INF_NEG = -1000000000;

// helper: does bomb used at time 'bt' (0-based) clear row r ?
bool bomb_clears_row(int bt, int r, int N) {
    if (bt < 0) return false;
    int top = N - 1 - bt;        // first row cleared
    int bottom = N - 5 - bt;     // last row cleared (may be negative)
    // cleared range is [bottom, top], but bottom might be < 0
    bottom = max(bottom, 0);
    return (r >= bottom && r <= top);
}

int dfs(int step, int col, int bombIdx) {
    if (step >= N) return 0; // no more rows
    
    int &res = memo[step][col][bombIdx];
    if (res != INT_MIN) return res;
    res = INT_MIN/4;
    
    int r = N - 1 - step; // row that will arrive this step

    // 3 possible moves
    for (int dx = -1; dx <= 1; ++dx) {
        int nc = col + dx;
        if (nc < 0 || nc > 4) continue;

        // Option A: do NOT use bomb now
        {
            bool cleared = false;
            if (bombIdx != 0) {
                int bt = bombIdx - 1;
                if (bomb_clears_row(bt, r, N)) cleared = true;
            }
            int cell = grid[r][nc];
            if (cell == 2 && !cleared) {
                // hits enemy -> game ends immediately; get 0 for future
                res = max(res, 0);
            } else {
                int gain = (cell == 1) ? 1 : 0;
                int future = dfs(step + 1, nc, bombIdx);
                res = max(res, gain + future);
            }
        }

        // Option B: if bomb not used yet, use it now (bombIdx == 0)
        if (bombIdx == 0) {
            int newBombIdx = step + 1; // represent used at time step (0-based) by storing +1
            bool cleared = false;
            int bt = newBombIdx - 1;
            if (bomb_clears_row(bt, r, N)) cleared = true;
            int cell = grid[r][nc];
            if (cell == 2 && !cleared) {
                // Even after using bomb at this time, if the row r isn't in bomb's cleared range,
                // we hit enemy and end immediately.
                res = max(res, 0);
            } else {
                int gain = (cell == 1) ? 1 : 0;
                int future = dfs(step + 1, nc, newBombIdx);
                res = max(res, gain + future);
            }
        }
    }

    return res;
}

int solve_case() {
    memo.assign(N+1, vector<vector<int>>(5, vector<int>(N+1, INT_MIN)));
    // initial position: spaceship center column = 2, step = 0, bombIdx = 0 (unused)
    return dfs(0, 2, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    for (int caseNo = 1; caseNo <= t; ++caseNo) {
        cin >> N;
        grid.assign(N, {0,0,0,0,0});
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < 5; ++j) {
                int x; cin >> x;
                grid[i][j] = x;
            }
        }
        int ans = solve_case();
        cout << "#" << caseNo << " " << ans << "\n";
    }
    return 0;
}
