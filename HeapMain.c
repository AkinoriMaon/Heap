// Visual Studio 2019에서 작성된 코드입니다.

#include <stdio.h>
#include <math.h> // log()의 사용을 위해 선언
#include "Heap.h"

int DataPirorityComp(int d1, int d2); // Heap 우선순위 결정

double GetLogData(double data, double base);
int GetHeapHeight(int n);
int IntSquare(int x, int base);

void PrintHeap(Heap* heap, const char* title); // Heap을 index 순으로 선형 출력
void PrintHeapTree(Heap* heap, const char* title); // Heap을 tree 모양으로 출력

int main()
{
	Heap heap;
	int i, sizeItemList = 0;

//	int itemList[] = { 50, 40, 30, 25, 30 };
//	int itemList[] = { 24, 17, 29, 22, 20, 31, 27, 18, 21 }; // 수행평가 10번
	int itemList[] = { 50, 40, 30, 25, 30, 20, 10, 5, 15, 20, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52 }; // 12번 수행평가

	sizeItemList = sizeof(itemList) / sizeof(int);

	HeapInit(&heap, DataPirorityComp);

	for (i = 0; i < sizeItemList; i++)
	{
		HInsert(&heap, itemList[i]);
	}

	// 삽입 후 결과 출력
	PrintHeap(&heap, "삽입 후");
	PrintHeapTree(&heap, "트리의 모양");

	// 중도 삽입
	HInsert(&heap, 45);
	HInsert(&heap, 60);

	// 삽입 후 결과 출력
	PrintHeap(&heap, "데이터 45, 60 삽입 후");
	PrintHeapTree(&heap, "트리의 모양");

	// 트리 하나 삭제
	HDelete(&heap);

	// 삽입 후 결과 출력
	PrintHeap(&heap, "데이터 1개 삭제 후");
	PrintHeapTree(&heap, "트리의 모양");
	

	return 1;
}

int DataPirorityComp(int d1, int d2)
{
	// return d1 - d2; // min heap
	return d2 - d1; // max heap
}

double GetLogData(double data, double base)
{
	return (log(data) / log(base));
}

int GetHeapHeight(int n)
{
	return (int)GetLogData((double)n, 2.0);
}

int IntSquare(int base, int x)
{
	int i, mul = 1;

	for (i = 0; i < x; i++)
	{
		mul *= base;
	}

	return mul;
}

void PrintHeap(Heap* heap, const char* title)
{
	int i;

	puts("================================");
	puts(title);
	puts("================================");

	for (i = 1; i < heap->numOfData; i++) // Heap의 인덱스는 1부터 시작한다.
	{
		printf(" %d ->", heap->Heap[i]);
	}
	printf(" %d \n", heap->Heap[i]);
}

void PrintHeapTree(Heap* heap, const char* title)
{
	int i, j;
	int height = GetHeapHeight(heap->numOfData);
	int idx = 1, numOfLevel = height + 1;

	puts("================================");
	puts(title);
	puts("================================");

	printf("전체 노드 수 : %d 높이 : %d 마지막 레벨의 최대 자식 개수 : %d", heap->numOfData, height, IntSquare(2, height));
	puts("\n\n\n");
	
	for (i = 0; i <= height; i++)
	{
		printf("[Level : %d]", i);

		for (j = 0; j < IntSquare(2, (height - i)); j++)
		{
			fputs("  ", stdout);
		}

		j = 0;

		// 자신의 레벨에서 가질 수 있는 자식 수만큼 돌리고 idx는 힙에 들어있는 정보의 인덱스까지만 돌아야 한다.
		while (j < IntSquare(2, i) && idx <= heap->numOfData)
		{
			printf("%2d", heap->Heap[idx++]);

			if ((j + 1) < IntSquare(2, i)) // 다음에 더 찍을 데이터가 있다면,
			{
				int k;

				for (k = 0; k < IntSquare(2, numOfLevel) - 1; k++)
				{
					fputs("  ", stdout);
				}
			}

			j++;
		}

		numOfLevel--;
		puts("\n\n");
	}
}