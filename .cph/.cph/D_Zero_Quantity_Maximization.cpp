#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> f(long long x, long long y) {

    long long g = gcd(x, y);
    return {x / g, y / g};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if(1) {
        int n;
        cin >> n;

        vector<long long> arr1(n);
        vector<long long> arr2(n);

        map<pair<long long, long long>, int> mp;

        for(int i = 0; i < n; i++) cin >> arr1[i];
        for(int i = 0; i < n; i++) cin >> arr2[i];

        int ans = 0;
        int c = 0;
        int zero = 0;

        for(int i = 0; i < n; i++) {
            int sign = 1;
            if((arr1[i] > 0 && arr2[i] < 0) || (arr1[i] < 0 && arr2[i] > 0)) sign = -1;

            if(arr1[i] == 0) {
                if(arr2[i] == 0) c += 1;
                continue;
            }
            else if(arr2[i] == 0) {
                zero++;
                continue;
            }

            pair<long long, long long> p = f(abs(arr2[i]), abs(arr1[i]));
            p.first *= sign;
            mp[p] += 1;
            //cout << f(arr2[i], arr1[i]).first << " " << f(arr2[i], arr1[i]).second << '\n';
            ans = max(ans, mp[p]);
        }

        cout << max(ans + c, zero + c) << '\n';
    }
}