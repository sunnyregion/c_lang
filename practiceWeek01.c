#include <stdio.h>
// 1逆序的三位数（5分）
// 题目内容：
// 逆序的三位数：

// 程序每次读入一个正三位数，然后输出逆序的数字。注意，当输入的数字含有结尾的0时，输出不应带有前导的0。比如输入700，输出应该是7。

// 提示：用%10可以得到个位数，用/100可以得到百位数...。将这样得到的三个数字合起来：百位*100+十位*10+个位，就得到了结果。

// 输入格式:
// 每个测试是一个3位的正整数。

// 输出格式：
// 输出逆序的数。

// 输入样例：
// 123

// 输出样例：
// 321
// 时间限制：500ms内存限制：32000kb
int main(){
	int iInput,iUnit,iDecade,iHundred,iResult;
	printf("请输入一个三位整数：" );
	scanf("%d",&iInput);
	if(iInput>999 || iInput<100){
		printf("不是一个三位数\n");
	}else{
		iUnit = iInput % 10;
		iDecade = (iInput % 100) /10;
		iHundred = iInput /100 ;
		//printf("你要的三位数的个位是%d,十分位%d , 百分位%d\n",iUnit,iDecade,iHundred);
		iResult = iUnit*100+iDecade*10+iHundred;
		printf("结果：%d\n", iResult);
	}
	return 0;
}
