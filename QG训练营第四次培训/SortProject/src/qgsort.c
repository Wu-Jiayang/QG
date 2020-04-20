#include "../inc/qgsort.h"

char *int_to_str(int num, int judge){
	char *str;
	int n = num, i = 0;
	if (!num) if (judge) return "0\n";
	else return "0";
	while (n){
		n /= 10;
		i++;
	}
	if (judge){
		str = (char*)malloc((i+2)*sizeof(char));
		str[i+1] = '\0';
		str[i] = '\n';
	}
	else{
		str = (char*)malloc((i+1)*sizeof(char));
		str[i] = '\0';
	}
	while (i--){
		str[i] = num % 10 +'0';
		num /= 10;
	}
	return str;
}

void creat_big_data(long num){
	FILE *fp;
	char *str, path[32] = "../src/";
	str = int_to_str(num/10, 0);
	strcat(path, str);
	strcat(path, "0.dat");
	fp = fopen(path, "w");
	free(str);
	if (!fp){
		printf("Error!");
		system("pause");
		exit(0);
	}
	for (long i=0; i<num; i++){
		str = int_to_str(rand(), 1);
		fputs(str, fp);
		free(str);
	}
	fclose(fp);
}

int str_to_int(char *str){
	int num = 0;
	for (; *str; str++) num = num * 10 + *str - '0';
	return num;
}

int *load_big_data(long size){
	FILE *fp;
	char *str, path[32] = "src/";
	int *a = (int*)malloc(size*sizeof(int));
	str = int_to_str(size/10, 0);
	strcat(path, str);
	strcat(path, "0.dat");
	fp = fopen(path, "r");
	free(str);
	if (!fp){
		printf("Error!");
		system("pause");
		exit(0);
	}
	for (long i=0; i<size; i++) fscanf(fp, "%d", &a[i]);
	fclose(fp);
	return a;
}

int **load_100X100k(){
	FILE *fp = fopen("src/100X100k.dat", "r");
	int **a = (int**)malloc(100000*sizeof(int*));
	if (!fp){
		printf("Error!");
		system("pause");
		exit(0);
	}
	for (long i=0; i<100000; i++){
		a[i] = (int*)malloc(100*sizeof(int));
		for (int j=0; j<100; j++) fscanf(fp, "%d", &a[i][j]);
	}
	fclose(fp);
	return a;
}

void free_100X100k(int **a){
	for (long i=0; i<100000; i++) free(a[i]);
	free(a);
}

void insertSort(int *a,long n){
	int temp;
	long i = 1, j;
	for (; i<n; i++){
		temp = a[i];
		for (j=i-1; j>=0 && a[j]>temp; j--) a[j+1] = a[j];
		a[j+1] = temp;
	}
}

void MergeSort(int *a,long begin,long end,int *temp){
	int *arr1, *arr2;
	long i = 0, i1 = 0, i2 = 0;
	if (end == 1) return;
	if (end % 2) begin = end / 2 + 1;
	else begin = end / 2;
	arr1 = (int*)malloc(begin*sizeof(int));
	arr2 = (int*)malloc((end-begin)*sizeof(int));
	for (; i<begin; i++) arr1[i] = a[i];
	for (; i<end; i++) arr2[i-begin] = a[i];
	MergeSort(arr1, 0, begin, NULL);
	MergeSort(arr2, 0, end-begin, NULL);
	for (i=0; i<end; i++) if (i1 == begin) a[i] = arr2[i2++];
		else if (i2 == end - begin) a[i] = arr1[i1++];
		else if (arr1[i1] > arr2[i2]) a[i] = arr2[i2++];
		else a[i] = arr1[i1++];
	free(arr1);
	free(arr2);
}

void QuickSort_Recursion(int *a, long begin, long end){
	long i1 = begin, i2 = end, temp;
	while (i1 != i2){
		while (i1 != i2 && a[i2] >= a[begin]) i2--;
		while (i1 != i2 && a[i1] <= a[begin]) i1++;
		if (i1 == i2) break;
		else{
			temp = a[i1];
			a[i1] = a[i2];
			a[i2] = temp;
		}
	}
	temp = a[begin];
	a[begin] = a[i1];
	a[i1] = temp;
	if (i1-1 > begin) QuickSort_Recursion(a, begin, i1-1);
	if (i1+1 < end) QuickSort_Recursion(a, i1+1, end);
}

