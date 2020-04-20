#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

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

int main(){
	FILE *fp = fopen("../src/100X100k.dat", "w");
	char *str;
	srand((unsigned int)time(NULL));
	for (long i=0; i<100000; i++){
		str = int_to_str(rand(), 0);
		fputs(str, fp);
		free(str);
		for (int j=1; j<100; j++){
			str = int_to_str(rand(), 0);
			fputs(" ", fp);
			fputs(str, fp);
			free(str);
		}
		fputs("\n", fp);
	}
	fclose(fp);
	creat_big_data(10000);
	creat_big_data(50000);
	creat_big_data(200000);
	printf("\n\t测试数据生成成功！");
	system("pause");
}
