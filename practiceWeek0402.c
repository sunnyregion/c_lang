#include "stdio.h"
#include <string.h>
/**
念整数（5分）
题目内容：
你的程序要读入一个整数，范围是[-100000,100000]。然后，用汉语拼音将这个整数的每一位输出出来。
如输入1234，则输出：
yi er san si
注意，每个字的拼音之间有一个空格，但是最后的字后面没有空格。当遇到负数时，在输出的开头加上“fu”，如-2341输出为：
fu er san si yi

输入格式:
一个整数，范围是[-100000,100000]。

输出格式：
表示这个整数的每一位数字的汉语拼音，每一位数字的拼音之间以空格分隔，末尾没有空格。

输入样例：
-30

输出样例：
fu san ling
时间限制：500ms内存限制：32000kb
*/
struct{               
	int name; 
	char pinyin[10]; 
}Py[]= {
    {45, "fu"},
    {0, "ling"},
    {1, "yi"},
    {2, "er"},
    {3, "san"},
    {4, "si"},
    {5, "wu"},
    {6, "liu"},
    {7, "qi"},
    {8, "ba"},
    {9, "jiu"},
};
int substring(char *, int, int, char *);

int main(int argc, char const *argv[])
{
	int i,iInput,digit,j;
	char cPlaces[7];
	char cResult[200];
	scanf("%d",&iInput);
	int iMark=0;
	if(iInput>=-100000 && iInput<=100000){
		if(iInput==0){
			printf("%s\n",Py[1].pinyin );
		}else{
			i=0;
			if(iInput<0){
				iMark=1;
				iInput*=-1;
			}
			while ( iInput!=0 ) {
				digit = iInput%10;
				cPlaces[i]=digit;
				iInput /= 10;
				i++;
			}
			if(iMark){
				cPlaces[i]='-';
				i++;
			}
			for(j=i-1;j>-1;j--){
				for(i=0;i<11;i++){
					if(cPlaces[j]==Py[i].name){
						strcat(cResult, Py[i].pinyin);
						strcat(cResult," ");
						break;
					}
				}
			}
			char t[100];
			int r=substring(cResult,0,strlen(cResult)-1,t);
			printf("%s\n",t);
		}
		
	}else{
		printf("Err number:");
	}
	return 0;
}


int substring(char * s,int start,int len,char * t)  
{  
	int i=0,j=0;  
	while(s[i])  
	   i++;  
	if(i<start)  
	   return -1;  
	else {  
	   for(i=start;i<=start+len-1;i++)  
	   {  
	    t[j]=s[i];  
	    j++;  
	   }  
	   t[j]='\0';  
	   return 1;  
	}  
}  
