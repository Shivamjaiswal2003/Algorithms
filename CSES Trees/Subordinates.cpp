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


void fxn(int src,  vector<int> &ans, vector<int> adj[]){
 
        int answer=0;
    
    for(auto it: adj[src]){
        if(it!=src) {
            fxn(it,  ans, adj);
            answer+=1+ans[it-1];
        }
    
    }
    ans[src-1]=answer;
    
}


void solve(){
 
    int n;
      cin>>n;
 
      vector<int> adj[n+1];
      for(int i=2; i<=n; i++){
          int x;
          cin>>x;
          adj[x].push_back(i);
          
      }
 
 
      vector<int> ans(n);
 
      fxn(1, ans, adj); 
 
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

    