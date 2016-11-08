#include <stdio.h>
#include <stdlib.h>

char * my_strlwr(char *str)
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
int main(int argc, char const *argv[])
{
	char str[] = "HTTP://see.xidian.edu.cn/cpp/u/shipin/";
    printf("%s\n", strlwr(str));
    printf("%s\n", str);
    return  0;
}