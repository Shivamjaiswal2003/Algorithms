#include "bits/stdc++.h"
// #define int long long
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

class SegmenTree{


    int n;
    vector<int> arr;
    vector<vector<int>> tree;

    vector<int> merge(vector<int> &v1, vector<int> &v2){
           vector<int> v(26, 0);
           for(int i=0; i<26; i++){
            v[i]+=v1[i]+v2[i];
           }

           return v;
    }

    void build(int idx, int l, int r){
        if(l==r){
            vector<int> v(26, 0);
            v[arr[l]]=1;
            tree[idx]=v;
            return;
        }

        int mid= (l+r)/2;

        build(2*idx+1, l, mid);
        build(2*idx+2, mid+1, r);

        tree[idx]= merge(tree[2*idx+1], tree[2*idx+2]);
    }

    void update(int idx, int l, int r, int pos, int val){
            if(l==r){
                tree[idx].assign(26, 0);
                tree[idx][val]=1;
                arr[l]=val;
                return;
            }

            int mid= (l+r)/2;

            if(pos<=mid){
                update(2*idx+1, l, mid, pos, val);
            }else{
                update(2*idx+2, mid+1, r, pos, val);
            }


            tree[idx]= merge(tree[2*idx+1], tree[2*idx+2]);
    }

    vector<int> query(int idx, int l, int r, int ql, int qr){
        if(r < ql || l > qr) return vector<int>(26, 0);
        if(l >= ql && r <= qr) return tree[idx];

        int mid = (l+r)/2;
        vector<int> left = query(2*idx+1, l, mid, ql, qr);
        vector<int> right = query(2*idx+2, mid+1, r, ql, qr);

        return merge(left, right);
    }




    public:


      SegmenTree(string s){
          n=s.size();
          arr.resize(n, 0);
          tree.resize(4*n);
          for(int i=0; i<n; i++){
            arr[i]=s[i]-'a';
          }

          build(0, 0, n-1);
      }


      void updatestr(int pos, char val){
           update(0, 0, n-1, pos, val-'a');
      }

      int getcnt(int ql, int qr){
            vector<int> v = query(0, 0, n-1, ql, qr);
            int cnt = 0;
            for(int i=0; i<26; i++) if(v[i] > 0) cnt++;
            return cnt;
       }

};



void solve(){
    
    string s;
    cin>>s;


SegmenTree st(s);


   int q;
   cin>>q;

   while(q--){

    int type;
    cin>>type;

    if(type==1){
        int pos;
        char val;
        cin>>pos>>val;
        st.updatestr(pos-1, val);
    }else{
        int ql, qr;
        cin>>ql>>qr;

        cout<<st.getcnt(ql-1, qr-1)<<endl;
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

    