#include <stdlib.h>

/* 0.3 배열 회전 */
// Q. right_rotate() 함수 작성하기
void right_rotate(int arr[], int s, int t)
{
	int i, last;

	last = arr[t];
	for (i = t; i > s; --i)
		arr[i] = arr[i - 1];
	arr[s] = last;
}

// Q. left_rotate() 함수 작성하기
void left_rotate(int arr[], int s, int t)
{
	int i, start;

	start = arr[s];
	for (i = s; i < t; ++i)
		arr[i] = arr[i + 1];
	arr[t] = start;
}
/* 생각해보기
	Q. k를 인자로 받아서 k만큼 오른쪽으로 회전시키는 함수를 작성하라. 
	k만큼 오른쪽으로 회전하는 것은 1만큼 오른쪽으로 회전하는 것을 
	k번 반복하면 되지만 이 방법은 느리다. 더 빠르게 결과를 얻도록 작성해보자. */
void right_rotate_k(int arr[], int s, int t, int k)
{
	int i;
	int size = t - s + 1;
	int realK = k % size;		// 불필요한 이동은 없앤다.
	int *arTemp = (int*)malloc(sizeof(int) * realK);

	// 옮길 필요가 없으면 그냥 끝냅니다.
	if (realK == 0)
		return;

	// arr의 뒤부터 realK만큼 백업합니다.
	for (i = 0; i < realK; ++i)
		arTemp[i] = arr[(size - realK) + i];

	for (i = t - realK; i >= s; --i)
		arr[i + realK] = arr[i];
	for (i = s; i < s + realK; ++i)
		arr[i] = arTemp[i - s];

	free(arTemp);
}