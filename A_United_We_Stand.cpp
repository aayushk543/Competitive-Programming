#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<ll> a(n);

        bool p = false;

        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i > 0){
                if(a[i-1] != a[i]) p = true;
            }
        }

        sort(a.begin(), a.end());

        int count = 0;

        for(int i = n - 2; i >= 0; i--){
            if(a[i] == a[n-1]) count++;
            else break;
        }

        if(!p) cout << -1 << '\n';
        else {
            cout << n-1-count << " " << 1+count << '\n';
            for(int i = 0; i < n-1-count; i++) cout << a[i] << " ";
            cout << '\n';
            cout << a[n-1] << " ";
            for(int i = 1; i <= count; i++){
                cout << a[n-1] << " ";
            }
            cout << '\n';
        }


    }
    return 0;
}