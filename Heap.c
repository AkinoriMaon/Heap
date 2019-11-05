// Visual Studio 2019에서 작성된 코드입니다.

#include <stdio.h>
#include <stdlib.h> // exit()을 사용하기 위해 선언
#include "Heap.h"

void HeapInit(Heap* ph, PirorityComp pc)
{
	ph->comp = pc;
	ph->numOfData = 0;
}

int HIsEmpty(Heap* ph)
{
	if (!(ph->numOfData))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void HInsert(Heap* ph, HData data)
{
	int idx = ++(ph->numOfData);

	if (ph->comp(1, 2) < 0) // 음수면 min heap
	{
		while (idx != 1 && data < ph->Heap[idx / 2]) // 루트 노드가 아니고 부모 노드보다 작다면
		{
			ph->Heap[idx] = ph->Heap[idx / 2]; // 현재 인덱스 자리에 부모 노드를 넣는다.
			idx /= 2; // 인덱스는 부모 노드로 변경된다.
		}
	}
	else // 양수면 max heap
	{
		while (idx != 1 && data > ph->Heap[idx / 2]) // 루트 노드가 아니고 부모 노드보다 크다면
		{
			ph->Heap[idx] = ph->Heap[idx / 2];
			idx /= 2;
		}
	}

	ph->Heap[idx] = data; // data가 Heap의 우선순위에 따라 들어가야 할 곳에 삽입됨.
}

int GetLChildIdx(int idx) // Node의 왼쪽 자식의 index를 반환하는 함수
{
	return 2 * idx;
}

int GetRChildIdx(int idx) // Node의 오른쪽 자식의 index를 반환하는 함수
{
	return GetLChildIdx(idx) + 1;
}

int GetHiPriChildIdx(Heap* ph, int idx) // Node의 두 자식 Node 중 우선순위가 높은 Child Node의 index 반환
{
	// 자식 노드가 없다면 (Ex : LChildIdx = 20, but numOfData = 10, 즉, 20번 째 index에 값이 없다는 말)
	if (GetLChildIdx(idx) > ph->numOfData)
	{
		return 0;
	}
	else if (GetLChildIdx(idx) == ph->numOfData) // 남은 자식 노드가 하나라면
	{
		return GetLChildIdx(idx);
	}
	else if (ph->comp(1, 2) < 0) // min heap이라면
	{
		if (ph->Heap[GetLChildIdx(idx)] < ph->Heap[GetRChildIdx(idx)]) // 왼쪽 자식 노드가 오른쪽 자식 노드보다 작다면
		{
			return GetLChildIdx(idx);
		}
		else
		{
			return GetRChildIdx;
		}
	}
	else // max heap이라면
	{
		if (ph->Heap[GetLChildIdx(idx)] < ph->Heap[GetRChildIdx(idx)])
		{
			return GetRChildIdx(idx);
		}
		else
		{
			return GetLChildIdx(idx);
		}
	}
}

HData HDelete(Heap* ph)
{
	int rdata = ph->Heap[1]; // Heap은 삭제 시 루트 노드를 삭제한다.
	int lastNodeData = ph->Heap[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	if (ph->comp(1, 2) < 0) // min heap이라면
	{
		while (childIdx = GetHiPriChildIdx(ph, parentIdx))
		{
			// 트리의 마지막 node가 childIdx보다 작거나 같다면
			if (lastNodeData <= ph->Heap[childIdx])
			{
				break;
			}

			// 부모 노드에 자식 노드를 넣음으로써 heap의 우선순위 조건을 지킨다.
			ph->Heap[parentIdx] = ph->Heap[childIdx];
			parentIdx = childIdx; // 마지막 node가 들어갈 위치를 구하기 위해 parentIdx 값 변경
		}
	}
	else // max heap이라면
	{
		while (childIdx = GetHiPriChildIdx(ph, parentIdx))
		{
			if (lastNodeData >= ph->Heap[childIdx])
			{
				break;
			}

			ph->Heap[parentIdx] = ph->Heap[childIdx];
			parentIdx = childIdx;
		}
	}

	ph->Heap[parentIdx] = lastNodeData;
	(ph->numOfData) -= 1;

	return rdata;
}