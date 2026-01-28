#include <bits/stdc++.h>
using namespace std;

long long computeF(const vector<int>& P, int n){
    long long ascents = 0;
    for(int i = 0; i < n-1; i++){
        if(P[i] < P[i+1]) ascents++;
    }
    
    vector<int> Q(n+1);
    for(int i = 0; i < n; i++){
        Q[P[i]] = i;
    }
    
    long long descents = 0;
    for(int v = 1; v < n; v++){
        if(Q[v] > Q[v+1]) descents++;
    }
    
    return ascents + descents;
}

int main(){
    // Test 1: n=6, k=6
    {
        int n = 6;
        vector<int> P;
        for(int v = 2; v <= n; v += 2) P.push_back(v);
        for(int v = 1; v <= n; v += 2) P.push_back(v);
        
        long long f = computeF(P, n);
        cout << "Test 1: n=6, k=6" << endl;
        cout << "  P = [";
        for(int i = 0; i < n; i++) cout << P[i] << (i < n-1 ? ", " : "");
        cout << "]" << endl;
        cout << "  f(P) = " << f << " >= 6? " << (f >= 6 ? "YES" : "NO") << endl;
    }
    
    // Test 2: n=100000, k=199000
    {
        int n = 100000;
        int mult = 123;
        vector<int> P(n);
        for(int i = 0; i < n; i++){
            P[i] = ((long long)i * mult) % n + 1;
        }
        
        long long f = computeF(P, n);
        cout << "\nTest 2: n=100000, k=199000" << endl;
        cout << "  f(P) = " << f << " >= 199000? " << (f >= 199000 ? "YES" : "NO") << endl;
    }
    
    return 0;
}
