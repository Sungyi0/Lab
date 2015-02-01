#pragma once

/* 0.2 두 변수의 값 바꾸기 */
// Q. 포인터를 이용하여 값을 바꾸는 함수
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// Q. 배열의 두 원소 바꾸기
void swap_arr(int arr[], int i, int j)
{
	int temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
