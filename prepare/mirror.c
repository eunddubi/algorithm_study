#include <stdio.h>
#include <stdlib.h>
#define LEFT '1'
#define TOP '2'
#define RIGHT '3'
#define DOWN '4'
int Answer;

int main(void)
{
	int T, test_case;
  int N,i,j,x,y;
  char dir;
  char ** room;
  char ** check;
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		N=0;i=0;j=0;x=0;y=0; dir=LEFT;
    scanf("%d", &N);
    room = (char **) malloc(sizeof(char*)*N);
    for(i=0;i<N;i++){
      room[i] = (char *) malloc(sizeof(char)*(N+1));
    }

    check = (char **) calloc(N, sizeof(char*));
    for(i=0;i<N;i++){
      check[i] = (char *) calloc(N, sizeof(char));
    }

		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				check[i][j] = '0';
			}
		}

    for(i=0;i<N;i++){
      scanf("%s", room[i]);
    }

    x=0, y=0;

    while(x>=0 && y>=0 && x<N && y<N){
      if(room[x][y] == '0'){ //empty space
        if(dir == LEFT)y++;
        else if(dir == TOP) x++;
        else if(dir == RIGHT) y--;
        else if(dir == DOWN)x--;
      }else if(room[x][y]=='1'){
        if(dir == LEFT){
          if(check[x][y] != '1'){
            check[x][y] = '1';
            Answer++;
          }
          x--;
          dir = DOWN;
        }
        else if(dir == TOP){
          if(check[x][y] != '1'){
            check[x][y] = '1';
            Answer++;
          }
          y--;
          dir = RIGHT;
        }
        else if(dir == RIGHT){
          if(check[x][y] != '1'){
            check[x][y] = '1';
            Answer++;
          }
          x++;
          dir = TOP;
        }
        else if(dir == DOWN){
          if(check[x][y] != '1'){
            check[x][y] = '1';
            Answer++;
          }
          y++;
          dir = LEFT;
        }
      }else if(room[x][y] == '2'){
        if(dir == LEFT){
          if(check[x][y] != '1'){
            check[x][y] = '1';
            Answer++;
          }
          x++;
          dir = TOP;
        }else if(dir == TOP){
          if(check[x][y] != '1'){
            check[x][y] = '1';
            Answer++;
          }
          y++;
          dir = LEFT;
        }
        else if(dir == RIGHT){
          if(check[x][y] != '1'){
            check[x][y] = '1';
            Answer++;
          }
          x--;
          dir = DOWN;
        }
        else if(dir == DOWN){
          if(check[x][y] != '1'){
            check[x][y] = '1';
            Answer++;
          }
          y--;
          dir = RIGHT;
        }
      }
    }
		for(i=0;i<N;i++){
			free(room[i]);
			free(check[i]);
		}
		free(room);
		free(check);
		printf("Case #%d\n", test_case+1);
    printf("%d\n", Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}
