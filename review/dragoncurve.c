#include <stdio.h>
#define MAX 101

int map[MAX][MAX] ={0,};
int trace[1024] ={0,};
int N;

typedef struct dragon{
  int x;
  int y;
  int d;
  int g;
}dragon;
dragon line[20];

int dragon_count(){
  int nemo = 0;
  int i, j;

  for(i=0; i<MAX; i++){
    for(j=0; j<MAX; j++){
      if(map[i][j]){
        if(map[i+1][j] && map[i][j+1] && map[i+1][j+1]){
          nemo++;
        }
      }
    }
  }
  return nemo;
}

void dragon_paint(int x, int y, int g){
  int i, len=1;
  for(i=0;i<g;i++){
    len *= 2;
  }
  map[y][x]++;
  for(i=0;i<len;i++){
    if(trace[i] == 0)       x++;
    else if(trace[i] == 1)  y--;
    else if(trace[i] == 2)  x--;
    else if(trace[i] == 3)  y++;
    map[y][x]++;
  }
}

void dragon_trace(int g){
  int i,j,len =1;
  int local_g = 1;
  while(local_g <= g){
    for(i=0;i<local_g;i++){
      len*=2;
    }
    i = len/2;
    j = i-1;

    while(j>=0){
      if(trace[j] == 0)        trace[i] = 1;
      else if(trace[j] == 1)   trace[i] = 2;
      else if(trace[j] == 2)   trace[i] = 3;
      else if(trace[j] == 3)   trace[i] = 0;
      j--; i++;
    }
    len = 1;
    local_g++;
  }
}

int main(){
  int i;
  int answer = 0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d %d %d %d", &line[i].x, &line[i].y, &line[i].d, &line[i].g);
  }

  for(i=0;i<N;i++){
    trace[0] = line[i].d;
    if(line[i].g != 0){
      dragon_trace(line[i].g);
    }
    dragon_paint(line[i].x, line[i].y, line[i].g);
  }
  answer = dragon_count();
  printf("%d\n", answer);
  return 0;
}
