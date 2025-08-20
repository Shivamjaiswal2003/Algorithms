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

     while(m--){
        int u, v, w;
        cin>>u>>v>>w;

        adj[u].push_back({v, w});
     }


     vector<int> dist(n+1, 1e18);
     dist[1]=0;

     vector<int> paths(n+1, 0);
     paths[1]=1;

     vector<int> minflights(n+1, 1e18);
     minflights[1]=0;

     vector<int> maxflights(n+1, 0);
  

     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
     pq.push({0, 1});

     while(!pq.empty()){
               
        auto it= pq.top();
        pq.pop();

        int node= it.second;
        int distance= it.first;

        if(distance>dist[node]) continue;

        for(auto it1: adj[node]){
            int adjnode= it1.first;
            int adjwt= it1.second;

            if(dist[node]+adjwt<dist[adjnode]){
                dist[adjnode]=dist[node]+adjwt;
                paths[adjnode]=paths[node];
                minflights[adjnode]=minflights[node]+1;
                maxflights[adjnode]=maxflights[node]+1;
                pq.push({dist[adjnode], adjnode});
            }else{

                 if(dist[node]+adjwt==dist[adjnode]){
                    paths[adjnode]= (paths[adjnode]+ paths[node])%MOD;
                    minflights[adjnode]=min(minflights[adjnode], minflights[node]+1);
                    maxflights[adjnode]=max(maxflights[adjnode], maxflights[node]+1);
                 }
            }

        }
     }


     cout<<dist[n]<<" "<<paths[n]<<" "<<minflights[n]<<" "<<maxflights[n]<<endl;
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

    