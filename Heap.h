// Visual Stduio 2019���� �ۼ��� �ڵ��Դϴ�.

#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100 // heap�� ��������Ʈ���� ������ �ϱ� ������ �迭�� ȿ����

typedef int HData;

typedef int (*PirorityComp) (HData d1, HData d2);

typedef struct _heap
{
	PirorityComp comp; // Heap�� �켱������ ������ �Լ��� ���� �Լ� ������
	int numOfData; // ������ ����
	int Heap[HEAP_LEN];
} Heap;

void HeapInit(Heap* ph, PirorityComp pc); // Heap �ʱ�ȭ
int HIsEmpty(Heap* ph); // Heap�� ������� Ȯ��

void HInsert(Heap* ph, HData data); // Heap�� data ����
HData HDelete(Heap* ph); // Heap�� ��Ʈ ��� ���� �� ��ȯ

#endif