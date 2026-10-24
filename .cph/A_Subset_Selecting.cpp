#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>
#include <map>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;

        vector<int> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        sort(arr.begin(), arr.end());

        int curr = 0;

        int size = n / k;

        int count = 0;

        int buffer = 0;

        for(int i = 0; i < n; i++) {

            count++;
            if(count > size) break;

            if(curr == arr[i]) curr++;
            //else if(arr[i] < curr) continue;
            else break;

            //cout << arr[i]  << " " << i << '\n';

            int prev = i;
            while(i + 1 < n && arr[i+1] == curr - 1) i++;

            int length = i - prev + 1;

            //cout << length << '\n';

            if(length < k && k - length - 1 >= buffer) {
                curr -= 1;
                break;
            }
            else buffer += length - k;
        }

        cout << curr << '\n';
    }
    return 0;
}