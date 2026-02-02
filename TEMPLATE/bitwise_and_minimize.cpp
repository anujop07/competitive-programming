#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        ll x, y;
        cin >> x >> y;
        
        ll c = x & y;  
        
        if (c == 0) {
            cout << x << " " << y << "\n";
            continue;
        }
        
        int h = 63 - __builtin_clzll(c);  
        
        ll bestP = x ^ c, bestQ = y, bestCost = c;  
        
        ll mask = (1LL << (h + 1)) - 1;
        ll newX = (x | mask) + 1;
        if ((newX & y) == 0 && newX - x < bestCost) {
            bestCost = newX - x;
            bestP = newX; bestQ = y;
        }
    
        ll newY = (y | mask) + 1;
        if ((newY & x) == 0 && newY - y < bestCost) {
            bestCost = newY - y;
            bestP = x; bestQ = newY;
        }
        
        ll newX2 = (1LL << h) - 1;
        if ((newX2 & y) == 0 && newX2 <= x && x - newX2 < bestCost) {
            bestCost = x - newX2;
            bestP = newX2; bestQ = y;
        }
    
        ll newY2 = (1LL << h) - 1;
        if ((newY2 & x) == 0 && newY2 <= y && y - newY2 < bestCost) {
            bestCost = y - newY2;
            bestP = x; bestQ = newY2;
        }
        
        cout << bestP << " " << bestQ << "\n";
    }
    
    return 0;
}
