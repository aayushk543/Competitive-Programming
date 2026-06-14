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

        vector<long long> a(n,0);
        vector<int> b(n,0);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        for(int i = 0; i < n; i++){
            cin >> b[i];
        }

        sort(a.begin(), a.end());


        int j = n - 1;
        long long ans = 0;
        long long mini = a[n-1];

        for(int i = 0; i < n; i++){
            while(b[i] > 0 && j >= 0){
                mini = min(mini, a[j]);
                j--;
                b[i]--;
            }

            if(b[i] == 0)
            ans = max(ans, (long long)(i + 1)* mini);
        }

        cout << ans << '\n';

    }
    return 0;
}