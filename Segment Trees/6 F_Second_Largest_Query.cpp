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


class SegmentTree{
      
    int n;
    vector<int> arr;
    vector<vector<pair<int, int>>> tree;
   

    vector<pair<int, int>> merge(const vector<pair<int, int>> &v1, const vector<pair<int, int>> &v2){
       
        int l1= v1[0].first;
        int l1cnt= v1[0].second;
        int s1= v1[1].first;
        int s1cnt=v1[1].second;

        int l2= v2[0].first;
        int l2cnt= v2[0].second;
        int s2= v2[1].first;
        int s2cnt=v2[1].second;


        if(l1>l2){
            int l= l1;
            int lcnt=l1cnt;
           
            int s=0;
            int scnt=0;
            if(l2>s1){
                s=l2;
                scnt=l2cnt;
            }else{
                if(s1>l2){
                    s=s1;
                    scnt=s1cnt;
                }else{
                    s=s1;
                    scnt=s1cnt+l2cnt;
                }
            }
           vector<pair<int, int>> v;
           v.push_back({l, lcnt});
           v.push_back({s, scnt});

          
           return v;
        }else{
                if(l2>l1){
                int l= l2;
                int lcnt=l2cnt;
            
                int s=0;
                int scnt=0;
                if(l1>s2){
                    s=l1;
                    scnt=l1cnt;
                }else{
                    if(s2>l1){
                        s=s2;
                        scnt=s2cnt;
                    }else{
                        s=s2;
                        scnt=s2cnt+l1cnt;
                    }
                }
            vector<pair<int, int>> v;
            v.push_back({l, lcnt});
            v.push_back({s, scnt});
            
            return v;
            }else{
                  

                  int l=l1;
                  int lcnt=l1cnt+l2cnt;

                  int s=0;
                  int scnt=0;

                  if(s2>s1){
                    s=s2;
                    scnt=s2cnt;
                  }else{
                    if(s1>s2){
                        s=s1;
                        scnt=s1cnt;
                    }else{
                        s=s1;
                        scnt=s1cnt+s2cnt;
                    }
                  }

                  vector<pair<int, int>> v;
               v.push_back({l, lcnt});
               v.push_back({s, scnt});
                 return v; 
            }
        }
    }
    void build(int idx, int l, int r){
        if(l==r){
            vector<pair<int, int>> v1;
            v1.push_back({arr[l], 1});
            v1.push_back({0, 0});
            tree[idx]=v1;
            return;
        }


        int mid=(l+r)/2;

        build(2*idx+1, l, mid);
        build(2*idx+2, mid+1, r);

       tree[idx]=merge(tree[2*idx+1], tree[2*idx+2]);
    }


    void update(int idx, int l, int r, int pos, int val){
        if(l==r){
            vector<pair<int, int>> v1;
            v1.push_back({val, 1});
            v1.push_back({0, 0});
            tree[idx]=v1;
            arr[l]=val;
            return;
        }

        int mid=(l+r)/2;
       
        if(pos<=mid){
            update(2*idx+1, l, mid, pos, val);
        }else{
            update(2*idx+2, mid+1, r, pos, val);
        }
        
        tree[idx]=merge(tree[2*idx+1], tree[2*idx+2]);
    }


    vector<pair<int, int>> query(int idx, int l, int r, int ql, int qr){
        if(r<ql || l>qr){
            vector<pair<int, int>> v1;
            v1.push_back({0, 0});
            v1.push_back({0, 0});
            
            return v1;
        }

        if(l>=ql && r<=qr){
            return tree[idx];
        }

        int mid= (l+r)/2;

        return merge(query(2*idx+1, l, mid, ql, qr), query(2*idx+2, mid+1, r, ql, qr));
    }

    public:

     SegmentTree(vector<int> &a){
           n=a.size();
           arr=a;
           tree.resize(4*n);
           build(0, 0, n-1);
     }


     void updateval(int pos, int val){
            update(0, 0, n-1, pos, val);
     }

     int getval(int ql, int qr){
            vector<pair<int, int>> v=query(0, 0, n-1, ql, qr);
            return v[1].second;
     }
};


void solve(){
    
    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    
    for(int i=0; i<n; i++){
         cin>>a[i];
    }

    SegmentTree st(a);

    while(q--){
        int type;
        cin>>type;

        if(type==1){
            int pos, val;
            cin>>pos>>val;
            st.updateval(pos-1, val);
        }else{
            int ql, qr;
            cin>>ql>>qr;
            cout<<st.getval(ql-1, qr-1)<<endl;
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

    