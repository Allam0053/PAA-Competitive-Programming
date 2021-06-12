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

void generate(int temp, int* l){
    int hash_temp[10];
    printf("temp:%d\n", temp);
    for(int i=0;i<10;i++){
        hash_temp[i]=hash[i];
    }
    int it=0;
    if(temp==0) hash_temp[0]-=2;
    else if(temp>10) hash_temp[0]-=2;
    else if(temp>100)hash_temp[0]-=1;
    while(temp/10>0){
        hash_temp[temp % 10]-=freq[temp % 10];
        // itoa((temp % 10), (hasil[len_hasil]+it), 10);
        // it++;
        temp = temp / 10;
    }
    for(int i=1;i<10;i++){
        if(hash_temp[i]--){
            itoa(i, (hasil[len_hasil]+it), 10);
            it++;
            // hasil[len_hasil][it++]=(i+'0');
            break;
        }
    }
    
    for(int i=0;i<10;i++){
        while(hash_temp[i]>0){
            hash_temp[i]--;
            itoa(i, (hasil[len_hasil]+it), 10);
            it++;
            // strncat(hasil[len_hasil], (i+'0'));
            // hasil[len_hasil][it++]=(i+'0');
        }
    }
    sprintf(hasil[len_hasil], "%s%d", hasil[len_hasil], temp);
    // printf("hasil[len_hasil]: %s\n", hasil[len_hasil]);
    len_hasil++;
    
    return;
}

char* solve(char* n, int* l){
    bool first=false, second=false;
    if( *l==1 && *n=='8') return eight;

	for (int i = 0; i <(*l); i++)
		hash[n[i] - '0']++;
    
    if (*l == 2) { //cek digit kurang dari 3
    
		if (atoi(n) % 8 == 0){
            first=true;
            strcpy(old, n);
        }
		swap( n, n+1 );
		if (atoi(n) % 8 == 0){
            second=true;
        }
		if(first==true && second==true)
            if(strcmp(old,n)<0)return old;
            else return n;
        else if(first==true)return old;
        else if(second==true)return n;
        else return nope;
	}
    
    //special case that need to be stop earlier
    if( (hash[0]==0) && (hash[2]==0) && (hash[4]==0) && (hash[6]==0) && (hash[8]==0 || hash[8]==1) ){
		return nope;
	}else if( (hash[0]==0) && (hash[2]==0) && (hash[4]==0 || hash[4]==1) && (hash[6]==0) && (hash[8]==0) ){
		return nope;
	}
    
    //for every divisble 8 found. generate the smallest number with the available num
    for (int i = 0; i < 1000; i += 8) {
        
		int dup = i;
        // printf("%d\n", i);
		// stores the frequency of all single
		// digit in three-digit number
		for(int j=0;j<10;j++)
            freq[j]=0;
		freq[dup % 10]++;
		dup = dup / 10;
		freq[dup % 10]++;
		dup = dup / 10;
		freq[dup % 10]++;
		dup = i;

		// check if the original number has
		// the digit
		if (freq[dup % 10] > hash[dup % 10])
			continue;
		dup = dup / 10;
		if (freq[dup % 10] > hash[dup % 10])
			continue;
		dup = dup / 10;
		if (freq[dup % 10] > hash[dup % 10])
			continue;

        
        if(*l==3){
            if(i>10) sprintf(res, "00%d", i);
            else if(i>100) sprintf(res, "0%d", i);
            else sprintf(res, "%d", i);
            return res;
        }else {
            generate(i, l); continue;
        }

		// printf("%s\n", res);
		return res;
	}

    return nope;
}

int main (){
    
    scanf("%s", num);
    // sprintf(num, "%s", "1000");
    len=strlen(num);
    if(len>=4){
        solve(num,&len);
        int max=0;
        if(len_hasil>0){
            for(int i=0;i<len_hasil;i++){
                if(strcmp( hasil[i], hasil[max] )>0 && strlen(hasil[max])==len)max=i;
                printf("%s\n", hasil[max]);
            }
        }
    }else printf("%s\n", solve(num,&len));
    
    

    return 0;
}

//if digit==1
//if digit==2
//if digit==3
//if digit>3
// 08
// 80