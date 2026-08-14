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

       vector<long long> x(n);
       long long pre = 0;

       for(int i = 0; i < n; i++) {
        cin >> x[i];
        pre += x[i];
       }

       long long time = 0;

       for(int i = 0; i < n; i++) {
        long long m;
        cin >> m;

        time += m;
       }

       sort(x.begin(), x.end());

       long long mini = -1;
       int ans = -1;

       long long prev = 0;

       for(int i = 0; i < n; i++) {
        prev += x[i];
        long long curr = pre - (n - i) * x[i] + (x[i] * (i + 1) - prev);

        if(mini == -1) {
            mini = curr;
            ans = x[i];
        }
        else if(mini > curr) {
            mini = curr;
            ans = x[i];
        }
       }

       cout << ans << '\n';

    }
    return 0;
}