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

       int a = -1, b = -1, c = -1;

       int l = n;

       for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            n /= i;
            a = i;

            for(int j = i + 1; j * j <= n; j++) {
                if(n % j == 0) {
                    n /= j;

                    if(n == a || n == j || n == 1) continue;
                    
                    b = j;

                    cout << "YES" << '\n';
                    cout << a << " " << b << " " << n << '\n';
                    goto end;
                    break;
                }
            }

            break;
        }

        if(b != -1) break;
       }

       end :

       if(b == -1) cout << "NO" << '\n';
    }
    return 0;
}