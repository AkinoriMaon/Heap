// Visual Stduio 2019에서 작성된 코드입니다.

#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100 // heap은 완전이진트리를 전제로 하기 때문에 배열이 효율적

typedef int HData;

typedef int (*PirorityComp) (HData d1, HData d2);

typedef struct _heap
{
	PirorityComp comp; // Heap의 우선순위를 결정할 함수를 담을 함수 포인터
	int numOfData; // 데이터 개수
	int Heap[HEAP_LEN];
} Heap;

void HeapInit(Heap* ph, PirorityComp pc); // Heap 초기화
int HIsEmpty(Heap* ph); // Heap이 비었는지 확인

void HInsert(Heap* ph, HData data); // Heap에 data 삽입
HData HDelete(Heap* ph); // Heap의 루트 노드 삭제 후 반환

#endif