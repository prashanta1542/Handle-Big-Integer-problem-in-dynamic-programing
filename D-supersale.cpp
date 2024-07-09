#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int knapsack(int maxweight, vector<pair<int,int>> &items){
    
    vector<int>dp(maxweight+1, 0);
    
    for( auto item : items){
        int price = item.first;
        int weight = item.second;
        for(int w=maxweight;w>=weight;w--){
            dp[w]=max(dp[w],dp[w-weight]+price);
        }
    }
    return dp[maxweight];
}

int main(){
    
    int T;
    cin>>T;
    
    while(T--){
        int m;
        cin>>m;
        vector<pair<int,int>>items(m);
        for(int i=0;i<m;i++){
            int price,weight;
            cin>>price>>weight;
            items[i]={price,weight};
        }
        int totalvalue=0;
        int G;
        cin>>G;
        for(int i=0;i<G;i++){
            int maxweight;
            cin>>maxweight;
            totalvalue += knapsack(maxweight,items);
        }
        cout<<"Total value : "<<totalvalue<<endl;
    }
    
    
    return 0;
}
