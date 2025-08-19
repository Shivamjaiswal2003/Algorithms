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


void toposort(int node,  vector<int> adj[], vector<int> &vis,  stack<int> &st){

    vis[node]=1;

    for(auto it: adj[node]){
            if(!vis[it]){
                toposort(it, adj, vis, st);
            }
    }
    st.push(node);
}


void solve(){
 
    int n, m;
    cin >> n>>m;
    
    vector<int> adj[n+1];

    while(m--){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
    }


    stack<int> st;

    vector<int> vis(n+1, 0);

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            toposort(i, adj, vis, st);
        }
    }

    vector<int> dist(n+1, -1);
    dist[1]=0;

    vector<int> par(n+1, -1);
    par[1]=1;

    while(!st.empty()){
        auto it= st.top();
        st.pop();

        // cout<<it<<endl;

        for(auto it1: adj[it]){
            if(dist[it]!=-1 && dist[it1]<dist[it]+1){
                dist[it1]=dist[it]+1;
                par[it1]=it;
            }
        }
    }


    if(dist[n]==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    vector<int> ans;

    int node=n;
    while(node!=1){
        ans.push_back(node);
        node=par[node];
    }
    ans.push_back(1);

    cout<<ans.size()<<endl;
    for(int i=ans.size()-1; i>=0; i--){
        cout<<ans[i]<<" ";
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

    