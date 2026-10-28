#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    
	    vector<int> arr(n + 1);
	    
	    for(int i = 1; i <= n; i++) cin >> arr[i];
	    
	    vector<int> same;
        int ans = 1;

        vector<vector<int>> arr2;

        for(int i = 1; i <= n; i++) {
            int l = 1;
            int j = i;

            while(i < n && arr[i] == arr[i+1]) {
                l++;
                i++;
            }

            if(l >= 0) {
                arr2.push_back({arr[i], l, j});
                //cout << (arr[i]) << " " << l << " " << j << '\n'; 
            }
        }

        for(int i = 0; i < arr2.size(); i++) {

            if(i + 2 < arr2.size() && arr2[i][0] == arr2[i+2][0] && arr2[i][1] + arr2[i][2] == arr2[i+1][2] && arr2[i+1][1] + arr2[i+1][2] == arr2[i+2][2] && (arr2[i][0] - arr2[i+1][0] == 1))  {
                //cout << arr2[i+2][2] + arr2[i+2][1] - arr2[i][2] << " " << "stage1" << '\n';
                ans = max(ans, (arr2[i+2][2] + arr2[i+2][1] - 1) - arr2[i][2] + 1);
            }
            else if(i + 1 < arr2.size() && abs(arr2[i+1][0] - arr2[i][0]) == 1) {
                ans = max(ans, arr2[i+1][1] + arr2[i+1][2] - (arr2[i][2]));

            
            }
            ans = max(ans, arr2[i][1]);

            //cout << ans << '\n';
        }
	    
        if(n == 1 || ans == 1) cout << 0 << '\n';
	    else cout << max(1, ans - 1) << '\n';
	}

}
