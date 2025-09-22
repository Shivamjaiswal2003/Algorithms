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


int fxn(int n,   vector<vector<char>>&grid, int row, int col,  vector<vector<int>>&dp ){
 
  if(row ==0 && col==0 ){
     if(grid[row][col]=='*') return dp[row][col]=0;
     else return dp[row][col]=1;
  }
  if(row<0 || col<0 || col>=n || row>=n || grid[row][col]=='*')  return 0;
 
if(dp[row][col]!=-1) return dp[row][col]%MOD;
 
 
 int up = fxn(n, grid, row - 1, col, dp);
    int left = fxn(n, grid, row, col - 1, dp);
 
    // Cache and return the result
    return dp[row][col] = (up + left)%MOD;
 
 
}



void solve(){
    
    int n;
   cin>>n;
   vector<vector<char>>grid(n, vector<char>(n));
 
   for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
         cin>>grid[i][j];
    }
   }
 
 vector<vector<int>>dp(n, vector<int>(n, -1));
 
  int ans = fxn(n, grid, n-1, n-1,  dp);
 
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

    