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

        string s;
        cin >> s;

        int ans = 0;

        if(n <= 3) {
            ans = 0;
        }
        else if(n >= 4){
            int i = 3;
            while(i < s.length()){
                if(s[i-3] == '2' && s[i-2] == '0' && s[i-1] == '2' && s[i] == '5'){
                    ans = 1;
                }
                else if(s[i-3] == '2' && s[i-2] == '0' && s[i-1] == '2' && s[i] == '6'){
                    ans = 0;
                    break;
                }
                i++;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}