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

       vector<int> v1(n + 1, 0);
       vector<int> v2(n + 1, 0);

       bool flag = true;

       for(int i = 1; i <= n; i++) {
        int m1, m2;
        cin >> m1 >> m2;

        if(m1 == m2) flag = false;
        else if(v2[m1] == 0 && v2[m2] == 0) {
            v2[m1] = 1;
            v2[m2] = 1;
        }
        else if(v1[m1] == 0 && v1[m2] == 0) {
            v1[m1] = 1;
            v1[m2] = 1;
        }
        else flag = false;

       }

       for(int i = 1; i <= n; i++) {
        if(v1[i] == 0 || v2[i] == 0) flag = false;
       }

       if(flag) cout << "YES" << '\n';
       else cout << "NO" << '\n';

    }
    return 0;
}