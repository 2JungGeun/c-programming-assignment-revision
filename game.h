#include"main.h"

int keyControl();
void titleDraw();
int menuSelect();
void GameInfo();
void MapDraw();
void peaple_Draw(struct Pos peaplePos);
void peaple_Remove(struct Pos peaplePos);
void ballDraw(struct Pos ballPos);
void ballRemove(struct Pos ballPos);
void tagetDraw(struct Pos targetPos, struct Pos peaplePos);
int tagetMove(struct Pos* targetPos, struct Pos peaplePos);
void tagetRemove(int x, int y);
void BALL_PEAPLE_MOVE(struct Pos targetPos, struct Pos* ballPos, struct Pos* peaplePos);
void scoreboardDraw(struct Pos s, int p[], int c[], int playCount);
int collision_desision(int px, int py, int bx, int by);
void gLoop();
void result(struct success s);