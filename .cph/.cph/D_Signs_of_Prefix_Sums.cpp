#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int prev = 0;
        int maxi = 1;

        bool flag = true;
        int i = 0;

        bool flag2 = true;
        int cycle = 1;

        while(i < n) {

            int curr = i;
            char sym = s[i];
            while(i < n && sym == s[i]) i++;

            int len = i - curr;

            if((len > 1 || i == 1) && sym == '0') {
                flag = false;
                break;
            }

            if(sym == '0') {
                flag2 = true; 
                cycle = 1;
            }
            else cycle -= 1;

            if(cycle < 0) flag2 = false;

            //cout << prev << " " << len << '\n';

            if(i == n && cycle == 0) break;
            if(len == 1) {
                if(prev == 0) {
                    if(sym == '+') prev = 1;
                    if(sym == '-') prev = -1;

                    //cout << prev << '\n';
                    maxi = max(maxi, prev);
                }
                if(prev < 0) {
                    if(sym == '+') prev = (-1 * prev) + 1;
                    if(sym == '0') prev = -1 * prev;

                    maxi = max(maxi, prev);
                }
                if(prev > 0) {
                    if(sym == '-') {
                        maxi = max(maxi, prev + 1);
                        prev = (prev * - 1) - 1;
                    }
                    if(sym == '0') {
                        maxi = max(maxi, prev);
                        prev = -1 * prev;
                    }
                }
            }
            else {
                if(prev < 0) {
                    if(sym == '+') {
                        maxi = max(maxi, (-1 * prev) + 1);

                        if(len % 2 == 1) prev = 1;
                        else prev = 2;

                        if(flag2) prev = 1;  
                    }

                    
                }
                if(prev > 0) {
                    if(sym == '-') {
                        maxi = max(maxi, prev + 1);
                        if(len % 2 == 1) prev = -1;
                        else prev = -2;

                        if(flag2) prev = -1;
                    }
                }

                if(prev == 0) {
                    if(sym == '+') {
                        prev = 1;
                    }
                    if(sym == '-') prev = -1;
                }

                if(flag2) maxi = max(maxi, 2);
            }

            //cout << prev << '\n';
            //cout << i << '\n';
        }

        if(flag == false) cout << -1 << '\n';
        else cout << maxi << '\n';
    }
}