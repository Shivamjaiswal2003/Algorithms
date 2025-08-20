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


vector<int> arr,dp,visited,dist;

int cycle_start = -1;
int cycle_len = 0;

void dfs(int u, int len) {
	if(visited[u]) return;
	visited[u] = true;

	dist[u] = len;

	int v = arr[u];

	if(!visited[v]) {
		dfs(v, len + 1);
	}
	else {
		if(dp[v] == 0) {
			cycle_len = dist[u] - dist[v] + 1;
			cycle_start = v;
		} else {
			cycle_len = dp[v];
		}
	}


	if(cycle_start != -1) {
		dp[u] = cycle_len;
		if(u == cycle_start) cycle_start = -1;
	} else {
		dp[u] = dp[v] + 1;
	}
}




void solve(){
    
    int n;
	cin >> n;

	arr.resize(n+1);
	dp.resize(n+1);
	visited.resize(n+1);
	dist.resize(n+1);

	for(int i=1; i<=n; ++i) {
		cin >> arr[i];
	}

	for(int i=1; i<=n; i++) {
		if(!visited[i]) {
			dfs(i, 1);
		}
	}

	for(int i=1; i<=n; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;
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

    
