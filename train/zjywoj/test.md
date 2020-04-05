# 1: Hello world!
入门题，可以用多种语言直接解决：
```cpp
#include <iostream>
using namespace std;
int main(){
    cout<<"Hello world!";
    return 0;
}
```
```c
#include <stdio.h>
int main(){
    printf("Hello world!");
    return 0;
}
```
```pascal
begin 
    write('Hello world!');
end.
```
```java
public class Main{
    public static void main(String args[]){
        System.out.println("Hello world!");
    }
}
```
```python
print('Hello world!')
```
# 2: A+B Problem
这道题对于大数字，$C++$可以用$long$ $long$。即：
```cpp
#include<cstdio>
long long a,b;
int main()
{
    scanf("%lld%lld",&a,&b);
    printf("%lld",a+b);
}
```
# 3: A+B Problem (Upgraded Edition)
先输入$n$，然后循环输入并求和，最后输出和。（同样要用$long$ $long$）
```cpp
#include<cstdio>
int n;
long long s,t;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lld",&t);
        s+=t;
    }
    printf("%lld",s);
}
```
# 4: A+B Problem (Upgraded Edition 2)
对于若干个数的输入可以判断是否等于$EOF$（即$end$ $of$ $file$）。
```cpp
#include<cstdio>
long long n,s;
int main()
{
    while(scanf("%lld",&n)!=EOF)s+=n;
    printf("%lld",s);
}
```
# 5: Copycat
用字符串输入输出即可（当然$Python$可以直接用$int$）。
```cpp
#include<iostream>
using namespace std;
string s;
int main()
{
    while(cin>>s)cout<<s<<endl;
}
```
# 6: 两数相除，商为何？
使用浮点类型可以保存小数。
```cpp
#include<cstdio>
double a,b;
int main()
{
    scanf("%lf%lf",&a,&b);
    if(!a)printf("0");//这里要特判，因为当结果为0的时候可能会输出-0.0000000
    else printf("%.7lf",a/b);
}
```
# 7: 合数之和
这个程序需要写一个$check$函数来判断一个数是否为合数：
```cpp
bool check(long long x)
{
    if(x<2)return 0;//0和1既不是素数又不是合数
    for(long long i=2;i*i<=x;i++)if(x%i==0)return 1;//只要有非1非本身的因数就返回1
    return 0;//否则返回0
}
```
通过这个函数的调用，可以快速进行判断。
```cpp
#include<cstdio>
bool check(long long x)//定义check函数
{
    if(x<2)return 0;
    for(long long i=2;i*i<=x;i++)if(x%i==0)return 1;
    return 0;
}
int main()
{
    int t;
    long long x;
    scanf("%d",&t);//测试数据组数
    while(t--)
    {
        scanf("%lld",&x);//输入合数的和
        if(x!=4&&x%4==0)//如果x能够被4整除且不为4（为4的时候4=2+2，不为合数），则两个拆分的数都为不为2的偶数，所以直接输出
        {
            printf("%lld %lld\n",x/2,x/2);
            continue;
        }
        for(long long i=2;i<=x/2;i++)//循环判断
        {
            if(check(i)&&check(x-i))//check函数返回为真就输出并跳出for循环
            {
                printf("%lld %lld\n",i,x-i);
                break;
            }
        }
    }
}
```