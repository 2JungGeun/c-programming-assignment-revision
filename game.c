#include"game.h"
#include"main.h"
#include"util.h"
struct success {
	int player_success;
	int computer_success;
};
struct Pos {
	int x;
	int y;
};
struct size {
	int x;
	int y;
};
int keyControl()
{
	char temp = getch();
	// 키보드 값 : up = 1 left = 2 down = 3 right = 4 submit = 5 shooting = 6 
	if (temp == 'w' || temp == 'W')
		return 1;
	else if (temp == 'a' || temp == 'A')
		return 2;
	else if (temp == 's' || temp == 'S')
		return 3;
	else if (temp == 'd' || temp == 'D')
		return 4;
	else if (temp == ' ')
		return 5;
	else if (temp == 'f' || temp == 'F')
		return 6;
	else
		return 7;
}
void titleDraw()
{
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("      #######     ####        ####   ###########      #######     ####    ##        ##   \n");
	printf("      ##        ##    ##    ##   ##      ##           ##    ##   ##  ##   ##        ##   \n");
	printf("      ##       ##     ##   ##     ##     ##           ##    ##  ##    ##  ##        ##   \n");
	printf("      #######  ##     ##   ##     ##     ##           ######    ########  ##        ##   \n");
	printf("      ##       ##     ##   ##     ##     ##           ##    ##  ##    ##  ##        ##   \n");
	printf("      ##        ##   ##     ##   ##      ##           ##    ##  ##    ##  ##        ##   \n");
	printf("      ##         ####        ####        ##           #######   ##    ##  ########  ######## \n\n\n");
	printf("       ######  ######  ##    ##   ####  ##   ###### ##    ##     ##  ## ####  ####   ##  ##\n");
	printf("       ##   ## ##      ####  ##  ##  ## ##     ##    ##  ##      ## ##   ##  ##  ##  ## ## \n");
	printf("       ######  ######  ## ## ##  ###### ##     ##     ####       ###     ##  ##      ###   \n");
	printf("       ##      ##      ##  ####  ##  ## ##     ##      ##        ## ##   ##  ##  ##  ## ## \n");
	printf("       ##      ######  ##    ##  ##  ## ###### ##      ##        ##  ## ####  ####   ##  ##\n");
	struct Pos cursorPos = { 41, 27 };
	gotoxy(cursorPos.x, cursorPos.y);
	printf("> 게 임 시 작 ");
	gotoxy(cursorPos.x + 2, cursorPos.y + 1);
	printf("게 임 정 보 ");
	gotoxy(cursorPos.x + 2, cursorPos.y + 2);
	printf("   종 료   ");
}
int menuSelect()
{
	struct Pos cursorPos = { 41, 27 };
	while (1)
	{
		int n = keyControl();
		switch (n)
		{
		case 1: {
			if (cursorPos.y > 27)
			{
				gotoxy(cursorPos.x, cursorPos.y);
				printf(" ");
				gotoxy(cursorPos.x, --cursorPos.y);
				printf(">");
			}
			break;
		}
		case 3: {
			if (cursorPos.y < 29)
			{
				gotoxy(cursorPos.x, cursorPos.y);
				printf(" ");
				gotoxy(cursorPos.x, ++cursorPos.y);
				printf(">");
			}
			break;
		}
		case 5: {
			return cursorPos.y - 27;
			break;
		}
		}
	}
}
void GameInfo()
{
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("   1. 이 게임은 승부차기 게임입니다.\n");
	printf("   2. 기본적으로 5번씩 컴퓨터와 유저가 번갈아 페널티킥을 찹니다.\n");
	printf("   3. 공격 상황에서 w, a, s, d로 방향을 조정할 수 있고 f를 누르면 슈팅을 합니다.\n");
	printf("   4. 슈팅에는 오차범위가 존재합니다.\n");
	printf("\n\n\n\n                            -스페이스바를 누르면 메뉴화면으로 돌아갑니다.-");
	while (1) {
		if (keyControl() == 5)
		{
			system("cls");
			break;
		}
	}
}
char Map[40][101] =
{
	{"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"},//0
	{"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"},//1
	{"0000001111111111111111111111111111111111111111111111111111111111111111111111111111111111111111000000"},//2
	{"0000001010000000000000000000000000000000000000000000000000000000000000000000000000000000000101000000"},//3
	{"0000001001111111111111111111111111111111111111111111111111111111111111111111111111111111111001000000"},//4
	{"0000001001000000000000000000000000000000000000000000000000000000000000000000000000000000001001000000"},//5
	{"0000001001000000000000000000000000000000000000000000000000000000000000000000000000000000001001000000"},//6
	{"0000001000100000000000000000000000000000000000000000000000000000000000000000000000000000010001000000"},//7
	{"0000001000100000000000000000000000000000000000000000000000000000000000000000000000000000010001000000"},//8
	{"0000001000100000000000000000000000000000000000000000000000000000000000000000000000000000010001000000"},//9
	{"0000001000010000000000000000000000000000000000000000000000000000000000000000000000000000100001000000"},//10
	{"0000001000010000000000000000000000000000000000000000000000000000000000000000000000000000100001000000"},//11
	{"0000001000001000000000000000000000000000000000000000000000000000000000000000000000000001000001000000"},//12
	{"0000001000001000000000000000000000000000000000000000000000000000000000000000000000000001000001000000"},//13
	{"0000001000001000000000000000000000000000000000000000000000000000000000000000000000000001000001000000"},//14
	{"0000001000000100000000000000000000000000000000000000000000000000000000000000000000000010000001000000"},//15
	{"0000001000000100000000000000000000000000000000000000000000000000000000000000000000000010000001000000"},//16
	{"0000001000000010000000000000000000000000000000000000000000000000000000000000000000000100000001000000"},//17
	{"0000001000000010000000000000000000000000000000000000000000000000000000000000000000000100000001000000"},//18
	{"0000001000000011111111111111111111111111111111111111111111111111111111111111111111111100000001000000"},//19
	{"0000001000000100000000000000000000000000000000000000000000000000000000000000000000000010000001000000"},//20
	{"0000001000010000000000000000000000000000000000000000000000000000000000000000000000000000100001000000"},//21
	{"0000001001000000000000000000000000000000000000000000000000000000000000000000000000000000001001000000"},//22
	{"0000001100000000000000000000000000000000000000000000000000000000000000000000000000000000000011000000"},//23
	{"1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"},//24
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//25
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//26
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//27
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//28
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//29
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//30
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//31
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//32
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//33
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//34
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//35
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//36
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//37
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//38
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"}//39
};
char ball[3][7] =
{
	{"011110"},
	{"111111"},
	{"011110"},
};
char peaple[6][9] =
{
	{"pppppppp"},
	{"pppppppp"},
	{"pppppppp"},
	{"pppppppp"},
	{"pppppppp"},
	{"pppppppp"}
};
// 5030 ball 4818peaple//
void gLoop()
{

	int Playing = 1;
	int playerResult[5] = { 0,0,0,0,0 };
	int computerResult[5] = { 0,0,0,0,0 };
	struct success s = { 0, 0 };
	int playCount = 0;
	while (Playing)
	{
		int n = 0;
		struct Pos targetPos = { 50, 10 };
		struct Pos ballPos = { 47, 30 };
		struct Pos peaplePos = { 46, 18 };
		struct Pos scoreboardPos = {5, 35};
		MapDraw();
		scoreboardDraw(scoreboardPos, playerResult, computerResult, playCount);
		peaple_Draw(peaplePos);
		tagetDraw(targetPos, peaplePos);
		ballDraw(ballPos);
		do
		{
			n = tagetMove(&targetPos, peaplePos);

		} while (n != 5);
		BALL_PEAPLE_MOVE(targetPos, &ballPos, &peaplePos);
		playCount++;
		playerResult[playCount - 1] = collision_desision(peaplePos.x, peaplePos.y, ballPos.x, ballPos.y);
		computerResult[playCount - 1] = computer_desision();
		scoreboardDraw(scoreboardPos, playerResult, computerResult, playCount);
		Sleep(1000);
		if (playCount == 5)
		{
			for (int i = 0; i <= playCount; i++)
			{
				if (playerResult[i] == 2)
					s.player_success++;
				if (computerResult[i] == 2)
					s.computer_success++;
			}
			break;
		}
	}
	SetColor(white, black);
	system("cls");
	result(s);
	Sleep(2000);
	system("cls");
}
void MapDraw()
{
	system("cls");
	for (int x = 0; x < 40; x++)
	{
		for (int y = 0; y < 101; y++)
		{
			char temp = Map[x][y];
			if (temp == '0')
			{
				SetColor(lightblue, lightblue);
				printf(" ");
			}
			else if (temp == '1')
			{
				SetColor(white, white);
				printf(" ");
			}
			else if (temp == 'g')
			{
				SetColor(lightgreen, lightgreen);
				printf(" ");
			}
		}
		if (x < 39)
			printf("\n");
	}
	SetColor(white, black);
}
void scoreboardDraw(struct Pos scoreboardPos, int p[], int c[], int playCount)
{
	SetColor(black, lightgreen);
	gotoxy(scoreboardPos.x, scoreboardPos.y);
	printf("플레이어의 성공 :");
	gotoxy(scoreboardPos.x, scoreboardPos.y + 1);
	printf("컴퓨터의 성공 :");
	if (playCount != 0)
	{
		for (int i = 0; i < playCount; i++)
		{
			if (p[i] == 1)
			{
				gotoxy(23 + 3 * i, scoreboardPos.y);
				printf("x");
			}
			else
			{
				gotoxy(23 + 3 * i, scoreboardPos.y);
				printf("0");
			}

			if (c[i] == 1)
			{
				gotoxy(23 + 3 * i, scoreboardPos.y+1);
				printf("x");
			}
			else
			{
				gotoxy(23 + 3 * i, scoreboardPos.y+1);
				printf("0");
			}
		}
	}
}
void ballDraw(struct Pos ballPos)
{
	for (int x = 0; x < 3; x++)
	{
		if (x == 0)
			gotoxy(ballPos.x + 1, ballPos.y);
		else if (x == 1)
			gotoxy(ballPos.x, ballPos.y + 1);
		else if (x == 2)
			gotoxy(ballPos.x + 1, ballPos.y + 2);

		for (int y = 0; y < 7; y++)
		{
			char temp = ball[x][y];
			if (temp == '1')
			{
				SetColor(red, yellow);
				printf("*");
			}
		}
	}
}
void ballRemove(struct Pos ballPos)
{
	for (int x = 0; x < 3; x++)
	{
		if (x == 0)
			gotoxy(ballPos.x + 1, ballPos.y);
		else if (x == 1)
			gotoxy(ballPos.x, ballPos.y + 1);
		else if (x == 2)
			gotoxy(ballPos.x + 1, ballPos.y + 2);

		for (int y = 0; y < 7; y++)
		{
			char temp = 0;
			if (x == 0 || x == 2)
				temp = Map[ballPos.y + x][ballPos.x + y + 1];
			else
				temp = Map[ballPos.y + x][ballPos.x + y];

			if (temp == '0')
			{
				SetColor(lightblue, lightblue);
				printf(" ");
			}
			else if (temp == '1')
			{
				SetColor(white, white);
				printf(" ");
			}
			else if (temp == 'g')
			{
				SetColor(lightgreen, lightgreen);
				printf(" ");
			}
		}
	}
}
void peaple_Draw(struct Pos peaplePos)
{
	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			char temp = peaple[y][x];
			if (temp == 'p')
			{
				SetColor(black, black);
				gotoxy(peaplePos.x + x, peaplePos.y + y);
				printf(" ");
			}
		}
	}
}
void peaple_Remove(struct Pos peaplePos)
{
	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			gotoxy(peaplePos.x + x, peaplePos.y + y);
			char temp = Map[peaplePos.y + y][peaplePos.x + x];
			if (temp == '0')
			{
				SetColor(lightblue, lightblue);
				printf(" ");
			}
			else if (temp == '1')
			{
				SetColor(white, white);
				printf(" ");
			}
			else if (temp == 'g')
			{
				SetColor(lightgreen, lightgreen);
				printf(" ");
			}
		}
	}
}
void BALL_PEAPLE_MOVE(struct Pos targetPos, struct Pos* ballPos, struct Pos* peaplePos)
{
	struct Pos recentPeaplePos = { 0, 0 };
	int keyChoice = 0;
	srand(time(NULL));
	int peapleDecision = rand() % 100;
	if (peapleDecision < 20)
	{
		recentPeaplePos = targetPos;
	}
	else
	{
		recentPeaplePos.x = 7 + rand() % 78;
		recentPeaplePos.y = 3 + rand() % 18;
	}
	double delta_peaplePosX = fabs(((double)recentPeaplePos.x - (double)peaplePos->x) / 10.0);
	double delta_peaplePosY = fabs(((double)recentPeaplePos.y - (double)peaplePos->y) / 10.0);
	double delta_ballPosX = fabs(((double)ballPos->x - (double)targetPos.x) / 10.0);
	double delta_ballPosY = fabs(((double)ballPos->y - (double)targetPos.y) / 10.0);
	double d_ballPosX = ballPos->x;
	double d_ballPosY = ballPos->y;
	double d_peaplePosX = peaplePos->x;
	double d_peaplePosY = peaplePos->y;
	while (keyChoice != 6)
	{
		keyChoice = keyControl();
		if (keyChoice == 6)
		{
			for (int i = 0; i < 10; i++)
			{
				peaple_Remove(*peaplePos);
				ballRemove(*ballPos);
				if (recentPeaplePos.x > peaplePos->x)
				{
					d_peaplePosX += delta_peaplePosX;
					peaplePos->x = d_peaplePosX;
				}
				else
				{
					d_peaplePosX -= delta_peaplePosX;
					peaplePos->x = d_peaplePosX;
				}
				d_peaplePosY -= delta_peaplePosY;
				peaplePos->y = d_peaplePosY;
				if (targetPos.x > ballPos->x)
				{
					d_ballPosX += delta_ballPosX;
					ballPos->x = d_ballPosX;
				}
				else
				{
					d_ballPosX -= delta_ballPosX;
					ballPos->x = d_ballPosX;
				}
				d_ballPosY -= delta_ballPosY;
				ballPos->y = d_ballPosY;
				peaple_Draw(*peaplePos);
				ballDraw(*ballPos);
				Sleep(500);
			}
		}
	}
}
void tagetDraw(struct Pos targetPos, struct Pos peaplePos)
{
	struct size peapleSize = { 8, 6 };
	if ((targetPos.x >= peaplePos.x) && (targetPos.x < peaplePos.x + peapleSize.x))
	{
		if ((targetPos.y >= peaplePos.y) && (targetPos.y <= peaplePos.y + peapleSize.y))
		{
			SetColor(white, black);
			gotoxy(targetPos.x, targetPos.y);
			printf("#");
		}
		else
		{
			char temp = Map[targetPos.y][targetPos.x];
			if (temp == '0')
			{
				SetColor(yellow, lightblue);
				gotoxy(targetPos.x, targetPos.y);
				printf("#");
			}
			else if (temp == '1')
			{
				SetColor(black, white);
				gotoxy(targetPos.x, targetPos.y);
				printf("#");
			}
		}
	}
	else
	{
		char temp = Map[targetPos.y][targetPos.x];
		if (temp == '0')
		{
			SetColor(yellow, lightblue);
			gotoxy(targetPos.x, targetPos.y);
			printf("#");
		}
		else if (temp == '1')
		{

			SetColor(black, white);
			gotoxy(targetPos.x, targetPos.y);
			printf("#");
		}
	}
}
void tagetRemove(int targetPosX, int targetPosY)
{
	if ((targetPosX >= 46) && (targetPosX < 54))
	{
		if ((targetPosY <= 24) && (targetPosY >= 18))
		{
			SetColor(black, black);
			gotoxy(targetPosX, targetPosY);
			printf(" ");
		}
		else
		{
			char temp = Map[targetPosY][targetPosX];
			if (temp == '0')
			{
				SetColor(yellow, lightblue);
				gotoxy(targetPosX, targetPosY);
				printf(" ");
			}
			else if (temp == 'p')
			{
				SetColor(yellow, black);
				gotoxy(targetPosX, targetPosY);
				printf(" ");
			}
			else if (temp == '1')
			{
				SetColor(yellow, white);
				gotoxy(targetPosX, targetPosY);
				printf(" ");
			}
		}
	}
	else
	{
		char temp = Map[targetPosY][targetPosX];
		if (temp == '0')
		{
			SetColor(yellow, lightblue);
			gotoxy(targetPosX, targetPosY);
			printf(" ");
		}
		else if (temp == 'p')
		{
			SetColor(yellow, black);
			gotoxy(targetPosX, targetPosY);
			printf(" ");
		}
		else if (temp == '1')
		{
			SetColor(yellow, white);
			gotoxy(targetPosX, targetPosY);
			printf(" ");
		}
	}
}

