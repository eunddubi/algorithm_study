#include <stdio.h>

int Answer;

int main(void)
{
	int T, test_case;
	int input, power, tmp;
	int i,j,k;
	int flag = 0;
	int ary[100];
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		scanf("%d", &input);
		i = 2;
		if(i == input){
			Answer = 3;
		}
		while(i != input){
			power = i;
			tmp = input;
			j = 0;

			while(tmp/power != 0){
				ary[j++] = tmp % power;
				tmp /= power;
			}
			ary[j] = tmp;
			for(k=0;k<=j;k++){
				if(ary[k] == tmp){
					if(k == j){
						flag = 1;
					}
					continue;
				}else{
					break;
				}
			}
			if(flag == 1) break;
			i++;
		}
		Answer = i;
		printf("Case #%d\n", test_case+1);
    printf("%d\n", Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}
