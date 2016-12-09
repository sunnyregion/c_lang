#include <stdio.h>
#include <stdlib.h>
/**
信号报告（5分）
题目内容：
无线电台的RS制信号报告是由三两个部分组成的：
R(Readability) 信号可辨度即清晰度.
S(Strength)    信号强度即大小.
其中R位于报告第一位，共分5级，用1—5数字表示.
Unreadable
Barely readable, occasional words distinguishable
Readable with considerable difficulty
Readable with practically no difficulty
Perfectly readable
报告第二位是S，共分九个级别，用1—9中的一位数字表示
Faint signals, barely perceptible
Very weak signals
Weak signals
Fair signals
Fairly good signals
Good signals
Moderately strong signals
Strong signals
Extremely strong signals
现在，你的程序要读入一个信号报告的数字，然后输出对应的含义。如读到59，则输出：

Extremely strong signals, perfectly readable.

输入格式:
一个整数，信号报告。整数的十位部分表示可辨度，个位部分表示强度。输入的整数范围是[11,59]中的个位不为0的数字，这个范围外的数字不可能出现在测试数据中。

输出格式：
一句话，表示这个信号报告的意义。按照题目中的文字，先输出表示强度的文字，跟上逗号和空格，然后是表示可辨度的文字，跟上句号。注意可辨度的句子的第一个字母是小写的。注意这里的标点符号都是英文的。

输入样例：
33

输出样例：
Weak signals, readable with considerable difficulty.

*/
char * strlwr(char *str)
{
   char *p = str;
   while (*p != '\0')
   {
      if(*p >= 'A' && *p <= 'Z')
        *p = (*p) + 0x20;
      p++;
    }
  return str;
}

char * strupr(char *str){
	if(str == NULL)
		return NULL; 
	char *p = str;
	while (*p != '\0'){
		if(*p >= 'a' && *p <= 'z')
			*p = (*p) - 0x20;
		p++;
	}
    return str;
}

int main(int argc, char const *argv[])
{
	int iInput;
	int iUnit,iDecade;
	char * chReadability[] = {
		"Unreadable",
		"Barely readable, occasional words distinguishable",
		"Readable with considerable difficulty",
		"Readable with practically no difficulty",
		"Perfectly readable"
	};
	char * chStrength[] ={
		"Faint signals, barely perceptible",
		"Very weak signals",
		"Weak signals",
		"Fair signals",
		"Fairly good signals",
		"Good signals",
		"Moderately strong signals",
		"Strong signals",
		"Extremely strong signals"
	};
	printf("请输入数字：" );
	scanf("%d",&iInput);
	iUnit=iInput/10;
	iDecade=iInput %10;
	if(iDecade==0 || iInput<11 || iUnit >6  ){
		printf("Err number:%d  %d\n",iUnit,iDecade);
	}else{
		char data[100];
		sprintf(data,"%s",chReadability[--iUnit]);
		printf("%s\n",data );
		printf("%s, %s.\n",chStrength[--iDecade],strlwr(data) );
	}
	return 0;
}