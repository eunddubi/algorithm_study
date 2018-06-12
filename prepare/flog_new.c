#include <stdio.h>
#include <stdlib.h>

int Answer;

int main(void)
{
	int T, test_case;
  int stone;
  int *stones;
  int K;
  int i, j, now;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
    scanf("%d", &stone);
    stones = (int *)malloc(sizeof(int) * (stone+2));
    for(i=1; i<=stone; i++){
      scanf("%d", &stones[i]);
    }
    scanf("%d", &K);
    stones[0] = 0;
    stones[i] = 2000000001;

    i=0; j = 0; Answer=0;

    while(now < stones[stone+1]){
      now = j;
      while(stones[now]<= i+K) now++;
      now--;
      if(now == j){
        Answer = -1;
        break;
      }
      Answer++;
      j = now;
      i = stones[j];
      if(stones[now] == stones[stone]) break;
    }

    printf("Case #%d\n", test_case+1);
    printf("%d\n", Answer);
	}

  free(stones);
	return 0;//Your program should return 0 on normal termination.
}
