/*상근이는 빈 공간과 벽으로 이루어진 건물에 갇혀있다.
건물의 일부에는 불이 났고, 상근이는 출구를 향해 뛰고 있다.
매 초마다, 불은 동서남북 방향으로 인접한 빈 공간으로 퍼져나간다.
벽에는 불이 붙지 않는다. 상근이는 동서남북 인접한 칸으로 이동할 수 있으며, 1초가 걸린다.
상근이는 벽을 통과할 수 없고, 불이 옮겨진 칸 또는 이제 불이 붙으려는 칸으로 이동할 수 없다.
상근이가 있는 칸에 불이 옮겨옴과 동시에 다른 칸으로 이동할 수 있다.
빌딩의 지도가 주어졌을 때, 얼마나 빨리 빌딩을 탈출할 수 있는지 구하는 프로그램을 작성하시오.

첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스는 최대 100개이다.
각 테스트 케이스의 첫째 줄에는 빌딩 지도의 너비와 높이 w와 h가 주어진다. (1 ≤ w,h ≤ 1000)
다음 h개 줄에는 w개의 문자, 빌딩의 지도가 주어진다.
'.': 빈 공간
'#': 벽
'@': 상근이의 시작 위치
'*': 불
각 지도에 @의 개수는 하나이다.

각 테스트 케이스마다 빌딩을 탈출하는데 가장 빠른 시간을 출력한다. 빌딩을 탈출할 수 없는 경우에는 "IMPOSSIBLE"을 출력한다.*/

#include <stdio.h>
#include <stdlib.h>

const char EMPTY = '.';
const char WALL  = '#';
const char NOW   = '@';
const char FIRE  = '*';
const char SPARK = '-';

int T = 0, test_case = 0;
char **map = NULL;
int w = 0, h = 0, i = 0;
int x =0, y =0;
int result = 0;

int escape(char** map);

int main(){
  scanf("%d", &test_case);

  for(T=0; T<test_case; T++){
    scanf("%d %d",&w, &h);

    map = (char **) malloc(sizeof(char*) * h);
    for(i = 0; i < h; i++){
      map[i] = (char *) malloc(sizeof(char) * (w+1));
    }

    for(i=0; i<h; i++){
      scanf("%s", map[i]);
    }

    result = escape(map);
    for(i=0; i<h; i++){
      printf("%s\n", map[i]);
    }



    for(i = 0; i < h; i++){
      free(map[i]);
    }
    free(map);
  }

  return 0;
}

int escape(char **map){
  int distance = 0;
  int w = 0, h = 0; //넓이, 높이
  int i = 0, j = 0; //for문 이용하기 위한 index
  int x = 0, y = 0; //현재위치

  h = sizeof(map)/sizeof(map[0]);
  w = sizeof(map[0])/sizeof(char);

  for(i = 0; i < h; i++){ //위치 파악
    for(j = 0; j < w; j++){
      if(map[i][j] == NOW){
        x = i; y = j;
      }
    }
  }

  for(i = 0; i < h; i++){ //불 처리
    for(j = 0; j < w; j++){
      if(map[i][j] == FIRE){
        burn(map, i, j);
      }else if(map[i][j] == SPARK){
        map[i][j] = FIRE;
      }
    }
  }

  if(x>=0 && y>0 && x<=h && y <=w){

  }else{

  }
}

int burn(char **map, int x, int y){
  if(x>=0 && y>0 && x<=h && y <=w){
    if(map[x-1][y] == EMPTY || map[x-1][y] == NOW){ //상
      map[x-1][y] = SPARK;
    }

    if(map[x][y+1] == EMPTY || map[x][y+1] == NOW){ //우
      map[x][y+1] = SPARK;
    }

    if(map[x+1][y] == EMPTY || map[x+1][y] == NOW){ //하
      map[x+1][y] = SPARK;
    }

    if(map[x][y-1] == EMPTY || map[x][y-1] == NOW){ //좌
      map[x][y-1] = SPARK;
    }
  }
}
