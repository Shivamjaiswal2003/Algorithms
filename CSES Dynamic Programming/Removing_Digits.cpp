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


int maxdigit(int n){
    int maxi=0;

    while(n){
        maxi=max(maxi, n%10);
        n/=10;
    }

    return maxi;
}


int fun(int n,  vector<int> &dp){
    if(n==0){
        return 0;
    }

    if(dp[n]!=-1) return dp[n];
    

    int maxi=maxdigit(n);

    return dp[n]= 1+fun(n-maxi, dp);
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

    