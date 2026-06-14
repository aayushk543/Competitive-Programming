#include <vector>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
    long long n;
    int count1 = 0, count2 = 0, count = 0;
    cin >> n;

    vector<long long> arr(n+1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int middle = -1;
    if(n % 2){
        middle = n/2 + 1;
        int i = middle;
        i--;
        while(i > -1) {
            if(arr[middle] == arr[i]) count++;
            i--;
        }
        i = middle;
        i++;
        while(i <= n){
            if(arr[middle] == arr[i]) count++;
            i++;
        }
    }
    else {
        middle = n/2;
        int i = middle;
        i--;
        while(i > -1) {
            if(arr[middle] == arr[i]) count1++;
            i--;
        }
        i = middle;
        i++;
        while(i <= n){
            if(arr[middle] == arr[i]) count1++;
            i++;
        }
        middle = n/2 + 1;
        i = middle;
        i--;
        while(i > -1) {
            if(arr[middle] == arr[i]) count2++;
            i--;
        }
        i = middle;
        i++;
        while(i <= n){
            if(arr[middle] == arr[i]) count2++;
            i++;
        }
        count = max(count1,count2);
    }
    cout << min(n - count - 1,(n-1)/2) << '\n';
}
return 0;

}