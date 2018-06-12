#include <stdio.h>
#include <stdlib.h>

int N, M, H;
int** map;
int** map2;
int Answer = 0;
void play();
int compare();
void bridge();
void reset();
void print_l();

int main(){
  int i, j;
  int x, y;
  int res;

  scanf("%d %d %d", &N, &M, &H);
  map = (int**)calloc((H+2), sizeof(int*));
  map2 = (int**)calloc((H+2), sizeof(int*));
  for(i=0;i<H+2;i++){
    map[i] = (int*)calloc(N, sizeof(int));
    map2[i] = (int*)calloc(N, sizeof(int));
  }

  for(i=0;i<N;i++){
    map[0][i] = i+1;
  }

  for(i=0;i<M;i++){
    scanf("%d %d", &x, &y);
    map[x][y-1] = 1;
    map[x][y] = -1;
  }
  reset();
  play();

  bridge();

  //print_l();
  //사다리 하나씩 추가하면서 완전탐색하기.


  printf("Answer = %d\n", Answer);
  return 0;
}

//재귀 문제 해결하기
void bridge(){
 int ans=0;
 int i, j;

 for(i=1;i<H+1;i++){
   for(j=0;j<N;j++){
     if(map2[i][j] == 0 && map2[i][j+1] == 0){
       map2[i][j] = 1;
       map2[i][j+1] = -1;
       play();
       if(compare()){
         Answer++;
         return;
       }else{
         map2[i][j] = 0;
         map2[i][j+1] = 0;
       }
     }
   }
 }
}

int compare(){
  int i = 0;
  for(i=0;i<N;i++){
    if(map2[0][i] != map2[H+1][i]){
      return 0;
    }else{
      continue;
    }
  }
  return 1;
}

void reset(){
  int i, j;
  for(i=0;i<H;i++){
    for(j=0;j<N;j++){
      map2[i][j] = map[i][j];
    }
  }
}

void play(){
  int i, j;
  int x, y;
  int stone;

  x=0; y=0;
  for(i=0;i<N;i++){
    stone = map2[0][i];
    x=1; y=i;
    while(x <= H){
      if(map2[x][y] == 0){
        x++;
      }else if(map2[x][y] == 1){
        x++;
        y++;
        stone += 1;
      }else if(map2[x][y] == -1){
        x++;
        y--;
        stone -= 1;
      }
    }
    map2[H+1][stone-1] = i+1;
  }
}

void print_l(){
  int i, j;
  for(i=0;i<H+2;i++){
    for(j=0;j<N;j++){
      printf(" %2d",map2[i][j]);
    }
    printf("\n");
  }
}
