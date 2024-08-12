#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int top = -1;
int topi = -1;
//takes variables, infix expression in form of variables
//we assign values to these variables, infix expression converted to postfix and then solved using stack implementation

void push1(int a[26], int n) {
   topi = topi + 1;
   a[topi] = n;
}

int pop1(int a[26]) {
   int n;
   n = a[topi];
   topi = topi - 1;
   return n;
}





bool IsEmpty(char a[26]) {
   if (top < 0) {
      return true;
   } else {
      return false;
   }
}

void prints(char a[26], int l) {
   int i;

   
      printf("\nPostfix Is:\n");
      for (i = 0; i < l; i++) {
         printf("%c", a[i]);
      }
      printf("\n");
   
}

bool IsFull(char a[26]) {
   if (top == 26 - 1) {
      return true;
   } else {
      return false;
   }
}

void push(char a[26], char n) {
   top = top + 1;
   a[top] = n;
}

char pop(char a[26]) {
   char n;
   n = a[top];
   top = top - 1;
   return n;
}

bool isoperand(char tkn) {
   if ((tkn == '(') || (tkn == ')') || (tkn == '^') || (tkn == '*') || (tkn == '/') || (tkn == '%') || (tkn == '+') || (tkn == '-')) {
      return false;
   } else {
      return true;
   }
}

int icp(char tkn) {
   if (tkn == '(') {
      return 5;
   } else if (tkn == '^') {
      return 4;
   } else if ((tkn == '*') || (tkn == '/') || (tkn == '%')) {
      return 2;
   } else {
      return 1;
   }
}

int isp(char tkn) {
   if (tkn == '(') {
      return 0;
   } else if (tkn == '^') {
      return 3;
   } else if ((tkn == '*') || (tkn == '/') || (tkn == '%')) {
      return 2;
   } else {
      return 1;
   }
}

int main() {
   char a[26];
   char b[26];
   char post[26];
   int i = 0;
   int j = 0;
   int ans = 0;
   int stk[26];
   int vals[10];
   char vars[] = {'a','b','c','d','e','f','g','h','i','j'};
   int op1,op2;
   int n;
   printf("Enter Number Of Variables Required (Maximum 10) : \n");
   scanf("%d",&n);
   printf("Enter An Expression In the form of variables a,b,c and so on upto j (max %d characters):\n", 26 - 1);
   scanf("%s", a);
   for(i = 0;i<n;i++)
   {
   printf("\nEnter the value of %c :\n",vars[i]);
   scanf("%d",&vals[i]);
   }
   i = 0;
   int l = strlen(a);

   char tkn = a[i];

   while (tkn != '\0') {
      if (isoperand(tkn) == true) {
         post[j] = tkn;
         j++;
      } else {
         if (tkn == '(') {
            push(b, tkn);
         }
else{
if (tkn == ')') {
            while (b[top] != '(') {
               post[j] = pop(b);
               j++;
            }
            pop(b);
         } else {
            while (IsEmpty(b) == false && (isp(b[top])) >= icp(tkn)) {
               post[j] = pop(b);
               j++;
            }
            push(b, tkn);
         }}
      }
      i++;
      tkn = a[i];
   }

   while (IsEmpty(b) == false) {
      post[j] = pop(b);
      j++;
   }

   prints(post, j);
   
   for(i = 0; i<l; i++)
   {
   
      if(isoperand(post[i]))
      {
          switch(post[i])
          {
         
             case 'a' : push1(stk,vals[0]);
                        break;
             case 'b' : push1(stk,vals[1]);
                        break;
             case 'c' : push1(stk,vals[2]);
                        break;
             case 'd' : push1(stk,vals[3]);
                        break;
             case 'e' : push1(stk,vals[4]);
                        break;
             case 'f' : push1(stk,vals[5]);
                        break;
             case 'g' : push1(stk,vals[6]);
                        break;
             case 'h' : push1(stk,vals[7]);
                        break;
             case 'i' : push1(stk,vals[8]);
                        break;
             case 'j' : push1(stk,vals[9]);
                        break;
                         
             
          }  
      }
      else
      {
          op1 = pop1(stk);
          op2 = pop1(stk);
          switch(post[i])
          {
             case '+' : ans = op1+op2;
                        break;
             case '-' : ans = op1-op2;
                        break;
             case '*' : ans = op1*op2;
                        break;
             case '/' : ans = op1/op2;
                        break;
          }  
          push1(stk,ans);
          }
          }
    printf("\nThe Final Answer Is : %d\n",ans);                              
         

   return 0;
}
