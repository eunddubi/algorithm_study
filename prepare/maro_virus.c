/*
 * baekjoon2606.c
 *
 *  Created on: 2018. 4. 11.
 *      Author: maroro
 */
#include<stdio.h>
#include<stdlib.h>
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
int main(){
   int** arr;
   int sum=0,n,cn,a,b;
   scanf("%d",&n);
   scanf("%d",&cn);
   arr=(int**)calloc(n+1,sizeof(int*));
   for(int i=0;i<n+1;i++){
      arr[i]=(int*)calloc(n+1,sizeof(int*));
   }
//   printf("n%d  cn%d",n,cn);
   for(int i=0;i<cn;i++){
//      printf("%d",i);
      scanf("%d %d",&a, &b);
      arr[a][b]=1;
      arr[b][a]=1;
   }
   for(int k=1;k<=n;k++)
      for(int i=1;i<=n;i++)
         for(int j=1;j<n;j++){
            if(i!=j&&arr[i][k] &&arr[k][j]){
               arr[i][j]=1;
               }
         }

         for(i=0;i<n;i++){
       		printf("ary[%d] = ",i);
       		for(j=0;j<n;j++){
       			printf("%d ",arr[i][j]);
       		}
       		printf("\n");
       	}

   for(int i=1;i<=n;i++)
      sum+=arr[1][i];
   printf("%d",sum);
   return 0;
}
