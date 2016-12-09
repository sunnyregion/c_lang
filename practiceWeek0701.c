#include "stdio.h"

#define   PRIME_ARRAY_LENGTH 101
void week7_1(){
	int powerArr[PRIME_ARRAY_LENGTH] = {0};
    int iPower,iIndex, count=0;
 
    //输入幂和系数，数组下标就是幂。count记录零次幂输入的次数
    while(count < 2){
        scanf("%d %d", &iPower, &iIndex);
        powerArr[iPower] += iIndex;
        if(iPower==0) count++;
    }
    int flag=0; //是否是第一个输出
    int i=PRIME_ARRAY_LENGTH-1;
    while(i>0){
        if(powerArr[i]!=0){
            if(flag&&powerArr[i]>0){
                printf("+");
            }
            if(i>1){
                if(powerArr[i]==-1){
                    printf("-x%d",i);
                }else if(powerArr[i]==1){
                    printf("x%d",i);
                }else{
                    printf("%dx%d",powerArr[i],i);
                }
            }else if(i==1){
                if(powerArr[i]==-1){
                    printf("-x");
                }else if(powerArr[i]==1){
                    printf("x");
                }else{
                    printf("%dx",powerArr[1]);
                }
            }
            flag=1;
        }
        i--;
    }
    //最后输出常数
    if(flag&&powerArr[0]>0){
        printf("+%d",powerArr[0]);
    }
    if( (flag&&powerArr[0]<0) || (!flag&&powerArr[0]>=0) ){
        printf("%d",powerArr[0]);
    }

    printf("\n");
}


int main(int argc, char const *argv[])
{
	week7_1();
	return 0;
}
