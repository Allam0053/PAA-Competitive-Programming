#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct Bigint {
  string a;
  int sign;
  Bigint(){}
  Bigint( string b ) { (*this) = b; }
  int size () {return a.size(); }
  Bigint inverseSign () { sign *= -1; return (*this); }
  Bigint normalize (int newSign) {
    sign = newSign;
    for (int i = a.size() - 1; i > 0 && a[i] == '0'; i--) a.erase(a.begin() + i);
    if (a.size() == 1 && a[0] == 0) sign = 1;
    return (*this);
  }
  void operator = ( string b ) {
    a = b[0] == '-' ? b.substr(1) : b;
    reverse( a.begin(), a.end() );
    this->normalize( b[0] == '-' ? -1 : 1);
  }
  bool operator < ( const Bigint &b) const {
    if ( a.size() != b.a.size() ) return a.size() < b.a.size();
    for (int i = a.size() - 1; i >= 0; i--) if ( a[i] != b.a[i] ) return a[i] < b.a[i];
    return false;
  }
  Bigint operator + ( Bigint b ) {
    if (sign != b.sign) return (*this) - b.inverseSign();
    Bigint c;
    for (int i = 0, carry = 0; i < (int)a.size() || i < (int)b.size() || carry ; i++) {
      carry += (i < (int)a.size() ? a[i] - 48 : 0) + (i < (int)b.a.size() ? b.a[i] - 48 : 0);
      c.a += (carry % 10 + 48);
      carry /= 10;
    }
    return c.normalize(sign);
  }
  Bigint operator - ( Bigint b ) {
    if ( sign != b.sign ) return (*this) + b.inverseSign();
    if ( (*this) < b ) return (b - (*this)).inverseSign();
    Bigint c;
    for(int i = 0, borrow = 0; i < (int)a.size(); i++) {
      borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);
      c.a += borrow >= 0 ? borrow + 48 : borrow + 58;
      borrow = borrow >= 0 ? 0 : 1;
    }
    return c.normalize(sign);
  }
  void print() {
    if (sign == -1) putchar_unlocked( '-' );
    for ( int i = a.size() - 1; i >= 0; i-- ) putchar_unlocked(a[i]);
  }
};

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  Bigint a, b, c;
  string s1, s2;
  while (cin >> s1) {
    cin >> s2;
    Bigint z1 = s1, z2 = s2;
    Bigint c = z1 + z2;
    c.print(); putchar_unlocked('\n');
  }
}