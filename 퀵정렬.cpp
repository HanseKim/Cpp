#include <stdio.h>

int number = 10;
int array[] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

void show() {
	for (int i = 0; i < number; i++)
		printf("%d ", array[i]);
}

void QuickSort(int* array, int start, int end) {
	if (start >= end) // 원소가 1개인 경우 그대로 두기
		return;

	int pivot = start; // 피봇은 첫번째 원소
	int i = start + 1, j = end, temp;

	while (i <= j) { // 엇갈릴 때까지 반복
		while (i <= end && (array[i] <= array[pivot])) { // 피봇보다 큰 값을 찾을 때까지
			i++;
		}
		while (j > start && (array[j] >= array[pivot])) { // 피봇보다 작은 값을 찾을 때까지
			j--;
		}

		if (i > j) { // 엇갈린 상태. 피봇보다 작은 값과 피봇과 교체
			temp = array[j];
			array[j] = array[pivot];
			array[pivot] = temp;
		}
		else { // 엇갈리지 않았다면 i와 j를 교체
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
