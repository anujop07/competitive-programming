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
       ll n,l,r;
        cin>>n>>l>>r;

        vector<int>p(n+1);

        p[0] = 0;

        for (int i=1;i<=n;i++){
            if (i==r)
            {
                 p[i]=l-1;  
            }
            else
            {
               p[i]=i;      
            }
                   
        }
        int ans=0;
        debug(p);

        vector<ll>arr;
        for (int i = 1; i <= n; i++) 
        {
            int ai = p[i] ^ p[i-1];
            if (ai == 0) ai = 1; 
            debug(i);
            debug(p[i]);
            debug(p[i-1]);
            if(i>=l && i<=r)
            {
                ans=ans^ai;
            }
            debug(ai);
            arr.push_back(ai);
            cout << ai << " ";
        }
        cout<<endl;
        debug(ans);
        // // cout<<ans<<endl;
        // for(int i=0;i<n;i++)
        // {
        //     ll cur=0;
        //     for(int j=i;j<n;j++)
        //     {
        //        cur=cur^arr[j];
        //        if(cur==0)
        //        {
        //         debug("ADHASD");
        //        }
        //     }
        // }


    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
    solve1();
    }
    return 0;
}