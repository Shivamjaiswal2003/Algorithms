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


void bubbleSort(vector<int> &a){
    int n= a.size();

    for(int i=n-2; i>=0; i--){
          
        for(int j=0; j<=i; j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}


void solve(){
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    
    for(int i=0; i<n; i++){
         cin>>a[i];
    }

    bubbleSort(a);
    
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

    