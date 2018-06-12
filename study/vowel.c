#include <stdio.h>
#include <stdlib.h>

int N;
char* word;
char vowel[5] = "aeiou";

int measure(int i){
  int j = 0;
  int len = 0;
  while(word[i] && j != 4){
    if(word[i] == vowel[j]){
      len++; j++;
    }
    i++;
  }
  return len;
}

int validate(int i){
  int c = 5;
  int j = 0;
  while(word[i] && c){
    if(word[i] == vowel[j]){
      c--; j++;
    }
    i++;
  }
  if(c == 0){
    //printf("this can make vowel\n");
    return 1;
  }else{
    //printf("this can not make vowel\n");
    return 0;
  }
}

int main(void)
{
	int T, test_case;
  int i, j;
  int start, end;
  int len1, len2;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
    i=0; j=9999; start=0; end=0; len1=0; len2=0;
    int k = 0;
    scanf("%d", &N);
    word = (char*)malloc((N+1)*sizeof(char));
    scanf("%s", word);

    for(k=0;k<N;k++){
      printf("vowel[%d] = %c\n", k, vowel[k]);
    }

    while(word[i]){
      if(word[i] == vowel[0] && validate(i)){
        if(len1 == 0){
          len1 = measure(i);
          start = i+1;
          j=0;
        }else{
          len2 = measure(i);
          if(len1 > len2){
            start = i+1;
            j=0;
          }
        }
      }else if(word[i] == vowel[1] && j == 0){
        j++;
      }else if(word[i] == vowel[2] && j == 1){
        j++;
      }else if(word[i] == vowel[3] && j == 2){
        j++;
      }else if(word[i] == vowel[4] && j == 3){
        j++;
        if(len2 == 0 || len1 > len2){
          end = i+1;
          len1 = len2;
        }
      }
      i++;
    }

    if(j != 4){
      start = -1;
      end = -1;
    }

		printf("Case #%d\n", test_case+1);
    printf("%d %d", start, end);
	}

	return 0;//Your program should return 0 on normal termination.
}
