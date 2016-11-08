#include <stdio.h>
/**
奇偶个数（5分）
题目内容：
你的程序要读入一系列正整数数据，输入-1表示输入结束，-1本身不是输入的数据。程序输出读到的数据中的奇数和偶数的个数。

输入格式:
一系列正整数，整数的范围是（0,100000）。如果输入-1则表示输入结束。

输出格式：
两个整数，第一个整数表示读入数据中的奇数的个数，第二个整数表示读入数据中的偶数的个数。两个整数之间以空格分隔。

输入样例：
9 3 4 2 5 7 －1 

输出样例：
4 2
*/
int main(int argc, char const *argv[])
{
	int iInput,iOdd,iEven;
	do{
		scanf("%d",&iInput);
		if(iInput==-1)
			break;
		if(iInput%2==0){
			iEven++;
		}else{
			iOdd++;
		}
	}while(iInput!=-1);

	printf("%d %d\n",iOdd,iEven );
	return 0;
}