#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int c = s[0] - '0';
        int count = 0;

        if(c == 0) {
            int count0 = 0, count1 = 0;

            for(int i = 0; i < n; i++) {
                if(s[i] == '0') count0++;
                else count1++;
            }

            int curr0 = 0, curr1 = 0, ans = n;

            for(int i = 0; i < n; i++) {

                if(s[i] == '0') {
                    ans = min(ans, curr1 + (count0 - curr0 - 1));
                }
                else ans = min(ans, (count0 - curr0) + curr1);

                if(s[i] == '1') curr1++;
                if(s[i] == '0') curr0++;
            }

            cout << ans << '\n';
        }
        else {
            
            for(int i = 0; i < n; i++) {
                if(s[i] == '0') count++;
            }

            cout << count << '\n';
        }


    }

    

}