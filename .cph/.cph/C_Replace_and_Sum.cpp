#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,q;
        cin >> n >> q;

        vector<int> a(n,0);
        vector<int> b(n,0);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
            b[i] = max(a[i],b[i]);
        }

        vector<int> qu(2*q,0);

        for(int i = 0; i < 2*q; i++){
            cin >> qu[i];
        }

        int maxi = b[n-1];
        int sum = 0;
        vector<long long> ans(n,0);

        for(int i = n - 1; i >= 0; i--){
            b[i] = max(maxi,b[i]);
            maxi = max(maxi,b[i]);



            ans[i] = b[i] + sum;
            sum = ans[i];

        }

        for(int i = 0; i < 2*q; i = i + 2){
            int l = qu[i] - 1;
            int r = qu[i+1] - 1;
            int sum2 = 0;

            sum2 = ans[l] - ans[r] + b[r];
            cout << sum2 << " ";
        }

        cout << '\n';

        


    }
    return 0;
}