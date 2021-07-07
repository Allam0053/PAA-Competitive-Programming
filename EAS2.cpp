#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int total = 0;
char lab[10][10];
bool is_visited[10][10];

void searchLab (int x, int y, int n) {
  if (x < 0 || y < 0 || x >= n || y >= n) return;
  if (is_visited[x][y] || lab[x][y] != '-') return;
  is_visited[x][y] = true;
  total++;
  searchLab (x-1, y, n);
  searchLab (x+1, y, n);
  searchLab (x, y-1, n);
  searchLab (x, y+1, n);
  return;
}

int main () {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%s", &lab[i]);
  }
  int start[2];
  scanf("%d%d", &start[0], &start[1]);
  searchLab(start[0], start[1], n);
  printf("%d\n", total);
}