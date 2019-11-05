// Visual Studio 2019���� �ۼ��� �ڵ��Դϴ�.

#include <stdio.h>
#include <math.h> // log()�� ����� ���� ����
#include "Heap.h"

int DataPirorityComp(int d1, int d2); // Heap �켱���� ����

double GetLogData(double data, double base);
int GetHeapHeight(int n);
int IntSquare(int x, int base);

void PrintHeap(Heap* heap, const char* title); // Heap�� index ������ ���� ���
void PrintHeapTree(Heap* heap, const char* title); // Heap�� tree ������� ���

int main()
{
	Heap heap;
	int i, sizeItemList = 0;

//	int itemList[] = { 50, 40, 30, 25, 30 };
//	int itemList[] = { 24, 17, 29, 22, 20, 31, 27, 18, 21 }; // ������ 10��
	int itemList[] = { 50, 40, 30, 25, 30, 20, 10, 5, 15, 20, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52 }; // 12�� ������

	sizeItemList = sizeof(itemList) / sizeof(int);

	HeapInit(&heap, DataPirorityComp);

	for (i = 0; i < sizeItemList; i++)
	{
		HInsert(&heap, itemList[i]);
	}

	// ���� �� ��� ���
	PrintHeap(&heap, "���� ��");
	PrintHeapTree(&heap, "Ʈ���� ���");

	// �ߵ� ����
	HInsert(&heap, 45);
	HInsert(&heap, 60);

	// ���� �� ��� ���
	PrintHeap(&heap, "������ 45, 60 ���� ��");
	PrintHeapTree(&heap, "Ʈ���� ���");

	// Ʈ�� �ϳ� ����
	HDelete(&heap);

	// ���� �� ��� ���
	PrintHeap(&heap, "������ 1�� ���� ��");
	PrintHeapTree(&heap, "Ʈ���� ���");
	

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

	for (i = 1; i < heap->numOfData; i++) // Heap�� �ε����� 1���� �����Ѵ�.
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

	printf("��ü ��� �� : %d ���� : %d ������ ������ �ִ� �ڽ� ���� : %d", heap->numOfData, height, IntSquare(2, height));
	puts("\n\n\n");
	
	for (i = 0; i <= height; i++)
	{
		printf("[Level : %d]", i);

		for (j = 0; j < IntSquare(2, (height - i)); j++)
		{
			fputs("  ", stdout);
		}

		j = 0;

		// �ڽ��� �������� ���� �� �ִ� �ڽ� ����ŭ ������ idx�� ���� ����ִ� ������ �ε��������� ���ƾ� �Ѵ�.
		while (j < IntSquare(2, i) && idx <= heap->numOfData)
		{
			printf("%2d", heap->Heap[idx++]);

			if ((j + 1) < IntSquare(2, i)) // ������ �� ���� �����Ͱ� �ִٸ�,
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