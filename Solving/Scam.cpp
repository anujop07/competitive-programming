#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<"\n";
#else
#define debug(x)
#endif

template<typename T> void _print(T t){cerr<<t;}
template<> void _print<string>(string t){cerr<<'"'<<t<<'"';}
template<typename T,typename V> void _print(pair<T,V> p){cerr<<"{";_print(p.first);cerr<<",";_print(p.second)<<"}";}
template<typename T> void _print(vector<T> v){cerr<<"[ "; for(T i:v){_print(i); cerr<<" ";} cerr<<"]";}
template<typename T> void _print(set<T> s){cerr<<"{ "; for(T i:s){_print(i); cerr<<" ";} cerr<<"}";}
template<typename T> void _print(multiset<T> s){cerr<<"{ "; for(T i:s){_print(i); cerr<<" ";} cerr<<"}";}
template<typename K, typename V> void _print(map<K,V> m){cerr<<"{ "; for(auto i:m){_print(i); cerr<<" ";} cerr<<"}";}
template<typename T> void _print(vector<vector<T>> v){
    cerr<<"[\n";
    for(auto &row:v){ cerr<<"  [ "; for(auto &x:row){ _print(x); cerr<<" "; } cerr<<"]\n"; }
    cerr<<"]";
}

template<typename T> void in(vector<T>& a){for(auto &i:a){cin>>i;}}

ll solve(ll cn, map<ll,ll>& mp, ll x, map<ll,ll>& curr)
{
    ll best = -1, mini = LLONG_MAX;
    for(auto &it : mp)
    {
        if(it.first == x || it.second == 0) continue;
        ll used = curr.count(it.first) ? curr[it.first] : 0;
        if(used < mini)
        {
            mini = used;
            best = it.first;
        }
    }
    if(best != -1) mp[best]--;
    return best;
}

ll wiiner(map<ll,ll>mp)
{
    // map<ll,ll> mp;
    // while(i>=0)
    // {
    //     if(arr[i] != -1) mp[arr[i]]++;
    //     i--;
    // }
    ll maxi = 0, can = -1;
    for(auto &it : mp)
    {
        if(it.second > maxi)
        {
            maxi = it.second;
            can = it.first;
        }
    }
    ll cnt = 0;
    for(auto &it : mp)
    {
        if(it.second == maxi) cnt++;
    }
    if(cnt >= 2) return -1;
    return can;
}

ll solve1(){
    int n;
    cin >> n;

    ll x;
    cin >> x;

    vector<ll> arr(n);
    in(arr);

    map<ll,ll> mp;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=-1) mp[arr[i]]++;
    }

    ll cn = mp[x];

    for(int i=0;i<n;i++)
    {
        if(arr[i]!=-1)
        {
            if(cn>0)
            {
                cn--;
                arr[i]=x;
            }
            else arr[i]=-2;
        }
    }
    mp[x]=0;

    debug(arr);

    ll seenx = 0;
    map<ll,ll> curr;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==x) seenx++;
        if(arr[i]==-2)
        {
            ll op = solve(seenx, mp, x, curr);
            arr[i]=op;
            curr[op]++;
        }
    }

    map<ll,ll> vote;

    map<ll,ll>op2;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==-1)
        {
            ll give = wiiner(op2);
            if(give!=-1) vote[give]++;
        }
        else
        {
            op2[arr[i]]++;
            vote[arr[i]]++;
        }
        // else 
    }

    ll maxi = 0, winner = -1;
    for(auto &it : vote)
    {
        if(it.first==-1) continue;
        if(it.second > maxi)
        {
            maxi = it.second;
            winner = it.first;
        }
    }

    ll cnt2 = 0;
    for(auto &it : vote)
    {
        if(it.second == maxi) cnt2++;
    }

    if(cnt2>=2 || winner!=x) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
       if(solve1())
           cout<<"YES\n";
       else
           cout<<"NO\n";
    }
    return 0;
}
