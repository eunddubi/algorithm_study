#include <stdio.h>
#include <string.h>
//anagram

int check_anagram(char a[], char b[]);
char first[100];
char second[100];

int main(){
  printf("Enter first string\n");
  scanf("%s", first);
  printf("Enter second string\n");
  scanf("%s", second);

  if(check_anagram(first, second)){
    printf("\"%s\" and \"%s\" are anagrams.\n", first, second);
  }else{
    printf("\"%s\" and \"%s\" are NOT anagrams.\n", first, second);
  }
}

int check_anagram(char first[], char second[]){
  int a[26]={0}, b[26]={0}, i, c;

  for(i=0; first[i] != '\0'; i++){
    c = first[i];
    if(c >= 'a'){  //small letter
      a[first[i]-'a']++;
    }else{        //capital letter
      a[first[i]-'A']++;
    }
  }

  for(i=0; second[i] != '\0'; i++){
    c = second[i];
    if(c >= 'a'){  //small letter
      b[second[i]-'a']++;
    }else{        //capital letter
      b[second[i]-'A']++;
    }
  }

  for(i=0;i< sizeof(a)/sizeof(a[0]);i++){
    if(a[i] != b[i]){
      return 0;
    }else{
      continue;
    }
  }
  return 1;
}
