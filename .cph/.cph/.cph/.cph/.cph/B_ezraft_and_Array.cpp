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

        long long count = 6;

        if(n == 2) {
            cout << -1 << '\n';
            continue;
        }
        
        for(int i = 1; i <= n; i++) {
            if(i == 1 || i == 2 || i == 3) cout << i << " ";
            else {
                cout << count << " ";
                count *= 2;
            }
        }

        cout << '\n';
    }
    return 0;
}