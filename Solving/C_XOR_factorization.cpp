// Author: anuj
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

pair<ll,ll> remainsolve(ll n)
{
    pair<ll,ll>ans={n,0};

    ll sum=n;

    for(ll ele=1;ele<=n;ele++)
    {
        for(ll ele2=1;ele2<=n;ele2++)
        {
            // debug(ele);
            // debug(ele2);
            if((ele^ele2) == n)
            {
                
                // cout<<ele<<" 0> "<<ele2<<endl;
              ll  cursum=ele+ele2;
               if(sum<cursum)
               {
                  ans.first=ele;
                  ans.second=ele2;
                  sum=cursum;
                //    cout<<ans.first<<" "<<ans.second<<endl;
                //    cout<<" BC : "<<(ele^ele2)<<endl;
               } 
                
            }
        }
    }
    // if(n==0)
    // {
    //     return {0,0};
    // }

    // int msb=0;
    // while((1LL<<(msb+1))<=n)
    // {
    //     msb++;
    // }

    // for(int t=msb;t>=1;t--)
    // {
    //     ll x=(1LL<<t)-1;
    //     ll y=x^n;

    //     if(y>=0 && y<=n)
    //     {
    //         return {x,y};
    //     }
    // }

    // return {0,n};
    // cout<<ans.first<<" "<<ans.second<<endl;
    return ans;
}

void solve1()
{
    ll k,n;
    cin>>n>>k;

    if(k%2==1)
    {
        for(int i=0;i<k;i++)
        {
            cout<<n<<" ";
        }
        cout<<endl;
        return;
    }

    for(int i=0;i<k-2;i++)
    {
        cout<<n<<" ";
    }

    pair<ll,ll> p=remainsolve(n);
    cout<<p.first<<" "<<p.second<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        solve1();
    }
    return 0;
}
