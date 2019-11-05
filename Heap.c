// Visual Studio 2019���� �ۼ��� �ڵ��Դϴ�.

#include <stdio.h>
#include <stdlib.h> // exit()�� ����ϱ� ���� ����
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

	if (ph->comp(1, 2) < 0) // ������ min heap
	{
		while (idx != 1 && data < ph->Heap[idx / 2]) // ��Ʈ ��尡 �ƴϰ� �θ� ��庸�� �۴ٸ�
		{
			ph->Heap[idx] = ph->Heap[idx / 2]; // ���� �ε��� �ڸ��� �θ� ��带 �ִ´�.
			idx /= 2; // �ε����� �θ� ���� ����ȴ�.
		}
	}
	else // ����� max heap
	{
		while (idx != 1 && data > ph->Heap[idx / 2]) // ��Ʈ ��尡 �ƴϰ� �θ� ��庸�� ũ�ٸ�
		{
			ph->Heap[idx] = ph->Heap[idx / 2];
			idx /= 2;
		}
	}

	ph->Heap[idx] = data; // data�� Heap�� �켱������ ���� ���� �� ���� ���Ե�.
}

int GetLChildIdx(int idx) // Node�� ���� �ڽ��� index�� ��ȯ�ϴ� �Լ�
{
	return 2 * idx;
}

int GetRChildIdx(int idx) // Node�� ������ �ڽ��� index�� ��ȯ�ϴ� �Լ�
{
	return GetLChildIdx(idx) + 1;
}

int GetHiPriChildIdx(Heap* ph, int idx) // Node�� �� �ڽ� Node �� �켱������ ���� Child Node�� index ��ȯ
{
	// �ڽ� ��尡 ���ٸ� (Ex : LChildIdx = 20, but numOfData = 10, ��, 20�� ° index�� ���� ���ٴ� ��)
	if (GetLChildIdx(idx) > ph->numOfData)
	{
		return 0;
	}
	else if (GetLChildIdx(idx) == ph->numOfData) // ���� �ڽ� ��尡 �ϳ����
	{
		return GetLChildIdx(idx);
	}
	else if (ph->comp(1, 2) < 0) // min heap�̶��
	{
		if (ph->Heap[GetLChildIdx(idx)] < ph->Heap[GetRChildIdx(idx)]) // ���� �ڽ� ��尡 ������ �ڽ� ��庸�� �۴ٸ�
		{
			return GetLChildIdx(idx);
		}
		else
		{
			return GetRChildIdx;
		}
	}
	else // max heap�̶��
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
	int rdata = ph->Heap[1]; // Heap�� ���� �� ��Ʈ ��带 �����Ѵ�.
	int lastNodeData = ph->Heap[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	if (ph->comp(1, 2) < 0) // min heap�̶��
	{
		while (childIdx = GetHiPriChildIdx(ph, parentIdx))
		{
			// Ʈ���� ������ node�� childIdx���� �۰ų� ���ٸ�
			if (lastNodeData <= ph->Heap[childIdx])
			{
				break;
			}

			// �θ� ��忡 �ڽ� ��带 �������ν� heap�� �켱���� ������ ��Ų��.
			ph->Heap[parentIdx] = ph->Heap[childIdx];
			parentIdx = childIdx; // ������ node�� �� ��ġ�� ���ϱ� ���� parentIdx �� ����
		}
	}
	else // max heap�̶��
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