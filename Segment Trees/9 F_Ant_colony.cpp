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


int gcd(int a, int b){
    if(b==0){
        return a;
    }

    return gcd(b, a%b);
}

class SegmentTree{
        
    vector<int> arr;
    vector<pair<int, int>> tree;
    int n;


  

    pair<int, int> merge(const pair<int, int> &p1, const pair<int, int> &p2){
            
        pair<int, int> p;

        int num= gcd(p1.first, p2.first);
       
        p.first=num;
        p.second=0;
        if(num==p1.first){
            p.second+=p1.second;
        }

        if(num==p2.first){
            p.second+=p2.second;
        }

        return p;
    }


    void build(int idx, int l, int r){
        if(l==r){
             tree[idx]={arr[l], 1};
             
             return;
        }
       

        int mid= (l+r)/2;

        build(2*idx+1, l, mid);
        build(2*idx+2, mid+1, r);
      
        tree[idx]=merge(tree[2*idx+1], tree[2*idx+2]);
    }


    pair<int, int> query(int idx, int l, int r, int ql, int qr){
        if(r<ql || l>qr){
            return {0, 0};
        }
        if(l>=ql && r<=qr){
            return tree[idx];
        }


        int mid= (l+r)/2;

        return merge(query(2*idx+1, l, mid, ql, qr), query(2*idx+2, mid+1, r, ql, qr));
    }
    

    public:

      SegmentTree(vector<int> &a){
        arr=a;
        n=a.size();
        tree.resize(4*n);
        build(0, 0, n-1);
      }


      int getans(int ql, int qr){
          pair<int, int> p= query(0, 0, n-1, ql, qr);
          return p.second;
      }
};




void solve(){
 
    int n;
    cin >> n;
    
    vector<int> a(n);
    
    for(int i=0; i<n; i++){
         cin>>a[i];
    }


    SegmentTree st(a);

    int q;
    cin>>q;


    while(q--){
        int ql, qr;
        cin>>ql>>qr;

        int cnt= st.getans(ql-1, qr-1);
        cout<<(qr-ql+1-cnt)<<endl;
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

    