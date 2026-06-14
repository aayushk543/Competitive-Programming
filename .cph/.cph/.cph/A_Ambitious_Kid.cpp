#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int ans = INT_MAX;

    for(int i = 0; i < n; i++){
        int x;
        
        cin >> x;
        if(x < 0) x *= -1;
        ans = min(ans,x);
    }
    cout << ans << '\n';

    return 0;
}
