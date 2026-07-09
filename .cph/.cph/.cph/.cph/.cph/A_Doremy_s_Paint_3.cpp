#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m1 = -1, m2 = -1;
        int count1 = 0, count2 = 0;
        bool flag = false;

        for(int i = 0; i < n; i++) {
            int curr;
            cin >> curr;

            if(m1 == -1 || m1 == curr) {
                m1 = curr;
                count1++;
            }
            else if(m2 == -1 || m2 == curr) {
                m2 = curr;
                count2++;
            }
            else flag = true;
        }

        if(count1 < count2) swap(count1, count2);

        if(flag) cout << "No" << '\n';
        else if(m2 == -1) cout << "Yes" << '\n';
        else if(n % 2 && count1 - 1 == count2) cout << "Yes" << '\n';
        else if(n % 2 == 0 && count1 == count2) cout << "Yes" << '\n';
        else cout << "No" << '\n'; 


    }

    return 0;
}
