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

        vector<int> a1(n);
        vector<int> a2(n);

        for(int i = 0; i < n; i++) cin >> a1[i];
        for(int i = 0; i < n; i++) cin >> a2[i];

        int l = -1, r = -1;

        for(int i = 0; i < n; i++) {
            if(a1[i] != a2[i]) {
                if(l == -1) l = i;
                r = i;
            } 
        }

        if(l == -1) {
            int len = 1;

            for(int i = 1; i < n; i++) {
                int j = i;
                int curr_len = 1;

                while(i < n && a1[i] <= a1[i+1]) {
                    i++;
                    curr_len++;
                }

                if(len < curr_len) {
                    len = curr_len;
                    l = j;
                    r = i;
                }

                if(curr_len > 1) i--;
            }

            cout << l + 1 << " " << r + 1 << '\n';
        }
        else {

            //cout << l + 1 << " " << r + 1 << '\n';
            int prev = a1[l];

            int i = l;

            while(l > 0 && a1[l-1] <= a2[l]) {
                l--;
            }

            while(r < n - 1 && a2[r] <= a1[r+1]) r++;

            cout << l + 1 << " " << r + 1 << '\n';
        }
    }
    return 0;
}