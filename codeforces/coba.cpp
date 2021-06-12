#include <stdio.h>

int main() {
    int tes;
    tes = 18;
    tes = tes & (-tes);
    printf("%d\n", tes);
    return 0;
}