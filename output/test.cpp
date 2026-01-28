#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 6, k = 123;
    // Since gcd(123, 6) = gcd(123, 6) = 3 != 1, this won't work as permutation
    cout << __gcd(123, 6) << endl;
    return 0;
}
