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


    vector<pair<int, int>> adj[n+1];

    for(int i=0; i<m; i++){
        int u, v, t;
        cin>>u>>v>>t;

        adj[u].push_back({v, t});
    }


    vector<vector<int>> dist(n+1, vector<int>(2, 1e18));

    dist[1][0]=0;
    dist[1][1]=0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    //{dist, {node, state}}

    pq.push({0, {1, 0}});
    pq.push({0, {1, 1}});
    

    while(!pq.empty()){
        auto it= pq.top();
        pq.pop();

        int distance= it.first;
        int node= it.second.first;
        int state= it.second.second;
      
        if(dist[node][state]<distance){
            continue;
        }


        if(state==0){
            for(auto it1: adj[node]){
                 int adjnode= it1.first;
                 int wt= it1.second;

                 if(dist[adjnode][0]>dist[node][0]+wt){
                    dist[adjnode][0]=dist[node][0]+wt;
                    pq.push({dist[adjnode][0], {adjnode, 0}});
                 }

                 if(dist[adjnode][1]>dist[node][0]+(wt/2)){
                    dist[adjnode][1]=dist[node][0]+(wt/2);
                    pq.push({dist[adjnode][1], {adjnode, 1}});
                 }
            }
        }else{
            for(auto it1: adj[node]){
                 int adjnode= it1.first;
                 int wt= it1.second;

                 if(dist[adjnode][1]>dist[node][1]+wt){
                    dist[adjnode][1]=dist[node][1]+wt;
                    pq.push({dist[adjnode][1], {adjnode, 1}});
                 }
             
            }
        }
    }

    cout<<dist[n][1]<<endl;
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

    