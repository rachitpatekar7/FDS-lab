#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
int top = -1;
bool IsEmpty(char a[10])
{
   if(top < 0)
   {
      return true;
   }
   else
   {
      return false;
   }
}
void prints(char a[10])
{
int i;

   if(IsEmpty(a) == true)
   {
     printf("\nStack Is Empty Now.");
   }
   else
   {
     printf("\nStack Is:.\n");
     for(i = 0; i<=top; i++)
     {
        printf("%c\n",a[i]);
     }
   }
}
   
   
bool IsFull(char a[10])
{
   if(top == 9)
   {
     return true;
   }
   else
   {
     return false;
   }
}
void push(char a[10], char n)
{
   top= top+1;
   a[top] = n;
   
 
}
char pop(char a[10])
{
   char n;
   n = a[top];
   top = top-1;
   return n;
   
}

int main()
{
   char a[10];
   char b[10];
   int i = 0;
   int j = 0;
   char n;
   int ch;
   printf("Enter A String. Max Size = 10\n");
   scanf("%s",a);
   int l = strlen(a);
   
 for(i = 0; i< l; i++)
 {
    push(b,a[i]);
 }
 printf("\nReversed String Is : ");
 for(i = 0; i<l ; i++)
 {
    a[i] = pop(b);
   
 }
 for(i = 0; i<l ; i++)
 {
    printf("%c",a[i]);
 }
    printf("\n");
}
