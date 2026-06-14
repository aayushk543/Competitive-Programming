#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        if(n % 2 == 1){
            ans = 0;
        }
        else{
            ans = n / 4 + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
