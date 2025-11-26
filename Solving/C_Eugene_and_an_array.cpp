// // Author: anuj
// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;
// #define ll long long

// // ---------- PBDS ----------
// template <typename T>
// using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

// // ---------- Debug ----------
// #ifndef ONLINE_JUDGE
// #define debug(x) cerr<<#x<<" "; _print(x); cerr<<"\n";
// #else
// #define debug(x)
// #endif

// // Primitive types
// template<typename T> void _print(T t){cerr<<t;}
// template<> void _print<string>(string t){cerr<<'"'<<t<<'"';}
// template<typename T,typename V> void _print(pair<T,V> p){cerr<<"{";_print(p.first);cerr<<",";_print(p.second);cerr<<"}";}
// template<typename T> void _print(vector<T> v){cerr<<"[ "; for(T i:v){_print(i); cerr<<" ";} cerr<<"]";}
// template<typename T> void _print(set<T> s){cerr<<"{ "; for(T i:s){_print(i); cerr<<" ";} cerr<<"}";}
// template<typename T> void _print(multiset<T> s){cerr<<"{ "; for(T i:s){_print(i); cerr<<" ";} cerr<<"}";}
// template<typename K, typename V> void _print(map<K,V> m){cerr<<"{ "; for(auto i:m){_print(i); cerr<<" ";} cerr<<"}";}
// template<typename T> void _print(vector<vector<T>> v){
//     cerr<<"[\n";
//     for(auto &row:v){ cerr<<"  [ "; for(auto &x:row){ _print(x); cerr<<" "; } cerr<<"]\n"; }
//     cerr<<"]";
// }

// // Utility
// template<typename T> void in(vector<T>& a){for(auto &i:a){cin>>i;}}

// // -------- Min Segment Tree for dupnext --------
// struct SegTree {
//     int n;
//     vector<ll> st;
//     SegTree(){}
//     SegTree(vector<ll> &a){ init(a); }

//     void init(vector<ll> &a){
//         n = a.size();
//         st.assign(4*n, LLONG_MAX);
//         build(1,0,n-1,a);
//     }
//     void build(int p,int l,int r,vector<ll> &a){
//         if(l==r){ st[p]=a[l]; return; }
//         int m=(l+r)/2;
//         build(2*p,l,m,a);
//         build(2*p+1,m+1,r,a);
//         st[p]=min(st[2*p],st[2*p+1]);
//     }
//     ll query(int p,int l,int r,int ql,int qr){
//         if(qr<l || r<ql) return LLONG_MAX;
//         if(ql<=l && r<=qr) return st[p];
//         int m=(l+r)/2;
//         return min(query(2*p,l,m,ql,qr), query(2*p+1,m+1,r,ql,qr));
//     }
//     ll query(int l,int r){
//         if(l>r) return LLONG_MAX;
//         return query(1,0,n-1,l,r);
//     }
// };

// // ll solve1(){
// //     // int n;
// //     // cin >> n;
// //     // vector<ll> arr(n);
// //     // in(arr);

// //     // // ---- Prefix sums with prefix[0] = 0 ----
// //     // vector<ll> pre(n+1);
// //     // for(int i=1;i<=n;i++)
// //     //     pre[i] = pre[i-1] + arr[i-1];
// //     // debug(pre);

// //     // // ---- Next occurrence of same prefix ----
// //     // map<ll,ll> mp;
// //     // for(int i=0;i<=n;i++)
// //     //     mp[pre[i]] = n+1;

// //     // vector<ll> dupnext(n+1, n+1);
// //     // for(int i=n;i>=0;i--){
// //     //     dupnext[i] = mp[pre[i]];
// //     //     mp[pre[i]] = i;
// //     // }
// //     // debug(dupnext);

// //     // SegTree sgtree(dupnext);

// //     // ll ans = 0;

// //     // // ---- Count good subarrays ending at i ----
// //     // for(int i=1;i<=n;i++){
// //     //     ll s = 0, e = i, curl = i;

// //     //     while(s <= e){
// //     //         ll mid = (s + e) / 2;
// //     //         ll mini = sgtree.query(mid, i);

// //     //         if(mini > i){
// //     //             curl = mid;
// //     //             e = mid - 1;
// //     //         } else {
// //     //             s = mid + 1;
// //     //         }
// //     //     }

// //     //     ans += (i - curl + 1);
// //     // }

// //     // return ans;
// // }
// ll solve1(){
//     int n;
//     cin >> n;
//     vector<ll> arr(n);
//     in(arr);
    
//     vector<ll> pre(n+1, 0);
//     for(int i=0;i<n;i++)
//     {
//         pre[i+1] = pre[i] + arr[i];  
//     }
    
//     map<ll,int> mp;
//     vector<ll> dupnext(n+2, n+1); 
    
//     for(int i = n; i >= 0; i--)
//     {  
//         if(mp.find(pre[i]) != mp.end()){
//             dupnext[i] = mp[pre[i]];
//         }
//         mp[pre[i]] = i;
//     }
    
//     debug(dupnext);
    
//     SegTree sgtree(dupnext);
    
//     ll ans=0;
    
//     for(int i=1; i<=n; i++){  

//         int curl = 0;
//         int s = 0, e = i-1;  
        
//         if(arr[i-1]==0) continue;
        
//         while(s <= e){
//             int mid = s + (e-s)/2;
//             ll minval = sgtree.query(mid, i);  
        
//             if(minval > i)
//             {
//                 curl = mid;
//                 e = mid - 1;
//             }
//             else{
//                 s = mid + 1;
//             }
//         }
        
//         ans += (i-curl);  
//     }
    
//     return ans;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int t=1;
//     while(t--){
//         cout << solve1() << "\n";
//     }
//     return 0;
// }


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

ll solve1(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    in(arr);

    ll ans = 0;
    ll i = 0, j = 0;

    ll pref = 0;           // current prefix sum while expanding
    vector<ll> pre(n);     

    // Build zero-based prefix array
    for(int k = 0; k < n; k++){
        pref += arr[k];
        pre[k] = pref;
    }

    set<ll> st;
    st.insert(0);         

    while(j < n){
    
        while(st.count(pre[j]))
        {
            st.erase(i == 0 ? 0 : pre[i-1]);
            i++;
        }
        st.insert(pre[j]);

        ans += (j - i + 1);
        j++;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int t=1;
    while(t--){
        cout << solve1() << "\n";
    }
    return 0;
}