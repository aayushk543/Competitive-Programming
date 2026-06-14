#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> arr(n,0);
    for(int i = 0; i < n; i++){ 
    cin >> arr[i];
    }

    if(k == 1){
        cout << arr[n-1] - arr[0];
        return 0;
    }

    vector<long long> df;
    for(int i = 0; i < n-1; i++){
        df.push_back(arr[i+1] - arr[i]);
    }

    sort(df.begin(), df.end(), greater<long long>());

    long long total = arr[n-1] - arr[0];
    long long remove = 0;

    for(int i = 0; i < k-1; i++){
        remove += df[i];
    }

    cout << total - remove;
}
