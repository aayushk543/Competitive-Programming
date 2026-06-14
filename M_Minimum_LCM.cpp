#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        ll ans1, ans2;

        if(n % 2 == 0){
            ans1 = n/2;
            ans2 = n/2;
        }
        else if(n % 3 == 0) {
            ans1 = n/3;
            ans2 = 2*ans1;
        }
        else {
            ans1 = 1;
            ans2 = n - 1;
        }

        cout << ans1 << " " << ans2 << '\n';
    }
    return 0;
}