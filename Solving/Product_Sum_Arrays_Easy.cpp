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
bool isPrime(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
vector<long long> getDivisors(long long n) {
    vector<long long> divs;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i * i != n) divs.push_back(n / i);
        }
    }

    // sort(divs.begin(), divs.end());
    return divs;
}

ll solve1(){
    ll n;
    cin >> n;

    if(n==1) return 1;

    if(n==2) return 1;

    if(n==3) return 1;
    if(n==4) return 2;


    if(isPrime(n)) return 1;

    
    vector<ll>arr=getDivisors(n);
    // debug(arr);
    if(arr.size()==1) return 2;
    if(arr.size()==2 && isPrime(arr[0]) && isPrime(arr[1])) return 2;
    return 3;
    ll cn=0;
    // // cout<<"ASDA"<<endl;
    // // if(arr.size()<=)
    // return cn+1;
   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        cout << solve1() << "\n";
    }
    return 0;
}