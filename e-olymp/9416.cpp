#include <iostream>
#include <algorithm>
using namespace std;
int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int pen, apple;
  cin >> pen >> apple;
  cout << __gcd(pen, apple) << endl;
  return 0;
}

#include <stdio.h>
#include <algorithm>
using namespace std;

int main () {
  int pen, apple, lol = 100500, trash = 0;
  scanf("%d%d", &pen, &apple);
  while (apple != min(apple, trash)) {
    while (pen == max(apple, pen)) {
      pen = abs(pen - apple);
    }
    int pineapple = pen;
    pen = apple;
    apple = pineapple;
  }
  printf("%d\n", pen + apple);
  return 0;
}


/*
input pen
input apple
//__gcd(a, b) : return the greatest common divisor of a and b
output_value = __gcd(pen, apple)
output output_value


Soal ini merupakan bentuk algoritma yang tidak formal dan harus dijadikan formal agar mendapat sebuah rancangan kode program atau pseudocode. Pada soal ini diberikan soal dengan teks yang mempunyai frasa dan indentasi yang mirip seperti sebuah kode program. Tetapi teks tersebut terdapat beberapa kata yang sepertinya salah dalam penulisan, seperti give me dituliskan GIMMEH, smaller ditulis SMALLR, number ditulis NUMBR, while ditulis WILE, ok thanks bye ditulis KTHXBYE, dan lain lain. Bila dicermati pada indentasi yang ada, terlihat bahwa pada kalimmat tersebut seperti mendeklarasikan sebuah loop dengan beberapa operasi di dalamnya.
bila dijadikan ke bahasa C maka kode program tersebut seperti berikut

HAI 1.2

I HAS A PEN, GIMMEH PEN, PEN R MAEK PEN A NUMBR
I HAS A APPLE, GIMMEH APPLE, APPLE IS NOW A number

I HAS A LOL ITZ 100500
I HAS A TRASH ITZ 0
IM IN YR DREAM UPPIN YR LOL WILE DIFFRINT APPLE AN SMALLR OF APPLE AN TRASH
  IM IN YR HOUSE UPPIN YR LOL WILE BOTH SAEM PEN BIGGR OF PEN AN APPLE AN
    PEN R DIFF OF PEN AN APPLE
  IM OUTTA YR HOUSE
  I HAS A PINEAPLLE ITZ PEN
  PEN R APPLE
  APPLE R PINEAPLLE
IM OUTTA YR DREAM
VISIBLE SUM OF PEN AN APPLE

KTHXBYE

BTW RLY LOL :D

pada baris ke 3 dan ke 4 diduga kode nya seperti mendeklarasikan sebuah variable yang bernama pen dan merupakan sebuah bilangan.

pada baris ke 6 dan ke 7 diduga kode nya seperti mendeklarasikan sebuah variable yang bernama LOL dengan value awal 100500 dan trash dengan value awal 0

pada baris ke 8 diduga kode nya seperti mendeklarasikan sebuah looping dengan syarat nilai pada variable apple berbeda dengan nilai terkecil dari dua variable yaitu variable apple dan trash

pada baris ke 9 diduga kode nya seperti mendeklarasikan sebuah looping dengan syarat value pada variable pen sama dengan value terbesar dari pen dan apple

pada baris ke 10 terdapat sebuah operasi yaitu pen diisi dengan selisih nilai dari pen dan apple

pada baris ke 11 adalah penutup dari loop yang dideklarasikan pada baris ke 9

pada baris ke 12 dideklarasikan variable pineapple yang valuenya sama dengan pen
pada baris ke 13 pen diisi dengan nilai sama dengan apple
pada baris ke 14 apple diisi dengan pineapple

pada baris ke 15 adalah penutup dari loop yang dideklarasikan pada baris ke 8
pada baris ke 16 diduga melakukan output jumlah dari pen dan apple

pada baris ke 18 dan 20 diduga adalah sebuah penutup dari program

Dengan melakukan uji coba output, ternyata nilai yang dikeluarkan oleh program tersebut adalah faktor persekutuan terbesar dari dua nilai yang diinputkan ke program. Maka program tersebut dapat disederhanakan dengan menggunakan fungsi __gcd(a, b) dari cpp yang return nya adalah FPB dari variable a dan b.
*/