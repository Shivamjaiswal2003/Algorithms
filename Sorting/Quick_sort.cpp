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

int fun(vector<int> &a, int low, int high){
    
      int pivot= a[low];

      int i=low;
      int j=high;

      while(i<j){

        while(i<=high && a[i]<=pivot ){
            i++;
        }

        while(j>=low && a[j]>pivot){
            j--;
        }

        if(i<j){
            swap(a[i], a[j]);
        }
      }

      swap(a[low], a[j]);
      return j;
}


void quickSort(vector<int> &a, int low, int high){

    if(low<high){

        int partitionIndex= fun(a, low, high);

        quickSort(a, low, partitionIndex-1);
        quickSort(a, partitionIndex+1, high);

    }
}



void solve(){
 
    int n;
    cin >> n;
    
    vector<int> a(n);
    
    for(int i=0; i<n; i++){
         cin>>a[i];
    }


    quickSort(a, 0, n-1);
    

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

    