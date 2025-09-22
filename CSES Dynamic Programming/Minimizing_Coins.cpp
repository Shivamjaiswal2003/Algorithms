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

    vector<int> dp(x+1, INT_MAX);

    dp[0]=0;

for(int i=1; i<=x; i++){
    for(int j=0; j<n; j++){
        if( i-a[j]>=0){
            dp[i]=min(dp[i], 1+dp[i-a[j]]);
        }
    }
}

  


    if(dp[x]==INT_MAX){
        cout<<-1<<endl;
        return;
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

    