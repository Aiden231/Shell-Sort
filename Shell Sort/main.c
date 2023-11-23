#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 20

inc_insertion_sort(int list[], int first, int last, int gap,int* move_count,int* compare_count) {
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		(*move_count)++;

		for (j = i - gap; j >= first && key < list[j]; j = j - gap) {
			list[j + gap] = list[j];
			(*compare_count)++;
		}
		list[j + gap] = key;
	}
}
// shell ����
void shell_sort(int list[], int n, int* move_count, int* compare_count, int print) {
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0)gap++;
		for (i = 0; i < gap; i++) {
			inc_insertion_sort(list, i, n - 1, gap, move_count, compare_count);
		}

		// print�� 1�� ��쿡�� ���� ���
		if (print == 1) {
			for (int i = 0; i < MAX_SIZE; i++) {
				printf("%d ", list[i]);
			}
			printf("\n");
		}
	}
}

int main()
{
	// ����Ʈ ����
	int n = MAX_SIZE;
	int list[MAX_SIZE] = { 0 };
	int move[MAX_SIZE] = { 0 };
	int compare[MAX_SIZE] = { 0 };
	// �̵�,�� Ƚ�� ����
	int move_count = 0;
	int compare_count = 0;
	// ��� �� ����� ���� ����
	int sum = 0;
	int move_average = 0;
	int compare_average = 0;
	// ���� ����Ʈ ����
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		list[i] = rand() % 100;
	}

	printf("Original List\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n\n");

	// shell ���� ����
	printf("Shell sort\n");
	shell_sort(list, n, &move_count, &compare_count, 1);
	
	// �̵�, �� Ƚ�� ����
	move[0] = move_count;
	compare[0] = compare_count;

	// �ݺ� ����
	for (int i = 1; i < MAX_SIZE; i++) {
		// ���� �ʱ�ȭ
		move_count = 0;
		compare_count = 0;
		// ����Ʈ ������ ä���
		for (int i = 0; i < n; i++) {
			list[i] = rand() % 100;
		}
		// shell ���� ����
		shell_sort(list, n, &move_count, &compare_count, 0);
		// �̵�, �� Ƚ�� �迭�� ����
		move[i] = move_count;
		compare[i] = compare_count;
	}
	
	// �̵� Ƚ�� ��� ���ϱ�
	for (int i = 0; i < MAX_SIZE; i++) {
		sum += move[i];
	}
	move_average = sum / 20;

	sum = 0; // sum �� �ʱ�ȭ

	// �� Ƚ�� ��� ���ϱ�
	for (int i = 0; i < MAX_SIZE; i++) {
		sum += compare[i];
	}
	compare_average = sum / 20;

	// ��� �̵�, �� Ƚ�� ����ϱ�
	printf("Average move : %d\nAverage compare : %d\n", move_average,compare_average);
}