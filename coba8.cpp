#include <cstdio>
using namespace std;

int main(){
	int t, n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		double val=1.0;
		for(int i=1;i<9;i++)
			val=val*(double)(n+i);
		double result=(((double)n+9.0)/9.0-(40320.0/val));
		printf("%.6lf\n", result);
	}
	return 0;
}

// 1    //menyiapkan variable
// 2    n, t : integer
// 3
// 4    //meminta input t sebagai test case
// 5    read t
// 6
// 7    While t>0
// 8
// 9        read(n)
// 10        val: double
// 11        val=1.0
// 12
// 13        For i=1 to 9
// 14            val=val*(n+1)
// 15
// 16
// 17        result : double
// 18        result = ((n+9)/9) – (9-(40320/val))
// 19         Write(result)
// 20
// 21    t = t-1