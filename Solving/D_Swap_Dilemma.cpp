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

ll mergeAndCount(vector<ll> &a, ll l, ll m, ll r) {
    ll cnt = 0;
    ll n1 = m - l + 1;
    ll n2 = r - m;

    vector<ll> L(n1), R(n2);

    for (ll i = 0; i < n1; i++) L[i] = a[l + i];
    for (ll i = 0; i < n2; i++) R[i] = a[m + 1 + i];

    ll i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            // inversion: all remaining in L are > R[j]
            cnt += (n1 - i);
            a[k++] = R[j++];
        }
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    return cnt;
}

ll mergeSortAndCount(vector<ll> &a, ll l, ll r) {
    if (l >= r) return 0;

    ll m = (l + r) / 2;
    ll cnt = 0;

    cnt += mergeSortAndCount(a, l, m);
    cnt += mergeSortAndCount(a, m + 1, r);
    cnt += mergeAndCount(a, l, m, r);

    return cnt;
}

ll countInversions(vector<ll> &a) {
    return mergeSortAndCount(a, 0, (ll)a.size() - 1);
}
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

    vector<ll>brr(n);
    in(brr);
    vector<pair<ll,ll>>nums;

    map<int,int>mp;
    set<ll>st1(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        mp[i]=arr[i];
        if(!st1.count(brr[i]))
        {
           return false;
        }
        nums.push_back({brr[i],i});
    }
    sort(brr);

    sort(nums);
    // debug(st1);

    for(int i=0;i<n;i++)
    {
        arr[i]=mp[nums[i].second];
    }

    debug(arr);
    debug(brr);
    if(arr==brr) return true;

    ll cn=countInversions(arr);
    if(cn%2==0) return true;

    return false;

    

    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
       if(solve1())
       {
        cout<<"YES"<<endl;
       }
       else
       {
        cout<<"NO"<<endl;
       }
    }
    return 0;
}