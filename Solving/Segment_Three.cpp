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
const ll INF = (ll)4e18;

ll dp_solve(int i, int previn1_mod, int previn2_mod, const vector<ll>& arr, vector<vector<vector<ll>>> &dp) {
    int n = (int)arr.size();
    if (i >= n) return 0;
    previn1_mod %= 3; if(previn1_mod<0) previn1_mod+=3;
    previn2_mod %= 3; if(previn2_mod<0) previn2_mod+=3;
    if (dp[i][previn1_mod][previn2_mod] != -1) return dp[i][previn1_mod][previn2_mod];

    // compute sum modulo 3 of triple (i-2, i-1, i)
    int a2 = (int)((arr[i-2] + previn2_mod) % 3); // arr[i-2] + previn2
    int a1 = (int)((arr[i-1] + previn1_mod) % 3); // arr[i-1] + previn1
    int a0 = (int)(arr[i] % 3); // arr[i]
    int sum_mod = (a2 + a1 + a0) % 3;

    ll &res = dp[i][previn1_mod][previn2_mod];
    res = INF;

    if (sum_mod == 0) {
        // no increments needed at position i
        // shift: new previn1 = 0 (no increment applied to arr[i]), new previn2 = previn1
        res = dp_solve(i+1, 0, previn1_mod, arr, dp);
        return res;
    }

    int need = (3 - sum_mod) % 3; // need == 1 or 2

    if (need == 1) {
        // try all ways to distribute 1 increment among (i-2, i-1, i)
        // distributions: (1,0,0), (0,1,0), (0,0,1)
        // cost = 1 each
        // if we add to arr[i-2]: previn2 increases by 1
        {
            ll opt = dp_solve(i+1, 0, (previn1_mod + 1) % 3, arr, dp); // increment applied to arr[i-1]? careful mapping below
            // NOTE: mapping chosen:
            //   inc to arr[i-2]  -> affects previn2 (but it was part of earlier triple; still we follow user's original approach and allow it)
            //   inc to arr[i-1]  -> affects previn1 for next shift (previn1 + 1 becomes previn2_next)
            //   inc to arr[i]    -> becomes previn1_next = 1
            // To keep consistent with the transition used elsewhere, we'll enumerate explicitly below.
            // We will overwrite opt after enumerating precise transitions below.
        }
        // clearer enumeration:
        // inc to arr[i-2]:
        {
            // increment i-2 by 1 -> previn2 for current triple increased by 1,
            // next state's previn1 = 0 (no inc to arr[i]), previn2 = previn1_mod + 1 (shift)
            ll opt = dp_solve(i+1, 0, (previn1_mod + 1) % 3, arr, dp);
            res = min(res, 1 + opt);
        }
        // inc to arr[i-1]:
        {
            // increment i-1 by 1 -> previn1 increases by 1 for the current triple
            // next state's previn1 = 0, previn2 = (previn1_mod + 1) % 3
            ll opt = dp_solve(i+1, 0, (previn1_mod + 1) % 3, arr, dp);
            res = min(res, 1 + opt);
        }
        // inc to arr[i]:
        {
            // increment i by 1 -> next state's previn1 = 1, previn2 = previn1_mod
            ll opt = dp_solve(i+1, 1 % 3, previn1_mod, arr, dp);
            res = min(res, 1 + opt);
        }

        return res;
    } else { // need == 2
        // distribute total of 2 increments among (i-2, i-1, i)
        // possible distributions (a,b,c) with a+b+c = 2, a,b,c in {0,1,2}
        vector<array<int,3>> dist = {
            {2,0,0}, {0,2,0}, {0,0,2},
            {1,1,0}, {1,0,1}, {0,1,1}
        };
        for (auto &d : dist) {
            int add_i2 = d[0]; // add to arr[i-2]
            int add_i1 = d[1]; // add to arr[i-1]
            int add_i0 = d[2]; // add to arr[i]
            // next state's previn1 = add_i0 % 3
            // next state's previn2 = (previn1_mod + add_i1) % 3
            ll opt = dp_solve(i+1, add_i0 % 3, (previn1_mod + add_i1) % 3, arr, dp);
            res = min(res, (ll)(add_i2 + add_i1 + add_i0) + opt);
        }
        return res;
    }
}

ll solve1(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    in(arr);

    if (n < 3) {
        cout << 0 << "\n";
        return 0;
    }

    // dp[i][previn1_mod][previn2_mod], i ranges from 0..n
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(3, vector<ll>(3, -1)));

    // start processing from i = 2 (first triple is indices 0,1,2) with zero previous increments
    ll ans = dp_solve(2, 0, 0, arr, dp);
    return ans;
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
