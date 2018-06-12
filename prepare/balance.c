#include <stdio.h>

int Answer;

int devide(int c, int d){
  int tmp;
  tmp = c%d;

  while(c > 0){
    if(tmp == c%d){
      c /= d;
    }else{
      return 0; // is not uniform number
    }
  }
  return 1; //is uniform number
}

int main(void)
{
	int T, test_case;
  int X;
  int a;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
    scanf("%d", &X);
    for(a=2;a<=X;a++){
      if(devide(X,a)){
        Answer = a;
        break;
      }
    }

		printf("Case #%d\n", test_case+1);
    printf("%d\n", Answer);
	}
	return 0;//Your program should return 0 on normal termination.
}
