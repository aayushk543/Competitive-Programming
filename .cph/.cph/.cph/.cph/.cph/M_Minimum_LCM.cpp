#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        if(n % 2 == 0) cout << n/2 << " " << n/2 << '\n';
        else {
            long long last = -1;
            for(long long i = 3; i * i <= n; i+=2) {
                if(n % i == 0) {
                    last = i;
                    break;
                }
            }

            if(last == -1) last = 1;
            else {
                last = n / last;
            }

            cout << last << " " << n - last << '\n';
        }

    }
    return 0;
}