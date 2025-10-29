#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> // for std::max

// As requested by the user
using namespace std;

int main() {
    // 1. Read n, m, k
    int n, m, k;
    cin >> n >> m >> k;

    // 2. Use a map to store row patterns and their frequencies
    map<string, int> mp;

    // 3. Read all n rows
    for (int i = 0; i < n; ++i) {
        string current_row = "";
        for (int j = 0; j < m; ++j) {
            char bit;
            // This will read the character '1' or '0', skipping any spaces
            cin >> bit; 
            current_row += bit;
        }
        // Increment the count for this row pattern
        mp[current_row]++;
    }

    // 4. Initialize max_rows
    int max_rows = 0;

    // 5. Iterate through each (key, value) pair in the map
    // 'pair' will be like {"100", 2}
    for (auto it : mp) {
        string row_pattern = it.first;
        int frequency = it.second;

        // 6. Count the number of '0's in the pattern
        int zero_count = 0;
        for (char c : row_pattern) {
            if (c == '0') {
                zero_count++;
            }
        }

        // 7. Check our deciding condition
        // Can we flip all '0's and waste the remaining toggles?
        if (zero_count <= k && (k - zero_count) % 2 == 0) {
            // If yes, this is a valid candidate.
            // Update our max with the frequency of this valid row.
            max_rows = max(max_rows, frequency);
        }
    }

    // 8. Print the final answer
    cout << max_rows << endl;

    return 0;
}