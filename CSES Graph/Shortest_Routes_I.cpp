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


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});
    vector<int> dist(n+1, 1e15);
    dist[1]=0;


    while(!pq.empty()){
        auto it1= pq.top();
        pq.pop();

        int node= it1.second;
        int d= it1.first;

        if (d > dist[node]) {
            continue;
        }
        
        for(auto it: adj[node]){
            
            int adjnode= it.first;
            int adjdist= it.second;
            if(dist[adjnode]>adjdist+d){
                dist[adjnode]=adjdist+d;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout<<dist[i]<<" ";
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

    