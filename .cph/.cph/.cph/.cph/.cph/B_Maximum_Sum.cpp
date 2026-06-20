#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n, k;
       cin >> n >> k;

       deque<long long> arr(n);
       deque<long long> arr2(k);

       for(int i = 0; i < n; i++) cin >> arr[i];

       sort(arr.begin(), arr.end());

       int j = 0;

       for(int i = 0; i < k; i++){
        arr2[i] = arr[j] + arr[j+1];
        j += 2;
       }

       for(int i = k; i < n && j < n; i++){
        arr2.push_back(arr[j++]);
       }

       sort(arr2.begin(), arr2.end());

       long long sum = 0;

       for(int i = k; i < arr2.size(); i++){
        sum += arr2[i];
       }

       cout << sum << '\n';
    }
    return 0;
}