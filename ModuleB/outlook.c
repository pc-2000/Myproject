#include "outlook.h"
void entermenu_stu(Stu *head,Cla *head_cla){

     printf("-------------欢迎来到学生信息管理系统--------------\n");
     Stu * p   =(Stu*)malloc(sizeof(Stu));
     p=head;
         printf("-----------------------------------------\n|  1.增加学生\t\t\t\t|\n|  2.删除学生\t\t\t\t|\n|  3.修改学生信息\t\t\t|\n|  4.查找学生信息\t\t\t|\n|  5.查看当前学生列表\t\t\t|\n|  6.切换到课程管理界面\t\t\t|\n|  7.通过log日至文档查询修改记录\t|\n|  0.退出该系统！\t\t\t|\n-----------------------------------------\n\n");
     int judge =9;
 
     while(1){
         

   if(judge ==0){
             break;
         }
   if(judge ==1){
    Stu * newstu;
     stu_add(p,newstu,head_cla);
     p=head;
   }
   if(judge==2){
       printf("请输入你要删除的学生行\n");
       int n ,line;
       n=stu_count(p);
       line=num_input(1,n);
       stu_del(p,line);
       p=head;
   }
   if(judge==3){
       printf("请输入你要修改的学生行\n");
       int n ,line;
       n=stu_count(p);
       line=num_input(1,n);
       stu_modify(p,line,head_cla);
       p=head;
   }
   if(judge==4){
      printf("请选择你要查找的方式（学号/姓名）（1/2）\n");
      int select = num_input(1,2);
      if(select==0){
          printf("请选择你要查找的学号\n");
          long int stu_id;
          scanf("%ld",&stu_id);
          stu_findbyID(p,stu_id);
          p=head;
      }
      if(select==1){
          printf("请选择你要查找的姓名\n");
          char *stu_name=(char *)malloc(sizeof(char)*20);
          scanf("%s",stu_name);
          stu_findbyNAME(p,stu_name);
          p=head;
      }
   }
   if(judge==5){
       ergodic_stu(p);
       p=head;
   }
   if(judge==6){
       entermenu_cla(head_cla,head);
       break;
   }
   if(judge==7){
        system(" cat ./loga.log |tr '\\0' ' ' " );
   }
   if(judge!=9){
   printf("-----------------------------------------\n|  1.增加学生\t\t\t\t|\n|  2.删除学生\t\t\t\t|\n|  3.修改学生信息\t\t\t|\n|  4.查找学生信息\t\t\t|\n|  5.查看当前学生列表\t\t\t|\n|  6.切换到课程管理界面\t\t\t|\n|  7.通过log日至文档查询修改记录\t|\n|  0.退出该系统！\t\t\t|\n-----------------------------------------\n\n");
   }
   
      judge=num_input(0,7);
   

     }
   }
   
   void entermenu_cla(Cla *head,Stu *head_stu){
     printf("-------------欢迎来到课程信息管理系统--------------\n");
     Cla * p   =(Cla*)malloc(sizeof(Cla));
     p=head;
     int judge =9;
       printf("+++++++++++++++++++++++++++++++++++++++++\n+  1.增加课程\t\t\t\t+\n+  2.删除课程\t\t\t\t+\n+  3.修改课程信息\t\t\t+\n+  4.查找课程信息\t\t\t+\n+  5.查看当前课程列表\t\t\t+\n+  6.切换到学生管理系统\t\t\t+\n+  7.通过log日至文档查询用户的记录\t+\n+  0.退出系统\t\t\t\t+\n+++++++++++++++++++++++++++++++++++++++++\n\n");
     while(1){
         if(judge ==0){
             break;
         }
   
   if(judge ==1){
 
    Cla * newcla;
     cla_add(p,newcla);
     p=head;
   }
   if(judge==2){
       printf("请输入你要删除的课程行\n");
       int n,line ;
       n=cla_count(p);
       line=num_input(1,n);
       cla_del(p,line);
       p=head;
   }
   if(judge==3){
       printf("请输入你要修改的课程行\n");
       int n ,line;
       n=cla_count(p);
       line=num_input(1,n);
       cla_modify(p,line);
       p=head;
   }
   if(judge==4){
      printf("请选择你要查找的方式（课程号/课程名）（1/2）\n");
      int select = num_input(1,2);
      if(select==0){
          printf("请选择你要查找的课程号\n");
          long int stu_id;
          scanf("%ld",&stu_id);
          cla_findbyID(p,stu_id);
          p=head;
      }
      if(select==1){
          printf("请选择你要查找的课程名\n");
          char *stu_name=(char *)malloc(sizeof(char)*30);
          scanf("%s",stu_name);
          cla_findbyNAME(p,stu_name);
          p=head;
      }
   }
   if(judge==5){
       ergodic_cla(p);
       p=head;
   }
   if(judge==6){
       entermenu_stu(head_stu,head);
       break;
   }
   if(judge==7){
       system("cat loga.log |tr '\\0' ' ' ");
   }
       if(judge!=9){
        printf("+++++++++++++++++++++++++++++++++++++++++\n+  1.增加课程\t\t\t\t+\n+  2.删除课程\t\t\t\t+\n+  3.修改课程信息\t\t\t+\n+  4.查找课程信息\t\t\t+\n+  5.查看当前课程列表\t\t\t+\n+  6.切换到学生管理系统\t\t\t+\n+  7.通过log日至文档查询用户的记录\t+\n+  0.退出系统\t\t\t\t+\n+++++++++++++++++++++++++++++++++++++++++\n\n");}
      judge=num_input(0,7);
   

     }
   }
Cla * creathead_cla(){

     printf("请输入您要选择的课程信息录入方式（手动输入/文件输入）（1/2)\n");
     int n =num_input(1,2);
     Cla * head=(Cla*)malloc(sizeof(Cla));
     if(n==1){
     head=cla_stdin_read();
 }
     else if (n==2){
     head=cla_file_read();
     }
     return head;
}  
Stu *creathead_stu(){

     printf("请输入您要选择的学生信息录入方式（手动输入/文件输入）（1/2)\n");
     int n =num_input(1,2);
     Stu * head=(Stu*)malloc(sizeof(Stu));
     if(n==1){
     head=stu_stdin_read();
 }
     else if (n==2){
     head=stu_file_read();
     }
     return head;
}
