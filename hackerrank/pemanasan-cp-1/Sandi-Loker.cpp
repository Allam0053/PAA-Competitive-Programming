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

int hitungplus (char in1, char in2) { //hitung jarak bila diputar ke atas
  // if (in2 - in1 > 5) {
  //   return (in2 - in1) - 10;
  // } else 
  if ( in2 - in1 < 0) {
    return 10 + (in2 - in1);
  } else {
    return in2 - in1;
  }
}

void carimaks (int* in1, int* in2, int *in3, unsigned index, int *max_val, unsigned *indexofmax, int *second) { //kalau diputar ke atas
  if (*in1 > *in2) {
    *max_val = *in1;
    *indexofmax = index;
    *second = *in2;
  } else {
    *max_val = *in2;
    *indexofmax = index + 1;
    *second = *in1;
  }
  if (*max_val < *in3) {
    *second = *max_val;
    *max_val = *in3;
    *indexofmax = index + 2;
  } else if (*second < *in3) {
    *second = *in3;
  }
  return;
}

void carimin (int in1, int in2, int in3, unsigned index, int *max_val, unsigned *indexofmax, int *second) { // kalau diputar ke bawah
  if (in1 != 0) in1 = 10 - in1;
  if (in2 != 0) in2 = 10 - in2;
  if (in3 != 0) in3 = 10 - in3;
  // cout << "in1: " << in1 << "in2: " << in2 << "in3: " << in3 << endl;
  if (in1 > in2) {
    *max_val = in1;
    *indexofmax = index;
    *second = in2;
  } else {
    *max_val = in2;
    *indexofmax = index + 1;
    *second = in1;
  }
  if (*max_val < in3) {
    *second = *max_val;
    *max_val = in3;
    *indexofmax = index + 2;
  } else if (*second < in3) {
    *second = in3;
  }
  return;
}

int main() {
    int n=0;
    string in1, in2;
    
    while ( cin >> in1 >> in2 ) {
        vector <int> dist;
        n=0;
        for (unsigned i = 0; i < in1.length(); i++) {
            dist.push_back( hitungplus(in1[i], in2[i]) );
        }

        // Consider all blocks starting with i.
        for (unsigned i = 0; i < in1.length() - 3 + 1; i++) {
            int max_val = 0;
            unsigned indexofmax = 0;
            int secondmax = 0;            
            carimaks(&dist[i], 
                     &dist[i + 1], 
                     &dist[i + 2], 
                     i, 
                     &max_val, 
                     &indexofmax, 
                     &secondmax);

            int min_val = 0;
            unsigned indexofmin = 0;
            int secondmin = 0;
            carimin(dist[i], dist[i + 1], dist[i + 2],
                    i, &min_val, &indexofmin, &secondmin);
            // cout << "minval: " << min_val << endl;

            if (min_val < max_val) {
              max_val = min_val;
              indexofmax = indexofmin;
              secondmax = secondmin;
            }
    
            if (indexofmax == i) {
              n += max_val;
              dist[i] = dist[i + 1] = dist[i + 2] = 0;
            } else if (indexofmax == i + 1) {
              n += secondmax;
              dist[i] = 0;
              dist[i + 1] -= secondmax;
              dist[i + 2] = 0;
            } else {
              n += secondmax;
              dist[i] = 0;
              dist[i + 1] = 0;
              dist[i + 2] -= secondmax;
            }
            // for (unsigned i = 0; i < in1.length(); i++) {
            //   cout << dist[i] << " ";
            // } cout << endl;
        }

    
        cout << n << "\n";
    }
    return 0;
}

/* Enter
00012 32190
0000 0000
81750 70462


00 21

19 55

4 -4

3 -5
2 -6
1 -7
0 -8

02

42

5
0



9
8
7
6
5
4
3
2
1
0
*/