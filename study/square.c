#include <stdio.h>

int ary[5][5] = {0};
int i = 0, j = 0;
int w = 0, h = 0, tmp = 0;
int max = 0;

int main(){
  ary[0] = {0,0,1,0,1};
  ary[1] = {1,0,1,1,1};
  ary[2] = {1,1,1,1,1};
  ary[3] = {1,1,0,1,0};
  ary[4] = {0,1,0,1,1};

  for(i=0;i<5;i++){
    for(j=0;j<5;j++){
      if(ary[i][j] == 1 && ary[i][j+1] == 1){
        w = check_width(i,j);
        h = check_height(i,j);
        tmp = check_square(i,j,w,h);
        if(max < tmp){
          max = tmp;
        }
      }
    }
  }

}

int check_width(int x, int y){
  int cnt = 1;
  while(ary[x][y] != 0){
    if(ary[x][y++] == 1){
      cnt++;
    }
  }
  return cnt;
}

int check_height(int x, int y){
  int cnt = 1;
  while(ary[x][y] != 0){
    if(ary[x++][y] == 1){
      cnt++;
    }
  }
  return cnt;
}

int check_square(int x, int y, int w, int h){

}
