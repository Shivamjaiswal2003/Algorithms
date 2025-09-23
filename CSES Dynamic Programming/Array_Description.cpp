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
int MOD=1e9+7;     


// ===================================END Of the Life ==========================================


int fun(int i, int n, int m, int prev,  vector<int> &a,  vector<vector<int>> &dp){
    if(i==n){
        return 1;
    }

    if(dp[i][prev]!=-1) return dp[i][prev];

    int ans=0;

    if(a[i]!=0){
        if(abs(a[i]-prev)<=1){
            ans=fun(i+1, n, m, a[i], a, dp);
        }
    }else{
        for(int x=max(prev-1, 1); x<=min(prev+1, m); x++){
            ans=(ans+fun(i+1, n, m, x, a, dp))%MOD;
        }
    }

    return dp[i][prev]=ans;
}



void solve(){
 
    int n, m;
    cin>>n>>m;

    vector<int> a(n);
    
    for(int i=0; i<n; i++){
         cin>>a[i];
    }


    vector<vector<int>> dp(n, vector<int>(m+1, -1));

    int ans=0;

    if(a[0]!=0){
        ans= (fun(1, n, m, a[0], a, dp))%MOD;
    }else{
        for(int i=1; i<=m; i++){
            ans=( ans+ fun(1, n, m, i, a, dp))%MOD;
        }
    }

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

    