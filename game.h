#include"main.h"

int keyControl();
void titleDraw();
int menuSelect();
void gameInfo();
void mapDraw();
void peapleDraw(struct Pos peaplePos);
void peapleRemove(struct Pos peaplePos);
void ballDraw(struct Pos ballPos);
void ballRemove(struct Pos ballPos);
void tagetDraw(struct Pos targetPos, struct Pos peaplePos);
int tagetMove(struct Pos* targetPos, struct Pos peaplePos);
void tagetRemove(int x, int y);
void ballPeapleMove(struct Pos targetPos, struct Pos* ballPos, struct Pos* peaplePos);
void scoreboardDraw(struct Pos s, int p[], int c[], int playCount);
int collisionDesision(int px, int py, int bx, int by);
void gLoop();
void result(struct Success s);