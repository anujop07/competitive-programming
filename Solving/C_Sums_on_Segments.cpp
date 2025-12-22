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

// void solveP(vector<ll>arr,set<ll>&st)
// {
//     ll sum=0;
//     ll maxi=0;
//     for(int i=0;i<arr.size();i++)
//     {
//         sum+=arr[i];
//         sum=max(sum,0LL);
//         maxi=max(sum,maxi);
//     }
//     i
//     ll neg=0;


// }
void solveP(vector<ll> arr, set<ll> &st) {
    ll sum = 0;
    ll maxi = LLONG_MIN;

    int start = 0;      // temporary start pointer
    int l = 0, r = 0;   // result indices

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
            l = start;
            r = i;
        }

        if (sum < 0) {
            sum = 0;
            start = i + 1;  
        }
    }

    if(maxi==0) return ;

    //
    ll n=arr.size();
    st.insert(maxi);
    debug(maxi);
    debug(l);
    debug(r);
    while(l>=0 || r<n)
    {
        if(l>=0 && arr[l]==-1)
        {
            maxi--;
            l--;
        }
        else if(r<n && arr[r]==-1)
        {
            maxi--;
            r++;
            st.insert(maxi);
        } 
        else
        {
            if(l>=0 && r<n)
            {
                if(arr[l]<arr[r])
                {
                     maxi+=arr[l];
                    l--;
                    st.insert(max(0LL,maxi));
                }
                else
                {
                    maxi+=arr[r];
                    r++;
                    st.insert(max(0LL,maxi));

                }
            }
            else 
            {
                if(l>=0)
                {
                    maxi+=arr[l];
                    l--;
                    st.insert(max(0LL,maxi));
                }
                else
                {
                    maxi+=arr[r];
                    r++;
                    st.insert(max(0LL,maxi));
                }
            }

        }

        // st.insert(maxi);
    }

    // cout << "Max Sum = " << maxi << "\n";
    // cout << "l = " << l << ", r = " << r << "\n";
}
void solveN(vector<ll> arr, set<ll> &st) {
    ll sum = 0;
    ll maxi = LLONG_MIN;

    int start = 0;      // temporary start pointer
    int l = 0, r = 0;   // result indices


    for(int i=0;i<arr.size();i++)
    {
        arr[i]=-arr[i];
    }
    debug(arr);

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
            l = start;
            r = i;
        }

        if (sum < 0) {
            sum = 0;
            start = i + 1;  
        }
    }

    if(maxi==0) return ;

    //
    ll n=arr.size();
    while(l>=0 || r<n)
    {
        if(l>=0 && arr[l]==-1)
        {
            maxi--;
            l--;
        }
        else 
        {
            if(arr[r]==-1) 
            {
                maxi--;
            }
            else
            {
                maxi++;
            }
            r++;
        }

        st.insert(-maxi);
    }

    // cout << "Max Sum = " << maxi << "\n";
    // cout << "l = " << l << ", r = " << r << "\n";
}
void solve1(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    in(arr);

    // TODO: implement solution here
    set<ll>st;
    solveP(arr,st);
    debug(st);
    solveN(arr,st);

    st.insert(0LL);
    cout<<st.size()<<endl;
    for(auto it:st)
    {
        cout<<it<<" ";
    }
    cout<<endl;
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