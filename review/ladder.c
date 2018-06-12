#include <stdio.h>
#include <stdlib.h>

int N, M, H;
int** map;

int compare(){
  int i = 0;
  for(i=0;i<N;i++){
    if(map[0][i] != map[H+1][i]){
      return 0;
    }else{
      continue;
    }
  }
  return 1;
}

void play(){
  int i, j;
  int x, y;
  int stone;

  x=0; y=0;
  for(i=0;i<N;i++){
    stone = map[0][i];
    x=1; y=i;
    while(x <= H){
      if(map[x][y] == 0){
        x++;
      }else if(map[x][y] == 1){
        x++;
        y++;
        stone += 1;
      }else if(map[x][y] == -1){
        x++;
        y--;
        stone -= 1;
      }
    }
    map[H+1][stone-1] = i+1;
  }
}

int main(){

  int i, j;
  int x, y;
  int res;

  scanf("%d %d %d", &N, &M, &H);
  map = (int**)calloc((H+2), sizeof(int*));
  for(i=0;i<H+2;i++){
    map[i] = (int*)calloc(N, sizeof(int));
  }

  for(i=0;i<N;i++){
    map[0][i] = i+1;
  }

  for(i=0;i<M;i++){
    scanf("%d %d", &x, &y);
    map[x][y-1] = 1;
    map[x][y] = -1;
  }

  play();
  for(i=0;i<H+2;i++){
    printf("map[%d] =",i);
    for(j=0;j<N;j++){
      printf(" %2d",map[i][j]);
    }
    printf("\n");
  }

  res = compare();
  if(res == 1){
    printf("correspond\n");
  }else if(res == 0){
    printf("not correspond\n");
  }

  for(i=0;i<H+2;i++){
    free(map[i]);
  }
  free(map);
  return 0;
}
