#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n;
       long long w;

       cin >> n >> w;

       vector<int> arr(21, 0);

       for(int i = 0; i < n; i++) {
        int val;
        cin >> val;

        arr[log2(val)]++;

       }

       int count = 0;

       while(n > 0) {
        count++;
        long long curr = w;

        for(int i = 20; i >= 0; i--) {
            int temp = 1;
            while(arr[i] > 0 && curr >= (temp << i)) {
                curr -= (temp << i);
                n--;
                arr[i]--;
            }
        }
       }

       cout << count << '\n';
    }
    return 0;
}