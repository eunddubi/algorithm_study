#include <stdio.h>

int Answer = 0;
int walk(int A, int B, int D);

int main(void)
{
	int T, test_case;
  int A=0, B=0, D=0;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
    scanf("%d %d %d", &A, &B, &D);
    //Answer = (D-A)/(A-B)+1;
    //if((D-A)%(A-B) != 0) Answer++;
    Answer = walk(A,B,D);

		printf("Case #%d\n", test_case+1);
    printf("%d\n", Answer);
	}
	return 0;//Your program should return 0 on normal termination.
}

int walk(int A, int B, int D){
  int result = 0;
  while(D > 0){
    if(D - A <= 0){
      result++;
      break;
    }else{
      D = D - A + B;
      result++;
    }
  }
  return result;
}
