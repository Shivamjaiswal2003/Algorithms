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




void dfs(int node, int par,  vector<int> adj[],  vector<vector<int>> &dp,  vector<int> &level, int l){

    level[node] = l;

    dp[node][0]=par;

    for(int i=1; i<=16; i++){
        dp[node][i]= dp[dp[node][i-1]][i-1];
    }

    for(auto it: adj[node]){
        if(it!=par){
            dfs(it, node, adj, dp, level, l+1);
        }
    }

}


int getpar(int node, int k,  vector<vector<int>> &dp){
  
    for(int i=16; i>=0; i--){
        if((k>>i)&1){
            node= dp[node][i];
        }
    }

    return node;

}


int lca(int a, int b, vector<int> &level,  vector<vector<int>> &dp){

    if(level[a]>level[b]){
        swap(a, b);
    }

    //STEP 1: GET BOTH ON THE SAME LEVEL

    int k= level[b]-level[a];

    if(k>0){
        b= getpar(b, k, dp);
    }

    if(a==b){
        return a;
    }

    // STEP 2: MOVE BOTH UP TO EVERY UNEQUAL NODE FROM 16 TO 0

    for(int i=16; i>=0; i--){
        if(dp[a][i]!=dp[b][i]){
            a = dp[a][i];
            b = dp[b][i];
        }
    }

    return dp[a][0];

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


     vector<vector<int>> dp(n+1, vector<int>(17, 0));
    // dp[node][i] = 2^ith parent of node


    vector<int> level(n+1, 0);


    dfs(1, 0, adj, dp, level, 0);

    int q;
    cin>>q;

    while(q--){
        int a, b;
        cin>>a>>b;

        cout<<lca(a, b, level, dp)<<endl;

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

    