#include <iostream>
#include <vector>
using namespace std;

const int N = 1000;

vector<int> dp[N];

vector<int> add(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int carry = 0, sum = 0;
    int size_a = a.size(), size_b = b.size();
    int max_size = max(size_a, size_b);
    
    for (int i = 0; i < max_size || carry; ++i) {
        sum = carry;
        if (i < size_a) sum += a[i];
        if (i < size_b) sum += b[i];
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    
    return result;
}

vector<int> fib(int n) {
    if (n == 0) return {0};
    if (n == 1) return {1};
    
    if (!dp[n].empty()) {
        return dp[n];
    }
    
    dp[n] = add(fib(n - 2), fib(n - 1));
    return dp[n];
}

void print_fib(const vector<int>& num) {
    for (int i = num.size() - 1; i >= 0; --i) {
        cout << num[i];
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    
    if (n >= N) {
        cout << "Please enter a number less than " << N << endl;
        return 1;
    }
    
    print_fib(fib(n));
    
    return 0;
}
