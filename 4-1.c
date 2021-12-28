#include <stdio.h>
#define MAX_E 15 // 배열 내 MAX_ELEMENT

int left = 0, right = MAX_E - 1;
void quick_sort(int arr[], int left, int right);

int main(void)
{
	int arr[MAX_E] = { 2, 301, 201, 105, 101, 91, 88 ,60, 15, 31, 12, 26, 82, 51, 6 };

	// 정렬 전 데이터 출력
	printf("정렬할 데이터: ");
	for (int i = 0; i < MAX_E; i++)
		printf("%d ", arr[i]);
	printf("\n\n");

	// quick_sort 진행(오름차순 정렬)
	quick_sort(arr, left, right);

	// 정렬 후 데이터 출력
	printf("Quick Sort: ");
	for (int i = 0; i < MAX_E; i++)
		printf("%d ", arr[i]);
	printf("\n\n");

	return 0;
}

void quick_sort(int arr[], int left, int right)
{
	int pivot, i, j, temp;

	if (left < right) {
		i = left; j = right + 1;
		pivot = arr[left];

		do {
			do i++; while (arr[i] < pivot);
			do j--; while (arr[j] > pivot);
			// i, j cross 전 SWAP
			if (i < j) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		} while (i < j);

		// i, j cross 후 SWAP
		temp = arr[left];
		arr[left] = arr[j];
		arr[j] = temp;

		// 좌측, 우측 quick sort
		quick_sort(arr, left, j - 1);
		quick_sort(arr, j + 1, right);
	}
}