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


void dfs(int node, int par, vector<int> adj[], vector<int> &level, int l ,  vector<vector<int>> &dp){
      
    dp[node][0]=par;

    
    for(int bit=1; bit<19; bit++){
            dp[node][bit]=dp[dp[node][bit-1]][bit-1];
    }

    level[node]=l;

    for(auto it: adj[node]){
        if(it==par) continue;

        dfs(it, node, adj, level, l+1, dp);
    }
}

int findkthpar(int node, int k,  vector<vector<int>> &dp){

    for(int bit =18; bit>=0; bit--){
        if((k>>bit)&1){
            node=dp[node][bit];
        }
    }

    return node;
}


int findlca(int a, int b,  vector<vector<int>> &dp){
     if(a==b) return a;

     for(int bit=18; bit>=0; bit--){
        if(dp[a][bit]!=dp[b][bit]){
            a=dp[a][bit];
            b=dp[b][bit];
        }
     }

     return dp[a][0];
}


void solve(){
    
      int n, q;
     cin >> n>>q;
     
     vector<int> adj[n+1];
    
     for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
     }


     vector<int> level(n+1, 0);

     vector<vector<int>> dp(n+1, vector<int>(19, 0));



     dfs(1, 0, adj, level, 0, dp);

 

     while(q--){

        int a, b;
        cin>>a>>b;
        
        if(level[a]>level[b]){
            swap(a, b);
        }

        int diff=level[b]-level[a];
      
        if(diff>0){
            b=findkthpar(b, diff, dp);
        }
        
         
        int lca= findlca(a, b, dp);

        int ans=diff + level[a]-level[lca]+level[b]-level[lca];

        cout<<ans<<endl;
     }
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

    