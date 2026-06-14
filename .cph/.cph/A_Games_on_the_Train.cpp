#include<bits/stdc++.h>
using namespace std;
#define ll as long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int maxi = 1;
        int mini = 6;

        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            maxi = max(maxi, m);
            mini = min(mini, m);
        }

        cout << maxi - mini + 1 << '\n';
    }
    return 0;
}
