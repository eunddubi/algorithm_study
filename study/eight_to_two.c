//8진수가 주어졌을 때, 2진수로 변환하는 프로그램을 작성하시오.
//첫째 줄에 8진수가 주어진다. 주어지는 수의 길이는 333,334을 넘지 않는다.
//첫째 줄에 주어진 수를 2진수로 변환하여 출력한다. 수가 0인 경우를 제외하고는 반드시 1로 시작해야 한다.

#include <stdio.h>
#include <string.h>

#define MAX 333335

char ary[MAX];
int i = 0;
int tmp;
char num[8][4] = {"000\0", "001\0", "010\0", "011\0", "100\0", "101\0", "110\0", "111\0"};

int main(){

  scanf("%s", ary);
  tmp = ((int)ary[0])-'0';

  if(tmp < 4){
    if(ary[0] == '0'){
    }else if(ary[0]-'0' == 1){
      printf("1");
    }else if(ary[0] == '2'){
      printf("10");
    }else if(ary[0] == '3'){
      printf("11");
    }
    i++;
  }
  while(i<strlen(ary)){
    printf("%s",num[ary[i++]-'0']);
  }
  printf("\n");

  return 0;
}
