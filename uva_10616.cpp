#include <bits/stdc++.h>
using namespace std;

#define MAX_N 205
#define MAX_Q 15
#define MAX_D 21
#define MAX_M 15

int N, Q, D, M;
int sets[MAX_N];
int memo[MAX_N][MAX_D][MAX_M];

int dp(int i, int sum, int c) {
    if (c == M) {
        return (sum % D == 0) ? 1 : 0;
    }
    if (i == N) {
        return 0;
    }
    if (memo[i][sum][c] != -1) {
        return memo[i][sum][c];
    }
    
    // Ensure the sum is non-negative
    int new_sum = (sum + sets[i]) % D;
    if (new_sum < 0) {
        new_sum += D;
    }

    memo[i][sum][c] = dp(i + 1, sum % D, c) + dp(i + 1, new_sum, c + 1);
    return memo[i][sum][c];
}

int main() {
    int setCount = 1;
    while (true) {
        cin >> N >> Q;
        if (N == 0 && Q == 0) {
            break;
        }

        for (int i = 0; i < N; i++) {
            cin >> sets[i];
        }

        cout << "SET " << setCount << ":\n";
        for (int q = 0; q < Q; q++) {
            cin >> D >> M;
            memset(memo, -1, sizeof(memo));
            int res = dp(0, 0, 0);
            cout << "QUERY " << q + 1 << ": " << res << "\n";
        }

        setCount++;
    }
    return 0;
}
