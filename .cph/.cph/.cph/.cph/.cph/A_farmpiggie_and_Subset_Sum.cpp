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

        int count = 2;

            for(int i = 0; i < n; i += 2) {
                arr[i] = count;
                count += 2;
            } 

            count = 1;

            for(int i = 1; i < n; i +=2) {
                arr[i] = count;
                count += 2;
            }
        

        for(int i = 0; i < n; i++) cout << arr[i] << " ";

        cout << '\n';
    }
    return 0;
}