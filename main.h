#include<stdio.h>
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
extern void entermenu_stu(Stu *head , Cla *head_cla);
extern void entermenu_cla(Cla *head , Stu *head_stu);
extern Cla * creathead_cla();
extern Stu * creathead_stu();
extern int num_input(int limit_min,int  limit_max);
