#include "bits/stdc++.h"
// #define int long long
// #define uint unsigned long long
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
    
    vector<int> arr;
    vector<vector<int>> tree;
    int n;
 

    vector<int> merge(const vector<int> &a, const vector<int> &b){

        vector<int> ans;

        int l=0; int r=0;
        int n1=a.size();
        int n2=b.size();

        while(l<n1 && r<n2){
             if(a[l]<=b[r]){
                ans.push_back(a[l]);
                l++;
             }else{
                ans.push_back(b[r]);
                r++;
             }
        }

        while(l<n1){
            ans.push_back(a[l]);
                l++;
        }

        while(r<n2){
            ans.push_back(b[r]);
                r++;
        }

        return ans;
    }

    void build(int idx, int l, int r){
        if(l==r){
            tree[idx].push_back(arr[l]);
            return;
        }
        int mid= (l+r)/2;

        build(2*idx+1, l, mid);
        build(2*idx+2, mid+1, r);

        tree[idx]=merge(tree[2*idx+1], tree[2*idx+2]);
    }


    int query(int idx, int l, int r, int ql, int qr, int k){

        if(r<ql || l>qr) return 0;
        if(l>=ql && r<=qr){
            vector<int> &v1= tree[idx];
            int num= v1.end()-upper_bound(v1.begin(), v1.end(), k);
            return num;

        }

        int mid=(l+r)/2;
        int leftans= query(2*idx+1, l, mid, ql, qr, k);
        int rightans= query(2*idx+2, mid+1, r, ql, qr, k);


        return leftans+rightans;

    }


    public:

        SegmentTree(vector<int> &a){
             n=a.size();
             tree.resize(4*n);
             arr=a;
             build(0, 0, n-1);
        }

        int getcnt(int ql, int qr, int k){
            return query(0, 0, n-1, ql, qr, k);
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
           
        int ql, qr, k;
        cin>>ql>>qr>>k;

        cout<<st.getcnt(ql-1, qr-1, k)<<'\n';
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

    