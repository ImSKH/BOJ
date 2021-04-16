#include<stdio.h>

int main()
{
	int count = 0;
	int arr[42]={0,};
	int array[10];
	int result[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &array[i]);
		result[i] = array[i] % 42;
		arr[result[i]] = 1;
	}
	for (int i = 0; i < 42; i++){
		if (arr[i] == 1)
			count++;}
	printf("%d ", count);
}
