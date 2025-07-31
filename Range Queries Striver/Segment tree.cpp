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




// given query 

// 1 L R  => return minimum in range L to R for type 1 query
// 2 i val => update array[i]=val



void build(int ind, int low, int high, vector<int> &a,   vector<int> &seg){
    if(low==high){
        seg[ind]=a[low];
        return;
    }

    int mid = (low+high)/2;
    build(2*ind + 1, low, mid, a, seg);
    build(2*ind+2, mid+1, high, a, seg);

    seg[ind]= min(seg[2*ind+1], seg[2*ind+2]);
}



int query(int ind, int low, int high, int l, int r, vector<int> &a, vector<int>&seg){
  
    // complete overlap
    // [L low  high r]
    if(low>=l && high<=r){
        return seg[ind];
    }
    
    // complete no overlap
    if(r<low || l>high){
        return INT_MAX;
    }

    //partial overlap
    int mid= (low+high)/2;

    int left= query(2*ind+1, low, mid, l, r, a, seg);
    int right= query(2*ind+2, mid+1, high, l, r, a, seg);

    return min(left, right);
    
}

void update(int ind, int low , int high, int i, int val, vector<int> &seg){
  
    if(low==high){
        seg[ind]=val;
        return;
    }

    int mid= (low+high)/2;

    if(i<=mid){
        update(2*ind+1, low, mid, i, val, seg);
    }else{
        update(2*ind+2, mid+1, high, i, val, seg);
    }

    seg[ind]=min(seg[2*ind+1], seg[2*ind+2]);
}

void solve(){
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    

    for(int i=0; i<n; i++){
         cin>>a[i];
    }

    vector<int> seg(4*n);


    build(0, 0, n-1, a, seg);

    int q;
    cin>>q;

    while(q--){
        int type;
        cin>>type;

        if(type==1){
            int L, R;
            cin>>L>>R;

            cout<<query(0, 0, n-1, L, R, a, seg)<<endl;
        }else{
            int i, val;
            cin>>i>>val;

            update(0, 0, n-1, i, val, seg);
            a[i]=val;
        }
        
    }

}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

        solve();
    
    return 0;
}

    