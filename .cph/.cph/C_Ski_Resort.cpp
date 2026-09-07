#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>
#include <map>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        long long k,q;
        cin >> k >> q;

        long long ans = 0;

        int count = 0;

        for(int i = 0; i < n; i++) {
            long long num;
            cin >> num;

            if(num <= q) {
                count++;
                if(count >= k) ans += (count - (k - 1));
            }
            else count = 0;
        }

        cout << ans << '\n';


    }
    return 0;
}