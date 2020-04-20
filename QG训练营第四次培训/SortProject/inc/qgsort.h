
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

struct Node{
	long begin;
	long end;
	struct Node *next;
};

/**
 *  @name        : int str_to_int(char *str);
 *  @description : str型转化为int型
 *  @param       : 转化对象 str
 */
int str_to_int(char *str);


/**
 *  @name        : char *int_to_str(int num, int judge);
 *  @description : int型转化为str型
 *  @param       : 转化对象 num，判断对象 judge
 */
char *int_to_str(int num, int judge);


/**
 *  @name        : void creat_big_data(long num);
 *  @description : 生成大数据
 *  @param       : 生成数量 num
 */
void creat_big_data(long num);


/**
 *  @name        : int *load_big_data(long num);
 *  @description : 加载大数据
 *  @param       : 数组长度 size
 */
int *load_big_data(long size);


/**
 *  @name        : int **load_100X100k();
 *  @description : 加载100k个小数据
 *  @param       : void
 */
int **load_100X100k();


/**
 *  @name        : void free_100X100k(int **a);
 *  @description : 释放100k个小数据占用的内存
 *  @param       : 二级int型指针 a
 */
void free_100X100k(int **a);


/**
 *  @name        : void insertSort(int *a,long n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,long n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp);


/**
 *  @name        : void MergeSort(int *a,long begin,long end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,long begin,long end,int *temp);


/**
 *  @name        : void QuickSort(int *a, long begin, long end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, long begin, long end);


/**
 *  @name        : void QuickSort(int *a,long size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,long size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, long size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, long size , int max);


/**
 *  @name        : void RadixCountSort(int *a,long size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,long size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size);


/**
 *  @name        : int Find_K(int *a, int size, int k);
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size，要找的位置k
 */
int Find_K(int *a, int size, int k);

#endif // QUEUE_H_INCLUDED
