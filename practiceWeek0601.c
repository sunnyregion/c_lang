#include <stdio.h>
/**
分解质因数（5分）
题目内容：
每个非素数（合数）都可以写成几个素数（也可称为质数）相乘的形式，这几个素数就都叫做这个合数的质因数。比如，6可以被分解为2x3，而24可以被分解为2x2x2x3。

现在，你的程序要读入一个[2,100000]范围内的整数，然后输出它的质因数分解式；当读到的就是素数时，输出它本身。

提示：可以用一个函数来判断某数是否是素数。

输入格式:
一个整数，范围在[2,100000]内。

输出格式：
形如：
n=axbxcxd
或
n=n
所有的符号之间都没有空格，x是小写字母x。abcd这样的数字一定是从小到大排列的。

输入样例：
18

输出样例：
18=2x3x3
时间限制：500ms内存限制：32000kb
*/
#define   PRIME_ARRAY_LENGTH 200
int isPrime(int i){
	int result=1;
	int k;
	for(k=2;k<i-1;k++){
		if(i%k==0){
			result=0;
			break;
		}
	}
	return result;
}


int* getPrimeArray(){
	int i=0;
	int j=2;
	static int result[PRIME_ARRAY_LENGTH];
	while(i<PRIME_ARRAY_LENGTH){
		if(isPrime(j)){
			result[i]=j;
			i++;
		}
		j++;
	}
	return result;
}
/**
	取得一个素数
*/
int getPrime(int iNum){
	int i;
	int iResult=-1;
	int* p=getPrimeArray();
	for(i=0;i<PRIME_ARRAY_LENGTH;i++){
		if(iNum % p[i] ==0){
			iResult=p[i];
			break; 
		}
	}
	return iResult;
}
int main(int argc, char const *argv[])
{
	
	int n,iTmp;
	scanf("%d",&n);
	if(n>1 && n<=100000){
		printf("%d=",n );
		while(n>1){
			iTmp=n;
			iTmp=getPrime(iTmp);
			printf("%d", iTmp);
			n=n/iTmp;
			if (n!=1){
				printf("x");
			}
		}
		
	}
	printf("\n");
	return 0;
}