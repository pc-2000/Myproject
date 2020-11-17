#include <stdio.h>
#include "main.h"
int main()
{   
    Stu *head_stu=creathead_stu();
    Cla *head_cla=creathead_cla();
    printf("进入学生管理输入1，进入课程管理进入2\n");
    int n;
    n=num_input(1,2);
    if(n==1){
        entermenu_stu(head_stu,head_cla);
    }
    else{
        entermenu_cla(head_cla,head_stu);
    }
    return 0;
}

