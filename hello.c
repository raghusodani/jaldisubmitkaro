#include<stdio.h>
long long a[1000],t,n,i,j;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        for(i=0;i<n;i++){
            a[i]=i+1;
        }
//        for(i=0;i<n;i++){
//            printf("%d ",a[i]);
//        }
		int i=1;
	    if(n%2)
	    { printf("3 1 2 "); i=4;}
	    for(;i<=n; i+=2)
	    printf("%d %d ",i+1,i);
	    printf("\n")
	}
	return 0;
}




