#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;

        bool flag = true;

        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                if((i <= m && i != 1) || ((n / i) <= m && (n / i) != 1)) {
                    flag = false;
                    cout << "NO" << '\n';
                    break;
                }
            }
        }

        if(flag) {
            //if(m >= n) cout << "NO" << '\n';
            cout << "YES" << '\n';
        }
    }
    
    return 0;
}