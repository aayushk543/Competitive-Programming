
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;

        int count = 0;

        long long temp = x;

        while (temp > 0) {
            temp /= 10;
            count++;
        }
        long long ans = 1;

        for (int i = 0; i < count; i++) ans *= 10;

        

        cout << ans + 1 << '\n';
    }
    return 0;
}