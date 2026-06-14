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
        int maxi = 0;
        bool c = false;
        bool c21 = false;
        bool c22 = false;

        for(int i = 0; i < n; i++){
            int a;
            cin >> a;

            if(a%k == 0) {
                c = true;
            }
            if(a%2 == 0 && k == 4 && !c21) c21 = true;
            else if(a%2 == 0 && c21 && k == 4) c22 = true;
            maxi = max(maxi, a%k);
        }

        if(c) cout << 0 << '\n';
        else if(c21 && c22) cout << 0 << '\n';
        else if(c21 && k == 4 && n >= 2 && maxi == 2 && !c22) cout << 1 << '\n';
        else if(k == 4 && n >= 2 && maxi == 1) cout << 2 << '\n';
        else cout << k - maxi << '\n';
    }
    return 0;
}