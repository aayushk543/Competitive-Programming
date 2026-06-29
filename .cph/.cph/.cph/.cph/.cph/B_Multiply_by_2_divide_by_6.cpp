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

        int count3 = 0;

        while(n > 1) {
            if(n % 3 != 0) break;
            n /= 3;
            count3++;
        }

        int count2 = 0;

        if(count3 != 0){
            while(n > 1) {
                if(n % 2 != 0) break;
                n /= 2;
                count2++;
            }
        }

        //cout << count2 << " " << count3 << '\n';

        if(n == 1 && count3 >= count2) cout << 2*(count3 - count2) + count2 << '\n';
        else cout << -1 << '\n';
        
    }
    return 0;
}