#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "Screen.h"
#include <windows.h>
#include <time.h>

typedef struct _PLAYER
{
	int nCenterX, nCenterY;
	int nMoveX, nMoveY;
	int nX, nY;
} PLAYER;

PLAYER g_sPlayer;
char g_strPlayer[] = "----0----";
int g_nLength;

void Init()
{
	g_sPlayer.nCenterX = 4;
	g_sPlayer.nCenterY = 0;
	g_sPlayer.nMoveX = 20;
	g_sPlayer.nMoveY = 22;
	g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;
	g_nLength = strlen(g_strPlayer);
}

void Update()
{
}

void Render()
{
	char string[100] = { 0, };
	ScreenClear();

	if (g_sPlayer.nX < 0)  
		ScreenPrint(0, g_sPlayer.nMoveY, &g_strPlayer[g_sPlayer.nX*-1]);
	else if (g_sPlayer.nMoveX + (g_nLength - (g_sPlayer.nCenterX + 1)) > 79) 
	{
		strncat(string, g_strPlayer, g_nLength - ((g_sPlayer.nMoveX + g_sPlayer.nCenterX + 1) - 79));
		ScreenPrint(g_sPlayer.nX, g_sPlayer.nMoveY, string);
	}
	else { 
		ScreenPrint(g_sPlayer.nX, g_sPlayer.nMoveY, g_strPlayer);
	}

	sprintf(string, "movement : %d, %d", g_sPlayer.nMoveX, g_sPlayer.nMoveY);
	ScreenPrint(0, 0, string);

	ScreenFlipping();
}

void Release()
{
}

int main(void)
{
	int nKey, nRemain;

	ScreenInit();
	Init();      

	while (1)
	{
		if (_kbhit())
		{
			nKey = _getch();
			if (nKey == 'q')
				break;

			switch (nKey)
			{
			case 'j':
				g_sPlayer.nMoveX--;
				nRemain = g_nLength - (g_sPlayer.nCenterX + 1); 
				if (g_sPlayer.nMoveX - g_sPlayer.nCenterX < 0 || g_sPlayer.nMoveX + nRemain > 79)
					g_sPlayer.nMoveX--;

				g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;
				break;
			case 'l':
				g_sPlayer.nMoveX++;
				nRemain = g_nLength - (g_sPlayer.nCenterX + 1); 
				if (g_sPlayer.nMoveX + nRemain > 79 || (g_sPlayer.nMoveX - g_sPlayer.nCenterX < 0))
					g_sPlayer.nMoveX++;

				g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;
				break;
			}
		}

		Update();    
		Render();    	
	}

	Release();  
	ScreenRelease();
	return 0;
}
