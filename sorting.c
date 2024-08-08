#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student  
{  
    char name[20];  
    int rollno;
    int marks;
    int age;
};  

void accept(struct student st [5])
{


printf("\nEnter a record of 5 students : \n");
for(int i = 0; i< 5; i++)
{
  printf("Enter Name Of Student %d \n" , (i+1));
  scanf("%s" ,st[i].name);
  printf("Enter Age Of Student %d \n" , (i+1));
  scanf("%d" ,&st[i].age);  
  printf("Enter Roll No. of Student (Max Roll No. Should be 99) %d \n" , (i+1));
  scanf("%d" ,&st[i].rollno);
  printf("Enter Marks Of Student %d \n" , (i+1));
  scanf("%d" ,&st[i].marks);
  printf("\n\n");
}
}

void Lsearch(int t,struct student st[5])
{
  int check=0;
  int i;
  for(i=0; i<5 ; i++)
  {
    if(st[i].rollno == t)
    {
       check = 1;
       break;
    }  
  }
  if(check == 1)
  {
     printf("\n\nRoll No. %d Details : \n",t);
     printf("\n --> Name : %s ",st[i].name);
     printf("\n --> Age : %d ",st[i].age);
     printf("\n --> Roll No : %d " ,t);
     printf("\n --> Marks : %d\n",st[i].marks);
  }
  else
  {
     printf("\nRoll No. %d Not Found.\n",t);
  }

}

void Bsearch(int t,struct student st[5])
{
  int check=0;
  int low = 0;
  int high = 4;
  int mid;
  int i;
  while(low <= high)
  {
    mid = (low+high)/2;
    if(st[mid].rollno == t)
    {
      check = 1;
      break;
    }
    else if(st[mid].rollno < t)
    {
      low = mid+1;
    }
    else
    {
      high = mid-1;
    }
  }
  if(check == 1)
  {
     printf("\n\nRoll No. %d Details : \n",t);
     printf("\n --> Name : %s ",st[mid].name);
     printf("\n --> Age : %d ",st[mid].age);
     printf("\n --> Roll No : %d " ,t);
     printf("\n --> Marks : %d\n",st[mid].marks);
  }
  else
  {
     printf("\nRoll No. %d Not Found.\n",t);
  }

}

void display(struct student st[5])
{
   printf("Name\tAge\tRollNo. Marks\n");
   for(int i = 0; i< 5; i++)
   {
    printf("%s \t %d \t %d \t %d\n", st[i].name,st[i].age,st[i].rollno,st[i].marks);
   }

}
void swap(int *x, int *y)
{
  int *t;
  *t = *x;
  *x = *y;
  *y = *t;
}



void bubble(struct student std[5])
{
int n = 5;
 for(int i =0;i<n;i++){
   for(int j=0;j<n-i-1;j++){
    if(std[j].rollno>std[j+1].rollno){
    //roll number
     int temp_rno = std[j+1].rollno;
     std[j+1].rollno = std[j].rollno;
     std[j].rollno = temp_rno;
     //name
     char temp_name[20];
     strcpy(temp_name,std[j+1].name);
     strcpy(std[j+1].name,std[j].name);
     strcpy(std[j].name,temp_name);
     //marks
     int temp_marks = std[j+1].marks;
     std[j+1].marks = std[j].marks;
     std[j].marks = temp_marks;
     //age
     int temp_age = std[j+1].age;
     std[j+1].age = std[j].age;
     std[j].age = temp_age;
    }
   }
 }
}

