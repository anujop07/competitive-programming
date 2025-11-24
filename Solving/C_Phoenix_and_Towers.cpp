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
    ll n;
    cin >> n;
    ll m,x;
    cin>>m>>x;



    priority_queue<  pair<ll,ll>,vector<  pair<ll,ll>>,greater<  pair<ll,ll>>>pq;


    for(int i=0;i<m;i++) pq.push({0,i});
    vector<ll> arr(n);
    in(arr);


    // sort(arr);


    map<int,int>id;
    for(int i=0;i<n;i++)
    {
        ll id1=pq.top().second;
        ll sum=pq.top().first;
        pq.pop();

        sum+=arr[i];

        pq.push({sum,id1});
        id[i]=id1;
    }
      ll mini=INT_MAX;
    ll maxi=INT_MIN;
    for(auto it:id)
    {
        mini=min(mini,(ll)it.second);
        maxi=max(maxi,(ll)it.second);
        // cout<<it.second+1<<" ";

    }

    if(maxi-mini>x)
    {
        cout<<"NO"<<endl;
        return ;
    }
    cout<<"YES"<<endl;
    // ll mini=INT_MAX;
    // ll maxi=INT_MIN;
    for(auto it:id)
    {
        // mini=min(mini,it.second);
        // maxi=max(maxi,it.second);
        cout<<it.second+1<<" ";

    }
    cout<<endl;

    return ;
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