#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        long long a,b,c;
        cin >> a >> b >> c;

        if(a + c - b < b - a) cout << b - a << '\n';
        else {
            cout << a + c - b << '\n';
        }
    }

    

}