void selectionsort(struct student st[5])
{
   int min, minpos;
   int n = 5;
   char temp_name[20];
   int temp_age;
   int temp_marks;
   for(int i = 0; i<= n-2; i++)
   {
      min = st[i].rollno;
      minpos = i;
      for(int j = i+1 ; j<n ; j++)
      {
         if(st[j].rollno<min)
         {
            minpos = j;
            min = st[j].rollno;
            temp_age = st[j].age;
            temp_marks = st[j].marks;
            strcpy(temp_name,st[j].name);
         }
      }
     st[minpos].rollno = st[i].rollno;
     st[i].rollno = min;
     //name
     
   
     strcpy(st[minpos].name,st[i].name);
     strcpy(st[i].name,temp_name);
     //marks
     
     st[minpos].age = st[i].age;
     st[i].age = temp_age;
     //age
     
     st[minpos].marks = st[i].marks;
     st[i].marks = temp_marks;
     }
     }
     
void insertion(struct student st[5])
{
   int key,key1,key2;
   char key3[20];
   for(int i = 1; i <5 ; i++)
   {
     key = st[i].rollno;
     key1 = st[i].age;
     key2 = st[i].marks;
     strcpy(key3,st[i].name);
     int j = i-1;
     while(j>=0)
     {
        if(st[j].rollno > key)
        {
          st[j+1].rollno = st[j].rollno;
          st[j+1].age = st[j].age;
          st[j+1].marks = st[j].marks;
          strcpy(st[j+1].name,st[j].name);
          j--;
        }
        else
        {
           break;
        }}
        st[j+1].rollno = key;
        st[j+1].age = key1;
        st[j+1].marks = key2;
        strcpy(st[j+1].name,key3);
     }
}  

void shellsort(struct student std[5])
{
  int gap = 5/2;
  int swapped;
  do
  {
    do
    {
      swapped = 0;
      for(int i = 0; i < 5-gap ; i++)
      {
        if(std[i].rollno > std[i+gap].rollno)
        {
             int temp_rno = std[i+gap].rollno;
             std[i+gap].rollno = std[i].rollno;
             std[i].rollno = temp_rno;
             //name
             char temp_name[20];
             strcpy(temp_name,std[i+gap].name);
             strcpy(std[i+gap].name,std[i].name);
             strcpy(std[i].name,temp_name);
             //marks
             int temp_marks = std[i+gap].marks;
             std[i+gap].marks = std[i].marks;
             std[i].marks = temp_marks;
             //age
             int temp_age = std[i+gap].age;
             std[i+gap].age = std[i].age;
             std[i].age = temp_age;
             swapped = 1;
          }
       }
     }while(swapped==1);
     }while((gap = gap/2) >=1);
     }
         
int main(void)
{  
 
   struct student st [5];
   accept(st);
   while(1)
   {
   printf("\nSelect Your Choice : \n");
   printf(" 1 = Display Data\n 2 = Linear Search \n 3 = Binary Search(Only If The Input is Sorted) \n 4 = Bubble Sort \n 5 = Selection Sort \n 6 = Insertion Sort \n 7 = Shell Sort \n 8 = Bucket Sort \n 9 = Exit \n\n");
   int ch;
   int rno;
   scanf("%d",&ch);
   switch(ch)
   {
   case 1:
       printf("\nThe Data You Have Entered is :\n\n");
       display(st);
       break;
   case 2:
       printf("\nEnter Roll No. To Find : \n");
       scanf("%d",&rno);    
       printf("\nLinear Search Result :");
       Lsearch(rno,st);
       break;
   case 3:
       printf("\nEnter Roll No. To Find : \n");
       scanf("%d",&rno);    
       printf("\nBinary Search Result :");
       Bsearch(rno,st);
       break;
   case 4:
       printf("\nArray After Bubble Sorting is : \n");
       bubble(st);
       display(st);
       break;
   case 5 :
       printf("\nArray After Selection Sorting is : \n");
       selectionsort(st);
       display(st);
       break;
   case 6 :
       printf("\nArray After Insertion Sorting is : \n");
       insertion(st);
       display(st);
       break;
   case 7 :
       printf("\nArray After Shell Sorting is : \n");
       shellsort(st);
       display(st);
       break;    
   case 8:
       printf("\nPROGRAM EXITTED.\n");
       exit(0);
   }
   
 }
 }
