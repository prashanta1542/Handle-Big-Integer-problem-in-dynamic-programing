#include <bits/stdc++.h>
using namespace std;

int MAXN=1121;
int MAXK=15;
vector<int>primes;

int check_prime(int n){
    int flag = 1;
    if(n==0 || n==1 ){
        return 0;
    }
    if(n==2){
        return 1;
    }
    
    for(int i=2;i<n;i++){
        if(n%i == 0){
            flag = 0;
            break;
        }
    }
    if(flag){
        return 1;
    }
    else{
        return 0;
    }
}
void prime_num(){
    vector<bool>is_prime(MAXN,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=0;i<MAXN;i++){
        
        if(check_prime(i)){
            primes.push_back(i);
        }
    }
}
int count_ways(int n,int k){
    int dp[MAXN][MAXK];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int prime : primes){
        for(int current_sum=n;current_sum >= prime ; --current_sum){
            for(int current_k=1;current_k <= k; ++current_k){
                dp[current_sum][current_k] += dp[current_sum-prime][current_k-1];
            }
        }
    }
    return dp[n][k];
}
int main() {
    
    prime_num();
     while(true){
         int n,k;
         cin>>n>>k;
         if(n == 0 && k == 0) break;
         cout << count_ways(n,k)<<endl;
     }
    return 0;
}
