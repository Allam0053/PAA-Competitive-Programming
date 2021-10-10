#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    string in;
    int T;
    scanf("%d", &T);
    while (T--) {
      cin >> in;
      string out;
      unsigned my_p = 0;
      for (int i = 0; i < in.length(); i++) {
        if (in[i] == '<' && my_p > 0) {
          my_p--;
        } else if (in[i] == '>' && out.length() > my_p) {
          my_p++;
        } else if (in[i] == '-') {
          out.erase( my_p - 1, 1 );
        } else {
          if (my_p > out.length()) out.append(my_p, 1);
          else out.insert(my_p, in.substr(my_p, my_p));
          my_p++;
        }
      }
      cout << out << endl;
    }
    return 0;
}
/*
 * |abc
 * 0
 * a|bc
 * 
 * 
 * 
 * -1
 * |
 * 
 * /