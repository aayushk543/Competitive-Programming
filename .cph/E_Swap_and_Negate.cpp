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

        vector<long long> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        int neg = 0;

        for(int i = 0; i < n; i++) {
            if(arr[i] < 0) {
                neg++;

                int l = 1;

                while(i + 1 < n && arr[i + 1] < 0) {
                    l++;
                    i++;
                }

                if(l % 2 == 0) neg--;
            }

            
        }

        vector<long long> arr2(n);

        for(int i = 0; i < n; i++) {
            arr2[i] = abs(arr[i]);
        }

        sort(arr2.begin(), arr2.end());

        long long sum = 0;

        for(int i = 0; i < n; i++) {

            if(neg > 0) {
                neg--;

                //cout << arr2[i] << " ";
                sum += -1*arr2[i];
            }
            else sum += arr2[i];
        }

        cout << sum << '\n';


    }
    return 0;
}