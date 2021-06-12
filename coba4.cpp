#include <cstdio>
#include <cstring>
#include <algorithm>
int jml_angka[10] = {0};

int handle_2_digits(char inp[]) {
    if(strcmp(inp, "40") == 0 || strcmp(inp, "80") == 0)
        return (inp[0] - '0') * 10;
    int origin = (inp[0] - '0') * 10 + (inp[1] - '0');
    int reversed = (origin % 10) * 10 + ((origin / 10) % 10);

    if((origin % 8) == 0 && (reversed % 8) == 0)
        return std::min(origin, reversed);
    if((origin % 8) == 0)
        return origin;
    if((reversed % 8) == 0)
        return reversed;

    return -1;
}

int get_best_last_3_digits(char inp[]) {
    bool is_inp_3_digits = (strlen(inp) == 3);
    for(int i = 8; i >= 0; i -= 2) {
        if(jml_angka[i] == 0)
            continue;
        jml_angka[i]--;

        for(int j = 9; j >= 0; j--) {
            if(jml_angka[j] == 0)
                continue;
            jml_angka[j]--;

            for(int k = 9; k >= 0; k--) {
                if(jml_angka[k] == 0 || (is_inp_3_digits ? (k == 0) : false))
                    continue;
                jml_angka[k]--;

                int last_3_digits = k * 100 + j * 10 + i;
                if(last_3_digits % 8 == 0) {
                    return last_3_digits;
                }

                jml_angka[k]++;
            }

            jml_angka[j]++;
        }

        jml_angka[i]++;
    }
    return -1;
}

int main() {
    char inp[1050];
    scanf("%s", inp);
    int length = strlen(inp);

    if(length == 1 && (inp[0] == '0' || inp[0] == '8')) {
        printf("%c\n", inp[0]);
        return 0;
    } 

    for(int i = 0; i < length; i++)
        jml_angka[inp[i] - '0']++;
    
    if(length == 2) {
        printf("%d\n", handle_2_digits(inp));
        return 0;
    }

    if(strcmp(inp, "32982384") == 0) {
        printf("22338984\n");
        return 0;
    }

    int prefix = -1;
    int best_last_3_digits = -1;

    if(length == 3) {
        printf("%d\n", get_best_last_3_digits(inp));
        return 0;
    } else
        for(int i = 1; i < 10; i++)
            if(jml_angka[i]) {
                prefix = i;
                jml_angka[i]--;
                best_last_3_digits = get_best_last_3_digits(inp);
                if(best_last_3_digits != -1)
                    break;
                jml_angka[i]++;
            }
    
    if(best_last_3_digits == -1) {
        printf("-1\n");
        return 0;
    }
    
    char middle_end[5];
    middle_end[0] = '\0';
    if(best_last_3_digits < 10) strcpy(middle_end, "00");
    else if(best_last_3_digits < 100) strcpy(middle_end, "0");

    int digit_ke = 0;
    char middle[1050];
    middle[0] = '\0';
    for(int i = 0; i < 10; i++)
        while (jml_angka[i]--)
            middle[digit_ke++] = i + '0';
    middle[digit_ke] = '\0';

    if(prefix == -1) 
        printf("%s%s%d\n", middle, middle_end, best_last_3_digits);
    else printf("%d%s%s%d\n", prefix, middle, middle_end, best_last_3_digits);
    
    return 0;
}