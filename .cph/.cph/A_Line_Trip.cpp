#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;

        int m1;
        int ans = 0;

        for(int i = 0; i < n; i++){
            int m;
            cin >> m;

            if(i == 0) ans = m;

            if(i >= 1){
                ans = max(ans, m - m1);
            }
            if(i == n - 1) ans = max(ans, 2*(k-m));
            m1 = m;
        }

        

        cout << ans << '\n';
    }
    return 0;
}