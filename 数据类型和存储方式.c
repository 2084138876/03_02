#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// char         字符型     1字节    1字节=8bit 即8个二进制位
// short	    短整型		2字节
// int			整型		4字节
// long         长整型		32位下4字节，64位下8字节
// long long    更长的整型	8字节
// float        单精度浮点型 4字节
// double		双精度浮点型 8字节

// 整型家族
//char //字符在内存中存的是ascll 码值，本质是整型，char 1个字节，8bit ,8二进制位
//		char// char到底是 signed char还是 unsigned char，c语言标准没有定义，取决于编译器的实现
//		unsigned char  0~ 255
//		signed char  -128 ~ 127
// short//2字节，16 bit  16二进制位 
//		unsigned short [int]
//		signed short [int]
// int
//		unsigned int
//		signed int //平常写的int a=0;其实就是 signed int a=0;
// long
//		unsigned long [int]
//		signed long [int] // 其实就是 long 
// long long
//		unsigned long long [int]
//		signed long long [int]//其实就是 long long
//整型家族的范围在limits.h头文件里面定义

//浮点型家族
// float 精度低，存储数据的范围小
// double 精度高，存储数据的范围大
// 浮点型家族的取值范围在float.h头文件里面定义

// 构造类型（自定义类型）
// 数组类型 //例如：int arr1[5] 的类型是 int [5],int arr2[10]的类型是int [10]
// 结构体类型 struct
// 枚举类型 enum
// 联合类型 union 

//指针类型
//int* pi
//char* pc
//float* pf
//void* pv

// 空类型
// void 表示空类型（无类型）
// 通常应用于函数的返回值类型、函数的参数、指针的类型

// 整数的二进制有三种表示形式：源码、反码、补码
// 正数的源码、反码、补码相同，直接按照二进制写出来
// 负数的源码、反码、补码需要计算得到
// 对于整数，数据在内存中存储的形式是补码的二进制序列
// 二进制的第一位是符号位，0表示正数，1表示负数
// 负数：
//源码：一个数字通过正负，按照二进制形式直接写出来
//反码：符号位不变，源码的其他位按位取反
//补码：反码加一
//int a = 20;
// 00000000000000000000000000010100 源码、反码、补码
// 16 进制：0x00000014
//int b = -10;
// 10000000000000000000000000001010  源码，首位是1 ，是符号位，表示负数
// 0x8000000a
// 11111111111111111111111111110101  反码，符号位不变，其他位按位取反
// 0xfffffff5
// 11111111111111111111111111110110  补码，反码加一
// 0xfffffff6
// 补码符号位不变，其他位按位取反再加1可以得到源码，
// 源码符号位不变，其他位按位取反再加1可以得到补码
//二进制转化位16进制，就是每四位二进制数字写成一位16进制数字，16进制以0x开头
//一个字节是8bit，即8个二进制位

//  0x 11223344
//   高位  低位字节序列
// 举例：地址    低地址  --->   高地址
// 大端存储：0x  11223344
// 小端存储：0x  44332211
// 大端还是小端存储取决于是硬件
// 大端字节序存储：把一个数据的高位字节序的内容存放在低地址处，低位字节序的内容存放在高地址处 //简记：相同
// 小端字节序存储：高位存放在高地址处，低位存放在低地址处									 //简记： 相反
//
//int main()
//{
//	//写一个程序自动判断当前存储是大端还是小端模式
//	int a = 1;
//	//00000000000000000000000000000001
//	//0x 00 00 00 01
//	// 大端存储： 0x 00 00 00 01 //4个字节
//	// 小端存储： 0x 01 00 00 00
//	if (*((char*)&a) == 1)//取出第一个字节的地址的10进制值
//	{
//		printf("小端模式");
//	}
//	else
//	{
//		// ==0
//		printf("大端模式");
//	}
//
//	return 0;
//}

