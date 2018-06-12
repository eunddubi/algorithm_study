#include <stdio.h>

int stone[1000002];

int main(void) {

	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int T;
	int test_case;
	int i, j, k, n, a, solution;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &n);
		stone[0] = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &stone[i]);
		}
		stone[i] = 2000000001;
		scanf("%d", &k);

		i = 0;
		j = 0;
		solution = 0;
		while (i < stone[n])
		{
			a = j;
			while (stone[a] <= i + k) a++;
			a--;
			if (a == j)
			{
				solution = -1;
				break;
			}
			solution++;
			j = a;
			i = stone[j];
		}
		printf("Case #%d\n%d\n", test_case, solution);
	}

	return 0;
}
