#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Treasure {
    int depth;
    int gold;
    int time; // time to retrieve this treasure
};

int main() {
    int t, w;
    bool firstCase = true;
    
    while (cin >> t >> w) {
        if (!firstCase) {
            cout << endl;
        }
        firstCase = false;

        int n;
        cin >> n;
        
        vector<Treasure> treasures(n);
        for (int i = 0; i < n; ++i) {
            cin >> treasures[i].depth >> treasures[i].gold;
            treasures[i].time = 3 * w * treasures[i].depth; // Calculate total time to retrieve each treasure
        }
        
        // DP array to store maximum gold that can be collected within given time
        vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
        // To track if a treasure is included in the optimal solution
        vector<vector<bool>> take(n + 1, vector<bool>(t + 1, false));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= t; ++j) {
                if (j >= treasures[i-1].time) {
                    if (dp[i-1][j] < dp[i-1][j - treasures[i-1].time] + treasures[i-1].gold) {
                        dp[i][j] = dp[i-1][j - treasures[i-1].time] + treasures[i-1].gold;
                        take[i][j] = true;
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        int maxGold = dp[n][t];
        int remainingTime = t;
        vector<int> selectedTreasures;
        
        for (int i = n; i > 0; --i) {
            if (take[i][remainingTime]) {
                selectedTreasures.push_back(i-1);
                remainingTime -= treasures[i-1].time;
            }
        }
        
        reverse(selectedTreasures.begin(), selectedTreasures.end());
        
        cout << maxGold << endl;
        cout << selectedTreasures.size() << endl;
        for (int index : selectedTreasures) {
            cout << treasures[index].depth << " " << treasures[index].gold << endl;
        }
    }
    return 0;
}
