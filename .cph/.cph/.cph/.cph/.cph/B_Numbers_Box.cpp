#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        int sign = 0, mini = 101;
        int sum = 0;

        for(int i = 1; i <= m*n; i++) {
            int m;
            cin >> m;

            if(m < 0) sign++;
            sum += abs(m);
            mini = min(mini, abs(m));
        }

        if(sign % 2 == 0) cout << sum << '\n';
        else cout << sum - 2*mini << '\n';

    }
    return 0;
}