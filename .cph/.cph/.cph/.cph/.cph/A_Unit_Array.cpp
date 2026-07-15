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

        int count = 0;

        for(int i = 0; i < n; i++) {
            int curr;
            cin >> curr;

            if(curr == 1) count++;
            else count--;
        }

        int ans = 0;

        if(count < 0) {
            if(n%2) {
                ans = -1*count;
                ans = (ans+1)/2;

                
            }
            else ans = (-1*(count))/2;

            if(n == -1*count) ans = n;

        }

        

        cout << ans << '\n';
    }
    return 0;
}