int tagetMove(struct Pos* targetPos, struct Pos peaplePos)
{
	int n = keyControl();
	if (n == 1 && (targetPos->y != 3))
	{
		tagetRemove(targetPos->x, targetPos->y);
		targetPos->y -= 1;
		tagetDraw(*targetPos, peaplePos);
	}
	else if (n == 2 && (targetPos->x != 7))
	{
		tagetRemove(targetPos->x, targetPos->y);
		targetPos->x -= 1;
		tagetDraw(*targetPos, peaplePos);
	}
	else if (n == 3 && (targetPos->y != 23))
	{
		tagetRemove(targetPos->x, targetPos->y);
		targetPos->y += 1;
		tagetDraw(*targetPos, peaplePos);
	}
	else if (n == 4 && (targetPos->x != 92))
	{
		tagetRemove(targetPos->x, targetPos->y);
		targetPos->x += 1;
		tagetDraw(*targetPos, peaplePos);
	}
	else if (n == 5)
	{
		tagetRemove(targetPos->x, targetPos->y);
	}
	return n;
}
int collision_desision(int px, int py, int bx, int by)
{
	if ((px - 5 <= bx) && (bx <= px + 8))
	{
		if ((py - 3 <= by) && (by <= py + 6))
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else
	{
		return 2;
	}
}
int computer_desision()
{
	srand(time(NULL));
	int computer_desision = 0;
	int random = rand() % 100;
	if (random < 70)
		computer_desision = 2;
	else
		computer_desision = 1;
	return computer_desision;
}

void result(struct success s)
{
	if (s.player_success > s.computer_success)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("                   ###        #####        ###     #######     ######        ###         \n");
		printf("                   ###       ### ###       ###       ###       ### ###       ###         \n");
		printf("                    ###     ###   ###     ###        ###       ###  ###      ###         \n");
		printf("                    ###     ###   ###     ###        ###       ###   ###     ###         \n");
		printf("                     ###   ###     ###   ###         ###       ###    ###    ###         \n");
		printf("                     ###   ###     ###   ###         ###       ###     ###   ###         \n");
		printf("                      ### ###       ### ###          ###       ###      ###  ###         \n");
		printf("                      ### ###       ### ###          ###       ###       ### ###         \n");
		printf("                       #####         #####         #######     ###        ######         \n");
		printf("\n\n\n\n\n\n\n\n");
	}
	else if (s.player_success == s.computer_success)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("       ###########         ###########              ########     ###        #####        ###       \n");
		printf("       ###       ###       ###       ###           ###    ###    ###       ### ###       ###       \n");
		printf("       ###        ###      ###        ###         ###     ###     ###     ###   ###     ###        \n");
		printf("       ###         ###     ###       ###         ###      ###     ###     ###   ###     ###        \n");
		printf("       ###         ###     ###########          #############      ###   ###     ###   ###         \n");
		printf("       ###         ###     ###      ###        ###        ###      ###   ###     ###   ###         \n");
		printf("       ###        ###      ###       ###      ###         ###       ### ###       ### ###          \n");
		printf("       ###       ###       ###        ###    ###          ###       ### ###       ### ###          \n");
		printf("       ###########         ###         ###  ###           ###        #####         #####           \n");
		printf("\n\n\n\n\n\n\n\n");
	}
	else
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("             ###                 #########           ###########        #############              \n");
		printf("             ###               ###       ###        ###       ###       ###                        \n");
		printf("             ###              ###         ###      ###                  ###                        \n");
		printf("             ###              ###         ###       ###                 ###                        \n");
		printf("             ###              ###         ###        ###########        #############              \n");
		printf("             ###              ###         ###                 ###       ###                        \n");
		printf("             ###              ###         ###                  ###      ###                        \n");
		printf("             ###               ###       ###       ###        ###       ###                        \n");
		printf("             #############       #########           ###########        #############              \n");
		printf("\n\n\n\n\n\n\n\n");
	}
}