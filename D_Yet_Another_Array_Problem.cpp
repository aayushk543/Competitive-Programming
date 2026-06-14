#include <iostream>
#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <string>
#include <numeric>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++){ 
            cin >> a[i];
        }

        long long g = a[0];
        for (int i = 1; i < n; i++) {
            g = gcd(g, a[i]);
        }

        int ans = -1;

        for (long long x = 2; x <= 1000000000000000; x++) {
            
            if (gcd(g, x) == 1) {
                ans = x;
                break;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
