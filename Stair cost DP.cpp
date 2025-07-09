#include <bits/stdc++.h>
using namespace std;

vector<int> dp(10000,0);

int mincost(const vector<int>& c, int ind){
    if(ind==0 or ind==1) return c[ind];
    return min(dp[ind-1],dp[ind-2])+c[ind];
}

int main(){
    int n;
    cin>>n;
    vector <int> cost(n+1,0);
    cin>>cost[0]>>cost[1];
    dp[0]=cost[0];
    dp[1]=cost[1];
    for(int i=2;i<n;i++){
        cin>>cost[i];
        dp[i]=mincost(cost, i);
    }
    dp[n]=mincost(cost, n);
    cout<<dp[n];
    return 0;
}
