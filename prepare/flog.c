#include <stdio.h>
#include <stdlib.h>

int Answer = 0;

int main(void)
{
	int T, test_case;
  int stone = 0;
  int *stones;
  long K = 0;
  int i = 0, now = 0;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
    scanf("%d", &stone);
    stones = (int *)malloc(sizeof(int) * stone);
    for(i=0; i<stone; i++){
      scanf("%d", &stones[i]);
    }
    scanf("%ld", &K);

    for(i=0; i<stone; i++){
      if(stones[i+1]-stones[i] > K){
        Answer = -1;
      }
    }

    i=0;

    while(Answer != -1){
      if(stones[i] <= now+K){
        i++;
      }else if(stones[i] > now+K){
        now = stones[i-1];
        Answer++;
        i++;
      }
      if(now+K == stones[stone-1]){
        Answer++;
        break;
      }else if(now+K > stones[stone-1]){
        Answer++;
        break;
      }
    }

    printf("Case #%d\n", test_case+1);
    printf("%d\n", Answer);
	}

  free(stones);
	return 0;//Your program should return 0 on normal termination.
}
