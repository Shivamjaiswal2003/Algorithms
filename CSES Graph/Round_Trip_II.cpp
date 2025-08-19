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


int cyclestart=-1;
int cycleend=-1;

bool dfs(int node, vector<int> adj[],  vector<int> &vis,  vector<int> &pathvis,   vector<int> &par){
    vis[node]=1;
    pathvis[node]=1;

    for(auto it: adj[node]){

        par[it]=node;
        if(!vis[it] ){
        
            if(dfs(it, adj, vis, pathvis, par)){
                return true;
            }
           
        }else{
             if(pathvis[it]){
                    cycleend=node;
                    cyclestart=it;
                    return true;
             }
            
        }
    }

    pathvis[node]=0;
    return false;
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

    vector<int> vis(n+1, 0);
    vector<int> pathvis(n+1, 0);

    vector<int> par(n+1, 0);


    for(int i=0; i<=n; i++){

        if(!vis[i]){
            if(dfs(i, adj, vis, pathvis, par)){
                break;
            }
        }
    }

    if(cyclestart==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    vector<int> ans;
    ans.push_back(cyclestart);

    int curr=cycleend;

    while(curr!=cyclestart){
        ans.push_back(curr);
        curr=par[curr];
    }

    ans.push_back(cyclestart);

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

    