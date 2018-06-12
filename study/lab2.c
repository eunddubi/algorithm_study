#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0
#define WALL 1
#define VIRUS 2
#define PRE 3
#define WALLMAX 3

int N, M;
int **map, **map2;
typedef struct point{
  int x;
  int y;
}point;
point virus[10];
point sidewall[3];
point empty[62];
int v, e, max;
void make_wall(int empty_space, int walls);
void infected(int x, int y);
void check_max();
void reset();

int main(){
  int i, j;
  v = 0; e = 0; max = 0;
  scanf("%d %d", &N, &M);
  map = (int**)malloc(sizeof(int*)*N);
  map2 = (int**)malloc(sizeof(int*)*N);
  for(i=0;i<N;i++){
    map[i] = (int*)malloc(sizeof(int)*M);
    map2[i] = (int*)malloc(sizeof(int)*M);
  }
  for(i=0;i<N;i++){
    for(j=0;j<M;j++){
      scanf("%d", &map[i][j]);
      if(map[i][j] == VIRUS){
        virus[v].x = i;
        virus[v].y = j;
        v++;
      }else if(map[i][j] == EMPTY){
        empty[e].x = i;
        empty[e].y = j;
        e++;
       }
    }
  }
  reset();
  make_wall(0,0);

  printf("%d",max);

  for(i=0;i<N;i++){
    free(map[i]);
    free(map2[i]);
  }
  free(map);
  free(map2);

  return 0;
}

void infected(int x, int y){
  if(x<0 || x>=N || y<0 || y>=M || map2[x][y] == WALL || map2[x][y] == PRE){
    return;
  }else{
    if(map2[x][y] == EMPTY || map2[x][y] == VIRUS){
      map2[x][y] = PRE;
    }else if(map[x][y] == PRE){
      return;
    }
    infected(x+1, y);
    infected(x, y+1);
    infected(x-1, y);
    infected(x, y-1);
    return;
  }
}

void check_max(){
  int tmp = 0;
  int i, j;

  for(i=0;i<N;i++){
    for(j=0;j<M;j++){
      if(map2[i][j] == EMPTY) tmp++;
    }
  }

  if(tmp>max) max = tmp;
  return;
}

void make_wall(int empty_space, int walls){
  int i;
  if(empty_space > e) return ;
  else if(empty_space == e && walls == WALLMAX){
    for(i=0; i<walls; i++){
      map2[sidewall[i].x][sidewall[i].y] = WALL;
    }
    for(i=0;i<v;i++){
      infected(virus[i].x,virus[i].y);
    }
    check_max();
    reset();
  }
  if(walls < WALLMAX){
    sidewall[walls].x = empty[empty_space].x;
    sidewall[walls].y = empty[empty_space].y;
    make_wall(empty_space+1, walls+1);
  }
  make_wall(empty_space+1, walls);
}

void reset(){
  int i,j;
  for(i=0;i<N;i++){
    for(j=0;j<M;j++){
      map2[i][j] = map[i][j];
    }
  }
}
