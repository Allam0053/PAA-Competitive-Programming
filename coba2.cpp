#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//input
    char num[1001];
    int len;
//special
    char nope[]="-1";
    char eight[]="8";
//getting the result
    char hasil[125][1001];
    int len_hasil=0;
    char res[1001];
    char old[3];
    int freq[10] = { 0 };
    int hash[10] = { 0 };

void swap(char *xp, char *yp){
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
    return;
}
//FAIL CASE
    //200003031 -> 100003032
    //213231390 -> 101233392
    //88198916266161630 -> 10111236666699888
    //9000000000089 -> 8000000099000
    //2108 -> 1208
    //42 -> 24
    //80000000 -> 80000000
    //80000001 -> 10000008
void hitung(int temp, int* l){
    int hash_temp[10];
    // printf("temp:%d\n", temp);
    for(int i=0;i<10;i++){
        hash_temp[i]=hash[i];
    }
    int it=0;
    int one=0;
    int two=0;
    int tre=0;
    if(temp==0) {
        one=0;
        two=0;
        tre=0;
    }else if(temp<10){
         one=0;
         two=0;
         tre=temp;
    }else if(temp<100){
        one=0;
        two=(temp/10);
        tre=(temp%10);
    }else if(temp>=100){
        one=(temp/100);
        two=((temp/10)%10);
        tre=(temp%10);
    }
    // printf("%d %d %d %d\n", one,two,tre,temp);
    hash_temp[one]--;
    hash_temp[two]--;
    hash_temp[tre]--;
    for(int i=1;i<10;i++){
        if(hash_temp[i]--){
            // itoa(i, (hasil[len_hasil]+it), 10);
            // it++;
            hasil[len_hasil][it++]=(i+'0');
            break;
        }
    }
    
    for(int i=0;i<10;i++){
        while(hash_temp[i]>0){
            hash_temp[i]--;
            // itoa(i, (hasil[len_hasil]+it), 10);
            // it++;
            hasil[len_hasil][it++]=(i+'0');
        }
    }
    sprintf(hasil[len_hasil], "%s%d%d%d", hasil[len_hasil], one,two,tre);
    // printf("%s\n", hasil[len_hasil]);
    len_hasil++;
    
    return;
}

char* solve(char* n, int* l){
    bool first=false, second=false;
    if( *l==1 && *n=='8') return eight; //cek digit 1 saat == 8

	for (int i = 0; i <(*l); i++)
		hash[n[i] - '0']++;
    
    if (*l == 2) { //cek digit 2
    
		if (atoi(n) % 8 == 0){
            first=true;
            strcpy(old, n);
        }
		swap( n, n+1 );
		if (atoi(n) % 8 == 0){
            second=true;
        }
		if(first==true && second==true)
            if(strcmp(old,n)<0 && old[0]!='0')return old;
            else return n;
        else if(first==true)return old;
        else if(second==true)return n;
        else return nope;
	}
    
    //for every divisble 8 found. generate the smallest number with the available num
    for (int i = 104; i < 1000; i+=8) {
        // printf("%d\n", i);
		int dup = i;
        int temp = i;

		for(int j=0;j<10;j++)
            freq[j]=0;
		freq[dup % 10]++;
		dup = dup / 10;
		freq[dup % 10]++;
		dup = dup / 10;
		freq[dup % 10]++;
		dup = i;

		if (freq[dup % 10] > hash[dup % 10])
			continue;
		dup = dup / 10;
		if (freq[dup % 10] > hash[dup % 10])
			continue;
		dup = dup / 10;
		if (freq[dup % 10] > hash[dup % 10])
			continue;

        sprintf(res, "%d", i);
        return res;
	}
    return nope;
}

bool digit_banyak (char* n, int* l){
    for (int i = 0; i <(*l); i++)
		hash[n[i] - '0']++;
    // //special case that need to be stop earlier
    if( (hash[0]==0) && (hash[2]==0) && (hash[4]==0) && (hash[6]==0) && (hash[8]==0 || hash[8]==1) ){
		return false;
	}else if( (hash[0]==0) && (hash[2]==0) && (hash[4]==0 || hash[4]==1) && (hash[6]==0) && (hash[8]==0) ){
		return false;
	}
    for (int i = 0; i < 1000; i+=8) {
        // printf("%d\n", i);
		int dup = i;
        int temp = i;

		for(int j=0;j<10;j++)
            freq[j]=0;
		freq[dup % 10]++;
		dup = dup / 10;
		freq[dup % 10]++;
		dup = dup / 10;
		freq[dup % 10]++;
		dup = i;

		if (freq[dup % 10] > hash[dup % 10])
			continue;
		dup = dup / 10;
		if (freq[dup % 10] > hash[dup % 10])
			continue;
		dup = dup / 10;
		if (freq[dup % 10] > hash[dup % 10])
			continue;

        hitung(i, l);
	}
    return true;
}

int main (){
    
    scanf("%s", num);
    bool flag=true;
    len=strlen(num);
    for(int i=0;i<len;i++){
        if(num[i]!='0'){
            flag=false;
        }
    }
    if (flag){printf("%s\n", num); return 0;}

    int max=0;
    if(len<4){
        printf("%s\n", solve(num,&len));
    }else if( digit_banyak(num, &len) ){
        for(int i=1;i<len_hasil;i++){
            if( strcmp( hasil[i], hasil[max] )<0 
                && strlen(hasil[i])==len && hasil[i][0]!='0')
                max=i;
        }
    }
    if(strcmp(hasil[max],"")==0)printf("-1\n");
    else printf("%s\n", hasil[max]);
    
    

    return 0;
}

//if digit==1
//if digit==2
//if digit==3
//if digit>3
// 08
// 80