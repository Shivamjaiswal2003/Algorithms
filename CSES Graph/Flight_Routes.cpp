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
    
    int n, m, k;
    cin>>n>>m>>k;


    vector<pair<int, int>> adj[n+1];

    while(m--){
        int u, v, c;
        cin>>u>>v>>c;

        adj[u].push_back({v, c});
    }

    vector<vector<int>> dist(n+1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});

    while(!pq.empty()){

        auto it= pq.top();
        pq.pop();

        int node= it.second;
        int distance= it.first;

        if(dist[node].size()>=k){
            continue;
        }

        dist[node].push_back(distance);

        for(auto it1: adj[node]){
            int adjnode= it1.first;
            int adjdist= it1.second;

                pq.push({distance+adjdist, adjnode});
            
        }
    }

    // sort(dist[n].begin(), dist[n].end());

    for(auto it: dist[n]){
        cout<<it<<" ";
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

    