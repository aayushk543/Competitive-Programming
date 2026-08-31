#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       long long n,x;

       cin >> n >> x;

       long long curr = n;
       int index = 60;

       long long ans = 0;

       bool p = false;
       bool flag = false;

       for(int i = 0; i <= 60; i++) {

        int n_i = (n >> i) & 1LL;
        int x_i = (x >> i) & 1LL;

        if(n_i == 0 && x_i == 1) {
            p = false;
            break;
        }
        else if(n_i == 1 && x_i == 0) {
            ans = ((n >> (i+1)) + 1) << (i + 1);
        }
       }

       if(ans == 0) ans = n;

       if(p || ans < n || n < x) cout << -1 << '\n';
       else cout <<  ans << '\n';


    }
    return 0;
}