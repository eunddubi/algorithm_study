#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0
#define WALL 1
#define VIRUS 2
#define PRE 3

int N, M;
int **map, **map2;
int safe;
void infected();
void defend(int x, int y, int n);
int check();
void reset();
int max = 0;

int main(){
  int i, j, k;
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
    }
  }

  //defend
  defend();
  //infected
  //check safe area

  infected();
  i = check();
  printf("safe area = %d\n",i);

  for(i=0;i<N;i++){
    free(map[i]);
    free(map2[i]);
  }
  free(map);
  free(map2);

  return 0;
}

void infected(){
  int i, j;

  for(i=0; i<N; i++){
    for(j=0; j<M; j++){
      if(map[i][j] == VIRUS){
        if(i-1 >= 0 && map[i-1][j] == EMPTY)map[i-1][j] = PRE;
        if(j-1 >= 0 && map[i][j-1] == EMPTY)map[i][j-1] = PRE;
        if(i+1 < N && map[i+1][j] == EMPTY)map[i+1][j] = PRE;
        if(j+1 < M && map[i][j+1] == EMPTY)map[i][j+1] = PRE;
      }
    }
  }

  for(i=0;i<N;i++){
    for(j=0;j<M;j++){
      if(map[i][j] == PRE) map[i][j] = VIRUS;
    }
  }
}

void infectcell(int x, int y){
  if(x < 0 || x >= N || y < 0 || y >= M) return;
  else if(map[x][y] == WALL) return;
  else{
    //map[x][y] =
  }
}

int check(){//블롭 체크 하는걸로
  int i, j, answer = 0;
  for(i=0;i<N;i++){
    for(j=0;j<M;j++){
      if(map[i][j] == EMPTY) answer++;
    }
  }
  return answer;
}

void defend(int x, int y, int n){
  int i, j;
  int tmp;
  if(n>0){
    for(i=x;i<N;i++){
      for(j=(i == x ? y : 0); j<M; j++){
        if(map[i][j] == EMPTY){
          map[i][j] == 4;
          defend(i,j+1,n-1);
          if(n==1){
            tmp = check();
            max = (max>tmp ? max : tmp);
          }
        }
      }
    }
  }
}

void reset(){
  int i,j;
  for(i=0;i<N;i++){
    for(j=0;j<M;j++){
      map2[i][j] = map[i][j];
    }
  }
}
