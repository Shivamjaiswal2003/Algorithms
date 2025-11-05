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


void dfs(int node, int par, vector<int> adj[], vector<int> &height){

    for(auto it: adj[node]){
        if(it==par) continue;
        dfs(it, node, adj, height);
        height[node]=max(height[node], 1+height[it]);
    }
}


void dfs1(int node, int par, vector<int> adj[],  vector<int> &out, vector<int> &height){

    int mx1=-1; int mx2=-1; int mx=-1;

    for(auto it: adj[node]){

        if(it==par) continue;

        if(height[it]>mx1){
            mx2=mx1;
            mx1=height[it];
        }else{
            if(height[it]>mx2){
                mx2=height[it];
            }
        }
    }

    for(auto it: adj[node]){
        if(it==par) continue;

        mx=mx1;

        if(height[it]==mx1){
            mx=mx2;
        }

        out[it]= max(1+out[node], 2+mx);
        dfs1(it, node, adj, out, height);
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

     vector<int> height(n+1, 0);

     dfs(1, -1, adj, height);

     vector<int> out(n+1, 0);

   dfs1(1, -1, adj, out, height);

    

   for(int i=1; i<=n; i++){
    cout<<max(out[i], height[i])<<" ";
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

    