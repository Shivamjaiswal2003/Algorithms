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


// PROBLEM LINK: https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A%C3%A2%C2%81%C2%A3


class SegmentTree{
   
    private: 

       vector<int> tree;
       vector<int> arr;
       int n;

       void build(int idx, int l, int r){
           
            if(l==r){
                tree[idx]=arr[l];
                return;
            }

            int mid= (l+r)/2;

            build(2*idx+1, l, mid);
            build(2*idx+2, mid+1, r);

            tree[idx]=min(tree[2*idx+1], tree[2*idx+2]);
       }


       void update(int idx, int l, int r, int pos, int val){
            
            if(l==r){
                arr[l]=val;
                tree[idx]=val;
                return;
            }

            int mid=(l+r)/2;

            if(pos<=mid){
                update(2*idx+1, l, mid, pos, val);
            }else{
                update(2*idx+2, mid+1, r, pos, val);
            }

            tree[idx]=min(tree[2*idx+1], tree[2*idx+2]);
       }

       int query(int idx, int l, int r, int ql, int qr){
            
            if(l>=ql && r<=qr){
                return tree[idx];
            }

            if(r<ql || l>qr){
                return INT_MAX;
            }

            int mid= (l+r)/2;

            int leftres= query(2*idx+1, l, mid, ql, qr);
            int rightres= query(2*idx+2, mid+1, r, ql, qr);

            return min(leftres,rightres);

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

       int getmin(int ql, int qr){
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
            cout<<st.getmin(ql, qr-1)<<endl;
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

    