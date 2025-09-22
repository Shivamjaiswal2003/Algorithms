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

int fun(int n, vector<int> &dp){
    if(n==0) return 1;

    if(dp[n]!=-1) return dp[n];

    int ans=0;

    for(int i=1; i<=6; i++){
        if(n-i>=0){
           ans= (ans+ fun(n-i, dp))%MOD;
        }
    }

    return dp[n]= ans;
}



void solve(){
    
    int n;
    cin >> n;
    
    vector<int> dp(n+1, -1);

    int ans= fun(n, dp);

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

    