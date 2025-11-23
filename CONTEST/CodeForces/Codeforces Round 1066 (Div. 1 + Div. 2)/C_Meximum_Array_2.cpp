// Author: anuj
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

// ---------- PBDS ----------
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

// ---------- Debug ----------
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<"\n";
#else
#define debug(x)
#endif

// Primitive types
template<typename T> void _print(T t){cerr<<t;}
template<> void _print<string>(string t){cerr<<'"'<<t<<'"';}
template<typename T,typename V> void _print(pair<T,V> p){cerr<<"{";_print(p.first);cerr<<",";_print(p.second);cerr<<"}";}
template<typename T> void _print(vector<T> v){cerr<<"[ "; for(T i:v){_print(i); cerr<<" ";} cerr<<"]";}
template<typename T> void _print(set<T> s){cerr<<"{ "; for(T i:s){_print(i); cerr<<" ";} cerr<<"}";}
template<typename T> void _print(multiset<T> s){cerr<<"{ "; for(T i:s){_print(i); cerr<<" ";} cerr<<"}";}
template<typename K, typename V> void _print(map<K,V> m){cerr<<"{ "; for(auto i:m){_print(i); cerr<<" ";} cerr<<"}";}
template<typename T> void _print(vector<vector<T>> v){
    cerr<<"[\n";
    for(auto &row:v){ cerr<<"  [ "; for(auto &x:row){ _print(x); cerr<<" "; } cerr<<"]\n"; }
    cerr<<"]";
}

// ---------- Utility Functions ----------
template<typename T> void sort(vector<T>& a){sort(a.begin(),a.end());}
template<typename T> void rsort(vector<T>& a){sort(a.rbegin(),a.rend());}
template<> void sort<string>(vector<string>& a){sort(a.begin(),a.end());}
template<typename T> T summ(const vector<T>& a){return accumulate(a.begin(),a.end(),T(0));}
template<typename T> void in(vector<T>& a){for(auto &i:a){cin>>i;}}

// ===================================================
// =================== SOLVE FUNCTION =================
// ===================================================
void solve1(){
    
    ll n,k,q;
    cin>>n>>k>>q;
    vector<ll>arr;
    for(int i=0;i<=k-1;i++) arr.push_back(i);

    vector<ll>diff(n+2,0);

    vector<pair<ll,ll>>que;

    vector<pair<ll,ll>>mini;
    vector<ll>ans(n+1,-1);
 set<int>st;
    while(q--)
    {
        ll op;
        cin>>op;

        ll l,r;
        cin>>l>>r;
       
        if(op==2)
        {
            diff[l]++;
            diff[r+1]--;
            que.push_back({l,r});
        }
        else
        {
            // pul
            while(l<=r)
            {
                st.insert(l);
                ans[l]=1e9;
                l++;
            }
        }
        
    }

   

    ll sum=0;
     
    for(int i=1;i<=n;i++)
    {
        sum+=diff[i];
        diff[i]=sum;
        if(diff[i]==0)
        {
            st.insert(i);
            ans[i]=k;
        }
    }
    
    // we have to put l to r
    // 0 0 k-1

    sort(que.begin(),que.end());

    // debug(arr);
    // debug(ans);
  
    int i=0;
    for(auto it:que)
    {
        ll l=it.first;
        ll r=it.second;


        while(l<=r)
        {
            if(st.count(l)) 
            {
                l++;
                continue;
            }
            st.insert(l);
            ans[l]=arr[i];
            i=(i+1)%arr.size();
            l++;
        }
    

    
    }

    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int t;
    cin >> t;
    while(t--){
        solve1();
    }
    return 0;
}