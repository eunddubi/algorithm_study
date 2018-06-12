/*스타트링크의 사무실은 1×1크기의 정사각형으로 나누어져 있는 N×M 크기의 직사각형으로 나타낼 수 있다.
사무실에는 총 K개의 CCTV가 설치되어져 있는데, CCTV는 5가지 종류가 있다.
각 CCTV가 감시할 수 있는 방법은 다음과 같다.
1번 CCTV는 한 쪽 방향만 감시할 수 있다.
2번과 3번은 두 방향을 감시할 수 있는데, 2번은 감시하는 방향이 서로 반대방향이어야 하고, 3번은 직각 방향이어야 한다.
4번은 세 방향, 5번은 네 방향을 감시할 수 있다.

CCTV는 감시할 수 있는 방향에 있는 칸 전체를 감시할 수 있다.
사무실에는 벽이 있는데, CCTV는 벽을 통과할 수 없다. CCTV가 감시할 수 없는 영역은 사각지대라고 한다.

CCTV는 90도 방향으로 회전시킬 수 있다.
지도에서 0은 빈 칸, 6은 벽, 1~5는 CCTV의 번호이다. CCTV는 벽을 통과할 수 없고, CCTV끼리는 통과할 수 있다.

첫째 줄에 사무실의 세로 크기 N과 가로 크기 M이 주어진다. (1 ≤ N, M ≤ 8)
둘째 줄부터 N개의 줄에는 사무실 각 칸의 정보가 주어진다. 0은 빈 칸, 6은 벽, 1~5는 CCTV를 나타내고, 문제에서 설명한 CCTV의 종류이다.
CCTV의 최대 개수는 8개를 넘지 않는다.

첫째 줄에 사각 지대의 최소 크기를 출력한다.*/

#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0
#define CCTV1 1
#define CCTV2 2
#define CCTV3 3
#define CCTV4 4
#define CCTV5 5
#define WALL 6
#define COVER 7
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int W, H;
int **map;
int **map2;
typedef struct point{
  int type;
  int x;
  int y;
  int dir[4];//0=up, 1=right, 2=down, 3=left
}point;
point camera[8];
int c;
int min = 9999;
void reset();
void rotate(int cctv);
void paint(point cam);
void blind_spot();

int main(){
  int i, j;
  c = 0;
  int cctv = 0;

  scanf("%d %d", &H, &W);

  map = (int**)malloc(sizeof(int*)*H);
  map2 = (int**)calloc(H, sizeof(int*));
  for(i=0;i<H;i++){
    map[i] = (int*)malloc(sizeof(int)*W);
    map2[i] = (int*)calloc(W, sizeof(int));
  }

  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      scanf("%d", &map[i][j]);
      if(map[i][j] > EMPTY && map[i][j] < WALL){
        camera[c].x = i;
        camera[c].y = j;
        camera[c].type = map[i][j];
        c++;
      }
    }
  }

  reset();
  blind_spot();
  rotate(cctv);

  printf("%d", min);

  for(i=0;i<H;i++){
    free(map[i]);
    free(map2[i]);
  }
  free(map);
  free(map2);
  return 0;
}

void paint(point cam){
  int x1 = cam.x;
  int y1 = cam.y;
  if(cam.dir[UP] == 1){
    while(x1<H && x1>=0 && y1<W && y1>=0 && map2[x1][y1] != WALL){
      if(map2[x1][y1] == EMPTY){
        map2[x1][y1] = COVER;
      }
      x1--;
    }
  }
  x1 = cam.x;  y1 = cam.y;
  if(cam.dir[RIGHT] == 1){
    while(x1<H && x1>=0 && y1<W && y1>=0 && map2[x1][y1] != WALL){
      if(map2[x1][y1] == EMPTY){
        map2[x1][y1] = COVER;
      }
      y1++;
    }
  }
  x1 = cam.x;  y1 = cam.y;
  if(cam.dir[DOWN] == 1){
    while(x1<H && x1>=0 && y1<W && y1>=0 && map2[x1][y1] != WALL){
      if(map2[x1][y1] == EMPTY){
        map2[x1][y1] = COVER;
      }
      x1++;
    }
  }
  x1 = cam.x;  y1 = cam.y;
  if(cam.dir[LEFT] == 1){
    while(x1<H && x1>=0 && y1<W && y1>=0 && map2[x1][y1] != WALL){
      if(map2[x1][y1] == EMPTY){
        map2[x1][y1] = COVER;
      }
      y1--;
    }
  }
}

void rotate(int cctv){
  int i, j;
  if(cctv > c){
    return;
  }else{//모든 cctv를 돌려가며 쓴다.
    if(camera[cctv].type == CCTV1){
      for(i=0; i<4; i++){
        for(j=0; j<4; j++) camera[cctv].dir[j] = 0;
        camera[cctv].dir[i] = 1;
        reset();
        for(j=0; j<c; j++) paint(camera[j]);
        blind_spot();
        rotate(cctv+1);
      }
    }else if(camera[cctv].type == CCTV2){
      for(i=0; i<2; i++){
        for(j=0; j<4; j++) camera[cctv].dir[j] = 0;
        camera[cctv].dir[i] = 1;
        camera[cctv].dir[i+2] = 1;
        reset();
        for(j=0; j<c; j++) paint(camera[j]);
        blind_spot();
        rotate(cctv+1);
      }
    }else if(camera[cctv].type == CCTV3){
      for(i=0; i<4; i++){
        for(j=0; j<4; j++) camera[cctv].dir[j] = 0;
        camera[cctv].dir[i] = 1;
        camera[cctv].dir[(i+1)%4] = 1;
        reset();
        for(j=0; j<c; j++) paint(camera[j]);
        blind_spot();
        rotate(cctv+1);
      }
    }else if(camera[cctv].type == CCTV4){
      for(i=0; i<4; i++){
        for(j=0; j<4; j++) camera[cctv].dir[j] = 1;
        camera[cctv].dir[i] = 0;
        reset();
        for(j=0; j<c; j++) paint(camera[j]);
        blind_spot();
        rotate(cctv+1);
      }
    }else if(camera[cctv].type == CCTV5){
      for(i=0; i<4; i++) camera[cctv].dir[i] = 1;
      reset();
      for(i=0; i<c; i++) paint(camera[i]);
      blind_spot();
      rotate(cctv+1);
    }
  }
  cctv++;
}

void blind_spot(){
  int i, j;
  int tmp = 0;
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      if(map2[i][j] == EMPTY) tmp++;
    }
  }
  if(tmp<min) {
    min = tmp;
  }
  return;
}

void reset(){
  int i, j;
  for(i=0; i<H; i++){
    for(j=0; j<W; j++){
      map2[i][j] = map[i][j];
    }
  }
}
