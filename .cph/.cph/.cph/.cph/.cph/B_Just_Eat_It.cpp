#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<long long>>& arr, long long level){
    int n = arr.size();

    for(int i = 0; i < n; i++){
        if(level > arr[i][0]) level += arr[i][1];
        else return false;
    }

    return true;
}

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

       long long curr1 = arr[0];
       long long best1 = arr[0];

       for(int i = 1; i < n-1; i++) {
        curr1 = max(arr[i], curr1+arr[i]);
        best1 = max(best1, curr1);
       }

       long long curr2 = arr[1];
       long long best2 = arr[1];

       for(int i = 2; i < n; i++) {
        curr2 = max(arr[i], curr2+arr[i]);
        best2 = max(best2, curr2);
       }

       long long best = max(best1, best2); 
       
       if(best >= sum) cout << "NO" << '\n';
       else cout << "YES" << '\n';


    }
    return 0;
}