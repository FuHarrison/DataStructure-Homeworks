// /*
//  * multiple inputs in C
//  * Author: zhiying
//  * Date: 2020.3.24 18:10
//  * URL: https://blog.csdn.net/zhouzying/article/details/105076417
//  * Homepage: www.zhouzying.cn
//  */

// #include <stdio.h>
// #include <stdlib.h>

// void input(int *a,int *len);
// void print_value(int *a,int len);

// int main(){

// 	int *nums = (int*)malloc(sizeof(int)*2000);
// 	int len=0;
	
//     if (nums == NULL){
	
// 		printf("memery error\n");
// 	}else{
	
// 		input(nums,&len);
// 	}

// 	print_value(nums,len);
// 	free(nums);
// 	return 0;
// }

// void input(int *a,int *len){

// 	int cnt=0;
//     int n=1;
//     char ch;

// 	do{
// 		scanf("%d%c",a,&ch);
// 		a++;
// 		cnt++;
// 	}while((int)ch != 10); //  The last character is line feed whose ascii value is 10

// 	*len = cnt;
// }

// /* show inputs */
// void print_value(int *a,int len){

// 	int j;
	
// 	for (j=0;j<len;j++,a++){
	
// 		printf("%d\n",*a);
// 	}
// }


////////////////////////////

#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[5];
    for(int i=0;i!=5;i++)
      scanf("%d", &arr[i]);
    for(int i=0;i!=5;i++)
      printf("%d ", arr[i]);
}