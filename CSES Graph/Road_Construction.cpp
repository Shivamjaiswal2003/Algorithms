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



class DisjointSet{
    
   
   
   public:
   
    
     vector<int> rank , parent, size;

    DisjointSet(int n){
        rank.resize(n+1, 0);
        
        parent.resize(n+1);
        size.resize(n+1);
        
        for(int i=0; i<=n; i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    
    
    int FindPar(int node){
        if(node == parent[node]) return node;
        
        return parent[node] = FindPar(parent[node]);
    }
    
    
    void UnionByRank(int u, int v){
        
        int ulp_u = FindPar(u);
        int ulp_v = FindPar(v);
        
        if(ulp_u==ulp_v) return;
        
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else{
            
            if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }else{
            
            parent[ulp_v] =ulp_u;
            rank[ulp_u]++;
          }
        }
    }
    
    
        void UnionBySize(int u, int v){
            int ulp_u = FindPar(u);
            int ulp_v = FindPar(v);
            
            if(ulp_u== ulp_v) return;
            
            if(size[ulp_u]<size[ulp_v]){
                size[ulp_v]+=size[ulp_u];
                parent[ulp_u]= ulp_v;
            }else{
                    
                    size[ulp_u]+=size[ulp_v];
                    parent[ulp_v] = ulp_u;
                
            }
        }
};


void solve(){
    
    int n, m;
    cin>>n>>m;

    DisjointSet ds(n);

    int components=n;
    int sizee=0;

    while(m--){
        int a, b;
        cin>>a>>b;
        
        int pa= ds.FindPar(a);
        int pb=ds.FindPar(b);

        if(pa==pb){
            cout<<components<<" "<<sizee<<endl;
            continue;
        }else{
            ds.UnionBySize(a, b);
            components--;
            sizee=max(sizee, max(ds.size[pa], ds.size[pb]));

            cout<<components<<" "<<sizee<<endl;
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

    