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

void merge(vector<int> &a, int low, int mid, int high){

    int left = low;
    int right=mid+1;

    vector<int> v;

    while(left<=mid && right<=high){
        if(a[left]<=a[right]){
            v.push_back(a[left]);
            left++;
        }else{
            v.push_back(a[right]);
            right++;
        }
    }


    while(left<=mid){
        v.push_back(a[left]);
            left++;
    }

    while(right<=high){
        v.push_back(a[right]);
            right++;
    }

    for(int i=0; i<v.size(); i++){
        a[i+low]=v[i];
    }


}

void mergeSort(vector<int> &a, int low, int high){
    if(low>=high){
        return;
    }

    int mid= (low+high)/2;
    mergeSort(a, low, mid);
    mergeSort(a, mid+1, high);

    merge(a, low, mid, high);
}

void solve(){
 
    int n;
    cin >> n;
    
    vector<int> a(n);
    
    for(int i=0; i<n; i++){
         cin>>a[i];
    }

    mergeSort(a, 0, n-1);
    
    for(auto it: a){
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

    