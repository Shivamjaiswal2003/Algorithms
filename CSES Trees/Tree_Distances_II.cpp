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


void dfs(int node, int par, vector<int> adj[], vector<int> &level, vector<int> &childcnt, int l){
    
    level[node]=l;
    int cnt=0;
    for(auto it: adj[node]){
        if(it==par) continue;
        dfs(it, node, adj, level, childcnt, l+1);
      cnt+=childcnt[it];
        
    }

    childcnt[node]= 1 + cnt;
}



void dfs1(int node, int par,  int n, vector<int> adj[],  vector<int> &childcnt, vector<int> &ans){
     
    int remaining=n-childcnt[node];

      ans[node]=ans[par]-childcnt[node]+remaining;

      for(auto it: adj[node]){

        if(it==par) continue;

        dfs1(it, node, n, adj, childcnt, ans);
      }
}


void solve(){
  
     int n;
     cin >> n;
     
     vector<int> adj[n+1];
    
     for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
     }

     vector<int> level(n+1, 0);


     vector<int> childcnt(n+1, 0);


      dfs(1, -1, adj, level, childcnt, 0);

      vector<int> ans(n+1, 0);

      for(auto it: level){
        ans[1]+=it;
      }

      for(auto it: adj[1]){
        dfs1(it, 1, n, adj, childcnt, ans);
      }

    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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

    