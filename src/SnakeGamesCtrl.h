#pragma once
#include <Windows.h>

#define    FILED_WIDTH		20
#define    FILED_HEIGHT		20
#define    BLOCK_WALL		0x01
#define    BLOCK_SNAKE		0x02
#define    BLOCK_Body		0x30
#define    BLOCK_NULL		0x00

typedef unsigned char   BLOCK;

// ∏ˆ≈Î¿ª ¿Ã∑Í ±∏¡∂√º
struct BODY {
	int x;
	int y;
	UINT direction;
	BODY* next = NULL;
};


void CreateSnake(BODY **LPSnakeHead, int cLength);
void DeleteSnake(BODY **LPSnakeHead);
void RenewField(BLOCK Field[FILED_HEIGHT][FILED_HEIGHT], BODY *SnakeHead, BODY *Body);
void MoveSnake(UINT SetMove, BODY *SnakeHead);
BOOL HitBody(const BODY *SnakeHead);
BOOL EatBody(BODY** LPSnakeHead, BODY *Body);
BOOL HitWall(BODY* SnakeHead);