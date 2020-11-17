#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
typedef struct stu{   
    long int id;
    char *name;
    char **List_Class;
    int score;
    struct stu *next;
}Stu;
typedef struct cla{
    long int id;
    char *name;
    char *nature;
    int period;
    int credit;
    int num_people;
    int num_highest;
    struct cla  *next;
}Cla;

void ergodic_stu(Stu *p);  //遍历一个学生类型的单链表
int stu_count(Stu *head);  //统计单链表长度
void stu_add( struct stu *head, struct stu *newstu,Cla *newcla ); //增加学生的函数
void stu_del(Stu *head,int line);  //删除学生的函数
void stu_modify(Stu *head,int line ,Cla *newcla ); // 修改学生
void stu_findbyID(Stu *head ,long int id  );   //通过学号查询学生
void stu_findbyNAME(Stu *head , char *stuname);  //通过姓名查询学生
Stu* stu_file_read();   //通过文件读入学生数据
Stu * stu_stdin_read();     //通过键盘读入学生数据 

void ergodic_cla(Cla *p);   //遍历课程类型的单链表
int cla_count(Cla *head);   //统计长度
void cla_add( struct cla *head, struct cla *newcla );  //增加课程
void cla_del(Cla *head,int line);   //删除课程
void cla_modify(Cla *head,int line );   //修改课程信息
void cla_findbyID(Cla *head ,long int id  );    //通过课程号查询课程信息
void cla_findbyNAME(Cla *head , char *claname);   //通过课程名查询课程信息
Cla* cla_file_read();    //通过文件读入课程数据
Cla* cla_stdin_read();    //通过键盘读入课程数据
 
int  num_input( int limit_min , int limit_max);   //从键盘读入min到max的一个值
void get_local_time(char* buffer);   //获取当前时间
void write_log_file(char *filename,char *buffer,unsigned buf_size); //日志文档写入



