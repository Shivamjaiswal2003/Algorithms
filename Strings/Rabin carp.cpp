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





void solve(){
 
    string t, s;
    cin>>t>>s;

    const int p=31;
    
    int n=t.size();
    int m=s.size();

    vector<int> p_pow(max(n, m));

    p_pow[0]=1;

    for(int i=1; i<p_pow.size(); i++){
       p_pow[i]=(p_pow[i-1]*p)%MOD;
    }
    
    int hashs=0;



    for(int i=0; i<m; i++){
        hashs=(hashs+(s[i]-'a'+1)*p_pow[i])%MOD;
    }

    vector<int> hasht(n+1, 0);
    
    for(int i=1; i<=n; i++){
        hasht[i]=((hasht[i-1])+(t[i-1]-'a'+1)*p_pow[i-1])%MOD;
    }

   
    vector<int> occurances;

    for(int i=0; i+m<=n; i++){
        int curr_h=(hasht[i+m]-hasht[i]+MOD)%MOD;
       
        if(curr_h == (hashs*p_pow[i])%MOD){
            occurances.push_back(i+1);
        }
    }

    if(occurances.size()==0){
        cout<<"Not Found"<<endl;
        cout<<endl;
        return;
    }

    cout<<occurances.size()<<endl;
    for(auto it: occurances){
    cout<<it<<" ";
    }
    cout<<endl;
    cout<<endl;

}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

    