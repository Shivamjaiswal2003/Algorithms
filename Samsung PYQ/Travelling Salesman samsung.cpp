#include <vector>
#include <iostream>
#include <algorithm>
#include<cstdint>
#include<climits>
using namespace std;


int fun(int mask, int currnode, int &allset, int n, vector<vector<int>> &adj,  vector<vector<int>> &dp){
     
    if(mask==allset){
        return adj[currnode][0];
    }
    
    if(dp[mask][currnode]!=-1) return dp[mask][currnode];

    int ans= INT_MAX;
    
    for(int node=0; node<n; node++){
        if((mask&(1<<node))==0){
             int res= adj[currnode][node]+fun(mask|(1<<node), node, allset, n, adj, dp);
            
            ans=min(ans, res);
        }
    }
    
    return dp[mask][currnode]= ans;
}

void solve(){
    int n; 
    cin>>n;
    
    vector<vector<int>> adj(n, vector<int>(n));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            cin>>adj[i][j];
        }
    }
    

    vector<vector<int>> dp(1<<n, vector<int>(n, -1));

    int allset= (1<<n)-1;
    
    int mask= 1;
    
    int ans= fun(mask, 0, allset, n, adj, dp);
    
    cout<<ans<<endl;
    
}

int main() {
    
    int t;
    cin>>t;
    
    
    while(t--){
        solve();
    }
    return 0;
}
