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
    
    int n, m, q;
    cin>>n>>m>>q;

    vector<vector<int>> dist(n+1, vector<int>(n+1, 1e17));

    while(m--){
        int a, b, w;
        
        cin>>a>>b>>w;

        dist[a][b]=min(dist[a][b], w);
        dist[b][a]= min(dist[b][a], w);
    }

    for(int i=0; i<=n; i++){
        dist[i][i]=0;
    }


    for(int via=1; via<=n; via++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j]=min(dist[i][j], dist[i][via]+dist[via][j]);
            }
        }
    }

    while(q--){
        int a, b;
        cin>>a>>b;
        if(dist[a][b]==1e17){
            cout<<-1<<endl;
            continue;
        }
        cout<<dist[a][b]<<endl;
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

    