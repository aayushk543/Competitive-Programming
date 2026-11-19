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

        vector<long long> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        long long sum = 0;

        for(int i = 0; i < n; i++) sum += arr[i];

        if(sum % 2 == 0 && k % 4 == 0) cout << "Bob" << '\n';
        else if(sum % 2 == 0 && k % 2 == 0) cout << "Alice" << '\n';
        else if(sum % 2 == 1 && k % 4 == 0) cout << "Alice" << '\n';
        else if(sum % 2 == 1 && k % 2 == 0) cout << "Bob" << '\n';
        else {
            cout << "ok" << '\n';
        }
    }
    return 0;
}