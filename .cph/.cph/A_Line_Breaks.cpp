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
        int n,m;
        cin >> n >> m;

        vector<int> num(n);

        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;

            num[i] = s.length();
        }

        int i = 0;
        int ans = 0;

        while(i < n && m > 0) {
            if(m - num[i] >= 0) {
                m -= num[i];
                ans++;
            }
            else break;

            i++;
        }

        cout << ans << '\n';
    }
    return 0;
}