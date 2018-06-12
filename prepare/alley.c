#include <stdio.h>
#include <stdlib.h>
#define MAX(X,Y) (((X)>(Y))?X:Y)
#define INF -1

int main() {
	int nod, link;
	int i, j, k;
	int x, y, z;
	int **ary;
	int **road;
	int result[100] = {0};
	scanf("%d %d", &nod, &link);

	ary = (int **)calloc(nod, sizeof(int*));
	for (i = 0; i < nod; i++) {
		ary[i] = (int*)calloc(nod, sizeof(int));
	}
	road = (int **)calloc(nod, sizeof(int*));
	for (i = 0; i < nod; i++) {
		road[i] = (int*)calloc(nod, sizeof(int));
	}

	for (i = 0; i < nod; i++) {
		for (j = 0; j < nod; j++) {
			ary[i][j] = INF;
		}
	}

	for (i = 0; i < link; i++) {
		scanf("%d %d %d", &x, &y, &z);
		ary[x-1][y-1] = z;
	}

	printf("-----------first value--------\n");
	for (i = 0; i < nod; i++) {
		printf("ary[%d]", i);
		for (j = 0; j < nod; j++) {
			printf("%d ", ary[i][j]);
		}
		printf("\n");
	}
	printf("-----------first value--------\n");




	for (k = 0; k < nod; k++)
		for (i = 0; i < nod; i++)
			for (j = 0; j < nod; j++) {
				if (i != j && ary[i][j] == INF && ary[i][k] != INF && ary[k][j] != INF) {
					ary[i][j] = ary[i][k] + ary[k][j];
					road[i][j] = k;
				}
				else if (i != j && ary[i][j] != INF && ary[i][k] != INF && ary[k][j] != INF) {
					if(ary[i][j] < ary[i][k] + ary[k][j]){
						road[i][j] = k;
					}
					ary[i][j] = MAX(ary[i][j], ary[i][k] + ary[k][j]);
				}
			}

			result[0] = 1;

			printf("-------------------\n");
			for (i = 0; i < nod; i++) {
				printf("ary[%d]", i);
				for (j = 0; j < nod; j++) {
					printf("%d ", ary[i][j]);
				}
				printf("\n");
			}
			printf("-------------------\n");


	printf("-------------------\n");
	for (i = 0; i < nod; i++) {
		printf("road[%d]", i);
		for (j = 0; j < nod; j++) {
			printf("%d ", road[i][j]);
		}
		printf("\n");
	}
	printf("-------------------\n");

	for(i=1;i<nod;i++){
		result[(road[0][i])+1] = i+1;
	}

	if(ary[0][nod-1] == INF){
		printf("%d", -1);
	}else{
		printf("%d",result[i]+1);
		i=1;
		while(result[i] != 0){
			printf(" %d",result[i++]);
		}
	}


	return 0;

}
