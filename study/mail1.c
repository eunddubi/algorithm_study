#include <stdio.h>

int input[100] = {0};
int num = 0, min = 1, i = 0;

int main(){

  printf("How many numbers you want to input: ");
  scanf("%d", &num);

  for(i = 0; i < num; i++){
    scanf("%d", &input[i]);
  }

  while(i == num){
    if(input[i] > 0 && input[i] < min){
      min = input[i];
    }
    i++;
  }

  for(i = 0; i < num; i++){
    if(min == input[i]){
      min++;
    }
  }

  printf("result: %d", min);
  return 0;
}
