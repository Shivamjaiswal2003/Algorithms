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





void solve(){
 
    int n, m;
    cin >> n >>m;
    
    vector<int> a(n);
    
    for(int i=0; i<n; i++){
         cin>>a[i];
    }

    vector<int> b(m);
    
    for(int i=0; i<m; i++){
         cin>>b[i];
    }
    

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int notpick= max(dp[i-1][j], dp[i][j-1]);
            int pick=0; 
            if(a[i-1]==b[j-1]){
                pick=1+dp[i-1][j-1];
            }
            dp[i][j]=max(pick, notpick);
        }
    }

    cout<<dp[n][m]<<endl;



    vector<int> ans;

    int i=n; int j=m;

    while(i>0 && j>0){

        if((dp[i-1][j]==dp[i][j-1]) && (dp[i-1][j]==dp[i][j]-1)){
            ans.push_back(a[i-1]);
            i--;
            j--;
        }else{
            if(dp[i][j-1]==dp[i][j]){
                j--;
            }else{
                i--;
            }
        }
    }

    reverse(ans.begin(), ans.end());

    for(auto it: ans){
    cout<<it<<" ";
    }
    cout<<endl;


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

    