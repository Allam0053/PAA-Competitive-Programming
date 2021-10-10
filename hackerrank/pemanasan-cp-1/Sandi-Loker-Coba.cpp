#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int hitung (char in1, char in2) {
  if (in2 - in1 > 5) {
    return (in2 - in1) - 10;
  } else if ( in2 - in1 < -5) {
    return 10 + (in2 - in1);
  } else {
    return in2 - in1;
  }
}

int main() {
    int T;
    string in1, in2;
    vector <int> dist;
    while ( cin >> in1 >> in2 ) {
        for (int i = 0; i < in1.length(); i++) {
          dist.push_back( hitung(in1[i], in2[i]) );
        }
        for (int i = 0; i < dist.size(); i++) {
          
        }
    }
    return 0;
}