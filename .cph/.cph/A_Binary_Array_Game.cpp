#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std;

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n,0);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        if(arr[0] == 0 && arr[n-1] == 0){
            cout << "Bob" << '\n';
        }
        else {
            cout << "Alice"  << '\n';
        }
        
    }
    return 0;
}