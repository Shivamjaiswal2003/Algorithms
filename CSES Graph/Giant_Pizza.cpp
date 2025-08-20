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


int findnegation(int x, int n){
    if(x<n){
        return x+n;
    }else{
        return x-n;
    }
}


void dfs(int node,  vector<vector<int>> &adj, vector<int> &vis, stack<int> &st){


    vis[node]=1;

    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, st);
        }
    }

    st.push(node);

}

void dfs2(int node, vector<vector<int>> &revadj, vector<int> &vis, int comp, vector<int> &component){

    vis[node]=1;
    component[node]=comp;

    for(auto it: revadj[node]){
        if(!vis[it]){
            dfs2(it, revadj, vis, comp, component);
        }
    }

}

void solve(){
    
    int m, n;
    cin>>m>>n;

int n_nodes = 2 * n;
vector<vector<int>> adj(n_nodes);
vector<vector<int>> revadj(n_nodes);

    while(m--){
        char ch1, ch2;
        int n1, n2;
        cin>>ch1>>n1>>ch2>>n2;

       n1--;
       n2--;

        if(ch1=='-'){
            n1=findnegation(n1, n);
        }

        if(ch2=='-'){
            n2=findnegation(n2, n);
        }

        adj[findnegation(n1, n)].push_back(n2);
        adj[findnegation(n2, n)].push_back(n1);

        revadj[n2].push_back(findnegation(n1, n));
        revadj[n1].push_back(findnegation(n2, n));

    }

    vector<int> vis(2*n, 0);

    stack<int> st;

    for(int i=0; i<2*n; i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }



    vis.assign(2*n, 0);

    vector<int> component(2*n, -1);
    int comp=0;

    while(!st.empty()){
        int node= st.top();
        st.pop();
       
        if(vis[node]) continue;

        dfs2(node, revadj, vis, comp, component);
        comp++;
    }




    vector<int> sign(n, -1);

    for(int i=0; i<n; i++){
        if(component[i]==component[findnegation(i, n)]){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }

        if(component[i]>component[findnegation(i, n)]){
            sign[i]=1;
        }else{
            sign[i]=0;
        }
    }

    for(int i=0; i<n; i++){
         if(sign[i]){
            cout<<"+"<<" ";
         }else{
            cout<<"-"<<" ";
         }
    }

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

    