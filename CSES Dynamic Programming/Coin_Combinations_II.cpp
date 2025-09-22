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





void solve(){
 
    int n, x;
    cin>>n>>x;

    vector<int> a(n);
    
    for(int i=0; i<n; i++){
         cin>>a[i];
    }

    vector<int> dp(x+1, 0);
    dp[0]=1;

    for(int i=0; i<n; i++){
        for(int j=1; j<=x; j++){
            if(j-a[i]>=0){
                dp[j]=( dp[j]+dp[j-a[i]])%MOD;
            }
        }
    }

    cout<<dp[x]<<endl;
    
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

    