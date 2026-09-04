#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>
#include <map>
using namespace std;

long long mod = 1e9 + 7;

long long factorial(long long n) {
    long long ans = 1;

    while(n > 0) {
        ans = (ans*n) % mod;
        n -= 1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<long long> v(n);
        long long all_and;

        for(int i = 0; i < n; i++) {
            cin >> v[i];

            if(i == 0) all_and = v[0];
            else all_and = all_and & v[i];
        }

        long long count = 0;

        for(int i = 0; i < n; i++) if(all_and == v[i]) count++;

        //cout << count << '\n';

        if(count <= 1) cout << 0 << '\n';
        else cout << (((count * (count - 1)) % mod) * (factorial(n - 2) % mod)) % mod << '\n';

        
    }
    return 0;
}