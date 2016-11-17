#include <stdio.h>
/**
完数（5分）
题目内容：
一个正整数的因子是所有可以整除它的正整数。而一个数如果恰好等于除它本身外的因子之和，这个数就称为完数。例如6=1＋2＋3(6的因子是1,2,3)。

现在，你要写一个程序，读入两个正整数n和m（1<=n<m<1000），输出[n,m]范围内所有的完数。

提示：可以写一个函数来判断某个数是否是完数。

输入格式:
两个正整数，以空格分隔。

输出格式：
其间所有的完数，以空格分隔，最后一个数字后面没有空格。如果没有，则输出一行文字：
NIL
（输出NIL三个大写字母加回车）。

输入样例：
1 10

输出样例：
6
时间限制：500ms内存限制：32000kb
*/
int getFactor(int i){
	int k,iResult=0;
	for (k=1;k<i;k++){
		if(i%k==0){
			iResult+=k;
		}
	}
	return iResult;
}
int main(int argc, char const *argv[])
{
	
	int n,m,i,iSum,iCount=0;
	int iArr[50];
	scanf("%d %d",&n,&m);
	if(n>=1 && n<m && m<=100000){
		for(i=n;i<=m;i++){
			iSum=getFactor(i);
			if(i==iSum && iSum>1){
				iArr[iCount]=i;
				iCount++;
			}
		}
		
	}else{
		printf("NIL\n");
	}
	if(iCount==0){
		printf("NIL\n");
	}else{
		n=iCount-1;
		for(i=0;i<iCount;i++){
			if(i!=n){
				printf("%d ", iArr[i]);
			}else{
				printf("%d\n", iArr[i]);
			}
		}
	}
	return 0;
}