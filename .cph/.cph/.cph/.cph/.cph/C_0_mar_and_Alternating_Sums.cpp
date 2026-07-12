#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long> arr;

        int count = 0;

        for(int i = 0; i < n; i++) {
            long long m;
            cin >> m;
            if(m == -1) count++;
            else {
                arr.push_back(m);
            }
        }

        set<long long> s;

        for(int i = 0; i < arr.size(); i++) s.insert(arr[i]);

        sort(arr.begin(), arr.end());
        long long prev = arr[0];

        int count2 = 0;
        long long ans = 0;
        int count_prev = 1;

        long long mod = 1000000007;

        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] == prev + 1) count2++;
            prev = arr[i];
        }

        if(count == 0) {
            ans = 1;

            int power = n - s.size();

            while(power--) {
                ans *= 2;
                ans %= mod;
            }
        }
        else {
            ans = 1;
            int power = n - s.size() - 1;

            while(power--) {
                ans *= 2;
                ans %= mod;
            }

            ans *= (count2 + 1);
        }

        cout << ans % mod << '\n';

    }
    return 0;
}