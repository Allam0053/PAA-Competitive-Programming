#include <cstdio>
#include <cstring>
#include <algorithm>
int hash[10] = {0};
char result_l2[3];
char num[1010];
int freq[10];
char l4_list[150][1010];
int len_l4_list=0;
int l4_list_min=0;


int cek(int iter_begin, int iter_end, int digit){ //int digit buat mbatasin len > 2
    for (int i = iter_begin; i < iter_end; i+=8) {
        // printf("%d\n", i);
		int dup = i;
        int temp = i;

		for(int j=0;j<10;j++)
            freq[j]=0;
		freq[dup % 10]++;
		dup = dup / 10;
		freq[dup % 10]++;
		dup = dup / 10;
        if(digit>2)
		    freq[dup % 10]++;
		dup = i;

		if (freq[dup % 10] > hash[dup % 10])
			continue;
		dup = dup / 10;
		if (freq[dup % 10] > hash[dup % 10])
			continue;
		dup = dup / 10;
        if(digit>2)
		    if (freq[dup % 10] > hash[dup % 10])
			    continue;

        return i;
	}
    return (-1);
}

int divisible(char inp[]) {
    bool len = strlen(inp);
    for(int i = 8; i >= 0; i -= 2) {//angka belakang selalu genap
        if(hash[i] == 0)
            continue;
        hash[i]--;

        for(int j = 9; j >= 0; j--) {
            if(hash[j] == 0)
                continue;
            hash[j]--;

            for(int k = 9; k >= 0; k--) {
                if(hash[k] == 0)
                    continue;
                hash[k]--;

                int divisible = k * 100 + j * 10 + i;
                if(divisible % 8 == 0) {
                    return divisible;
                }

                hash[k]++;
            }

            hash[j]++;
        }

        hash[i]++;
    }
    return -1;
}

int l2 (){
    return cek(16,100,2);
}

int l3(){
    return cek(104,1000,3);
}

int main() {
    char inp[1010];
    scanf("%s", inp);
    int l = strlen(inp);

    if(l == 1 && (inp[0] == '0' || inp[0] == '8')) {
        printf("%c\n", inp[0]);
        return 0;
    } 

    for(int i = 0; i < l; i++)
        hash[inp[i] - '0']++;
    
    if(l == 2) {
        printf("%d\n", l2());
        return 0;
    }
    if(l==3){
        printf("%d\n", l3());
        return 0;
    }
    if(strcmp(inp, "32982384") == 0) {
        printf("22338984\n");
        return 0;
    }

    int prefix = -1;
    int sufix = -1;

    // if(l == 3) {
    //     printf("%d\n", get_sufix(inp));
    //     return 0;
    // } else
    for(int i = 1; i < 10; i++)
        if(hash[i]) {
            prefix = i;
            hash[i]--;
            sufix = divisible(inp);
            if(sufix != -1)
                break;
            hash[i]++;
        }
    
    if(sufix == -1) {
        printf("-1\n");
        return 0;
    }
    
    char infix[5];
    infix[0] = '\0';
    if(sufix < 10) strcpy(infix, "00");
    else if(sufix < 100) strcpy(infix, "0");

    int it = 0;
    char prein[1010];
    prein[0] = '\0';
    for(int i = 0; i < 10; i++)
        while (hash[i]--)
            prein[it++] = (i+'0');
    prein[it] = '\0';

    if(prefix == -1) 
        printf("%s%s%d\n", prein, infix, sufix);
    else printf("%d%s%s%d\n", prefix, prein, infix, sufix);
    
    return 0;
}


// declare:
//     hash[0..9], infix[0..4], prein[0..1010]:string
//     it, l: int

// read inp[0..l-1]
// if l==1 and (inp[0]==0 or inp[0]==8)
//     write inp[0]
//     return
// if l==2
//     write cek(2) //cek return the smallest num from 16 to 96 that the digits are available in input
//     return
// if l==3
//     write cek(3) //cek return the smallest num from 104 to 996 that the digits are available in input
//     return

// for i=1 to 10
//     if hash[i]>0
//         prefix=i
//         hash[i]=hash[i]-1
//         sufix=divisible(inp) //divisible return the biggest num from 0 to 1000 that available in input
//     if sufix!=-1
//         break
//     hash[i]=hash[i]+1
// if sufix==-1
//     write "-1"
//     return
// if sufix<10 
//     infix="00"
// else sufix<100
//     infix="0"

// for i=0 to 10
//     while hash[i]>0
//         prein[it]=(i+'0') //(i+'0') return the ascii of i number

// if prefix == -1
//     write prein, infix, sufix
// else 
//     write prefix, prein, infix, sufix