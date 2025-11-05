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

    private:

      int n;
      vector<int> tree;

      void update(int idx, int l, int r, int pos){
            
         if(l==r){
            tree[idx]=1;
            return;
         }

         int mid=(l+r)/2;

         if(pos<=mid){
            update(2*idx+1, l, mid, pos);
         }else{
            update(2*idx+2, mid+1, r, pos);
         }

         tree[idx]=tree[2*idx+1]+tree[2*idx+2];
      }

      int query(int idx, int l, int r, int ql, int qr){
          
           if(l>=ql && r<=qr){
            return tree[idx];
           }

           if(l>qr || r<ql) return 0;

           int mid=(l+r)/2;

           int leftres= query(2*idx+1, l, mid, ql, qr);
           int rightres= query(2*idx+2, mid+1, r, ql, qr);

           return leftres+rightres;
      }

    public:
       
        SegmentTree(int size){
            n = size;
            tree.assign(4*n, 0);
        }
    
        void add(int pos){
            update(0, 1, n, pos);
        }

        int getcount(int ql, int qr){
            if(ql>qr) return 0;
             return query(0, 1, n, ql, qr);
        }

};


void solve(){
    
     int n;
     cin >> n;
     
     SegmentTree st(n);

     vector<int> ans(n);

     for(int i=0; i<n; i++){
        int x;
        cin>>x;
         
         int res= st.getcount(x+1, n);
        ans[i]=res;

        st.add(x);
     }
    
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

    