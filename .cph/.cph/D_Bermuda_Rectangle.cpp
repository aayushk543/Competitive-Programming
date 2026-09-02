#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       long long S;
       int q;

       cin >> S >> q;

       vector<vector<long long>> factors;

       for(int i = 1; i * i <= S; i++) {
        if(S % i == 0) factors.push_back({i, (S*1LL)/((long long)i)});
       }

       for(int i = 1; i <= q; i++) {
        long long x,y;
        cin >> x >> y;

        long long ans = 0;
        long long prev = 0;

        for(int j = 0; j < factors.size(); j++) {
            ans += min(y, factors[j][1]) * abs(prev - min(factors[j][0], x));
            prev = min(factors[j][0], x);

            if(prev == x) break;
        }

        for(int j = factors.size() - 1; j >= 0; j--) {
            ans += min(y, factors[j][0]) * abs(prev - min(factors[j][1], x));
            prev = min(factors[j][1], x);

            if(prev == x) break;
        }

        cout << ans << '\n';
       }

    }
    return 0;
}