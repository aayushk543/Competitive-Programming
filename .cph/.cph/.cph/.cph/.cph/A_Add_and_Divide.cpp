#include<bits/stdc++.h>
using namespace std;

int check(long long a, long long b) {
    int count = 0;
    while(a > 0) {
        a /= b;
        count++;
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        long long a,b;

        cin >> a >> b;
        int ans = INT_MAX;

        for(int i = 0; i <= 40; i++) {
            int curr_b = b + i;
            
            if(curr_b == 1) continue;

            long long x = a;
            int count = 0;

            while(x > 0) {
                x /= curr_b;
                count++;
            }

            ans = min(count + i, ans);
        }

        cout << ans << '\n';

    }
    return 0;
}