#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0
#define HOUSE 1
#define SHOP 2
#define MIN(X,Y) ((X<Y)?X:Y)

int N, M;
int **map;
int shop_num=0;
int list[13][4] ={0,};//0:shop_num, 1: x, 2:y, 3:shop distance

void delete_shop(){
  int max = 0;
  int i, j;
  for(i=0;i<shop_num;i++){
    if(max < list[i][4]){
      max = list[i][4];
    }
  }

  for(i=0;i<shop_num;i++){
    if(list[i][4] == max){
      map[(list[i][1])][(list[i][2])] = 0;
      shop_num--;
    }
  }
}

int cal_dis(int x, int y){
  int sum = 0;
  int i, j;

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(map[i][j] == HOUSE){
        sum += abs(i-x) + abs(j-y);
      }
    }
  }
  return sum;
}

int main(){
  int i, j;
  int delete;
  scanf("%d %d", &N, &M);
  map = (int**)malloc(N*sizeof(int*));
  for(i=0;i<N;i++){
    map[i] = (int*)malloc(N*sizeof(int));
  }

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      scanf("%d", &map[i][j]);
      if(map[i][j] == SHOP){
        list[shop_num][0] = shop_num;
        list[shop_num][1] = i;
        list[shop_num][2] = j;
        shop_num++;
      }
    }
  }

  delete = shop_num-M;

  for(i=0;i<shop_num;i++){
    list[i][3] = cal_dis(list[i][1], list[i][2]);
  }


  if(M != delete){
    for(i=0;i<delete;i++){
      delete_shop();
    }
  }

  for(i=0;i<N;i++){
    free(map[i]);
  }
  free(map);
  return 0;
}
