#include <stdio.h>
#include <stdlib.h>
#define MAX(X,Y) ((X)>(Y)?(X):(Y))

int Answer;
char* vowels="aeiou";
int ans[2];
void chk(char* str,int n){
   int StEn[2];
   int i=0,k=0;
   ans[0]=0;ans[1]=9999;
   while(k<=n){
      if(str[k]==vowels[i]){
         if(i==0){
            StEn[0]=k+1;
         }
         else if(i==4){h
            StEn[1]=k+1;
            i=-1;
            if((StEn[1]-StEn[0])<(ans[1]-ans[0])){
               ans[1]=StEn[1];
               ans[0]=StEn[0];
            }
         }
         ++i;
      }
      if(((k==(n-1))&&(i!=4))&&ans[1]==9999){
                  ans[0]=-1;
                  ans[1]=-1;
               }
      ++k;
      if(i==1 && str[k]=='a'){
         i=1;   StEn[0]=k+1;
      }
   }
}
int main(void)
{
   int T, test_case;
   int n;
   char* str;
   setbuf(stdout, NULL);
   scanf("%d", &T);
   for(test_case = 0; test_case < T; test_case++)
   {
      scanf("%d",&n);
      str=(char*)calloc(n,sizeof(char));
      scanf("%s",str);
      chk(str, n);
      printf("Case #%d\n", test_case+1);
       printf("%d %d\n", ans[0],ans[1]);
   }
   return 0;
}
