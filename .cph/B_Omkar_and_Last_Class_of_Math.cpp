#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        long long n;
        cin >> n;

        if(n % 2 == 0) {
            cout << (n >> 1) << " " << (n >> 1) << '\n';
        }
        else {
            //cout << 1 << " " << n << '\n';
            int ans = n - 1;
            int a = 1, b = n-1;

            for(int i = 1; i * i <= n; i++) {

                if(n % i == 0) {

                    long long curr = i;
                    long long curr2 = n - i;

                    if(ans > (curr * curr2) / gcd(curr, curr2)) {
                        ans = (curr * curr2) / gcd(curr, curr2);
                        a = curr;
                        b = curr2;
                    }

                    if(curr == 1) continue;

                    curr = n / i;
                    curr2 = n - curr;

                    if(ans > (curr * curr2) / gcd(curr, curr2)) {
                        ans = (curr * curr2) / gcd(curr, curr2);
                        a = curr;
                        b = curr2;
                    }
                }
            }

            cout << a << " " << b << '\n';
        }
    }
    return 0;
}