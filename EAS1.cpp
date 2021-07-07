

int main () {
  int n;
  char nilai[100];
  scanf("%d", &n);\
  for (int it1=0; it1<n; it1++) {
    scanf("%s", &nilai[it1]);
  }
  float GPA = 0.0;
  float list[] = {4.0, 3.0, 2.0, 1.0, 0.0};

  for (int it1=0; it1<n; it1++) {
    int convert = nilai[it1] - 'A';
    GPA += list[convert];
  }
  GPA /= float(n);
  printf("%.2f\n", GPA);
}