#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define srt(v)  sort(v.begin(),v.end())      
#define mxe(v)  *max_element(v.begin(),v.end())     
#define mne(v)  *min_element(v.begin(),v.end())    

using namespace std;
int MOD=1e9+7;     


// ===================================END Of the Life ==========================================



int dfs(int node,  vector<int> adj[], int n,  vector<int> &dp){
    if(node==n){
        return 1;
    }

    if(dp[node]!=-1){
        return dp[node];
    }

    int res=0;

    for(auto it: adj[node]){
       res= (res+ dfs(it, adj, n, dp))%MOD;
    }
    return dp[node]= res;
}

void solve(){
    
    int n, m;
    cin>>n>>m;

    vector<int> adj[n+1];

    while(m--){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

   

    vector<int> dp(n+1, -1);

   int ans= dfs(1, adj, n, dp);

    cout<<ans<<endl;
    
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

    