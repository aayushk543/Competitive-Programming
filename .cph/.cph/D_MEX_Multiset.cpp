#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>
#include <map>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<long long> arr(n + 1);
        map<long long, int> mp;

        //cout << "o" << '\n';

        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            mp[arr[i]] += 1;
        }

        int a = 0;
        int b = 0;
        int c = 0;

        bool flag = false;

        for(auto it = mp.begin(); it != mp.end(); it++) {
            int curr = it->first;
            int val = it->second;



            //cout << curr << '\n';

            if(a == curr) {
                a += 1;
                val -= 1;
            }
            else {
                
                vector<int> arr1(a);
                vector<int> arr2(b);
                //vector<int> arr3(c);

                string ans(" ",n);

                //cout << "1" ;

                for(int i = 0; i < n; i++) {
                    if(arr[i] > a) ans[i] = 'C';
                    else {
                        if(arr1[arr[i]] > 0) {
                            ans[i] = 'A';
                            arr1[arr[i]] = 1; 
                        }
                        else if(arr2[arr[i]] > 0) {
                            ans[i] = 'B';
                            arr2[arr[i]] = 1; 
                        }
                        else {
                            ans[i] = 'C';
                        }
                    }
                }

                cout << "YES" << '\n';
                cout << ans << '\n';

                flag = true;

                break;
            }
            if(b == curr) {
                if(val == 0) {

                    vector<int> arr1(a);
                    vector<int> arr2(b);
                    //vector<int> arr3(c);

                    string ans(" ",n);


                    if(a + b + c < 2*(max(a, max(b, c)))) {
                        cout << "NO" << '\n';
                    }
                    else {
                        for(int i = 0; i < n; i++) {
                    if(arr[i] > a) ans[i] = 'C';
                    else {
                        if(arr1[arr[i]] > 0) {
                            ans[i] = 'A';
                            arr1[arr[i]] = 1; 
                        }
                        else if(arr2[arr[i]] > 0) {
                            ans[i] = 'B';
                            arr2[arr[i]] = 1; 
                        }
                        else {
                            ans[i] = 'C';
                        }


                    }
                }

                cout << "YES" << '\n';
                        cout << ans << '\n';

                    }

                    flag = true;

                    break;
                }
                b += 1;
                val -= 1;
            }

            if(c == curr) {
                if(val == 0) {
                    vector<int> arr1(a);
                    vector<int> arr2(b);
                    //vector<int> arr3(c);

                    string ans(" ",n);


                    if(a + b + c < 2*(max(a, max(b, c)))) {
                        cout << "NO" << '\n';
                    }
                    else {
                        for(int i = 0; i < n; i++) {
                    if(arr[i] > a) ans[i] = 'C';
                    else {
                        if(arr1[arr[i]] > 0) {
                            ans[i] = 'A';
                            arr1[arr[i]] = 1; 
                        }
                        else if(arr2[arr[i]] > 0) {
                            ans[i] = 'B';
                            arr2[arr[i]] = 1; 
                        }
                        else {
                            ans[i] = 'C';
                        }

                        
                    }

                   
                }
                cout << "YES" << '\n';
                        cout << ans << '\n';
                    }

                    flag = true;

                    break;
                }
                c += 1;
                val -= 1;
            }

        }

        if(flag == false) {
            vector<int> arr1(a);
            vector<int> arr2(a);
            //vector<int> arr3(a);

            string ans(" ",n);


                    if(a + b + c < 2*(max(a, max(b, c)))) {
                        cout << "NO" << '\n';
                    }
                    else {
                        for(int i = 0; i < n; i++) {
                    if(arr[i] > a) ans[i] = 'C';
                    else {
                        if(arr1[arr[i]] > 0) {
                            ans[i] = 'A';
                            arr1[arr[i]] = 1; 
                        }
                        else if(arr2[arr[i]] > 0) {
                            ans[i] = 'B';
                            arr2[arr[i]] = 1; 
                        }
                        else {
                            ans[i] = 'C';
                        }

                    }
                }

                cout << "YES" << '\n';
                        cout << ans << '\n';
                    }

        }

    }
    return 0;
}