#include "stdafx.h"
#include "SnakeGamesCtrl.h"
#pragma warning(disable : 4996)

//---------------------------------------------------
// ���� �Ӹ��� �������� ���̸�ŭ ����Ʈ(����) �޾ƿ� ����.
//---------------------------------------------------
void CreateSnake(BODY **LPSnakeHead, int cLength)
{
	BODY *BODYPos = NULL;
	int i = 0;

	(*LPSnakeHead) = (BODY*)malloc(sizeof(BODY));
	BODYPos = (*LPSnakeHead);

	for (i = 0; i <= cLength; i++)
	{
		BODYPos->direction = VK_LEFT;
		BODYPos->x = FILED_WIDTH / 2 + i;
		BODYPos->y = FILED_HEIGHT / 2;
		if (cLength != i) BODYPos->next = (BODY*)malloc(sizeof(BODY));
		else BODYPos->next = NULL;
		BODYPos = BODYPos->next;
	}
}

//---------------------------------------------------
// ����Ʈ(��) �� �����Ѵ�.
//---------------------------------------------------
void DeleteSnake(BODY **LPSnakeHead)
{
	BODY *BODYPos = (*LPSnakeHead);
	BODY *OldBODYPos;
	int i = 0;
	while (BODYPos != NULL)
	{
		i++;
		OldBODYPos = BODYPos;
		BODYPos = BODYPos->next;
		free(OldBODYPos);
	}
}

//---------------------------------------------------
// �� �̵�
//---------------------------------------------------
void MoveSnake(UINT SetMove, BODY *SnakeHead)
{
	BODY *BODYPos = SnakeHead;
	BODY *OldPos;
	UINT directionFront;
	int directionBack;
	directionFront = SnakeHead->direction;
	//CString test;
	//test.Format(_T("%d"), SetMove);
	//AfxMessageBox(test);

	if (SetMove != NULL)
	{
		SnakeHead->direction = SetMove;
	}

	while (BODYPos->next != NULL)
	{
		BODYPos = BODYPos->next;
		directionBack = BODYPos->direction;
		BODYPos->direction = directionFront;
		directionFront = directionBack;
	}

	BODYPos = SnakeHead;
	while (BODYPos != NULL)
	{
		switch (BODYPos->direction)
		{
		case VK_DOWN:
			BODYPos->y += 1;
			break;
		case VK_UP:
			BODYPos->y -= 1;
			break;
		case VK_LEFT:
			BODYPos->x -= 1;
			break;
		case VK_RIGHT:
			BODYPos->x += 1;
			break;
		}

		OldPos = BODYPos;
		BODYPos = BODYPos->next;
	}

}
//---------------------------------------------------
// ȭ�鿡 ��Ÿ���� �Ǵ� �ʵ� ������
//---------------------------------------------------
void RenewField(BLOCK Field[FILED_HEIGHT][FILED_HEIGHT], BODY *SnakeHead, BODY *Body)
{
	BODY *BODYPos = SnakeHead;
	int i;
	int j;

	// ������ �迭 �ʱ�ȭ.
	for (i = 0; i < FILED_HEIGHT; i++)
	{
		for (j = 0; j < FILED_HEIGHT; j++)
		{
			// ������ ���� �� ����� ����.
			Field[i][j] = (i == 0 || i == FILED_HEIGHT - 1 || j == 0 || j == FILED_WIDTH - 1) ? BLOCK_WALL : BLOCK_NULL;
		}
	}

	// �� ��ġ ����
	while (BODYPos != NULL)
	{
		Field[BODYPos->y][BODYPos->x] = BLOCK_SNAKE;
		BODYPos = BODYPos->next;
	}

	// �߰� ���� ��ġ ����.
	Field[Body->y][Body->x] = BLOCK_Body;
}


//---------------------------------------------------
// ���� ������ �Ծ��� ���� ���� �˻�.
//---------------------------------------------------
BOOL EatBody(BODY** LPSnakeHead, BODY *Body)
{

	BODY* NewHead;
	BODY* BODYPos = *LPSnakeHead;
	BOOL  OverlapBody = FALSE;


	if ((*LPSnakeHead)->y != Body->y || (*LPSnakeHead)->x != Body->x)
	{
		return FALSE;
	}


	NewHead = (BODY*)malloc(sizeof(BODY));
	NewHead->direction = (*LPSnakeHead)->direction;

	NewHead->x = Body->x;
	NewHead->y = Body->y;

	// �߰���ġ ������
	switch (NewHead->direction)
	{
	case VK_DOWN:
		NewHead->y += 1;
		break;
	case VK_UP:
		NewHead->y -= 1;
		break;
	case VK_LEFT:
		NewHead->x -= 1;
		break;
	case VK_RIGHT:
		NewHead->x += 1;
		break;
	}

	NewHead->next = BODYPos;
	*LPSnakeHead = NewHead;


	while (1)
	{
		Body->x = rand() % (FILED_WIDTH - 4) + 2;
		Body->y = rand() % (FILED_HEIGHT - 4) + 2;

		OverlapBody = FALSE;
		BODYPos = *LPSnakeHead;
		while (BODYPos != NULL)
		{
			if (BODYPos->x == Body->x && BODYPos->y == Body->y)
			{
				OverlapBody = TRUE;
				break;
			}
			BODYPos = BODYPos->next;
		}

		if (OverlapBody == FALSE)
		{
			break;
		}
	}

	return TRUE;
}
//---------------------------------------------------
// ������ �浹 �˻�
//---------------------------------------------------
BOOL HitWall(BODY* SnakeHead)
{
	if (!(SnakeHead->y > 0 && SnakeHead->y < FILED_HEIGHT - 1) ||
		!(SnakeHead->x > 0 && SnakeHead->x < FILED_WIDTH - 1))
	{
		return TRUE;
	}
	return  FALSE;
}


//---------------------------------------------------
// ������� �浹 �˻�
//---------------------------------------------------
BOOL HitBody(const BODY *SnakeHead)
{
	BODY *BODYPos = (BODY*)SnakeHead->next;
	while (BODYPos != NULL)
	{
		if (BODYPos->x == SnakeHead->x && BODYPos->y == SnakeHead->y)
		{
			return TRUE;
		}
		BODYPos = BODYPos->next;
	}
	return FALSE;
}