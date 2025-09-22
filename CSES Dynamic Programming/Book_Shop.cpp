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


// int fun(int i, int n,  vector<int> &price, vector<int> &pages, int x,   vector<vector<int>> &dp ){

//     if(i==n || x==0) return 0;

//     if(dp[i][x]!=-1) return dp[i][x];
//     int pick= 0;

//     if(price[i]<=x){
//         pick=pages[i]+fun(i+1, n, price, pages, x-price[i], dp);
//     }

//     int notpick= fun(i+1, n, price, pages, x, dp);

//     return dp[i][x]= max(pick, notpick);

// }



void solve(){
 
    int n, x;
    cin>>n>>x;

    vector<int> price(n);

    for(int i=0; i<n; i++){
        cin>>price[i];
    }


    vector<int>pages(n);

    for(int i=0; i<n; i++){
        cin>>pages[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

// int ans= fun(0, n, price, pages, x, dp);

// cout<<ans<<endl;

for(int i=1; i<=n; i++){
    for(int j=0; j<=x; j++){

        // int page=pages[i-1];
        // int prices= price[i-1];

        // int pick=0;

        // if(prices<=j){
        //   pick= page+dp[i-1][j-prices];
        // }

        // int notpick= dp[i-1][j];

        // dp[i][j]=max(pick, notpick);
       
        dp[i][j]=dp[i-1][j];

        if(j-price[i-1]>=0){
            dp[i][j]=max(dp[i][j], pages[i-1]+dp[i-1][j-price[i-1]]);
        }
    }
}

cout<<dp[n][x]<<endl;
    
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

    