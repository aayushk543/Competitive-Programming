#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if(b == 0) return a;

    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        long long a = -1;
        long long b = -1;

        vector<long long> arr(n + 1);

        for(int i = 1; i <= n; i++) {
            cin >> arr[i];

            if(i == 1) a = arr[1];
            else if(i == 2) b = arr[2];

            if(i % 2 == 1) a = gcd(a, arr[i]);
            else b = gcd(b, arr[i]);
        }

        bool flag = true;
        
        for(int i = 1; i <= n; i += 2) {
            if(arr[i] % b == 0) {
                flag = false;
                break;
            }

            if(i + 2 > n) flag = true;
        }

        if(flag == true) {
            cout << b << '\n';
            continue;
        }

        if(flag == false) {
            for(int i = 2; i <= n; i += 2) {
                if(arr[i] % a == 0) {
                    flag = false;
                    break;
                }

                if(i + 2 > n) flag = true;
            }
        }

        if(flag == false) cout << 0 << '\n';
        else cout << a << '\n'; 


    }

    return 0;
}
