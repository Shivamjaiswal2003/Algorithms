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


int fun(int node, int par,  vector<int> adj[], int f, vector<vector<int>> &dp){

    if(dp[node][f]!=-1) return dp[node][f];


    if(f==0){
        int ans=0;

        for(auto it: adj[node]){
            if(it!=par){
                ans= ans+ fun(it, node, adj, 1, dp);
            }
        }
        return dp[node][f]= ans;
    }else{
        
        int ans=0;

        for(auto it: adj[node]){
           if(it!=par) ans+=fun(it, node, adj, 1, dp);
        }


        int myans=0;

        for(auto it: adj[node]){
             if(it!=par){
                myans= max(myans, ans-dp[it][1]+1+fun(it, node, adj, 0, dp));
             }
        }

        return dp[node][f]= myans;
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

    vector<vector<int>> dp(n+1, vector<int>(2, -1));

    int ans= max(fun(1, -1, adj, 0, dp), fun(1, -1, adj, 1, dp));

    cout<<ans<<endl;
    
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

    