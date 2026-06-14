#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a,b,c;
        cin >> a >> b >> c;
        bool p;

        if(c % 2 == 0){
            if(a > b) p = true;
            else p = false;
        }
        else {
            if(a >= b) p = true;
            else p = false;
        }

        if(p) cout << "First" << '\n';
        else cout << "Second" << '\n';
    }

    return 0;
}
