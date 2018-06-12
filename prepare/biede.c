/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>
#include <stdlib.h>
int Answer;

int main(void)
{
   int T, test_case;
   /*
      The freopen function below opens input.txt file in read only mode, and afterward,
      the program will read from input.txt file instead of standard(keyboard) input.
      To test your program, you may save input data in input.txt file,
      and use freopen function to read from the file when using scanf function.
      You may remove the comment symbols(//) in the below statement and use it.
      But before submission, you must remove the freopen function or rewrite comment symbols(//).
    */
   // freopen("input.txt", "r", stdin);

   /*
      If you remove the statement below, your program's output may not be rocorded
      when your program is terminated after the time limit.
      For safety, please use setbuf(stdout, NULL); statement.
    */
   setbuf(stdout, NULL);

   scanf("%d", &T);
   if(T<6 && T>0){
      for(test_case = 0; test_case < T; test_case++)
      {
         int n, k;
         int* a;
         scanf("%d",&n);
         a=(int*)malloc(sizeof(int)*(n+1));
         a[0]=0;
         for(int i=1;i<=n;i++){
            scanf("%d ",&a[i]);
            if(a[i]<1 || a[i]>1000000000){
               i--;
               continue;
            }
         }
         scanf("%d",&k);
         int l=0,flag=0;
//         printf("\na[%d]=%d",0,a[0]);
         for(int i=1;i<=n;){
//            printf("\na[%d]=%d",i,a[i]);
//            printf("\nl1: %d ",l);
            if((a[i]>a[l]+k)&&flag){
               l=i-1;
               Answer++;
               flag=0;
//               printf("l: %d",l);
            }
            else if(a[l]+k>=a[i]){
               i++;
               flag=1;
//               printf("i: %d",i);
               if((i>n)){
                  Answer++;
               }
            }

            else{
//               printf("err");
               Answer=-1;
               break;
            }
         }


         free(a);
         printf("Case #%d\n", test_case+1);
         printf("%d\n", Answer);

      }
   }

   return 0;//Your program should return 0 on normal termination.
}
