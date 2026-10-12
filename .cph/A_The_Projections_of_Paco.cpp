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

       int count = 0;

       if(n == 1) {
        int num;
        cin >> num;

        cout << num << '\n';
       }
       else {

            vector<int> arr(n);
            for(int i = 1; i <= n; i++) {
            int curr;
            cin >> curr;

            arr[i-1] = curr;
            
            if(curr < count) {
                count = curr - (count - curr);
            }
            else if(count < curr) {
                count = curr + (curr - count);
            }
            else count = curr;
        }

        int val1 = count;

        count = 1;
        for(int i = 1; i <= n; i++) {
            int curr = arr[i-1];
            
            if(curr < count) {
                count = curr - (count - curr);
            }
            else if(count < curr) {
                count = curr + (curr - count);
            }
            else count = curr;
        }


        if(abs(val1) < abs(count)) cout << -abs((val1 / 2)) << '\n';
        else cout << abs(val1 / 2) << '\n';
       }
    }
    return 0;
}