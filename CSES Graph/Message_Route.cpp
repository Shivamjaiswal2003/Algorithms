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





void solve(){
     
   int n, m;
    cin>>n>>m;

    vector<int> adj[n+1];

    while(m--){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int> par(n+1, 0);
    vector<int> vis(n+1, 0);


    queue<int> q;
    q.push(1); 
    vis[1]=1;

    vector<int> ans;

    while(!q.empty()){
        auto node=q.front();
        q.pop();
        
        if(node==n){
              while(node!=0){
                ans.push_back(node);
                node=par[node];
              }
              break;
        }

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
                par[it]=node;
            }
        }
    }

    if(par[n]==0){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    reverse(ans.begin(), ans.end());

    cout<<ans.size()<<endl;
    for(auto it: ans){
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

    