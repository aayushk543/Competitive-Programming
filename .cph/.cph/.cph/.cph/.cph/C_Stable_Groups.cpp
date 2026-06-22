#include<bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k,x;

    cin >> n >> k >> x;

    vector<long long> arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int count = 0;

    for(int i = 1; i < n; i++){
        if(k == 0 && arr[i] - arr[i-1] > x) count++;
        else if(k > 0 && arr[i] - arr[i-1] > x) {
            if(ceil(((double)arr[i] - (double)arr[i-1])/2.00) <= x) k--;
            else count++;
        }
    }

    cout << count + 1 << '\n';
}