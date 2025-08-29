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


void dfs(int node,  vector<pair<int, int>> adj[], vector<int> &seen, vector<int> &path){
    

    while(!adj[node].empty()){
        auto it=adj[node].back();
        adj[node].pop_back();
        int adjnode=it.first;

        int edgeind=it.second;
        if(seen[edgeind]){
            continue;
        }
        seen[edgeind]=1;
        dfs(adjnode, adj, seen, path);

    }

    path.push_back(node);
}


void solve(){
    
    int n, m;
    cin>>n>>m;

    vector<pair<int, int>> adj[n+1];
    vector<int>degree(n+1, 0);

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        degree[u]++;
        degree[v]++;
    }

    vector<int> seen(m+1, 0);

    vector<int> path;
   
   for(int i=1; i<=n; i++){
    if(degree[i]%2!=0){
         cout<<"IMPOSSIBLE"<<endl;
         return;
    }
   }

   dfs(1, adj, seen, path);

   if(path.size()!=m+1){
    cout<<"IMPOSSIBLE"<<endl;
    return;
   }

   for(auto it: path){
   cout<<it<<" ";
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

    