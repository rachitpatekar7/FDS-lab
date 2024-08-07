#include<stdio.h>
#include<stdlib.h>
void input(int arr[5][5],int r,int c)
{
  int i,j;
  for(i = 0; i<r ; i++)
   {
     for (j = 0; j<c; j++)
     {
        scanf("%d", &arr[i][j]);
       
     }
        printf("\n");
   }
}
void display(int arr[5][5],int r,int c)
{
  int i,j;
  for(i = 0; i<r ; i++)
   {
     for (j = 0; j<c; j++)
     {
        printf("%d", arr[i][j]);
        printf("\t");
     }
        printf("\n");
   }
}
int countzero(int arr[5][5],int r,int c)
{  
   int i,j;
   int count=0;
   for(i = 0; i<r ; i++)
  {
     for (j = 0; j<c; j++)
     {
        if(arr[i][j] == 0)
        {
          count++;
        }                
     }
   }
   return count;
}
   
int compact(int arr[5][5],int r,int c,int comp[20][5])
{  
    int k = 1;
    for(int i = 0; i<r ; i++)
    {
       for(int j = 0; j<c; j++)
       {
          if(arr[i][j] != 0)
          {
             comp[k][0] = i;
             comp[k][1] = j;
             comp[k][2] = arr[i][j];
             k++;
          }
       }  
    }  
    comp[0][0] = r;
    comp[0][1] = c;
    comp[0][2] = k-1;
    return k;
}
int transpose(int comp[20][5],int trans[20][5])
{  
  int m,n,t,q;
   
    m = comp[0][0];
    n = comp[0][1];
    t = comp[0][2];
     q = 1;
    trans[0][0] = n;
    trans[0][1] = m;
    trans[0][2] = t;
   
    if (t<=0)
    {
      return 0;
    }
    else
    {
      for(int col = 0; col<n ; col++)
    {
       for(int p = 1; p<=t; p++)
       {
            if (comp[p][1] == col)
            {
           
            trans[q][0] = comp[p][1];
            trans[q][1] = comp[p][0];
            trans[q][2] = comp[p][2];
           
            q++;
           }
        }
     }
   }
}    
int fasttranspose(int comp[20][5],int trans[20][5])
{
   int S[20];
   int T[20];
   int m,n,t,q;
   
    m = comp[0][0];
    n = comp[0][1];
    t = comp[0][2];
    trans[0][0] = n;
    trans[0][1] = m;
    trans[0][2] = t;
    int L;
    if(t<=0)
    {
    return 0;
    }
    else
    {
      for(int i = 0; i<n; i++)
      {
        S[i] = 0;
      }
     for(int j = 1; j<=t ; j++)
     {
       int ele = *comp[j,1];
       S[ele] = S[ele] + 1;
     }
     T[0] = 1;
     for(int i = 1; i<n; i++)
      {
       T[i] = T[i-1] + S[i-1];
       }
       for(int j = 1; j<=t ; j++)
     {
       L = comp[j][1];
       trans[T[L]][0] = comp[j][1];
       trans[T[L]][1] = comp[j][0];
       trans[T[L]][2] = comp[j][2];
       T[L] = T[L] + 1;
     }
      }
    }
int main()
{
  int a[15][5];
  int r1,c1;
  int c0;
  int total;
  int half;
  int com[20][5];
  int k;
  int trans[20][5];
 
   printf("Enter rows and columns for the matrix (max 5) : \n");
   scanf("%d %d", &r1, &c1);
   printf("Enter a Matrix.\n");
   input(a,r1,c1);
   printf("The Matrix is : \n");
   display(a,r1,c1);
   c0 = countzero(a,r1,c1);
   total = r1*c1;
   half = total/2;
   printf("\nTotal No. of elements are : %d  \n", total);
   printf("Half of total number of elements are : %d  \n", half);
   printf("No. of zeroes are : %d  \n",c0);
   if(c0 >= ((r1*c1)/2))
   {
     printf("It is a Sparse Matrix.\n\n");
     printf("The compact form of the matrix is :\n");
     k = compact(a,r1,c1,com);
     display(com,k,3);
     printf("\nThe SIMPLE tranpose form of the compact matrix is :\n");
     transpose(com,trans);
     display(trans,k,3);
     printf("\nThe FAST tranpose form of the compact matrix is :\n");
     fasttranspose(com,trans);
     display(trans,k,3);
     exit(0);
   }
   else
   {
     printf("It is Not a Sparse Matrix.\n");
   }  
}
