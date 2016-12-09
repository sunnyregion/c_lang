#include <stdio.h>
int main()
{
    int m;
    printf("Input m: ");
    scanf("%d", &m);        //输入一个整数
    if (m > 0)              //是否为正数
    {
        if (m % 2 == 0)     //是正数，且能被2整除，则是正偶数
        {
            printf("%d is a positive even\n", m);
        }
        else                    //不能被2整除，则是正奇数
        {
            printf("%d is a positive odd\n", m);
        }
    }
 
     
   else if(m<0)          //判断是否为负数
     
    {
        if(m % 2 ==0)
         
        {
             printf("%d is a negative even\n", m);   //是负偶数
        }
        else
        {
             printf("%d is a negative odd\n", m);    //是负奇数
        }
    }
    else
    {
        printf("%d is zero.It is an even\n", m);    
    }
   return 0;
}