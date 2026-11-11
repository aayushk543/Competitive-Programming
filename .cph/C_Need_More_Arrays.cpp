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

        for(int i = 0; i < n; i++) cin >> arr[i];

        int count = 1;
        int prev = arr[0];

        for(int i = 1; i < n; i++) {

            if(prev + 1 < arr[i]) {
                count++;
                prev = arr[i];
            }
        }

        cout << count << '\n';
    }
    
    return 0;
}