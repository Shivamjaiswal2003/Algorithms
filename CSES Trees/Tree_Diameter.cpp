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
 
vector<int> height;
 
 
void computeHeight(int node , int par,  vector<int> adj[]){
 
    for(auto it: adj[node]){
        if(it!=par){
            computeHeight(it, node, adj);
            height[node]=max(height[node], 1+height[it]);
        }
    }
 
 
}
 
 
vector<int> diameter;
 
 
void fun(int node, int par,   vector<int> adj[]){
 
    vector<int> childheights;
 
    int ans=0;
 
    for(auto it: adj[node]){
        if(it!=par){
            fun(it, node, adj);
            ans= max(ans, diameter[it]);
            childheights.push_back(height[it]);
        }
    }
 
    int n=childheights.size();
 
    if(n==0){
        diameter[node]=0;
    }
 
    srt(childheights);
 
    if(n==1){
        diameter[node]= max(diameter[node], 1+ childheights[n-1]);
    }
    if(n>=2){
         diameter[node]=  max(diameter[node], 2+ childheights[n-1]+childheights[n-2]);
    }
 
 
 
    diameter[node]=max(ans, diameter[node]);
   
}
 
 
 
void solve(){
    int n;
    cin >> n;
    
    vector<int> adj[n+1];
 
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
 
    height.resize(n+1, 0);
    computeHeight(1, 0, adj);
 
    diameter.resize(n+1, 0);
 
    fun(1, 0, adj);
 
 
    cout<<diameter[1]<<endl;
  
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
