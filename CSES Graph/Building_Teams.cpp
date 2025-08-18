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

bool check(int start,  vector<int> adj[],  queue<int> q,   vector<int> &color){

    q.push(start);
    color[start]=0;

    while(!q.empty()){

        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(color[it]==-1){
                color[it] = !color[node];
                q.push(it);
            }else{

                if(color[it]== color[node])return false;
            }
        }
    }
    return true;
}



void solve(){
    int n, m;
    cin>>n>>m;

    vector<int> adj[n+1];

    while(m--){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int> color(n+1, -1);

    queue<int> q;
  
    for(int i=1; i<=n; i++){
        if(color[i]==-1){
              if(!check(i, adj, q, color)){
                    cout<<"IMPOSSIBLE"<<endl;
                    return;
               }
        }
    }

        for(int i=1; i<=n; i++){
            cout<<color[i]+1<<" ";
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

    