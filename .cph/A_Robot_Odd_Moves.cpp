#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int a,b;
       cin >> a >> b;

       if(b - a > 1) cout << "-1" << '\n';
       else {
        if(a % 2 == 0) {
            if(b % 2 == 0) cout << a << '\n';
            else cout << a + 1 << '\n';
        }
        else {
            if(b % 2 == 0) cout << a + 1 << '\n';
            else cout << a << '\n';
        }
       }
    }
    return 0;
}