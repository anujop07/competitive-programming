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
// ll solve(vector<ll>arr,ll sum,ll req)
// {
//     // now find out left most where
//     // (i+1)*2!=sumupto that

// }
void solve1()
{
    set<ll>st;
    int n;
    cin >> n;

    ll q;
    cin>>q;
    vector<ll> arr(n);
    in(arr);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            st.insert(i);
        }
    }

    ll sum=summ(arr);
    while(q--)
    {
        ll op;
        cin>>op;

        if(op==1)
        {
            ll curr;
            cin>>curr;
            
            if(curr>sum)
            {
                cout<<"NO"<<endl;
                continue;
            }
            if(curr==sum)
            {
                cout<<"YES"<<endl;
                continue;
            }
            //now
            if(curr%2==sum%2)
            {
                cout<<"YES"<<endl;
                continue;
            }

            // done 
            bool f=0;
            // 
             // logic for the checkg over ehre
              int sub=0;
              if(sum%2==0)
              {
                 sub=1;
              }
             if(st.size()>0)
             {
                // 
                int leftI=*(st.begin());
                if(sum-2*(leftI)-sub>=curr)
                {
                    f=1;
                }
                int rh=*(st.rbegin());
                debug(rh);
                debug(leftI);
                int cn=n-(rh)-1;
                if(sum-2*(cn)-sub>=curr)
                {
                    f=1;
                }

             }

            if(f)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
        else
        {
            ll idx;
            ll val;
            cin>>idx>>val;

            idx--;
            if(arr[idx]==2 && val==1)
            {
                st.insert(idx);
            }
            if(arr[idx]==1 && val==2)
            {
                st.erase(idx);
            }
            sum+=(val-arr[idx]);
            arr[idx]=val;
        }

        // debug(q);
        // debug(sum);
        debug(arr);
        debug(st);

    }


    return;
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