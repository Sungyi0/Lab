/* 0.1 최대와 최소 */
// Q. 최대 값과 최소 값을 구하는 함수
int min(int x, int y)
{
	if (x < y)
		return x;

	return y;
}

int max(int x, int y)
{
	if (x > y)
		return x;

	return y;
}

// Q. 배열의 최대 값을 구하는 함수
int max_arr(int arr[], int arr_len)
{
	int maxa, i;

	maxa = arr[0];
	for (i = 1; i < arr_len; ++i)
		if (arr[i] > maxa)
			maxa = arr[i];

	return maxa;
}
