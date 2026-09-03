#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int a,b,c;
       cin >> a >> b >> c;

       if(a == b || b == c || a == c) cout << 0 << '\n';
       else {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        mini = min(a, mini);
        mini = min(b, mini);
        mini = min(c, mini);

        maxi = max(maxi, a);
        maxi = max(maxi, b);
        maxi = max(maxi, c);

        int other = 0;

        for(int i = 1; i <= 3; i++) {
            if(i == 1 ) {
                if(a == mini || a == maxi) continue;
                else {
                    other = a;
                    break;
                }
            }
            if(i == 2) {
                if(b == mini || b == maxi) continue;
                else {
                    other = b;
                    break;
                }
            }
            if(i == 3) {
                if(c == mini || c == maxi) continue;
                else {
                    other = c;
                    break;
                }
            }
        }

        cout << min(maxi - other, other - mini) << '\n';

       }
    }
    return 0;
}