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
const int MOD=1e9+7;     


// ===================================END Of the Life ==========================================


int maxN=1e6;

vector<vector<int>> dp(maxN+1, vector<int>(2, 0));


void precomputeans(){
    
    dp[1][0]=1;
    dp[1][1]=1;

    for(int i=2; i<=maxN; i++){
        dp[i][0]= (4*dp[i-1][0] + dp[i-1][1])%MOD;
        dp[i][1]= (2*dp[i-1][1] + dp[i-1][0])%MOD;

    }
}


void solve(){

    int n;
    cin >> n;
    
    int ans= (dp[n][0]+dp[n][1])%MOD;
    cout<<ans<<endl;
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    precomputeans();

    int T = 1;
    cin >> T;

    while (T--)
    {
        solve();
    }
    return 0;
}

    