#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
A.主要内容：指针
**指针是什么、指针和指针类型、野指针、指针运算、指针和数组、二级指针和指针数组
一.指针是什么
在计算机科学中，指针( Pointer )是编程语言中的一个对象，利用地址，它的值直接指向( points to )存在电脑存储器中另一个地方的值。
由于通过地址能找到所需的变量单元，可以说，地址指向该变量单元。因此，将地址形象化的称为“指针"。
意思是通过它能找到以它为地址的内存单元。
总结：指针是用来存放地址的，地址是唯一标示一块地址空间的。
指针的大小在32位平台是4个字节，在64位平台是8个字节。
//
//
二.指针和指针类型
i）指针类型决定了:指针解引用的权限有多大
int main()
{
	int a = 0x11223344;
	int* pa = &a;
	*pa = 0;

	
	int a = 0x11223344;
	char* pc = &a;
	*pc = 0;
	
	return 0;
}
ii）指针类型决定了，指针走一步，能走多远(步长)
int main()
{
	int arr[10] = {0};
	int *p = arr;
	char *pc = arr;
	printf("%p\n",p);
	printf("%p\n",p+1);          /*加了4*/
	
	printf("%p\n",pc);
	printf("%p\n",pc+1);         /*加了1*/
}
//
//
三.野指针
概念︰野指针就是指针指向的位置是不可知的（随机的、不正确的、没有明确限制的)
成因：
i)指针未初始化
int main()
{
	int *p;                     /*p是一个局部的指针变量，局部变量不初始化的话，默认是随机值*/
	*p=20;                      /*非法访问内存了*/
	return 0;
}
ii)指针越界访问
int main()
{
	int arr[10] = {0};
	int *p = arr;
	int i = 0;
	for(i = 0;i <= 10; i++)
	{
		*p = i;
		p++;                //当指针指向的范围超出数组arr的范围时，p就是野指针
	}
	return 0;
}
iii)指针指向的空间释放
int* test()
{
	int a = 10;
	return &a;
}
int main()
{
	int*p = test():
	*p = 20;
	return 0;
}
如何规避野指针
1.指针初始化                   /*当不知道p应该初始化为什么地址的时候，直接初始化NULL(int *p=NULL;)*/
2.小心指针越界                 /*C语言本身是不会检查数据的越界行为的*/
3.指针指向空间释放即使置NULL    /*当空间被释放时，也置成空指针*/
4.指针使用之前检查有效性        /*当指向有效空间时，给有效的地址*/
if(p!=NULL)
  *p = 10;
//
//
四.指针运算（指针+-整数、指针-指针、指针的关系运算）
i).指针+-整数
int main()
{
	int arr[10]={0};
	int i = 0;
	int sz = sizeof(arr)/sizeof(arr[0]);

1.//	for(i=0;i<sZ;i++)
//	{
//		arr[i] = 1;
//	}

2.//	int *p =arr;
//	for(i=0;i<sz:i++)
//	{
//		*p=1;
//		p++;
//	}

	int *p = arr;
	for(i=0;i<sz;i++)
	{
		*(p+i) = 1;
	}
	return 0;
}
ii)指针-指针
绝对值得到的是两个指针之间的元素个数
不是所有的指针都能相减：指向同一块空间的两个指针才能相减
指针+指针？地址+地址？莫法
int main()
{
	int arr[10] = {0};
	printf("%d",&arr[9] - &arr[0]);             /*结果为9*/
	return 0;
}
应用： 
int my_strlen(char *str)
{
	char *start = str;
	while(*str != '\0')
	{
		str++;
	}
	return(str-start);
}
int main()
{
	int len = my_strlen("abcdef");   /*a b c d e f \0*/
	printf("%d\n",len);              /*结果为6*/
	return 0;
}
iii)指针的关系运算（比较大小）
允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较，但是不允许与指向第一个元素之前的那个内存位置的指针进行比较,
