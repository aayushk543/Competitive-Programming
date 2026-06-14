#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std;

int f(vector<int>& arr, int i, int sum){
    if(i == 0) {
        return sum - abs(arr[1]-arr[0]);
    }
    else if(i == arr.size() - 1){
        return sum - abs(arr[i-1] - arr[i]);
    }
    return sum - abs(arr[i-1]-arr[i]) - abs(arr[i+1]-arr[i]) + abs(arr[i-1]-arr[i+1]);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> arr;
        int i1 = 0;
        int i2 = INT_MAX;
        int sum = 0;

        for(int i = 0; i < n; i++){
            int p;
            cin >> p;
            arr.push_back(p);

            if(i > 0)
            sum += abs(arr[i-1]-arr[i]);
        }
        for(int i = 0; i < arr.size(); i++){
            i2 = min(i2,f(arr,i,sum));
        }

        cout << i2 << '\n';
    }
    return 0;
}