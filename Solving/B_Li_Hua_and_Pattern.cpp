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
void rotateMatrix(vector<vector<ll>>& mat) {
    int n = mat.size();
  
    // Swap elements from the start and end to
    // rotate by 180 degrees
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            swap(mat[i][j], mat[n - i - 1][n - j - 1]);
        }
    }
  
    // Handle the middle row if the matrix 
    // has odd dimensions
    if (n % 2 != 0) {
        int mid = n / 2;
        for (int j = 0; j < n/2; j++)
            swap(mat[mid][j], mat[mid][n - j - 1]);
    }
}

ll solve1(){
 
    ll n,m,k;
    cin>>n>>k;

    m=n;

    vector<vector<ll>>arr(n,vector<ll>(m,0));
    vector<vector<ll>>brr(n,vector<ll>(m,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            brr[i][j]=arr[i][j];
        }
    }
    rotateMatrix(brr);
    debug(brr);
    
    
    ll cn=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]!=brr[i][j]) cn++;
        }
    }
    debug(cn);
    
    cn=cn/2;
    if(cn>k) return false;

    // return true;
    if(n%2==1) return true;
    k-=cn;
    return k%2==0;


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