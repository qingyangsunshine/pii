#include<stdio.h>
#include<limits.h>

char *itobs(int n,char *ps);
void show_bstr(const char *str);//void有两个用法，放在函数返回值的位置上，表示不需要返回值；放在
//放在参数位置时，表示此函数不接受参数

int main(void)
{
	char bin_str[CHAR_BIT * sizeof(int)+1];//int在内存中所占的字节数+1
	int number;
	puts("Enter integers and see them in binary");//将字符串输出到屏幕，遇到\0停止
	puts("Non-numeric input terminates program");
	while(scanf("%d",&number)==1)     //scanf的返回值是按照指定的格式符正确读入数据的个数
//当第n个变量不正确时，返回值为n-1
	{
		itobs(number,bin_str);
		printf("%d is",number);
		show_bstr(bin_str);
		putchar('\n');
	}
	puts("Bye!");

	return 0;
}

char *itobs(int n,char *ps)
{
	int i;
	const static int size=CHAR_BIT*sizeof(int);//const定义只读变量的关键字，常量
	//必须在定义时同时赋值，常量指针是不能通过指针来改变常量的值，也不能改变指针的地址
	//，但可以通过其他引用来改变值，注意，指针本身和他指向的数据可以都是只读的
	//int const*const p5;
	/*    constant和define的区别
	1、const定义常量时带类型，define不带
	2、const是在编译运行时起作用，define是在预处理阶段起作用
	3、define只是简单的替换没有类型的检查
	4、const不能重新定义，而define可通过undef取消某个符号的定义
	*/

/*static
1、在修饰变量时，static修饰的静态局部变量只执行一次，而且延长了局部变量的生命周期，
直到程序运行结束以后才释放
2、static修饰全局变量时，这个全局变量只能在本文中访问，即便是extern外部声明也不可以
3、static修饰一个函数，则这个函数只能在本文件中调用，不能被其他文件调用。static修饰的局部变量
存放在全局数据库的静态变量区。

*/

//CHAR_BIT表示char类型的位数


for(i=size-1;i>=0;i--,n>>=1)
		ps[i]=(01&n)+'0';//加上'0'是int类型转化成char类型，01&n的结果为0或1
	ps[size]='\0';//'\0'是字符串的结束标志。

/*
eg:  char str[]={'a','b','c'}
printf("%s\n",str)
用单引号赋值时会丢失'\0'.所以此时字符串数组无结束标志
修改为：char str1[5]={"abcd"}
		char str1[5]={'a','b','c','d','\0'}
		char str1[5]={'a','b','c','d'}

*/
	return ps;   
	//返回数组的首地址
}
void show_bstr(const char *str)
{
	int i=0;
	while(str[i])  // 是不是一个空字符
	{
		putchar(str[i]);
		/*
		putchar与puts的区别
		putchar函数只能用于单个字符的输出，且一次只能输出一个字符；puts()向标准输出设备
		写字符串并换行
		*/
		if(++i%4==0 && str[i])
			putchar(' ');
		/*
		++i与i++的区别
		1、用于赋值语句，i++先赋值后加1，++i先加1后赋值
		i=1;y=i++;     执行完成后y=1;i=2
		i=1;y=++i;     执行完成后y=2;i=2
		2、用于判断条件表达式
		i++先执行判断再加1
		++i先加1在执行判断

		*/

	}

}
