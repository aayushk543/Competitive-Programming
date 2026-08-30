#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int f(int num) {

    if(num == 0) return 1;
    if(num < 0) return 0;

    int count = 0;

    for(int i = 1; i <= (num / 2); i++) {

        int curr = i;
        int p = 2;

        while(curr*p <= num) {
            count += f(num - curr*p);
            p += 2;
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n;

       cin >> n;

       long long ans = 0;

       for(int i = 0; i <= n; i++) {
        ans += f(n - i);
       }

       cout << ans << '\n';
    }
    return 0;
}