#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//第一题
//int main()
//{
//	int a = 0; int b = 0; int c = 0; int d = 0;
//	for (a = 1; a < 10; a++)
//	{
//		for (b = 0; b < 10; b++)
//		{
//			for (c = 0; c < 10; c++)
//			{
//				for (d = 0; d < 10; d++)
//				{
//					if (a != b && a != c && a != d && b != c && b != d && c != d)
//					{
//						if ((1000 * a + 100 * a + 10 * a + a + 100 * b + 10 * b + b + 10 * c + c + d) < 10000)
//						{
//							printf("%d A=%d B=%d C=%d D=%d\n", 1000 * a + 100 * a + 10 * a + a + 100 * b + 10 * b + b + 10 * c + c + d,
//								a, b, c, d);
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//
//}
//第二题
//#include<string.h>
//#include<assert.h>
//void func(char* in, char* out)
//{
//	int sz = strlen(in);
//	assert(sz < 2048);
//	char* x = in + 1;
//	char* y = out;
//	while ((*x) != 0&&x<in+sz)
//	{
//		if ((*x) % 2 == 0)
//		{
//			*y = *x;
//			y++;
//		}
//		x += 2;
//	}
//}
//int main()
//{
//	char in[2048] = {0};
//	char out[2048] = { 0 };
//	printf("请输入需要处理的字符串:");
//	scanf("%[^\n]", in);
//	func(in, out);
//	printf("处理后的字符串为:%s", out);
//}
//第三题
//#include <math.h>
//int main()
//{
//	double t = 0.0;
//	double out = 0;
//	FILE* p = fopen("curve.txt", "w");
//	for (t = 0.0; t < 0.2; t = t + 0.001)
//	{
//		out = (3.0 + 150.0 * t) * exp(-50.0 * t);
//		fprintf(p, "t为:%.3lf,输出为:%.3lf", t, out);
//		fputc('\n', p);
// fclose(p);
// p=NULL;
//	}
//}
//最后一题
#include <stdlib.h>
#include <string.h>
typedef struct Stu 
{
	char name[20];
	char id[10];
	size_t s1;
	size_t s2;
	size_t total;
}Stu;
struct StuInfo
{
	Stu* arr;
}stus;
int main()
{
	FILE* p1 = fopen("name.txt", "r");
	FILE* p2 = fopen("s1.txt", "r");
	FILE* p3 = fopen("s2.txt", "r");
	int num = 0;
	fscanf(p1,"%d\n", &num);
	Stu*ret = (Stu*)realloc(NULL,(size_t)num * sizeof(Stu));
	if (ret == NULL)
	{
		perror("开辟失败:");
		return 1;
	}
	stus.arr = ret;

	Stu* p1x = stus.arr; Stu* p2x = stus.arr; Stu* p3x = stus.arr; Stu* p4x = stus.arr;
	//读name的数据
	while (fscanf(p1, "%s %s\n", p1x->name, p1x->id)==2)
	{
		p1x++;
	}
	//读s1的数据
	Stu teststu;
	while (fscanf(p2, "%s %u\n", teststu.id, &(teststu.s1)) == 2)
	{
		for (p2x; p2x < stus.arr + num; p2x++)
		{
			if (strcmp(p2x->id,teststu.id)==0)
			{
				p2x->s1 = teststu.s1;
			}
		}
		p2x = stus.arr;
	}
	//读s2的数据
	while (fscanf(p3, "%s %u\n", teststu.id,&(teststu.s2)) == 2)
	{
		for (p3x; p3x < stus.arr + num; p3x++)
		{
			if (strcmp(p3x->id,teststu.id)==0)
			{
				p3x->s2 = teststu.s2;
			}
		}
		p3x = stus.arr;
	}
	//总步数
	for (p4x; p4x < stus.arr + num; p4x++)
	{
		p4x->total = p4x->s1 + p4x->s2;
	}
	//排序
	Stu tmp;
	Stu* p5x = stus.arr;
	int i = 0;
	for (i = 0; i < num - 1; i++)
	{
		for (p5x; p5x < stus.arr + num - i - 1; p5x++)
		{
			if (p5x->total < (p5x + 1)->total)
			{
				tmp= *p5x;
				*p5x = *(p5x + 1);
				*(p5x + 1) = tmp;
			}
			else if (p5x->total == (p5x + 1)->total)
			{
				if (p5x->s2 < (p5x + 1)->s2)
				{
					tmp= *p5x;
					*p5x = *(p5x + 1);
					*(p5x + 1) = tmp;
				}
			}
		}
	}
	//写入board.txt
	FILE* p4 = fopen("board.txt", "w"); Stu* p6x = stus.arr;
	int j = 1;
	fprintf(p4, "%-5s %-8s %-6s %-12s %-12s %-10s\n", "排名", "学号", "姓名", "第一天步数", "第二天步数", "总步数");
	for (j = 1; j <1+num; j++)
	{
		fprintf(p4, "%-5d %-8s %-6s %-12u %-12u %-10u\n", j, p6x->id, p6x->name, p6x->s1, p6x->s2, p6x->total);
		p6x++;
	}
	fclose(p1); fclose(p2); fclose(p3); fclose(p4);
	p1 = NULL; p2 = NULL; p3 = NULL; p4 = NULL;
	free(stus.arr); 
	return 0;
}






