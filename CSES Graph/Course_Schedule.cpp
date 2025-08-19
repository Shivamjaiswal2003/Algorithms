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


bool dfs(int node,  vector<int> adj[], vector<int> &vis, vector<int> &pathvis, stack<int> &st ){
    vis[node]=1;
    pathvis[node]=1;

    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfs(it, adj, vis, pathvis, st)){
                return true;
            }
        }else{
            if(pathvis[it]){
                 return true;
            }
        }
    }

    pathvis[node]=0;
    st.push(node);
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

    stack<int> st;

    vector<int> vis(n+1, 0);
    vector<int> pathvis(n+1, 0);


    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(dfs(i, adj, vis, pathvis, st)){
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
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

    