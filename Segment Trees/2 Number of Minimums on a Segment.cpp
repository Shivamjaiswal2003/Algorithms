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



// PROBLEM LINK: https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C


struct Node{
    int mn;
    int cnt;

};


class SegmentTree{
       
    private:
       
       vector<int> arr;
       vector<Node> tree;
       int n;


       Node merge(const Node& a, const Node& b){
           
           if(a.mn<b.mn) return a;
           if(b.mn<a.mn) return b;

           return {a.mn, a.cnt+b.cnt};
       }

       void build(int idx, int l, int r){
           
            if(l==r){
                tree[idx] = {arr[l], 1};
                return;
            }

            int mid= (l+r)/2;

            build(2*idx+1, l, mid);
            build(2*idx+2, mid+1, r);
         
            tree[idx]= merge(tree[2*idx+1], tree[2*idx+2]);
       }

       void update(int idx, int l, int r, int pos, int val){
            
           if(l==r){
               arr[l]=val;
               tree[idx]={val, 1};
               return;
           }

           int mid= (l+r)/2;

           if(pos<=mid){
             update(2*idx+1, l, mid, pos, val);
           }else{
             update(2*idx+2, mid+1, r, pos, val);
           } 

        tree[idx]=merge(tree[2*idx+1], tree[2*idx+2]);

       }

       Node query(int idx, int l, int r, int ql, int qr){
           
           if(r<ql || l>qr){
            return {INT_MAX, 0};
           }

           if(l>=ql && r<=qr){
            return tree[idx];
           }

           int mid= (l+r)/2;

           Node leftres= query(2*idx+1, l, mid, ql, qr);
           Node rightres= query(2*idx+2, mid+1, r, ql, qr);

           return merge(leftres, rightres);
       }


    public:

       SegmentTree(const vector<int> &input){
           arr=input;
           n=arr.size();
           tree.resize(4*n);
           build(0, 0, n-1);
       }

       void setval(int pos, int val){
           update(0, 0, n-1, pos, val);
       }

       Node getsum(int ql, int qr){
          return query(0, 0, n-1, ql, qr);
       }
};


void solve(){
     
    int n, m;
    cin>>n>>m;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }


    SegmentTree st(arr);
    
    while(m--){
        int type;
        cin>>type;

        if(type==1){
            int pos, val;
            cin>>pos>>val;

            st.setval(pos, val);
        }else{
            int ql, qr;
            cin>>ql>>qr;

            auto it= st.getsum(ql, qr-1);

            cout<<it.mn<<" "<<it.cnt<<endl;
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

    