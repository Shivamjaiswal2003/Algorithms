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



void dfs(int node, vector<int> &vis ,  vector<int> adj[]){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj);
        }
    }
}

void solve(){
    
    int n, m;
    cin>>n>>m;

    vector<int> adj[n+1];

    for(int i=0; i<m; i++){
        
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }  

    vector<int>vis(n+1, 0);


    vector<int> ans;
    for(int i=1; i<=n; i++){

        if(!vis[i]){
            ans.push_back(i);
            dfs(i, vis, adj);
        }

    }

    cout<<ans.size()-1<<endl;
    for(int i=0; i<ans.size()-1; i++){
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
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

    