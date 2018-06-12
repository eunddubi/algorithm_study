#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0
#define CCTV1 1
#define CCTV2 2
#define CCTV3 3
#define CCTV4 4
#define CCTV5 5
#define WALL 6
#define MAX(X,Y) ((X)>=(Y)?X:Y)

int W, H;
int **map;
int **check;

void mark(int x, int y, int dir){//x,y = coordinates, dir = direction
  int x1 = x;
  int y1 = y;
  if(dir == 0){//up
    while(x1<H && x1>=0 && y1<W && y1>=0 && check[x1][y1] != WALL){
      check[x1][y1]++;
      x1--;
    }
  }else if(dir == 1){//down
    while(x1<H && x1>=0 && y1<W && y1>=0 && check[x1][y1] != WALL){
      check[x1][y1]++;
      x1++;
    }
  }else if(dir == 2){//left
    while(x1<H && x1>=0 && y1<W && y1>=0 && check[x1][y1] != WALL){
      check[x1][y1]++;
      y1--;
    }
  }else if(dir == 3){//right
    while(x1<H && x1>=0 && y1<W && y1>=0 && check[x1][y1] != WALL){
      check[x1][y1]++;
      y1++;
    }
  }
}

void monitor(int x, int y){
  int x1, y1;
  int cover[4] = {0,}; //0:up, 1:down, 2:left, 3:right
  int sum[4] = {0,};
  int max = 0;
  check[x][y]++;

  x1 = x-1; y1 = y;//up check
  while(x1<H && x1>=0 && y1<W && y1>=0 && check[x1][y1] != WALL){
    if(check[x1][y1] == EMPTY) cover[0]++;
    x1--;
  }

  x1 = x+1; y1 = y;//down check
  while(x1<H && x1>=0 && y1<W && y1>=0 && check[x1][y1] != WALL){
    if(check[x1][y1] == EMPTY) cover[1]++;
    x1++;
  }

  x1 = x; y1 = y-1;//left check
  while(x1<H && x1>=0 && y1<W && y1>=0 && check[x1][y1] != WALL){
    if(check[x1][y1] == EMPTY) cover[2]++;
    y1--;
  }

  x1 = x; y1 = y+1;//right check
  while(x1<H && x1>=0 && y1<W && y1>=0 && check[x1][y1] != WALL){
    if(check[x1][y1] == EMPTY) cover[3]++;
    y1++;
  }

  if(map[x][y] == CCTV5){
    mark(x,y,0);
    mark(x,y,1);
    mark(x,y,2);
    mark(x,y,3);
  }else if(map[x][y] == CCTV4){
    sum[0] = cover[1] + cover[2] + cover[3]; //except up
    sum[1] = cover[0] + cover[2] + cover[3]; //except down
    sum[2] = cover[0] + cover[1] + cover[3]; //except left
    sum[3] = cover[0] + cover[1] + cover[2]; //except right
    max = MAX(MAX(sum[0],sum[1]),MAX(sum[2],sum[3]));

    if(max == sum[0]){
      mark(x,y,1);
      mark(x,y,2);
      mark(x,y,3);
    }else if(max == sum[1]){
      mark(x,y,0);
      mark(x,y,2);
      mark(x,y,3);
    }else if(max == sum[2]){
      mark(x,y,0);
      mark(x,y,1);
      mark(x,y,3);
    }else if(max == sum[3]){
      mark(x,y,0);
      mark(x,y,1);
      mark(x,y,2);
    }
  }else if(map[x][y] == CCTV3){
    sum[0] = cover[0]+cover[3]; //up+right
    sum[1] = cover[1]+cover[3]; //down+right
    sum[2] = cover[1]+cover[2]; //down+left
    sum[3] = cover[0]+cover[2]; //up+left
    max = MAX(MAX(sum[0],sum[1]),MAX(sum[2],sum[3]));

    if(max == sum[0]){
      mark(x,y,0);
      mark(x,y,3);
    }else if(max == sum[1]){
      mark(x,y,1);
      mark(x,y,3);
    }else if(max == sum[2]){
      mark(x,y,1);
      mark(x,y,2);
    }else if(max == sum[3]){
      mark(x,y,0);
      mark(x,y,2);
    }
  }else if(map[x][y] == CCTV2){
    sum[0] = cover[0] + cover[1];
    sum[1] = cover[2] + cover[3];
    max = MAX(sum[0],sum[1]);

    if(max == sum[0]){
      mark(x,y,0);
      mark(x,y,1);
    }else if(max == sum[1]){
      mark(x,y,2);
      mark(x,y,3);
    }
  }else if(map[x][y] == CCTV1){
    max = MAX(MAX(cover[0],cover[1]),MAX(cover[2],cover[3]));
    if(max == cover[0]) mark(x,y,0);
    else if(max == cover[1]) mark(x,y,1);
    else if(max == cover[2]) mark(x,y,2);
    else if(max == cover[3]) mark(x,y,3);
  }
}

int main(){
  int i, j, k;
  int Answer = 0;
    scanf("%d %d", &H, &W);

    map = (int**)malloc(sizeof(int*)*H);
    check = (int**)calloc(H, sizeof(int*));
    for(i=0;i<H;i++){
      map[i] = (int*)malloc(sizeof(int)*W);
      check[i] = (int*)calloc(W, sizeof(int));
    }

    for(i=0;i<H;i++){
      for(j=0;j<W;j++){
        scanf("%d", &map[i][j]);
        if(map[i][j] == WALL) check[i][j] = WALL;
      }
    }

    for(k=5; k>0;k--){
      for(i=0;i<H;i++){
        for(j=0;j<W;j++) if(map[i][j] == k) monitor(i,j);
      }
    }

    for(i=0;i<H;i++){
      printf("check[%d] =", i);
      for(j=0;j<W;j++){
        printf(" %d",check[i][j]);
      }
      printf("\n");
    }

    for(i=0;i<H;i++){
      for(j=0;j<W;j++) if(check[i][j] == EMPTY) Answer++;
    }

    for(i=0;i<H;i++){
      free(map[i]);
      free(check[i]);
    }
    free(map);
    free(check);

    printf("%d", Answer);
    return 0;
}
