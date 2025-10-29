#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

// Global variables to store problem state
int N; // Total fishing spots
int min_total_cost = INT_MAX;
vector<bool> occupied;
vector<int> gate_pos(3);
vector<int> gate_men(3);
vector<int> original_men(3); // To reset men count for each permutation

// Helper function to find the nearest vacant spot to the left
// Returns -1 if no spot is found
int findLeft(int pos) {
    for (int i = pos; i >= 1; --i) {
        if (!occupied[i]) return i;
    }
    return -1; 
}

// Helper function to find the nearest vacant spot to the right
// Returns -1 if no spot is found
int findRight(int pos) {
    for (int i = pos; i <= N; ++i) {
        if (!occupied[i]) return i;
    }
    return -1; 
}

/**
 * @brief The core recursive backtracking function.
 * @param order The current permutation of gate indices (e.g., {0, 1, 2})
 * @param gate_idx The index *within the order vector* we are currently processing (0, 1, or 2)
 * @param current_cost The total cost accumulated so far for this permutation
 */
void solve(const vector<int>& order, int gate_idx, int current_cost) {
    
  
    if (current_cost >= min_total_cost) {
        return;
    }

    if (gate_idx == 3) {
        min_total_cost = min(min_total_cost, current_cost);
        return;
    }

    int gate_id = order[gate_idx];

    if (gate_men[gate_id] == 0) {
      
        solve(order, gate_idx + 1, current_cost);
        return;
    }

 
    int pos = gate_pos[gate_id];

    // 1. Find nearest left and right spots and their costs
    int l_spot = findLeft(pos);
    int r_spot = findRight(pos);

    // Calculate costs (1 + distance). Use INT_MAX if no spot is found.
    int cost_l = (l_spot != -1) ? (1 + abs(pos - l_spot)) : INT_MAX;
    int cost_r = (r_spot != -1) ? (1 + abs(pos - r_spot)) : INT_MAX;

    // 2. Make decisions
    
    // Case 1: Left is cheaper (or right doesn't exist)
    if (cost_l < cost_r) {
        occupied[l_spot] = true;
        gate_men[gate_id]--; // One less man at this gate
        
        solve(order, gate_idx, current_cost + cost_l);
        
        // Backtrack: undo the choice
        gate_men[gate_id]++;
        occupied[l_spot] = false;
    }
    // Case 2: Right is cheaper (or left doesn't exist)
    else if (cost_r < cost_l) {
        occupied[r_spot] = true;
        gate_men[gate_id]--;
        
        solve(order, gate_idx, current_cost + cost_r);
        
        // Backtrack
        gate_men[gate_id]++;
        occupied[r_spot] = false;
    }
    // Case 3: Costs are equal (and at least one valid spot exists)
    // This is the tie-breaker: we must explore BOTH paths.
    else if (cost_l != INT_MAX) {
        
        // Path 1: Recurse by choosing LEFT
        occupied[l_spot] = true;
        gate_men[gate_id]--;
        
        solve(order, gate_idx, current_cost + cost_l);
        
        // Backtrack from Path 1
        gate_men[gate_id]++;
        occupied[l_spot] = false;

        // Path 2: Recurse by choosing RIGHT
        occupied[r_spot] = true;
        gate_men[gate_id]--;
        
        solve(order, gate_idx, current_cost + cost_r);
        
        // Backtrack from Path 2
        gate_men[gate_id]++;
        occupied[r_spot] = false;
    }
   
}

int main() {
    cin >> N;

    occupied.resize(N + 1, false);
    

    for (int i = 0; i < 3; ++i) {
        cin >> gate_pos[i];
    }

     for (int i = 0; i < 3; ++i) {
        cin >> gate_men[i];
        original_men[i] = gate_men[i]; // Store original count
    }
 
    vector<vector<int>> all_orders = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 0, 2},
        {1, 2, 0},
        {2, 0, 1},
        {2, 1, 0}
    };


    for (const auto& order : all_orders) {
        
    
        fill(occupied.begin(), occupied.end(), false);

        for (int i = 0; i < 3; ++i) {
            gate_men[i] = original_men[i];
        }

        solve(order, 0, 0);
    }

    cout << min_total_cost << endl;

    return 0;
}