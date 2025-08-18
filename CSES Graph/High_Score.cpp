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
    
    vector<pair<int, pair<int, int>>> adj;
    vector<pair<int, int>> adjlist[n+1];

    int f=0;

    while(m--){
        int u, v, w;
        cin>>u>>v>>w;

        if(n==1  && u==1 && v==1 && w>0){
            cout<<-1<<endl;
            return;
        }

        adj.push_back({u, {v, w}});
        adjlist[u].push_back({v, w});
    }

   

    vector<int> dist(n+1, -1e17);

    dist[1]=0;

    for(int i=0; i<n-1; i++){

        for(auto it: adj){
            int u=it.first;
            int v=it.second.first;
            int w=it.second.second;

            if(dist[u]!=1e17 && dist[u]+w>dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }


    set<int> cyclenode;

     for(auto it: adj){
            int u=it.first;
            int v=it.second.first;
            int w=it.second.second;

            if(dist[u]!=1e17 && dist[u]+w>dist[v]){
                dist[v]=dist[u]+w;
                cyclenode.insert(v);
            }
        }


    queue<int> cycle;
    queue<int> q;
    q.push(1);

    vector<int> vis(n+1, 0);
    vis[1]=1;

    while(!q.empty()){
        int node= q.front();
        q.pop();
         
       for(auto it: adjlist[node]){
        if(vis[it.first]){
            continue;
        }
        if(cyclenode.count(it.first)){
            cycle.push(it.first);
        }
        vis[it.first]=1;
        q.push(it.first);
       }
       
    }


    vis.assign(n+1, 0);



    while(!cycle.empty()){
        int node= cycle.front();
        cycle.pop();
       vis[node]=1;
        if(node==n){
            cout<<-1<<endl;
            return;
        }

        for(auto it: adjlist[node]){
            if(!vis[it.first]){
                cycle.push(it.first);
            }
        }
    }
    

    cout<<dist[n]<<endl;
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

    