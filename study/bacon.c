#include <stdio.h>
#include <stdlib.h>

int people, relationship;
int **ary;
int *temp;

int relationship_check(int a, int b){
  int result = 0;
  int i,j;
  temp[a] = 1;

  if(a == b){
    return 0;
  }else{
    if(ary[a][b] == 1){
      return 1;
    }else{
      for(i=0;i<people;i++){
        //그 레벨에서 b와 관계있는 애가 있니?
        //없으면 다음단계로 가서 관계 있는 애가 있니?
        //있으면
      }
    }
  }
}

int bacon_check(int person){
  int bacon=0;
  int i, j,k;

  for(i=0; i<people; i++){
    if(i != person){
      bacon += relationship_check(person, i);
    }
  }
  for(i=0;i<people;i++){
    printf("ary[%d] = ",i);
    for(j=0;j<people;j++){
      printf("%d ",ary[i][j]);
    }
    printf("\n");
  }
  for(k=0;k<sizeof(temp)/sizeof(int);k++) {
    temp[k] = 0;
  }
  return bacon;
}

int main(){
  int r1, r2;
  int i, j, k;
  int tmp = -1;
  int min = 0;

  scanf("%d %d", &people, &relationship);

  ary = (int **)calloc(people, sizeof(int*));
  for(i=0; i<people; i++){
    ary[i] = (int *) calloc(people, sizeof(int));
  }
  temp = (int*)calloc(people,sizeof(int));

  for(i=0;i<relationship;i++){
    scanf("%d %d", &r1, &r2);
    ary[r1-1][r2-1] = 1;
    ary[r2-1][r1-1] = 1;
  }
  //
  // for(i=0;i<people;i++){
  //   printf("ary[%d] = ",i);
  //   for(j=0;j<people;j++){
  //     printf("%d ",ary[i][j]);
  //   }
  //   printf("\n");
  // }

  for(i=0;i<people;i++){
    ary[i][i] = bacon_check(i);
  }

  for(i=0;i<people;i++){
    if(tmp == -1){
      min = i;
      tmp = ary[i][i];
    }else if(tmp > ary[i][i]){
      min = i;
      tmp = ary[i][i];
    }else if(min == ary[i][i]){
      continue;
    }
  }

  printf("%d", min+1);
  return 0;
}
