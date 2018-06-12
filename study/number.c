#include <stdio.h>
#include <stdlib.h>

int Answer;

int main(void)
{
	int T, test_case;
  int N;
  int *input;
  int temp;
  int i;
	Answer = -1;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{

    scanf("%d", &N);
    input = (int*) malloc(sizeof(int) * N);

    for(i=0;i<N;i++){
      scanf("%d", &input[i]);
			if(i==0){
				Answer = input[i];
			}else{
				Answer ^= input[i];
			}
    }

		printf("Case #%d\n", test_case+1);
    printf("%d\n", Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}
