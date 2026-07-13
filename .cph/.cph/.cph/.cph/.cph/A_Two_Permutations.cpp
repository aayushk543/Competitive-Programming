#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int a,b,n;
       cin >> n >> a >> b;

       if((a == b && a == n) || (a + b + 1 < n)) cout << "Yes" << '\n';
       else cout << "No" << '\n';
    }
    return 0;
}