#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        long long a,b,n;
        cin >> a >> b >> n;

        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long m;

            cin >> m;

            if(m >= a){
                ans += a - 1;
            }
            else ans += m;
        }
        cout << ans + b << '\n';


    }
    return 0;
}