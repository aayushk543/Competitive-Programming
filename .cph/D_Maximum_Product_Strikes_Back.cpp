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

        vector<int> arr(n);

        long long prod = 1;

        vector<int> minus(n);

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            prod *= arr[i];

            if(i > 0) minus[i] = minus[i-1];

            if(arr[i] < 0) minus[i] += 1;

            minus[i] %= 2;
        }

        


    }
    return 0;
}