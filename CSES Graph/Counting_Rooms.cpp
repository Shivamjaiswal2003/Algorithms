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


int dr[] = {1, 0, -1, 0};
int dc[] = {0, -1, 0, 1};


void dfs(int i, int j, int n, int m,  vector<vector<char>> &adj, vector<vector<int>> &vis){

    vis[i][j]=1;
   
    for(int x=0; x<4; x++){
        int nr=i+dr[x];
        int nc=j+dc[x];

        if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && adj[nr][nc]=='.'){
            dfs(nr, nc, n, m, adj, vis);
        }
    }



}


void solve(){
    
    int n, m;
    cin>>n>>m;

    vector<vector<char>> adj(n, vector<char>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
           cin>>adj[i][j];
        }
    }


    vector<vector<int>> vis(n, vector<int>(m, 0));

    int ans=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
           if(!vis[i][j] && adj[i][j]=='.'){
            dfs(i, j, n, m, adj, vis);
            ans++;
           }
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

    