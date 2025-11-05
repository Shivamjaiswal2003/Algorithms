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

class SegmentTree{


    vector<int> tree;
    vector<int> a;
    int n;


       void build(int idx, int l, int r){
        if(l==r){
            tree[idx]=a[l];
            return;
        }

        int mid= (l+r)/2;
       
        build(2*idx+1, l, mid);
        build(2*idx+2, mid+1, r);

        tree[idx]=tree[2*idx+1]+tree[2*idx+2];
    }

    void update(int idx, int l, int r, int ind, int val){

        if(l==r){
            tree[idx]=val;
            a[l]=val;
            return;
        }

        int mid= (l+r)/2;

        if(ind<=mid){
            update(2*idx+1, l, mid, ind, val);
        }else{
            update(2*idx+2, mid+1, r, ind, val);
        }

        tree[idx]=tree[2*idx+1]+tree[2*idx+2];
    }

    int query(int idx, int l, int r, int ql, int qr){

        if(r<ql || l>qr){
            return 0;
        }

        if(l>=ql && r<=qr){
            return tree[idx];
        }

        int mid=(l+r)/2;

        int leftans= query(2*idx+1, l, mid, ql, qr);
        int rightans= query(2*idx+2, mid+1, r, ql, qr);

        return leftans+rightans;
    }


    public:

    SegmentTree(vector<int> &arr){
          n=arr.size();
          a=arr;
          tree.resize(4*n+1, 0);
          build(0, 0, n-1);
    }


    int getsum(int ql, int qr){
        return query(0, 0, n-1, ql, qr);
    }
 
    void updateval(int ind, int val){
        update(0, 0, n-1, ind, val);
    }

};





int t=0;

void dfs(int node, int par,    vector<int> adj[],  vector<int> &val, vector<int> &linearTree,  vector<int> &in,  vector<int> &out){

    in[node]=t;
    linearTree[t]=val[node];

    t++;

    for(auto it: adj[node]){
        if(it!=par){
            dfs(it, node, adj, val, linearTree, in, out);
        }
    }

    out[node]=t;
    linearTree[t]=val[node];
    t++;


}



void solve(){
    
   
    int n, q;
    cin>>n>>q;

    vector<int> val(n+1, 0);

    for(int i=1; i<=n; i++){
        int x; cin>>x;
        val[i]=x;
    }


    vector<int> adj[n+1];

    for(int i=0; i<n-1; i++){
         int u, v;
         cin>>u>>v;

         adj[u].push_back(v);
         adj[v].push_back(u);
    }

    vector<int> linearTree(2*n, 0);
    vector<int> in(n+1, 0);
    vector<int> out(n+1, 0);

 
    dfs(1, 0, adj, val, linearTree, in, out);

    // for(auto it: linearTree){
    //     cout<<it<<" ";
    // }

  
    SegmentTree st(linearTree);

    while(q--){

        int type;
        cin>>type;

        if(type==2){
            int node; cin>>node;
            int ql= in[node];
            int qr= out[node];

            int ans= st.getsum(ql, qr);
            cout<<ans/2<<endl;
        }else{

            int node, value;
            cin>>node>>value;
            
            int ind1= in[node];
           
            st.updateval(ind1, value);
            int ind2= out[node];
            
             st.updateval(ind2, value);
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

    