#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>
#include <map>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<long long> arr(n);
        long long sum = 0;

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        long long target2 = (sum / (1LL*n));

        if(sum % n != 0) cout << "NO" << '\n';
        else {
            //cout << "else" << '\n';
            for(int i = 0; i < n; i++) {

                if(arr[i] == target2) continue;
                if(i + 2 <= n - 1) {
                    arr[i+2] += (arr[i] - target2); 
                    arr[i] = target2;
                }
            }

            bool flag = true;

            for(int i = 0; i < n; i++) {
                if(arr[i] != target2) {
                    cout << "NO" << '\n';
                    flag = false;
                    break;
                }
            }

            if(flag) cout << "YES" << '\n';
        }

        
    }
    return 0;
}