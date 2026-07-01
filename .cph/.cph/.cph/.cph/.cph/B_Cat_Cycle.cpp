#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        long long n, k;

        cin >> n >> k;

        if(n % 2 == 0) {
            cout << k % (n + 1) << '\n';
        }
        else {
            vector<long long> arr(2*n + 1, 0);

            long long count = n;

            for(int i = 1; i <= 2*n; i++){
                int j = i % (n+1);
                if(i > n) j+=1;

                if(j == count) count--;
                if(count == 0) count = n;

                arr[i] = count;
                count -= 1;
            }

            cout << arr[n - (k % (2*n + 1))] << '\n';
        }

    }
    return 0;
}