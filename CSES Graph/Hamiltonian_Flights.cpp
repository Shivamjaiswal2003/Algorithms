#include "bits/stdc++.h"
// #define int long long
#define uint unsigned long long
#define vi vector<int>
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define srt(v)  sort(v.begin(),v.end())      
#define mxe(v)  *max_element(v.begin(),v.end())     
#define mne(v)  *min_element(v.begin(),v.end())    

using namespace std;
const int MOD=1e9+7;     


// ===================================END Of the Life ==========================================





void solve(){
     
    int n, m;
    cin>>n>>m;

    vector<int> adj[n];

    while(m--){
        int a, b;
        cin>>a>>b;

        a--; b--;

        adj[a].push_back(b);
     
    }

    int full= (1<<n)-1;
    vector<vector<int>> dp(full+1, vector<int>(n, 0));

    dp[1][0]=1;

    for(int mask=0; mask<=full; mask++){
           
        for(int u=0; u<n; u++){
            if(!(mask&(1<<u))) continue;

            if(dp[mask][u]==0) continue;

            for(auto it: adj[u]){
                if((mask&(1<<it))) continue;

                int nextmask= mask|(1<<it);
                dp[nextmask][it]=(dp[nextmask][it] + dp[mask][u])%MOD;
            }
        }
    }

    cout<<(dp[full][n-1])%MOD<<endl;
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

    