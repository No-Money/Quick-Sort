#include <stdio.h>
#define MAX_E 15 // �迭 �� MAX_ELEMENT

int left = 0, right = MAX_E - 1;
void quick_sort(int arr[], int left, int right);

int main(void)
{
	int arr[MAX_E] = { 2, 301, 201, 105, 101, 91, 88 ,60, 15, 31, 12, 26, 82, 51, 6 };

	// ���� �� ������ ���
	printf("������ ������: ");
	for (int i = 0; i < MAX_E; i++)
		printf("%d ", arr[i]);
	printf("\n\n");

	// quick_sort ����(�������� ����)
	quick_sort(arr, left, right);

	// ���� �� ������ ���
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
			// i, j cross �� SWAP
			if (i < j) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		} while (i < j);

		// i, j cross �� SWAP
		temp = arr[left];
		arr[left] = arr[j];
		arr[j] = temp;

		// ����, ���� quick sort
		quick_sort(arr, left, j - 1);
		quick_sort(arr, j + 1, right);
	}
}