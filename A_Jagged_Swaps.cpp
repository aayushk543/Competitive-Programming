#include<bits/stdc++.h>
using namespace std;

int f(string s, int i, vector<int>& arr1){

    vector<int> arr(3,0);
    int prev;

    for(i = i + 1; i < s.length(); i++){
        if(s[i] == 'C'){
            arr[0]++;
            prev = 0;
        }
        else if(s[i] == 'H') {
            arr[1]++;
            prev = 1;
        }
        else if(s[i] == 'O') {
            arr[2]++;
            prev = 2;
        }
        else if(s[i] >= '1' && s[i] <= '9'){
            arr[prev] += (s[i] - '0' - 1);
        }
        else if(s[i] == ')'){
            if(i < s.length()-1) i++;

            if(s[i] >= '1' && s[i] <= '9'){
                int count = s[i] - '0';
                for(int i = 0; i < 3; i++){
                    arr1[i] += count*arr[i];
                }
            }
            else {
                for(int i = 0; i < 3; i++){
                    arr1[i] += arr[i];
                }
            }

            break;
        }
        else if(s[i] == '('){
            i = f(s,i,arr);
        }
    }
    return i; 
        
}

int main() {
    string s;

    cin >> s;

    int ans = 0;
    int prev;

    vector<int> arr(3,0);

    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'C'){
            arr[0]++;
            prev = 0;
        }
        else if(s[i] == 'H') {
            arr[1]++;
            prev = 1;
        }
        else if(s[i] == 'O') {
            arr[2]++;
            prev = 2;
        }
        else if(s[i] >= '1' && s[i] <= '9'){
            arr[prev] += (s[i] - '0' - 1);
        }
        else if(s[i] == '('){
            i = f(s,i,arr);
        }
    }

    ans += arr[0]*12;
    ans += arr[1]*1;
    ans += arr[2]*16;

    cout << ans << '\n';
    return 0;
}
