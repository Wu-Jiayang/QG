
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
 *  @description : str��ת��Ϊint��
 *  @param       : ת������ str
 */
int str_to_int(char *str);


/**
 *  @name        : char *int_to_str(int num, int judge);
 *  @description : int��ת��Ϊstr��
 *  @param       : ת������ num���ж϶��� judge
 */
char *int_to_str(int num, int judge);


/**
 *  @name        : void creat_big_data(long num);
 *  @description : ���ɴ�����
 *  @param       : �������� num
 */
void creat_big_data(long num);


/**
 *  @name        : int *load_big_data(long num);
 *  @description : ���ش�����
 *  @param       : ���鳤�� size
 */
int *load_big_data(long size);


/**
 *  @name        : int **load_100X100k();
 *  @description : ����100k��С����
 *  @param       : void
 */
int **load_100X100k();


/**
 *  @name        : void free_100X100k(int **a);
 *  @description : �ͷ�100k��С����ռ�õ��ڴ�
 *  @param       : ����int��ָ�� a
 */
void free_100X100k(int **a);


/**
 *  @name        : void insertSort(int *a,long n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,long n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp);


/**
 *  @name        : void MergeSort(int *a,long begin,long end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,long begin,long end,int *temp);


/**
 *  @name        : void QuickSort(int *a, long begin, long end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, long begin, long end);


/**
 *  @name        : void QuickSort(int *a,long size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,long size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, long size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, long size , int max);


/**
 *  @name        : void RadixCountSort(int *a,long size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,long size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size);


/**
 *  @name        : int Find_K(int *a, int size, int k);
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size��Ҫ�ҵ�λ��k
 */
int Find_K(int *a, int size, int k);

#endif // QUEUE_H_INCLUDED
