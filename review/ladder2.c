#include <stdio.h>
#include <stdlib.h>

int N, M, H;
int** map;
void play();
int compare();

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



return 0;
}

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
