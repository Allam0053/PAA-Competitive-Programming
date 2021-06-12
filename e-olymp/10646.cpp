#include <set>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    int n = (int) s.length();
    set<char> sc;
    for (int i = 0; i < n; i++) {
        if(!sc.count(s[i])) {
            sc.insert(s[i]);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

// main ()
//     s: string
//     input s
//     ans: int
//     n: int
//     n = s.length() // function length return the length of string s
//     sc: set<char>
//     for i=0 to n 
//         if sc.count(s[i]) == 0 // function count return the count of a char appeared in set
//             sc.insert(s[i]) // function insert used to insert a char to set
//             ans = ans + 1
        
    
//     output ans
//     return