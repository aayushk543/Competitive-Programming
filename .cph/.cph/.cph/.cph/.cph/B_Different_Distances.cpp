#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(4 * n, 0);

        for (int x = 1; x <= n; x++) {
            int a = x;
            int b = (x - 1 + 1) % n + 1;
            int c = (x - 1 + 3) % n + 1;
            int d = (x - 1 + 6) % n + 1;

            arr[a - 1] = x;
            arr[n + b - 1] = x;
            arr[2 * n + c - 1] = x;
            arr[3 * n + d - 1] = x;
        }

        for (int i = 0; i < 4 * n; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}