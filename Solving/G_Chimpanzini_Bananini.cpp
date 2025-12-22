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
// ---------- Debug Extended ----------

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << "\n";
#else
#define debug(x)
#endif

// Base print
template<typename T> void _print(const T &t){ cerr << t; }

// String
template<> void _print<string>(const string &t){ cerr << '"' << t << '"'; }

// Pair
template<typename T, typename V> 
void _print(const pair<T,V> &p){
    cerr << "{";
    _print(p.first);
    cerr << ", ";
    _print(p.second);
    cerr << "}";
}

// Vector
template<typename T>
void _print(const vector<T> &v){
    cerr << "[ ";
    for(const T &i : v){
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

// 2D Vector
template<typename T>
void _print(const vector<vector<T>> &v){
    cerr << "[\n";
    for(auto &row : v){
        cerr << "  [ ";
        for(auto &x: row){
            _print(x);
            cerr << " ";
        }
        cerr << "]\n";
    }
    cerr << "]";
}

// Set
template<typename T>
void _print(const set<T> &s){
    cerr << "{ ";
    for(const T &i : s){
        _print(i);
        cerr << " ";
    }
    cerr << "}";
}

// Multiset
template<typename T>
void _print(const multiset<T> &s){
    cerr << "{ ";
    for(const T &i : s){
        _print(i);
        cerr << " ";
    }
    cerr << "}";
}

// Map
template<typename K, typename V>
void _print(const map<K,V> &m){
    cerr << "{ ";
    for(auto &p : m){
        _print(p);
        cerr << " ";
    }
    cerr << "}";
}

// ---------- NEW: DEQUE ----------
template<typename T>
void _print(const deque<T> &dq){
    cerr << "deque[ ";
    for(const T &i : dq){
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

// ---------- NEW: QUEUE ----------
template<typename T>
void _print(queue<T> q){
    cerr << "queue[ ";
    while(!q.empty()){
        _print(q.front());
        cerr << " ";
        q.pop();
    }
    cerr << "]";
}

// ---------- NEW: STACK ----------
template<typename T>
void _print(stack<T> st){
    cerr << "stack[ ";
    vector<T> temp;
    while(!st.empty()){
        temp.push_back(st.top());
        st.pop();
    }
    reverse(temp.begin(), temp.end());
    for(auto &i : temp){
        _print(i);
        cerr << " ";
    }
    cerr << "]";
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
   ll revans=0;
   ll ans=0;
   ll sum=0;

   ll curlen=0;

   deque<ll>dq;

   bool f=1;

   ll q;
   cin>>q;

   while(q--)
   {
      ll type;
      cin>>type;

      if(type==3)
      {
        ll ele;
        cin>>ele;

        curlen++;
        sum+=ele;

        ans+=curlen*ele;
        revans=revans+sum;
       
        if(f)
        {
           dq.push_back(ele);
        }
        else
        {
           dq.push_front(ele);
        }

      }
      else if(type==2)
      {
         f=!f;
         swap(revans,ans);
      }
      else
      {
          // shift that here do effect on the oht arra
          
          if(f)
          {
              int lastele=dq.back();
              ans=ans+sum-curlen*lastele;
              dq.pop_back();
              dq.push_front(lastele);

              revans+=-sum+curlen*lastele;

              debug(f);
              debug(lastele);

          }
          else
          {
             // here ulta honga 
              int lastele=dq.front();
              ans=ans+sum-curlen*lastele;
              dq.pop_front();
              dq.push_back(lastele);
              revans+=-sum+curlen*lastele;
             
          }
      }
      debug(dq);
      debug(revans);
      debug(ans);

      cout<<ans<<endl;
   }

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