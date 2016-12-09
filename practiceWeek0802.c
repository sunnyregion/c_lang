/**
GPS数据处理（6分）
题目内容：
NMEA-0183协议是为了在不同的GPS（全球定位系统）导航设备中建立统一的BTCM（海事无线电技术委员会）标准，由美国国家海洋电子协会（NMEA-The National Marine Electronics Associa-tion）制定的一套通讯协议。GPS接收机根据NMEA-0183协议的标准规范，将位置、速度等信息通过串口传送到PC机、PDA等设备。

NMEA-0183协议是GPS接收机应当遵守的标准协议，也是目前GPS接收机上使用最广泛的协议，大多数常见的GPS接收机、GPS数据处理软件、导航软件都遵守或者至少兼容这个协议。

NMEA-0183协议定义的语句非常多，但是常用的或者说兼容性最广的语句只有$GPGGA、$GPGSA、$GPGSV、$GPRMC、$GPVTG、$GPGLL等。

其中$GPRMC语句的格式如下：
    $GPRMC,024813.640,A,3158.4608,N,11848.3737,E,10.05,324.27,150706,,,A*50

这里整条语句是一个文本行，行中以逗号“,”隔开各个字段，每个字段的大小（长度）不一，这里的示例只是一种可能，并不能认为字段的大小就如上述例句一样。
    字段0：$GPRMC，语句ID，表明该语句为Recommended Minimum Specific GPS/TRANSIT Data（RMC）推荐最小定位信息
    字段1：UTC时间，hhmmss.sss格式
    字段2：状态，A=定位，V=未定位
    字段3：纬度ddmm.mmmm，度分格式（前导位数不足则补0）
    字段4：纬度N（北纬）或S（南纬）
    字段5：经度dddmm.mmmm，度分格式（前导位数不足则补0）
    字段6：经度E（东经）或W（西经）
    字段7：速度，节，Knots
    字段8：方位角，度
    字段9：UTC日期，DDMMYY格式
    字段10：磁偏角，（000 - 180）度（前导位数不足则补0）
    字段11：磁偏角方向，E=东W=西
    字段16：校验值
这里，“*”为校验和识别符，其后面的两位数为校验和，代表了“$”和“*”之间所有字符（不包括这两个字符）的异或值的十六进制值。上面这条例句的校验和是十六进制的50，也就是十进制的80。

提示：^运算符的作用是异或。将$和*之间所有的字符做^运算(第一个字符和第二个字符异或，结果再和第三个字符异或，依此类推)之后的值对65536取余后的结果，应该和*后面的两个十六进制数字的值相等，否则的话说明这条语句在传输中发生了错误。注意这个十六进制值中是会出现A-F的大写字母的。

现在，你的程序要读入一系列GPS输出，其中包含$GPRMC，也包含其他语句。在数据的最后，有一行单独的
    END
表示数据的结束。

你的程序要从中找出$GPRMC语句，计算校验和，找出其中校验正确，并且字段2表示已定位的语句，从中计算出时间，换算成北京时间。一次数据中会包含多条$GPRMC语句，以最后一条语句得到的北京时间作为结果输出。
你的程序一定会读到一条有效的$GPRMC语句。

输入格式:
多条GPS语句，每条均以回车换行结束。最后一行是END三个大写字母。

输出格式：
6位数时间，表达为：
    hh:mm:ss
其中，hh是两位数的小时，不足两位时前面补0；mm是两位数的分钟，不足两位时前面补0；ss是两位数的秒，不足两位时前面补0。

输入样例：
$GPRMC,024813.640,A,3158.4608,N,11848.3737,E,10.05,324.27,150706,,,A*50
END

输出样例：
10:48:13
时间限制：500ms内存限制：32000kb
*/
#include "stdio.h"
#define GPS_ARRAY_SIZE 1000
 
/*GPS数据处理
str[]是一行GPS数据，times[]长度为3，存储验证通过的时间的时分秒数
*/
void gps(char str[], int times[]){
    int i;
    if(str[0]=='$'&&str[1]=='G'&&str[2]=='P'&&str[3]=='R'&&str[4]=='M'&&str[5]=='C'&&str[6]!='\0'){
 
        //处理$和*之间所有字符异或
        int sum = 0; //异或值
        for(i=1; str[i]!='*'; i++){
            sum = sum ^ str[i];
        }
 
        //处理*后的字符
        char c1=str[i+1], c2=str[i+2];
 
        //int1,int2存储校验字符的整型值，mask存储int1,int2转换为10进制
        int int1, int2, mask;
        if(c1 >='A' && c1<='F'){
            int1 = 10+(c1-'A');
        }else{
            int1 = c1 - '0';
        }
        if(c2 >='A' && c2<='F'){
            int2 = 10+(c2-'A');
        }else{
            int2 = c2 - '0';
        }
        mask = int1*16 + int2; //16进制转10进制
 
        //找出状态值
        for(i=7; str[i]!='*'; i++){ //从第一个逗号后面开始遍历
            if(str[i]==',')break;
        }
        if(str[i+1]=='A' && sum==mask){
            int hour = 10*(str[7]-'0') + (str[8]-'0'); //小时
            hour = (hour + 8) % 24;
            times[0] = hour;
            times[1] = 10 * (str[9] - '0') + (str[10] - '0'); //分钟
            times[2] = 10 * (str[11] - '0') + (str[12] - '0'); //秒
        }
    }
}
void week0802(){
    char str[GPS_ARRAY_SIZE][GPS_ARRAY_SIZE];
    int count=0;
    char a[GPS_ARRAY_SIZE];
    do{
        scanf("%s", a);
        if(strcmp("END",a) != 0){
            strcpy(str[count], a);
            count++;
        }
    }while(strcmp("END",a) !=0);
 
    int times[3] = {0}; //存储时分秒的数值
    int i;
    for(i=0; i<count; i++){
        gps(str[i],times);
    }
    printf("%02d:%02d:%02d\n", times[0],times[1],times[2]);
}

int main(int argc, char const *argv[])
{
	week0802();
	return 0;
}