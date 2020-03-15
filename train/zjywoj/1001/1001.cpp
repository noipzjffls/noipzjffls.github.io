#include<bits/stdc++.h>//万能头文件
using namespace std;
long double a,b,s;//定义变量
int d,p,i;
string x;
int main()
{
    ios::sync_with_stdio(0);//关闭同步
    scanf("%Lf%Lf%d",&a,&b,&d);
    s=a/b;//赋值为两个数的商
    x=to_string(s);//字符串赋值为相应的值
    for(;x[p]!='.';p++)printf("%c",x[p]);//有小数点出现，所以先输出整数部分
    p++;//到下一位（即小数点后第一位）
    if(d)printf(".");//如果d!=0就打印小数点
    for(i=0;i<d;i++,p++)printf("%c",x[p]);//输出小数点后部分
}
