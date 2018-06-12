/*
 * BaekJoon14502_Lab&Virus.c
 *
 *  Created on: 2018. 5. 29.
 *      Author: maroro
 */
/*
인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다. 다행히 바이러스는 아직 퍼지지 않았고, 바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.
연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다. 연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다.
일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다. 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.

입력
첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)
둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.
빈 칸의 개수는 3개 이상이다

출력
첫째 줄에 얻을 수 있는 안전 영역의 최대 크기를 출력한다.
*/
#include<stdio.h>
#include<stdlib.h>
#define WALL 3
typedef struct Point{
   int x;
   int y;
}Point;
Point vir[10];
Point wall[59];
Point walltmp[3];
Point space[62];
int w, v, s, max;
int **lab;
int **test;
int N,M;

void Move(int X,int Y){//바이러스 퍼지는거
   if((X<0) || (X>=M) || (Y<0) || (Y>=N) || test[Y][X]==1 ||test[Y][X]==3){
      return ;
   }
   else{
      if(test[Y][X]==0 || test[Y][X]==2){
         test[Y][X]=3;
      }
      else if(test[Y][X]==3){
         return ;
      }
         Move(X+1,Y);
         Move(X,Y+1);
         Move(X-1,Y);
         Move(X,Y-1);
         return ;
   }
}

void Reset(){
   for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
         test[i][j]=lab[i][j];
      }
   }
}

int Calc(){//empty 세주는 거
   int tmp=0;
   for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
         if(test[i][j]==0){
            tmp++;
         }
      }
   }
   if(tmp>max){
      max=tmp;
   }
   return 0;
}

void Wall(int cnts, int three){//make wall method
   if(cnts>s){
      return ;
   }
   else if(cnts==s && three==WALL){
      for(int i=0;i<three;i++){
         test[walltmp[i].y][walltmp[i].x]=1;
      }
      for(int a=0;a<v;a++){
         Move(vir[a].x,vir[a].y);
      }
      Calc();
      Reset();
   }
   if(three<WALL){
      walltmp[three].x=space[cnts].x;
      walltmp[three].y=space[cnts].y;
      Wall(cnts+1,three+1);
   }
   Wall(cnts+1,three);
}

int main(){
   scanf("%d %d",&N, &M);
   fflush(stdout);
   lab=(int**)calloc(N,sizeof(int*));
   test=(int**)calloc(N,sizeof(int*));
   for(int i=0;i<N;i++){
      lab[i]=(int*)calloc(M,sizeof(int));
      test[i]=(int*)calloc(M,sizeof(int));
   }
   for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
         scanf("%d",&lab[i][j]);
         if(lab[i][j]==1){
            wall[w].x=j;
            wall[w].y=i;
         }
         else if (lab[i][j]==2){
            vir[v].x=j;
            vir[v].y=i;
            v++;
         }
         else if (lab[i][j]==0){
            space[s].x=j;
            space[s].y=i;
            s++;
         }
      }
   }

   Reset();
   Wall(0,0);

   printf("%d",max);
   for(int i=0;i<N;i++){
      free(lab[i]);
      free(test[i]);
   }
   free(lab);
   free(test);
   return 0;
}
