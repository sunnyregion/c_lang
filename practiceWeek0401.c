#include "stdio.h"
#include "math.h"
/**
素数和（5分）
题目内容：
我们认为2是第一个素数，3是第二个素数，5是第三个素数，依次类推。
现在，给定两个整数n和m，0<n<=m<=200，你的程序要计算第n个素数到第m个素数之间所有的素数的和，包括第n个素数和第m个素数。

输入格式:
两个整数，第一个表示n，第二个表示m。

输出格式：
一个整数，表示第n个素数到第m个素数之间所有的素数的和，包括第n个素数和第m个素数。

输入样例：
2 4

输出样例：
15
*/


/**
 * 求素数的函数
 */
int prime (int n)
{
	int i,temp;
	temp=sqrt(n);
	for (i=2;i<=temp;i++){
		if (n%i==0) 
			return 0;
	}
		
	return 1;
}

int* getPrimeArray(){
	int i=0;
	int j=2;
	static int result[200];
	while(i<200){
		if(prime(j)){
			result[i]=j;
			i++;
		}
		j++;
	}
	return result;
}
int main(int argc, char const *argv[])
{
	int i,n,m,iResult;
	scanf("%d %d",&n,&m);
	int* p=getPrimeArray();
	for(i=n-1;i<m;i++){
		iResult+=p[i] ;
	}
	printf("%d\n", iResult);
	return 0;
}