//对于无符号数，最高位不再是符号位，最高位也是有效位
//对于有符号数字，整型提升时高位补符号位；对于无符号数，整型提升时，高位补0。
//截断：截取低位
//补：补高位

// %d用于打印有符号整数
// %u用于打印无符号整数、
// 两个数相加就是两个数内存里存储的补码相加

//strlen() 函数的返回值是 size_t,即unsigned int类型
// assert() 函数，断言……,如果括号内的表达式为假，那么就报错
// 例如:assert(a>0),表示，断言：a>0;a如果不大于0，那么就报错
//assert() 函数需要头文件：<assert.h>
//有符号数与无符号数进行计算时，会把有符号数转化为无符号数再进行计算
//无符号数级别更高
//#include <windows.h>
//int main()
//{
//	printf("111\n");
//	Sleep(1000);//休眠1000ms 即1s
//	printf("111\n");
//	return 0;
//	//size_t;
//}


//浮点数在内存中的存储
//常见的浮点数：
// 3.14159
// 1E10  //1.0*10的 10次方
//浮点数家族包括：
//			float
//			double
//			long double

// 对于任意一个浮点数V,都可以写成以下形式： V =(-1)^S*M*2^E
// 其中，S=1,表示负数；S=0表示正数；
// 例如： V=5.0f
// 表示： 5  ->   101
//		  0.0 ->   0//0*2^(-1)
//  即  101.0 ,即  1.01*2^2, 
// 也就是说：S=0 ;  M=1.01 ; E=2
//即表示为： (-1)^0*1.01*2^2   
// 例如：V=9.5f 
// 9  ->  1001
//0.5 ->  1*(2)^-1
//即 1001.1   ，即 1.0011*2^3
// 即 S=0 ,M=1.0011, E=3
// 即表示为： (-1)^0*1.0011*2^3

// 0.75 -->   1 * 2 ^ (-1) + 1 * 2^ (-2)
//以此类推
//所以，浮点数在内存中存储时，可能会无法准确存储，会丢失精度

//对于 float 4字节  32bit 
//最高位给S，接下来的8位给E,剩下的23位给M
//对于 double  8字节  64bit
//最高位给S,接下来的11位给E,剩下的52位给M

// 小数点前面的数字是：…… 2^3  2^2  2^1 2^0
// 小数点后面的数字是：2^(-1)  2^(-2)  2^(-3) ……

//这样存储，仅仅需要保存 S M E 三个数字即可保存浮点数

// 1<=M<2,也就是说，M可以写成1.xxxx 的形式，其中xxxx表示小数部分
// IEEE 754规定：在计算机内部保存M时，默认这个数的第一位总是1，因此可以被舍去，只保存后面的xxxx部分
// 例如在保存 1.01时，只保存01,等到读取的时候，再把第一位的1加上去，这样做的目的，是节省了一位有效数字
// 以32为的浮点数为例子，留给Md的只有23位
//将第一位的1舍去后，等于可以保存24位有效数字

//对于指数E
// 首先，E是一个无符号整数 unsigned int 类型
// 这意味着，如果E是8位，他的取值范围是0~255；如果E是11位，他的取值是0~2047,但是我们知道，
// 科学计数法中的E是可以出现负数的
// 所以 IEEE 754 规定，存入内存时E的真实数据必须再加上一个中间数，对于8位的E,这个中间数是127
// 对于 11 位的E,这个中间数是1023
// 比如，2^10的E是10，所以保存成32位浮点数时，必须保存为 10+127，即137，即10001001
// float -> E(真实值) +127(中间值) ->  存储
// double ->E(真实值) +1023(中间值) -> 存储

// 举例：
// float f=5.5;
// 对于5.5  ->   101.1  ->   1.011*2^2
// S=0  , E=2 所以存 2+127即129  , M=1.011
// 按照 SME存储:
// 0   10000001  01100000000000000000000
// S    E+127     M小数点后面的011，小数点前面的1省略，剩余位在后面补0
//int main()
//
//{
//	float f = 5.5;
//
//	return 0;
//}