void QuickSort(int *a,long size){
	struct Node *head = (struct Node*)malloc(sizeof(struct Node)), *end = head, *p;
	long i1, i2, temp;
	head->begin = 0;
	head->end = size-1;
	head->next = NULL;
	for (; head; head=p){
		i1 = head->begin;
		i2 = head->end;
		while (i1 != i2){
			while (i1 != i2 && a[i2] >= a[head->begin]) i2--;
			while (i1 != i2 && a[i1] <= a[head->begin]) i1++;
			if (i1 == i2) break;
			else{
				temp = a[i1];
				a[i1] = a[i2];
				a[i2] = temp;
			}
		}
		temp = a[head->begin];
		a[head->begin] = a[i1];
		a[i1] = temp;
		if (i1-1 > head->begin){
			end = end->next = (struct Node*)malloc(sizeof(struct Node));
			end->begin = head->begin;
			end->end = i1 - 1;
			end->next = NULL;
		}
		if (i1+1 < head->end){
			end = end->next = (struct Node*)malloc(sizeof(struct Node));
			end->begin = i1 + 1;
			end->end = head->end;
			end->next = NULL;
		}
		p = head->next;
		free(head);
	}
}

void CountSort(int *a, long size , int max){
	long *arr = (long*)malloc(max*sizeof(long));
	int *arr2 = (int*)malloc(size*sizeof(int));
	for (int i=0; i<max; i++) arr[i] = 0;
	for (long i=0; i<size; i++){
		arr[a[i]]++;
		arr2[i] = a[i];
	}
	for (int i=1; i<max; i++) arr[i] += arr[i-1];
	for (; size; size--) a[--arr[arr2[size-1]]] = arr2[size-1];
	free(arr);
	free(arr2);
}

void RadixCountSort(int *a,long size){
	long *arr = (long*)malloc(10*sizeof(long));
	int *arr2 = (int*)malloc(size*sizeof(int)), radix = 1;
	for (int radix=1; radix<=10000; radix*=10){
		for (int i=0; i<10; i++) arr[i] = 0;
		for (long i=0; i<size; i++){
			arr[a[i] % (radix * 10) / radix]++;
			arr2[i] = a[i];
		}
		for (int i=1; i<10; i++) arr[i] += arr[i-1];
		for (long i=size; i; i--) a[--arr[arr2[i-1] % (radix * 10) / radix]] = arr2[i-1];
	}
	free(arr);
	free(arr2);
}

void ColorSort(int *a,int size){
	int temp, begin = 0, end = size-1, p = 0;
        while (p != end){
		if (a[p] == 1 || p < begin) p++;
		else if (a[p]){
			temp = a[p];
			a[p] = a[end];
			a[end--] = temp;
		}
		else {
			temp = a[p];
			a[p] = a[begin];
			a[begin++] = temp;
		}
        }
}

int Find_K(int *a, int size, int k){
	struct Node *head = (struct Node*)malloc(sizeof(struct Node)), *end = head, *p;
	int i1, i2, temp;
	head->begin = 0;
	head->end = size-1;
	head->next = NULL;
	for (; head; head=p){
		i1 = head->begin;
		i2 = head->end;
		while (i1 != i2){
			while (i1 != i2 && a[i2] >= a[head->begin]) i2--;
			while (i1 != i2 && a[i1] <= a[head->begin]) i1++;
			if (i1 == i2) break;
			else{
				temp = a[i1];
				a[i1] = a[i2];
				a[i2] = temp;
			}
		}
		temp = a[head->begin];
		a[head->begin] = a[i1];
		a[i1] = temp;
		if (i1 == k-1){
			free(head);
			return a[i1];
		}
		if (i1-1 > head->begin && i1 > k-1){
			end = end->next = (struct Node*)malloc(sizeof(struct Node));
			end->begin = head->begin;
			end->end = i1 - 1;
			end->next = NULL;
		}
		else if (i1+1 < head->end){
			end = end->next = (struct Node*)malloc(sizeof(struct Node));
			end->begin = i1 + 1;
			end->end = head->end;
			end->next = NULL;
		}
		p = head->next;
		free(head);
	}
}
