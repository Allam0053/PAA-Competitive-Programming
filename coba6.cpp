#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char num[1050];
int hash[10], freq[10];
char l4_list[150][1050];
int len_l4_list=0;
int l4_list_min=0;

void cari_prefix(int sufix){
    int hash_temp[10];
    // printf("temp:%d\n", temp);
    for(int i=0;i<10;i++){
        hash_temp[i]=hash[i];
    }
    int iter=0;
    int one=0;
    int two=0;
    int tre=0;
    if(sufix==0) {
        one=0;
        two=0;
        tre=0;
    }else if(sufix<10){
         one=0;
         two=0;
         tre=sufix;
    }else if(sufix<100){
        one=0;
        two=(sufix/10);
        tre=(sufix%10);
    }else if(sufix>=100){
        one=(sufix/100);
        two=((sufix/10)%10);
        tre=(sufix%10);
    }
    // printf("%d %d %d %d\n", one,two,tre,sufix);
    hash_temp[one]--;
    hash_temp[two]--;
    hash_temp[tre]--;
    for(int i=1;i<10;i++){
        if(hash_temp[i]--){
            l4_list[len_l4_list][iter++]=(i+'0');
            break;
        }
    }
    
    for(int i=0;i<10;i++){
        while(hash_temp[i]>0){
            hash_temp[i]--;
            l4_list[len_l4_list][iter++]=(i+'0');
        }
    }
    sprintf(l4_list[len_l4_list], "%s%d%d%d", l4_list[len_l4_list], one,two,tre);
    len_l4_list++;
    
    return;
}

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

int cek_invers(int iter_begin, int iter_end, int digit){ //int digit buat mbatasin len > 2
    for (int i = iter_begin; i > iter_end; i-=8) {
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
char result_l2[3];
int l2 (){
    return cek(16,100,2);
}

int l3(){
    return cek(104,1000,3);
}

void l4(){
    int divisible[150];
    for(int i=0; i<150; i++){
        divisible[i]=cek_invers(992-(i*8),-1,4);
    }
    for(int i=0; i<150; i++){
        if( divisible[i]!=-1 ){
            cari_prefix(divisible[i]); //hasil dari prefix+sufix ada di l4_list
        }
    }
    for(int i=1; i<len_l4_list; i++){
        if( strcmp(l4_list[i], l4_list[l4_list_min])<0 ){ // jika l4_list[i] < l4_list_min
            l4_list_min=i;
        }
    }
    return;
}

int main(){
    scanf("%s", num);
    int l=strlen(num);

    for(int i = 0; i<l; i++)
        hash[num[i] - '0']++;

    if(l==1){
        if(num[0]=='8' || num[0]=='0')
            printf("%c\n", num[0]);
        else printf("-1\n");
        return 0;
    }

    if(l==2){
        // if(strcmp(num,"00")==0){printf("0\n"); return 0;}
        printf("%d\n", l2());
        return 0;
    }

    if(l==3){
        printf("%d\n", l3());
        return 0;
    }

    if(l>=4){
        l4();
        bool flag=false;
        for(int i=0; i<l; i++)
        {
            if ( num[i]=='0' )
                flag=true;
        }
        if( flag ){
            printf("-1\n");
            return 0;
        }
        printf("%s\n", l4_list[l4_list_min]);
        return 0;
    }

    return 0;
}