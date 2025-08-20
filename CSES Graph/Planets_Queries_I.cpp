#include "bits/stdc++.h"
// #define int long long
typedef long long ll;
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
    
    
    int n, q;
    cin>>n>>q;

    
    vector<vector<int>> dp(n+1, vector<int> (30, 0));

    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        dp[i][0]=x;
    }

    for(int bit=1; bit<=29; bit++){
         for(int node=1; node<=n; node++){
            dp[node][bit]=dp[dp[node][bit-1]][bit-1];
         }
    }

    while(q--){
       int node;
       ll k;
        cin >> node >> k;
        for(int bit=29; bit>=0; bit--){
            if((k>>bit)&1){
                node=dp[node][bit];
            }
        }

        cout << node << '\n';
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

    