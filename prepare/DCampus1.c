#include <stdio.h>
#include <stdlib.h>
#define MIN(X,Y) (((X)<(Y))?X:Y)

int Answer;

int main(void)
{
	int T, test_case;
  int nod, link;
  int ary[1001][1001] ={0, };
  int check[1001][1001]={0, };
  int result[1001]={0, };
  int sum;
  int i, j, k;
  int x, y, z;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
    sum = 0;
    scanf("%d %d", &nod, &link);

    for(i=0;i<link;i++){
      scanf("%d %d %d", &x, &y, &z);
      ary[x-1][y-1] = z;
      ary[y-1][x-1] = z;
    }

    for(k=0;k<nod;k++){
      for(i=0;i<nod;i++){
        for(j=0;j<nod;j++){
          if(i<j){
            if(i!=j&&ary[i][j]==0&&ary[i][k]&&ary[k][j]){
              ary[i][j] = ary[i][k]+ary[k][j];
              //ary[j][i] = ary[i][k]+ary[k][j];
              check[i][j] = k+1;
              //check[j][i] = k+1;
            }else if(i!=j&&ary[i][j]&&ary[i][k]&&ary[k][j]){
              if(ary[i][j]>ary[i][k]+ary[k][j]){
                check[i][j] = k+1;
                //check[j][i] = k+1;
              }
              ary[i][j] = MIN(ary[i][j],ary[i][k]+ary[k][j]);
              //ary[j][i] = MIN(ary[i][j],ary[i][k]+ary[k][j]);
            }
          }
        }
      }
    }


//     for(i=0;i<nod;i++){
//       printf("ary[%d] =", i);
//       for(j=0;j<nod;j++){
//         printf(" %d",ary[i][j]);
//       }
//       printf("\n");
//     }
printf("----------------\n");
    for(i=0;i<nod;i++){
      printf("check=[%d] =", i);
      for(j=0;j<nod;j++){
        printf(" %d",check[i][j]);
      }
      printf("\n");
    }

    for(i=0;i<nod;i++){
      for(j=0;j<nod;j++){
        if(i<j){
          if(check[i][j]){
            result[(check[i][j])]++;
          }
        }
      }
    }

    for(i=1;i<=nod;i++){
      if(result[i]==0)sum++;
    }

		printf("Case #%d\n", test_case+1);
    printf("%d",sum);
    for(i=1;i<=nod;i++){
      if(result[i] == 0){
        printf(" %d",i);
      }
    }


	}
	return 0;//Your program should return 0 on normal termination.
}
