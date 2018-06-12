#include <stdio.h>
#include <stdlib.h>

char key[5] = "aeiou";//[0] = a; [1] = e; [2] = i; [3] = o; [4] = u;
char* word;
int N;

int count_len(int i){
  int j=0;
  int check[5]={0,};//check[0] = a; [1] = e; [2] = i; [3] = o; [4] = u;
  int from = i;
  while(check[4] == 0 && word[i]){
    if(word[i] == key[j]){
      check[j]++;
      j++;
    }
    i++;
  }
  return i-from;
}

int validate(int i, int c){
  int num = 4 - c++;
  while(word[i]){
    if(word[i] == key[c]){
      num--; c++;
    }
    i++;
  }
  if(num == 0)   return 1;
  else           return 0;
}

int main(void)
{
  int T, test_case;
  int start, end;
  int i, j, len1, len2;
   setbuf(stdout, NULL);

   scanf("%d", &T);
   for(test_case = 0; test_case < T; test_case++)
   {
    start = 0; end = 0; i=0; j=0; len1 = 9999; len2 = 0;
    scanf("%d", &N);
    word = (char*)calloc((N+1),sizeof(char));
    scanf("%s", word);

    while(word[i]){
      if(word[i] == key[0] && validate(i,0)){ //a
        if(len1 == 9999){
          len1 = count_len(i);
          start = i+1;
        }else if(len1 != 9999){
          len2 = count_len(i);
          if(len1>len2){
            start = i+1;
          }
        }
        j=0;
      }else if(word[i] == key[1] && j == 0){ //e
        j++;
      }
      else if(word[i] == key[2] && j == 1){ //i
        j++;
      }
      else if(word[i] == key[3] && j == 2){ //o
        j++;
      }
      else if(word[i] == key[4] && j == 3){ //u
        if(len1 > len2 || len2 == 0){
          end = i+1;
          if(len2 != 0) len1 = len2;
        }
        j++;
      }
      i++;
    }

    if(j != 4){
      start = -1; end = -1;
    }

    free(word);
    printf("Case #%d\n", test_case+1);
    printf("%d %d\n", start, end);
   }
   return 0;
}
