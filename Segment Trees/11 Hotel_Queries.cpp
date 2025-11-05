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

    int n;
    vector<int> arr;
    vector<int> tree;

    void build(int idx, int l, int r){
        if(l==r){
            tree[idx]=arr[l];
            return;
        }

        int mid=(l+r)/2;
        build(2*idx+1, l, mid);
        build(2*idx+2, mid+1, r);

        tree[idx]= max(tree[2*idx+1], tree[2*idx+2]);


    }

    void update(int idx, int l, int r, int pos, int val){
        if(l==r){
            tree[idx]=val;
            arr[l]=val;
            return;
        }

        int mid= (l+r)/2;

        if(pos<=mid){
            update(2*idx+1, l, mid, pos, val);
        }else{
            update(2*idx+2, mid+1, r, pos, val);
        }

        tree[idx]=max(tree[2*idx+1], tree[2*idx+2]);
    }
 
    int query(int idx, int l, int r, int num){
          if(l==r){
             if(tree[idx]>=num){
                return l;
             }else{
                return -1;
             }
          }

          int mid= (l+r)/2;

       
          if(tree[2*idx+1]>=num){
             return query(2*idx+1, l, mid, num);
          }else{
             return query(2*idx+2, mid+1, r, num);
          }

         
    }


    public:

      
      SegmentTree(vector<int> &a){
        arr=a;
        n=arr.size();
        tree.resize(4*n);
        build(0, 0, n-1);
      }


      int getroom(int num){
        return query(0, 0, n-1, num);
      }

      void updatehotel(int pos, int val){
        update(0,0, n-1, pos, val);
      }

};


void solve(){
 
    int n, g;
    cin>>n>>g;

    vector<int> h(n);
    for(int i=0; i<n;i++){
        cin>>h[i];
    }


    SegmentTree st(h);

    vector<int> r(g);
    for(int i=0; i<g; i++){
        cin>>r[i];

       int ans= st.getroom(r[i]);
       if(ans==-1){
        cout<<0<<" ";
       }else{
        cout<<ans+1<<" ";
        h[ans]-=r[i];
        st.updatehotel(ans, h[ans]);
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

    