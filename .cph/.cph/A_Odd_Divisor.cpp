#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       long long n;
       cin >> n;

       if(n % 2 == 1) cout << "YES" << '\n';
       else {

        while(n > 1 && (1 & n) == 0) n = n >> 1;
        
        if(n > 1) cout << "YES" << '\n';
        else cout << "NO" << '\n';
       } 
    }
    return 0;
}