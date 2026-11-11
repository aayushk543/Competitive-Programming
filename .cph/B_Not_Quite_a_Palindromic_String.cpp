#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;

        string s;
        cin >> s;

        int count = 0;
        int count_0 = 0, count_1 = 0;

        for(int i = 0; i < n; i++) {

            if(s[i] == '0') count_0++;
            else count_1++;
        }

        int total = n / 2;
        int diff_p = total - k;

        count_0 -= diff_p;
        count_1 -= diff_p;

        if(count_0 % 2 == 0 && count_1 % 2 == 0 && ((count_0 / 2) + (count_1 / 2) == k) && count_0 >= 0 && count_1 >= 0) {
            cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
        
    }
    
    return 0;
}