#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Student
{
     char ID[20];
     char Name[20];
     float Mark1;
     float Mark2;
     float Mark3;
     float Average;
};
struct Student students[1000];
int num=0;
float Avg(struct Student stu)
{
     return (stu.Mark1+stu.Mark2+stu.Mark3)/3;
}
int Student_SearchByIndex(char id[])
{
     int i;
     for (i=0;i<num;i++)
     {
         if (strcmp(students[i].ID,id)==0)
         {
              return i;
         }
     }
     return -1;
}
int Student_SearchByName(char name[])
{
     int i;
     for (i=0;i<num;i++)
     {
         if (strcmp(students[i].Name,name)==0)
         {
              return i;
         }
     }
     return -1;
}
void Student_DisplaySingle(int index)
{
     printf("%10s%10s%8s%8s%8s%10s\n","Student ID","Name"," Mark1 "," Mark2 "," Mark3 "," Average Mark ");
     printf("-------------------------------------------------------------\n");
     printf("%10s%10s%8.2f%8.2f%8.2f%10.2f\n",students[index].ID,students[index].Name,
              students[index].Mark1,students[index].Mark2,students[index].Mark3,students[index].Average);
}
void Student_Insert()
{
     while(1)
     {
         printf("Please input Student ID:");
         scanf("%s",&students[num].ID);
         getchar();
printf("Please input name:");
         scanf("%s",&students[num].Name);
         getchar();
printf("Please input mark1:");
         scanf("%f",&students[num].Mark1);
         getchar();
printf("Please input mark2:");
         scanf("%f",&students[num].Mark2);
         getchar();
printf("Please input mark3:");
         scanf("%f",&students[num].Mark3);
         getchar();
students[num].Average=Avg(students[num]);
         num++; 
printf("Continue?(y/n)");

         if (getchar()=='n')
         {
              break;
         }
     }
}
void Student_Modify()
{
     float mark1,mark2,mark3;
     while(1)
     {
         char id[20];
         int index;
         printf("Please input Student ID you want to modify:");
         scanf("%s",&id);
         getchar();
         index=Student_SearchByIndex(id);
         if (index==-1)
         {
              printf("Student non-existant!\n");
         }
         else
         {
              printf("The message you want to modify is:\n");
              Student_DisplaySingle(index);
              printf("-- Please input new message--\n");
              printf("please input Student ID:");
              scanf("%s",&students[index].ID);
              getchar();
              printf("Please input name:");
              scanf("%s",&students[index].Name);
              getchar();
              printf("please input mark 1:");
              scanf("%f",&students[index].Mark1);
              getchar();
              printf("Please input mark 2:");
              scanf("%f",&students[index].Mark2);
              getchar();
              printf("Please input mark 3:");
              scanf("%f",&students[index].Mark3);
              getchar();
              students[index].Average=Avg(students[index]);
         }
         printf("Continue?(y/n)");
         if (getchar()=='n')
         {
              break;
         }
     }
}
void Student_Delete()
{
     int i;
     while(1)
     {
         char id[20];
         int index;
         printf("Please input the Student ID you want to delete:");
         scanf("%s",&id);
         getchar();
         index=Student_SearchByIndex(id);
         if (index==-1)
         {
              printf("Student non-existant!\n");
         }
         else
         {
              printf("the deleted student's message is:\n");
              Student_DisplaySingle(index);
              printf("Do you really want to delete it?(y/n)");
              if (getchar()=='y')
              {
                   for (i=index;i<num-1;i++)
                   {
                       students[i]=students[i+1];
                   }
                   num--;
              }
              getchar();
         }
         printf("continue?(y/n)");
         if (getchar()=='n')
         {
              break;
         }
     }
}
void Student_Select()
{
     while(1)
     { 
         char name[20];
         int index;
         printf("please input student's name:");
         scanf("%s",&name);
         getchar();
         index=Student_SearchByName(name);
         if (index==-1)
         {
              printf("student is non-existant\n");
         }
         else
         {
              printf("the student's message you search is:\n");
              Student_DisplaySingle(index);
         }
         printf("continue?(y/n)");
         if (getchar()=='n')
         {
              break;
         }
     }
}
void Student_SortByAverage()
{
     int i,j;
     struct Student tmp;
     for (i=0;i<num;i++)
     {
         for (j=1;j<num-i;j++)
         {
              if (students[j-1].Average<students[j].Average)
              {
                   tmp=students[j-1];
                   students[j-1]=students[j];
                   students[j]=tmp;
              }
         }
     }
}
void Student_Display()
{
     int i;
     printf("%10s%10s%8s%8s%8s%10s\n","Student ID","Name","Mark1","Mark2","Mark3","Average Mark");
     printf("-------------------------------------------------------------\n");
     for (i=0;i<num;i++)
     {
         printf("%10s%10s%8.2f%8.2f%8.2f%10.2f\n",students[i].ID,students[i].Name,
              students[i].Mark1,students[i].Mark2,students[i].Mark3,students[i].Average);
     }

} 
void IO_ReadInfo()
{
     FILE *fp;
     int i;
     if ((fp=fopen("Database.txt","rb"))==NULL)
     {
         printf("can't open this file!\n");
         return; 
     }
     if (fread(&num,sizeof(int),1,fp)!=1)
     {
         num=-1;
     }
     else
     {
         for(i=0;i<num;i++)
         {
              fread(&students[i],sizeof(struct Student),1,fp);
         }
     }
     fclose(fp);
}
void IO_WriteInfo()
{
     FILE *fp;
     int i;
     if ((fp=fopen("Database.txt","wb"))==NULL)
     {
         printf("can't open this file!\n");
         return;
     }
     if (fwrite(&num,sizeof(int),1,fp)!=1)
     {
         printf("write fault!\n");
     }
     for (i=0;i<num;i++)
     {
         if (fwrite(&students[i],sizeof(struct Student),1,fp)!=1)
         {
              printf("write fault!\n");
         }
     }    
     fclose(fp);
}
main()
{
     int choice;
     IO_ReadInfo();
     while(1)
     {
         printf("\n------ Student Mark Manage System------\n");
         printf("1. Add student record\n");
         printf("2. Modify student record\n");
         printf("3. Delete student record\n");
         printf("4. Inquire the student records by name\n");
         printf("5. Ranking by average\n");
         printf("6. Exit\n");
         printf("Please choose (1-6):");
         scanf("%d",&choice);
         getchar();
         switch(choice)
         {
         case 1:
              Student_Insert();
              break;
         case 2:
              Student_Modify();
              break;
         case 3:
              Student_Delete();
              break;
         case 4:
              Student_Select();
              break;
         case 5:
              Student_SortByAverage();
              Student_Display();
              break;
         case 6: 
              exit(0);
              break;
         }
         IO_WriteInfo();
     } 
}
