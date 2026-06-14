#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long a, b, x;
        cin >> a >> b >> x;

        // if(b > a) swap(a,b);

        // bool c = false;

        // if(a/x == b/x){
        //     c = true;
        // }

        // int count = 0;

        // while(a/x > b) {
        //     a = a/x;
        //     count++;
        // }
        
        // long long ans = count + min(llabs(a - b), 1 + llabs((a / x) - b));

        // if(a <= x && b <= x){
        //     ans = min(ans, llabs(a-b));
        // }

        // if(c) ans = min(llabs(b-a), 2LL);

        vector<pair<long long,long long>> A, B;

        long long cur = a, cost = 0;
        while (true) {
            A.push_back({cur, cost});
            if (cur == 0) break;
            cur /= x;
            cost++;
        }

        cur = b;
        cost = 0;
        while (true) {
            B.push_back({cur, cost});
            if (cur == 0) break;
            cur /= x;
            cost++;
        }

        long long ans = LLONG_MAX;

        for (auto &[u, da] : A) {
            for (auto &[v, db] : B) {
                ans = min(ans, da + db + llabs(u - v));
            }
        }

        cout << ans << '\n';
    }
}


