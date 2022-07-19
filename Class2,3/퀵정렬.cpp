#include <stdio.h>

int number = 10;
int array[] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

void show() {
	for (int i = 0; i < number; i++)
		printf("%d ", array[i]);
}

void QuickSort(int* array, int start, int end) {
	if (start >= end)
		return;

	int pivot = start;
	int i = start + 1, j = end, temp;

	while (i <= j) {
			while (i <= end && (array[i] <= array[pivot])) { // �Ǻ����� ū ���� ã�� ������
			i++;
		}
		while (j > start && (array[j] >= array[pivot])) { // �Ǻ����� ���� ���� ã�� ������
			j--;
		}

		if (i > j) {
			temp = array[j];
			array[j] = array[pivot];
			array[pivot] = temp;
		}
		else {
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	QuickSort(array, start, j - 1);
	QuickSort(array, j + 1, end);
}

int main() {
	QuickSort(array, 0, number - 1);
	show();

	return 0;
}
