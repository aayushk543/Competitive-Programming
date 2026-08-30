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

       int val;
       cin >> val;

       for(int i = 1; i < n; i++) {
        int m;
        cin >> m;

        val = val & m;
       }

    //    int a = 3;
    //    int b = 11;

    //    cout << a & b << '\n';

       cout << val << '\n';
    }
    return 0;
}