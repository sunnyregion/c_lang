#include "stdio.h"
/**
数字特征值（5分）
题目内容：
对数字求特征值是常用的编码算法，奇偶特征是一种简单的特征值。对于一个整数，从个位开始对每一位数字编号，个位是1号，十位是2号，以此类推。这个整数在第n位上的数字记作x，如果x和n的奇偶性相同，则记下一个1，否则记下一个0。按照整数的顺序把对应位的表示奇偶性的0和1都记录下来，就形成了一个二进制数字。比如，对于342315，这个二进制数字就是001101。

这里的计算可以用下面的表格来表示：

数字 	3 	4 	2 	3 	1 	5
数位 	6 	5	4	3 	2 	1
数字奇偶	奇 	偶 	偶 	奇 	奇 	奇
数字奇偶	奇 	偶 	偶 	奇 	奇 	奇
奇偶一致 	0 	0 	1 	1 	0 	1
二进制位值 32 	16 	8 	4 	2 	1
你的程序要读入一个非负整数，整数的范围是[0,1000000]，然后按照上述算法计算出表示奇偶性的那个二进制数字，输出它对应的十进制值。

提示：将整数从右向左分解，数位每次加1，而二进制值每次乘2。

输入格式:
一个非负整数，整数的范围是[0,1000000]。

输出格式：
一个整数，表示计算结果。

输入样例：
342315

输出样例：
13
时间限制：500ms内存限制：32000kb
*/
int main(int argc, char const *argv[])
{
	int iInput,digit ,x,i,j;
	int iOddEven[6];
	int iPlaces[6];
	int iResult=0;
	scanf("%d",&iInput);
	i=1;
	if(iInput>-1 && iInput<=1000000){
		x=iInput;
		while ( x> 0 ) {
			digit = x%10;
			iOddEven[i-1]=digit%2;
			iPlaces[i-1]=i%2;
			//printf("%d\n", digit);
			x /= 10;
			i++;
		}
		i--;i--;
		for(j=i;j>-1;j--){
			iResult+=!(iOddEven[j]^iPlaces[j]);
			
			printf("%d %d %d %d\n", iOddEven[j],iPlaces[j] ,!(iOddEven[j]^iPlaces[j]),iResult);
			iResult=iResult<<1;
		}
		iResult=iResult>>1;
		printf("%d\n", iResult);

	}else{
		printf("Error number\n");
	}
	return 0;
}