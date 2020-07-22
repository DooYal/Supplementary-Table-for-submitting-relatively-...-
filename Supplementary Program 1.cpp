#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
int main()
{   printf("The randomly generated sequence will be saved at C://sequence.fasta!!!\n");
    int a,t,g,c,genome;
    do
    {
        printf("Enter the number of each base(the genome size<=500000 bp), respectively!:\nA=");
        scanf("%d",&a);
        printf("T=");
        scanf("%d",&t);
        printf("G=");
        scanf("%d",&g); 
        printf("C=");
        scanf("%d",&c);
        genome=a+t+c+g;
        if(genome>500000) 
        {
            printf("Wrong!!! The length of genome is more than 500000 bp!!!\nPlease try again!\n");
        }
    }while(genome>500000);
     
    int n,i,p,q,k;
    k=genome;
    char G[500000],GG[500000];
    int num[4]={0,0,0,0};
    srand((unsigned)time(NULL));
   
  for (i=0;i<genome;)/*generate nonrandom sequence corresponding to reference sequence */
      {
            n=rand()%4+1;
             
         if(n==1&&num[0]<a)
           {
              G[i]='A';
              num[0]++;
              i++;
           }
     
           if(n==2&&num[1]<t)
           {
              G[i]='T';
              num[1]++;
              i++;
           }
     
           if(n==3&&num[2]<g)
           {
              G[i]='G';
              num[2]++;
              i++;
           }
           if(n==4&&num[3]<c)
           {
             G[i]='C';
             num[3]++;
             i++;
           }
    
      }
    
      for (i=0;k-1>=0;i++)/*generate the random sequence from nonrandom sequence*/
        {
             p=rand()%10+1;  
             q=rand();
             n=(p*q+q)%k;
             GG[i]=G[n];
             G[n]=G[k-1];
             k--;
         }
 
      FILE *fp=fopen("C://sequence.fasta","w");/*save the random sequence*/
 
      fprintf(fp,"%s",">random sequence\n");
      for(i=0;i<genome;i++)
      {    
          fprintf(fp,"%c",GG[i]);
      }
     fputs("\n\n",fp);
     fclose(fp);
	 printf("\ngenome=%d\nFinished!!!\nPlease check file in the disk C!!!!!!!!!\n",genome);
     system("pause");
     return 0;
}
