#include <stdio.h>
#include <string.h>

// int i: return size
void split_string(char splitted[][50], char origin[], const char delimiter[]) {
  int i = 0;
  char* token = strtok(origin, delimiter);
  
  while (token != NULL) {
    strcpy(splitted[i++], token);
    token = strtok(NULL, delimiter);
  }

  // return i;
}

int main() {
  int number;
  char splitted[300][50];
  char data[] = { "t.me/kbtuopen Subscribe Participants INTRODUCING KBTU Open Spring 2021 Regular ICPC-style programming contest organized by Kazakh-British Technical University Join us on May 30, 2021 to compete and have fun UPDATE: Start time was rescheduled from 11:00 to 13:00 Link to contest Schedule 30 May, Online 11:00 - 13:00 Sending accounts 00. 13:00 - 18:00 Epic battle 01. 18:00 - 19:00 Leaderboard unfreeze 02. FAQ Frequently Asked Questions 00. What the heck is ICPC? The International Collegiate Programming Contest is an algorithmic programming contest for college students. Teams of three, representing their university, work to solve the most real-world problems. Quite simply, it is the oldest, largest, and most prestigious programming contest in the world. 01. Who are eligible to participate? The entire competition will be held online and everyone is welcome to participate! 02. How many people should be in a team? Teams should be formed out of maximum 3 people. 03. What kind of problems will we solve? Have a look at this and this. These are some problems to get you familiar with the format. 04. Who have prepared the problems? All the problems are prepared by KBTU students/alumni and Daniyar Zakarin :) 05. What are the prizes? Top performed team consisting of only high school students will have a chance to win KBTU grants after interview process. We love open source"};

  split_string(splitted, data, " ");
 
  scanf("%d", &number);
  printf("%s\n", splitted[number]);

  return 0;
}
/*


split_string(splitted[][], origin[], delimiter[])
  i = 0
  token = strtok(origin, delimiter) //return alamat dari char yang telah dipotong
  while token != NULL
    strcpy(splitted[i], token);
    i = i + 1
    token = strtok(NULL, delimiter);

data = "t.me/kbtuopen Subscribe Participants INTRODUCING KBTU Open Spring 2021 Regular ICPC-style programming contest organized by Kazakh-British Technical University Join us on May 30, 2021 to compete and have fun UPDATE: Start time was rescheduled from 11:00 to 13:00 Link to contest Schedule 30 May, Online 11:00 - 13:00 Sending accounts 00. 13:00 - 18:00 Epic battle 01. 18:00 - 19:00 Leaderboard unfreeze 02. FAQ Frequently Asked Questions 00. What the heck is ICPC? The International Collegiate Programming Contest is an algorithmic programming contest for college students. Teams of three, representing their university, work to solve the most real-world problems. Quite simply, it is the oldest, largest, and most prestigious programming contest in the world. 01. Who are eligible to participate? The entire competition will be held online and everyone is welcome to participate! 02. How many people should be in a team? Teams should be formed out of maximum 3 people. 03. What kind of problems will we solve? Have a look at this and this. These are some problems to get you familiar with the format. 04. Who have prepared the problems? All the problems are prepared by KBTU students/alumni and Daniyar Zakarin :) 05. What are the prizes? Top performed team consisting of only high school students will have a chance to win KBTU grants after interview process. We love open source"
splitted: 2d array of char

split_string(splitted, data, " ")

input number
output splitted[number]

Pada problem ini diberikan beberapa kasus uji diberikan input berupa angka dan keluaran yang acak. Pada angka tertentu, output memberikan angka dan pada angka tertentu lainnya output memberikan output berupa kata. Bila input 1 maka outputnya Subscribe. Bila input berupa angka 43 maka outputnya Online. Diduga output dari program yang diminta adalah sebuah kata dari kalimat yang berhubungan dengan event online yang diadakan pada 2021. Bila dilihat dari source soal, soal ini dibuat oleh KTBU Open 2021.
 
Bila ‘2021 KBTU Open’ disearch dengan google maka akan keluar:
 
Dan bila link paling atas dibuka, maka akan menuju web berikut:
 
Bila di select all dengan menekan ctrl+a dan meng-copy konten yang ada pada web tersebut maka akan didapat:
t.me/kbtuopen Subscribe Participants INTRODUCING KBTU Open Spring 2021 Regular ICPC-style programming contest organized by Kazakh-British Technical University Join us on May 30, 2021 to compete and have fun UPDATE: Start time was rescheduled from 11:00 to 13:00 Link to contest Schedule 30 May, Online 11:00 - 13:00 Sending accounts 00. 13:00 - 18:00 Epic battle 01. 18:00 - 19:00 Leaderboard unfreeze 02. FAQ Frequently Asked Questions 00. What the heck is ICPC? The International Collegiate Programming Contest is an algorithmic programming contest for college students. Teams of three, representing their university, work to solve the most real-world problems. Quite simply, it is the oldest, largest, and most prestigious programming contest in the world. 01. Who are eligible to participate? The entire competition will be held online and everyone is welcome to participate! 02. How many people should be in a team? Teams should be formed out of maximum 3 people. 03. What kind of problems will we solve? Have a look at this and this. These are some problems to get you familiar with the format. 04. Who have prepared the problems? All the problems are prepared by KBTU students/alumni and Daniyar Zakarin :) 05. What are the prizes? Top performed team consisting of only high school students will have a chance to win KBTU grants after interview process. We love open source
Dan bila tiap kata diambil dengan delimiter spasi, maka didapat kata dengan urutan yang sesuai dengan kasus uji yang diberikan.

*/