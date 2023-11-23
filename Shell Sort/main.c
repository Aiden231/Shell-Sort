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
// shell 정렬
void shell_sort(int list[], int n, int* move_count, int* compare_count, int print) {
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0)gap++;
		for (i = 0; i < gap; i++) {
			inc_insertion_sort(list, i, n - 1, gap, move_count, compare_count);
		}

		// print가 1인 경우에만 과정 출력
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
	// 리스트 생성
	int n = MAX_SIZE;
	int list[MAX_SIZE] = { 0 };
	int move[MAX_SIZE] = { 0 };
	int compare[MAX_SIZE] = { 0 };
	// 이동,비교 횟수 변수
	int move_count = 0;
	int compare_count = 0;
	// 평균 값 계산을 위한 변수
	int sum = 0;
	int move_average = 0;
	int compare_average = 0;
	// 난수 리스트 생성
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		list[i] = rand() % 100;
	}

	printf("Original List\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n\n");

	// shell 정렬 시행
	printf("Shell sort\n");
	shell_sort(list, n, &move_count, &compare_count, 1);
	
	// 이동, 비교 횟수 저장
	move[0] = move_count;
	compare[0] = compare_count;

	// 반복 시행
	for (int i = 1; i < MAX_SIZE; i++) {
		// 변수 초기화
		move_count = 0;
		compare_count = 0;
		// 리스트 난수로 채우기
		for (int i = 0; i < n; i++) {
			list[i] = rand() % 100;
		}
		// shell 정렬 시행
		shell_sort(list, n, &move_count, &compare_count, 0);
		// 이동, 비교 횟수 배열에 저장
		move[i] = move_count;
		compare[i] = compare_count;
	}
	
	// 이동 횟수 평균 구하기
	for (int i = 0; i < MAX_SIZE; i++) {
		sum += move[i];
	}
	move_average = sum / 20;

	sum = 0; // sum 값 초기화

	// 비교 횟수 평균 구하기
	for (int i = 0; i < MAX_SIZE; i++) {
		sum += compare[i];
	}
	compare_average = sum / 20;

	// 평균 이동, 비교 횟수 출력하기
	printf("Average move : %d\nAverage compare : %d\n", move_average,compare_average);
}