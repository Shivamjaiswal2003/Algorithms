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

struct Node{
    int match, open, close;
    Node() : match(0), open(0), close(0) {}
};

class SegmentTree{

      int n;
      vector<Node> tree;
      string s;

      Node merge( const Node &n1, const Node &n2){
              Node node;
              node.match+=n1.match+n2.match;
              int mini=min(n1.open, n2.close);
              node.match+=mini;
              node.open= n1.open+n2.open-mini;
              node.close= n1.close+n2.close-mini;
              
              return node;
      }


      void build(int idx, int l, int r){
        if(l==r){
            if(s[l]==')'){
                   tree[idx].close++;
            }else{
                   tree[idx].open++;
            }  
           return;
        }

        int mid= (l+r)/2;

        build(2*idx+1, l, mid);
        build(2*idx+2, mid+1, r);

        tree[idx]= merge(tree[2*idx+1], tree[2*idx+2]);
      }


      Node query(int idx, int l, int r, int ql, int qr){
          
          Node node;

           if(r<ql || l>qr )  return node;

           if(l>=ql && r<=qr)  return tree[idx];

           int mid = (l+r)/2;
         
           node= merge(query(2*idx+1, l, mid, ql, qr), query(2*idx+2, mid+1, r, ql, qr));

           return node;
      }


      public:

          SegmentTree(string s1){
            n=s1.length();
            s=s1;
            tree.resize(4*n);
            build(0, 0, n-1);
          }

          int getcnt(int ql, int qr){
            Node node= query(0, 0, n-1, ql, qr);

            return 2*node.match;
          }
};



void solve(){
    
    string s;
    cin>>s;

    SegmentTree st(s);

    int q;
    cin>>q;
    while(q--){
        int ql, qr;
        cin>>ql>>qr;

        cout<<st.getcnt(ql-1, qr-1)<<endl;
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

    