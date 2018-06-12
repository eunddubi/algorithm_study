#include <stdio.h>
#include <stdlib.h>
#define MIN(X,Y) (((X)<(Y))?X:Y)

int main() {

	int computer, link;
	int r1, r2;
	int i, j, k;
	int ** ary;
	int result;

	scanf("%d", &computer);
	scanf("%d", &link);

	ary = (int**)calloc(computer, sizeof(int*));
	for (i = 0; i < computer; i++) {
		ary[i] = (int*)calloc(computer, sizeof(int));
	}

	for (i = 0; i < link; i++) {
		scanf("%d %d", &r1, &r2);
		ary[r1-1][r2-1] = 1;
		ary[r2-1][r1-1] = 1;
	}

	for(k=0;k<computer;k++)
		for(i=0;i<computer;i++)
			for (j = 0; j < computer; j++) {
				if (i != j && ary[i][j] == 0 && ary[i][k] && ary[k][j]) {
					ary[i][j] = ary[i][k] + ary[k][j];
				}
				else if (i != j && ary[i][j] && ary[i][k] && ary[k][j]) {
					ary[i][j] = MIN(ary[i][j], ary[i][k] + ary[k][j]);
				}
			}

	for (i = 1; i < computer; i++) {
		if (ary[0][i]) {
			result++;
		}
	}

	printf("%d", result);
}
