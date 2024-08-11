#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int top = -1;

bool IsEmpty(char a[26])
{
   if (top < 0) {
      return true;
   } else {
      return false;
   }
}

void prints(char a[26], int l)
{
   int i;

   
      printf("Prefix Is:.\n");
      for (i = 0; i < l; i++)
      {
         printf("%c", a[i]);
      }
      printf("\n");
   
}

bool IsFull(char a[26]) 
{
   if (top == 26 - 1) 
   {
      return true;
   } 
   else 
   {
      return false;
   }
}

void push(char a[26], char n) 
{
   top = top + 1;
   a[top] = n;
}

char pop(char a[26]) 
{
   char n;
   n = a[top];
   top = top - 1;
   return n;
}

bool isoperand(char tkn) 
{
   if ((tkn == '(') || (tkn == ')') || (tkn == '^') || (tkn == '*') || (tkn == '/') || (tkn == '%') || (tkn == '+') || (tkn == '-')) 
   {
      return false;
   } 
   else 
   {
      return true;
   }
}

int icp(char tkn) 
  {
   if (tkn == '(') 
   {
      return 5;
   } 
   else if (tkn == '^') 
   {
      return 4;
   } 
   else if ((tkn == '*') || (tkn == '/') || (tkn == '%')) 
   {
      return 2;
   } 
   else 
   {
      return 1;
   }
}

int isp(char tkn) 
   {
   if (tkn == '(') 
   {
      return 0;
   } 
   else if (tkn == '^') 
   {
      return 3;
   } 
   else if ((tkn == '*') || (tkn == '/') || (tkn == '%')) 
   {
      return 2;
   } 
   else 
   {
      return 1;
   }
}

int main() 
{
   char a[26];
   char b[26];
   char post[26];
   int i = 0;
   int j = 0;

   printf("Enter An Expression (max %d characters):\n", 26 - 1);
   scanf("%s", a);
   int l = strlen(a);
   i = l-1;
   char tkn = a[i];

   while (i>=0) 
   {
      if (isoperand(tkn) == true) 
      {
         post[j] = tkn;
         j++;
      } 
      else
      {
         if (tkn == ')')
         {
            push(b, tkn);
         }
         else
         {
            if (tkn == '(') 
            {
            while (b[top] != ')') 
            {
               post[j] = pop(b);
               j++;
            }
            pop(b);
         } 
         else 
         {
            while (IsEmpty(b) == false && (isp(b[top])) > icp(tkn)) 
            {
               post[j] = pop(b);
               j++;
            }
            push(b, tkn);
         }}
      }
      i--;
      tkn = a[i];
   }
   
   while (IsEmpty(b) == false) 
   {
      post[j] = pop(b);
      j++;
   }
   strrev(post);
   prints(post, j);

   return 0;
}
