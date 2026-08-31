#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n,k,a,b;

       cin >> n >> k >> a >> b;

       vector<vector<long long>> vec(n + 1);

       for(int i = 1; i <= n; i++) {
        long long u,v;
        cin >> u >> v;

        vec[i] = {u, v};
       }

       long long ans = abs(vec[a][0] - vec[b][0]) + abs(vec[a][1] - vec[b][1]);

       long long h1 = LLONG_MAX;
       long long h2 = LLONG_MAX;

       for(int i = 1; i <= k; i++) {
        h1 = min(h1, abs(vec[a][0] - vec[i][0]) + abs(vec[a][1] - vec[i][1]));
        h2 = min(h2, abs(vec[b][0] - vec[i][0]) + abs(vec[b][1] - vec[i][1]));
       }

    //    if(a <= k) h1 = 0;
    //    if(b <= k) h2 = 0;

       if(h1 != LLONG_MAX && h2 != LLONG_MAX) ans = min(ans, h1 + h2);

       cout << ans << '\n';
    }
    return 0;
}