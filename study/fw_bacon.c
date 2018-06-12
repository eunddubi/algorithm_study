
#include<stdio.h>
#include<stdlib.h>
#define MIN(X,Y) ((X)<(Y)?X:Y)


int main(){
   setbuf(stdout,NULL);
   int n, m; //첫째 줄에 유저의 수 N (2 ≤ N ≤ 100)과 친구 관계의 수 M (1 ≤ M ≤ 5,000)이 주어진다.
   int** arr;
   int* bacon;
   int k,i,j,min=0;
   scanf("%d %d",&n, &m);
   arr=(int**)calloc(n+1,sizeof(int*));
   bacon=(int*)calloc(n+1,sizeof(int));
   for(i=1;i<=n;i++){
      arr[i]=(int*)calloc(n+1,sizeof(int));
   }
   bacon[0]=99999;
   int f1,f2;
   while(m>0){
      scanf("%d %d",&f1,&f2);
      arr[f1][f2]=1;
      arr[f2][f1]=1;
      m--;
   }
   for(k=1;k<=n;k++)
      for(i=1;i<=n;i++)
         for(j=1;j<=n;j++){
            if(i!=j&&arr[i][j]==0 && arr[i][k]&&arr[k][j]){
               arr[i][j]=arr[i][k]+arr[k][j];
            }
            else if(i!=j && arr[i][j] && arr[i][k]&&arr[k][j]){
               arr[i][j]=MIN(arr[i][j],arr[i][k]+arr[k][j]);
            }
         }

   for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
         if(i!=j)
            bacon[i]+=arr[i][j];
      }
   }

   for(i=1;i<=n;i++){
      if(bacon[i]<bacon[min])
         min=i;
   }

   printf("%d",min);
   return 0;
}
