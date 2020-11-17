#include "tool.h"

void ergodic_stu(Stu *q){
    Stu *p=(Stu*)malloc(sizeof(Stu));
    p=q;
    p=p->next;
    while(p->next!=NULL){
    printf("%ld\t%s\t%s\t%s\t%d\n",p->id,p->name,p->List_Class[0],p->List_Class[1],p->score);
    p=p->next;
    }
    printf("%ld\t%s\t%s\t%s\t%d\n",p->id,p->name,p->List_Class[0],p->List_Class[1],p->score);
}
int stu_count(Stu *head){
    Stu *p=head;
    int count=0;
    while(p->next!=NULL){
        count++;
        p=p->next;
    }
    return count;
}
int cla_count(Cla *head){
    Cla *p=head;
    int count=0;
        while(p->next!=NULL){
            count ++;
            p=p->next;
        }
        return count;
}
void stu_add( struct stu *head, struct stu *newstu ,Cla *newcla){
    Cla *p_cla=newcla;
    Stu *p;
    newstu=(Stu*)malloc(sizeof(Stu));
    newstu->List_Class=(char**)malloc(sizeof(char)*60);
    newstu->List_Class[0]=(char*)malloc(sizeof(char)*30);
    newstu->List_Class[1]=(char*)malloc(sizeof(char)*30);
    newstu->name=(char*)malloc(sizeof(char)*20);
    printf("请输入学号鸭:\n");
    scanf("%ld",&newstu->id);
    printf("请输入姓名鸭：\n");
    scanf("%s",newstu->name);
    printf("请输入课程1:\n");
    int count = 0;
    while(count==0){
    scanf("%s",newstu->List_Class[0]);
    while(p_cla->next!=NULL){
        p_cla=p_cla->next;
        if((strcmp(p_cla->name,newstu->List_Class[0]))==0){
            count=1;
    }
    }
    if(count==0){
        printf("你输入的课程名，不在课程列表中，请在先在课程列表添加该课程!\n");
    }
    p_cla=newcla;
    }
    printf("请输入课程2:\n");
    p_cla=newcla;
     count = 0;
    while(count==0){
    scanf("%s",newstu->List_Class[1]);
    while(p_cla->next!=NULL){
        p_cla=p_cla->next;
        if((strcmp(p_cla->name,newstu->List_Class[1]))==0){
            count=1;
        }
    }
    if(count==0){
        printf("你输入的课程名，不在课程列表中，请在先在课程列表添加该课程!\n");

    }
    p_cla=newcla;
    }
    printf("请输入您的课程总分鸭：\n");
    scanf("%d",&newstu->score);
    newstu->next=NULL;
    char buffer[100];                                                     
    memset(buffer,0,sizeof(buffer));
    sprintf(buffer,"\t添加了该学生:学号:%ld,姓名:%s\n",newstu->id,newstu->name);
    write_log_file("loga.log",buffer,strlen(buffer));
    p=head;
    while (p->next!=NULL){
        p=p->next;
    }
    p->next=newstu;
    printf("添加成功！\n");
}
void stu_del(Stu *head,int line){
    Stu *p;
    p=head;
    for (int i = 1 ; i < line ; i ++ ){
        p=p->next;
    }
    char buffer[100];                                                     
    memset(buffer,0,sizeof(buffer));
    sprintf(buffer,"\t删除了了该学生:学号:%ld,姓名:%s\n",p->next->id,p->next->name);
    write_log_file("loga.log",buffer,strlen(buffer));
    Stu *q=p->next;
    p->next=p->next->next;
    free(q);
    printf("修改成功！\n");
}
void stu_modify(Stu *head,int line ,Cla * newcla ){
    Stu *p;
    p=head;
    int i;
    for ( i= 0 ; i < line ; i ++ ){
        p=p->next;
    }
    printf("请输入您想要修改的字段（1～5）1.学生ID 2.学生名 3.课程1 4.课程2 5.总学分\n");
    scanf("%d",&i);
    if(i==1){
        printf("请输入修改后的学号\n");
    char buffer[100];                                                     
    memset(buffer,0,sizeof(buffer));
    sprintf(buffer,"\t学号:%ld,姓名:%s学号从%ld修改为了",p->id,p->name,p->id);
    scanf("%ld",&p->id);
    char buffer1[50];                                                     
    memset(buffer1,0,sizeof(buffer1));
    sprintf(buffer1,"%ld\n",p->id);
    strcat(buffer,buffer1);
    write_log_file("loga.log",buffer,strlen(buffer));
    }
    else if(i==2){
        printf("请输入修改后的姓名\n");
        char buffer[100];                                                     
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"\t学号:%ld,姓名:%s姓名从%s修改为了",p->id,p->name,p->name);
        scanf("%s",p->name);
        char buffer1[50];                                                     
        memset(buffer1,0,sizeof(buffer1));
        sprintf(buffer1,"%s\n",p->name);
        strcat(buffer,buffer1);
        write_log_file("loga.log",buffer,strlen(buffer));
    }
 
    else if(i==3){
        printf("请输入修改后的课程1\n");
        char buffer[100];                                                     
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"\t学号:%ld,姓名:%s课程号1从%s修改为了",p->id,p->name,p->List_Class[0]);
    int count = 0;
    Cla *p_cla=newcla;
    while(count==0){
    scanf("%s",p->List_Class[0]);
    while(p_cla->next!=NULL){
        p_cla=p_cla->next;
        if((strcmp(p_cla->name,p->List_Class[0]))==0){
            count=1;
    }
    }
    if(count==0){
        printf("你输入的课程名，不在课程列表中，请在先在课程列表添加该课程!\n");
    }
    p_cla=newcla;
    }
        char buffer1[50];                                                     
        memset(buffer1,0,sizeof(buffer1));
        sprintf(buffer1,"%s\n",p->List_Class[0]);
        strcat(buffer,buffer1);
        write_log_file("loga.log",buffer,strlen(buffer));
    }
    else if(i==4){
        printf("请输入修改后的课程2\n");
        char buffer[100];                                                     
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"  学号:%ld,姓名:%s课程号2从%s修改为了",p->id,p->name,p->List_Class[1]);
    int count = 0;
    Cla *p_cla=newcla;
    while(count==0){
    scanf("%s",p->List_Class[0]);
    while(p_cla->next!=NULL){
        p_cla=p_cla->next;
        if((strcmp(p_cla->name,p->List_Class[0]))==0){
            count=1;
    }
    }
    if(count==0){
        printf("你输入的课程名，不在课程列表中，请在先在课程列表添加该课程!\n");
    }
    p_cla=newcla;
    }
        char buffer1[50];                                                     
        memset(buffer1,0,sizeof(buffer1));
        sprintf(buffer1,"%s\n",p->List_Class[1]);
        strcat(buffer,buffer1);
        write_log_file("loga.log",buffer,strlen(buffer));
    }
    else if(i==5){
        printf("请输入修改后的总分\n");
        char buffer[100];                                                     
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"\t学号:%ld,姓名:%s总分从%d修改为了",p->id,p->name,p->score);
        scanf("%d",&p->score);
        char buffer1[50];                                                     
        memset(buffer1,0,sizeof(buffer1));
        sprintf(buffer1,"%d\n",p->score);
        strcat(buffer,buffer1);
        write_log_file("loga.log",buffer,strlen(buffer));
    }
    printf("修改成功！\n");
}
void stu_findbyID(Stu *head ,long int id  ){
    Stu *p;
    p=head;
    int count = 0;
    while(p->next!=NULL){
        p=p->next;
        if(p->id==id){
            count=1;
            break;
        }
    }
    if(count==1){

    printf("该学生信息为：%ld\t%s\t%s\t%s\t%d",p->id,p->name,p->List_Class[0],p->List_Class[1],p->score);
    }
    else{
        printf("没有此学生！\n");
    }
}
void stu_findbyNAME(Stu *head , char *stuname){
     Stu *p;
     int count=0;
    p=head;
    while(p->next!=NULL){
        p=p->next;
        if((strcmp(p->name,stuname))==0){
            count = 1;
            break;
        }
    }
    if (count==1){

    printf("该学生信息为：%ld\t%s\t%s\t%s\t%d",p->id,p->name,p->List_Class[0],p->List_Class[1],p->score);
    }else{
        printf("没有这个学生！\n");
    }

}

Stu* stu_file_read(){

  struct stu *p,*head;
  head=(Stu*)malloc(sizeof(Stu));
  p=(Stu*)malloc(sizeof(Stu));
  p=head;
  
  FILE *fp = fopen ("stu.txt","r+w");
  char *id1=(char*)malloc(sizeof(char)*20);
  while ( fscanf(fp,"%s",id1)!=EOF ){
      struct stu *t;
      t=(Stu*)malloc(sizeof(Stu));
      t->id=atoi(id1);
      id1=(char*)malloc(sizeof(char)*20);
      fscanf(fp,"%s",id1);
      t->name=id1;
      id1=(char*)malloc(sizeof(char)*20);
      t->List_Class=(char**)malloc(sizeof(char)*60);
      fscanf(fp,"%s",id1);
      t->List_Class[0]=id1;
      id1=(char*)malloc(sizeof(char)*20);
      fscanf(fp,"%s",id1);
      t->List_Class[1]=id1;
      id1=(char*)malloc(sizeof(char)*20);
      fscanf(fp,"%s",id1);
      t->score=atoi(id1);
      p->next=t;
      p=t; 
      id1=(char*)malloc(sizeof(char)*20);
  }

  p->next=NULL;
  p=head;
  fclose(fp);
  printf("创建成功！\n");
  return p;

}
Stu * stu_stdin_read(){
    Stu *head =(Stu*)malloc(sizeof(Stu));
    Stu *p=(Stu*)malloc(sizeof(Stu));
    p=head;
    printf("请输入你要加入的学生数量\n");
    int  n;
    n=num_input(1,50);
    printf("%d",n);
    for ( int i = 1 ; i <= n ; i ++ ){
        Stu *newstu=(Stu*)malloc(sizeof(Stu));
        newstu->name=(char*)malloc(sizeof(char)*20);
        newstu->List_Class=(char**)malloc(sizeof(char)*40);
        newstu->List_Class[0]=(char*)malloc(sizeof(char)*20);
        newstu->List_Class[1]=(char*)malloc(sizeof(char)*20);
        printf("请输入第%d个学生的id",i);
        scanf("%ld",&newstu->id);
        printf("请输入第%d个学生的姓名",i);
        scanf("%s",newstu->name);
        printf("请输入第%d个学生的课程1",i);
        scanf("%s",newstu->List_Class[0]);
        printf("请输入第%d个学生的课程2",i);
        scanf("%s",newstu->List_Class[1]);
        printf("请输入第%d个学生的课程总分",i);
        scanf("%d",&newstu->score);
        p->next=newstu;
        p=newstu;
   }
    p->next=NULL;
    p=head;
    printf("创建成功！\n");
    return p;
}

int  num_input( int limit_min , int limit_max)
{
    printf("请在%d和%d之间输入数字\n",limit_min,limit_max);
    int sub;
    char *sub1=(char*)malloc(sizeof(char)*20);
    scanf("%s",sub1);
    while(1){
    sub=atoi(sub1);
        if ( sub>= limit_min && sub<=limit_max ){
            break;
        }
     printf("您输入有误，请重新在%d和%d之间输入！\n",limit_min,limit_max);
     scanf("%s",sub1);
    }
    return sub;
}
void ergodic_cla(Cla *p){
    p=p->next;
    while(p->next!=NULL){
    printf("%ld\t%s\t%s\t%d\t%d\t%d\t%d\n",p->id,p->name,p->nature,p->period,p->credit,p->num_people,p->num_highest);
    p=p->next;
    }
    printf("%ld\t%s\t%s\t%d\t%d\t%d\t%d\n",p->id,p->name,p->nature,p->period,p->credit,p->num_people,p->num_highest);
}
void cla_add( struct cla *head, struct cla *newcla ){
    Cla *p;
    newcla=(Cla*)malloc(sizeof(Cla));
    newcla->name=(char*)malloc(sizeof(char)*30);
    newcla->nature=(char*)malloc(sizeof(char)*30);
    printf("请输入课程编号鸭:\n");
    scanf("%ld",&newcla->id);
    printf("请输入课程名称鸭：\n");
    scanf("%s",newcla->name);
    printf("请输入课程性质:\n");
    scanf("%s",newcla->nature);
    printf("请输入授课学时:\n");
    scanf("%d",&newcla->period);
    printf("请输入课程学分鸭：\n");
    scanf("%d",&newcla->credit);
    printf("请输入课程已选人数\n");
    scanf("%d",&newcla->num_people);
    printf("请输入课程人数上限\n");
    scanf("%d",&newcla->num_highest);
    newcla->next=NULL;
    char buffer[100];                                                     
    memset(buffer,0,sizeof(buffer));
    sprintf(buffer,"\t添加了该课程:课程号:%ld,课程名:%s\n",newcla->id,newcla->name);
    write_log_file("loga.log",buffer,strlen(buffer));
    p=head;
    while (p->next!=NULL){
        p=p->next;
    }
    p->next=newcla;
    printf("添加成功！\n");
}
void cla_del(Cla *head,int line){
    Cla *p;
    
    p=head;
    for (int i = 1 ; i < line ; i ++ ){
        p=p->next;
    }
    char buffer[100];                                                     
    memset(buffer,0,sizeof(buffer));
    sprintf(buffer,"\t删除了了该课程：课程号:%ld,课程名:%s\n",p->next->id,p->next->name);
    write_log_file("loga.log",buffer,strlen(buffer));
    Cla *q=p->next;
    p->next=p->next->next;
    free(q);
    printf("删除成功！\n");
}
void cla_modify(Cla *head,int line ){
    Cla *p;
    p=head;
    int i;
    for ( i= 0 ; i < line ; i ++ ){
        p=p->next;
    }
    printf("请输入您想要修改的字段（1～7）1.课程号2.课程名3.课程性质4.授课学时5.学分6.当前人数7.人数上限\n");
    scanf("%d",&i);
    if(i==1){
        printf("请输入修改后的课程号为\n");
    char buffer[100];                                                     
    memset(buffer,0,sizeof(buffer));
    sprintf(buffer,"\t课程号:%ld,课程名:%s课程号从%ld修改为了",p->id,p->name,p->id);
    scanf("%ld",&p->id);
    char buffer1[50];                                                     
    memset(buffer1,0,sizeof(buffer1));
    sprintf(buffer1,"%ld\n",p->id);
    strcat(buffer,buffer1);
    write_log_file("loga.log",buffer,strlen(buffer));
    }
    else if(i==2){
        printf("请输入修改后的课程名\n");
        char buffer[100];                                                     
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"\t课程号:%ld,课程名:%s课程名从%s修改为了",p->id,p->name,p->name);
        scanf("%s",p->name);
        char buffer1[50];                                                     
        memset(buffer1,0,sizeof(buffer1));
        sprintf(buffer1,"%s\n",p->name);
        strcat(buffer,buffer1);
        write_log_file("loga.log",buffer,strlen(buffer));
    }
 
    else if(i==3){
        printf("请输入修改后课程性质\n");
        char buffer[100];                                                     
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"\t课程号:%ld,课程名:%s课程性质从%s修改为了",p->id,p->name,p->nature);
        scanf("%s",p->nature);
        char buffer1[50];                                                     
        memset(buffer1,0,sizeof(buffer1));
        sprintf(buffer1,"%s\n",p->nature);
        strcat(buffer,buffer1);
        write_log_file("loga.log",buffer,strlen(buffer));
    }
    else if(i==4){
        printf("请输入修改后的授课学时\n");
        char buffer[100];                                                     
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"\t课程号:%ld,课程名:%s授课学时从%d修改为了",p->id,p->name,p->period);
        scanf("%d",&p->period);
        char buffer1[50];                                                     
        memset(buffer1,0,sizeof(buffer1));
        sprintf(buffer1,"%d\n",p->period);
        strcat(buffer,buffer1);
        write_log_file("loga.log",buffer,strlen(buffer));
    }
    else if(i==5){
        printf("请输入修改后的学分\n");
        char buffer[100];                                                     
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"\t课程号:%ld,课程名:%s学分从%d修改为了",p->id,p->name,p->credit);
        scanf("%d",&p->credit);
        char buffer1[50];                                                     
        memset(buffer1,0,sizeof(buffer1));
        sprintf(buffer1,"%d\n",p->credit);
        strcat(buffer,buffer1);
        write_log_file("loga.log",buffer,strlen(buffer));
    }
    else if(i == 6){
        printf("请输入修改后的课程已选人数\n");
        char buffer[100];                                                     
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"\t课程号:%ld,课程名:%s课程已选人数从%d修改为了",p->id,p->name,p->num_people);
        scanf("%d",&p->num_people);
        char buffer1[50];                                                     
        memset(buffer1,0,sizeof(buffer1));
        sprintf(buffer1,"%d\n",p->num_people);
        strcat(buffer,buffer1);
        write_log_file("loga.log",buffer,strlen(buffer));
    } 
    else if (i== 7){
        printf("请输入修改后的课程人数上限");
        char buffer[100];                                                     
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"\t课程号:%ld,课程名:%s课程人数上限从%d修改为了",p->id,p->name,p->num_highest);
        scanf("%d",&p->num_highest);
        char buffer1[50];                                                     
        memset(buffer1,0,sizeof(buffer1));
        sprintf(buffer1,"%d\n",p->num_highest);
        strcat(buffer,buffer1);
        write_log_file("loga.log",buffer,strlen(buffer));
    }
    printf("修改成功！\n");
}
void cla_findbyID(Cla *head ,long int id  ){
    Cla *p;
    p=head;
    int count = 0;
    while(p->next!=NULL){
        p=p->next;
        if(p->id==id){
            count=1;
            break;
        }
    }
    if(count==1){

    printf("该课程信息为：%ld\t%s\t%s\t%d\t%d\t%d\t%d\n",p->id,p->name,p->nature,p->period,p->credit,p->num_people,p->num_highest);
    }
    else{
        printf("没有此课程！\n");
    }
}
void cla_findbyNAME(Cla *head , char *claname){
     Cla *p;
     int count=0;
    p=head;
    while(p->next!=NULL){
        p=p->next;
        if((strcmp(p->name,claname))==0){
            count = 1;
            break;
        }
    }
    if (count==1){

    printf("该课程信息为：%ld\t%s\t%s\t%d\t%d\t%d\t%d\n",p->id,p->name,p->nature,p->period,p->credit,p->num_people,p->num_highest);
    }else{
        printf("没有这个课程！\n");
    }
}
Cla* cla_file_read(){

  struct cla *p,*head;
  head=(Cla*)malloc(sizeof(Cla));
  p=(Cla*)malloc(sizeof(Cla));
  p=head;
  
  FILE *fp = fopen ("class.txt","r+w");
  char *id1=(char*)malloc(sizeof(char)*20);
  while ( fscanf(fp,"%s",id1)!=EOF ){
      struct cla *t;
      t=(Cla*)malloc(sizeof(Cla));
      t->id=atoi(id1);
      id1=(char*)malloc(sizeof(char)*30);
      fscanf(fp,"%s",id1);
      t->name=id1;
      id1=(char*)malloc(sizeof(char)*20);
      fscanf(fp,"%s",id1);
      t->nature=id1;
      id1=(char*)malloc(sizeof(char)*20);
      fscanf(fp,"%s",id1);
      t->period=atoi(id1);
      id1=(char*)malloc(sizeof(char)*20);
      fscanf(fp,"%s",id1);
      t->credit=atoi(id1);
      id1=(char*)malloc(sizeof(char)*20);
      fscanf(fp,"%s",id1);
      t->num_people=atoi(id1);
      id1=(char*)malloc(sizeof(char)*20);
      fscanf(fp,"%s",id1);
      t->num_highest=atoi(id1);
      p->next=t;
      p=t; 
      id1=(char*)malloc(sizeof(char)*20);
  }

  p->next=NULL;
  p=head;
  fclose(fp);
  printf("创建成功！\n");
  return p;

}
Cla * cla_stdin_read(){
    Cla *head =(Cla*)malloc(sizeof(Cla));
    Cla *p=(Cla*)malloc(sizeof(Cla));
    p=head;
    printf("请输入你要加入的课程数量\n");
    int  n;
    n=num_input(1,50);
    printf("%d",n);
    for ( int i = 1 ; i <= n ; i ++ ){
        Cla *newstu=(Cla*)malloc(sizeof(Cla));
        newstu->name=(char*)malloc(sizeof(char)*20);
        newstu->nature=(char*)malloc(sizeof(char)*20);
        printf("请输入第%d个课程的id",i);
        scanf("%ld",&newstu->id);
        printf("请输入第%d个课程名字",i);
        scanf("%s",newstu->name);
        printf("请输入第%d个课程的性质",i);
        scanf("%s",newstu->nature);
        printf("请输入第%d个课程的授课学时",i);
        scanf("%d",&newstu->period);
        printf("请输入第%d个课程的课程学分",i);
        scanf("%d",&newstu->credit);
        printf("请输入第%d个课程的人数",i);
        scanf("%d",&newstu->num_people);
        printf("请输入第%d个课程的人数上限",i);
        scanf("%d",&newstu->num_highest);
        p->next=newstu;
        p=newstu;
   }
    p->next=NULL;
    p=head;
    printf("创建成功！\n");
    return p;
}
int cla_judge ( Cla *head,char *cla_sam){

     Cla *p;
    p=head;
    int count = 0;

    while(p->next!=NULL){
        p=p->next;
        if((strcmp(p->name,cla_sam))==0){
            count=1;
            break;
        }
        
    }
    if(count==1){
        return 1;
    }
    else{
        return 0;
    }


}
void get_local_time(char* buffer)
{
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    sprintf(buffer, "%04d-%02d-%02d %02d:%02d:%02d",
    (timeinfo->tm_year+1900), timeinfo->tm_mon, timeinfo->tm_mday,
    timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}

void write_log_file(char *filename,char *buffer,unsigned buf_size){
    FILE *fp;
    fp = fopen(filename,"aw+");
    if(fp!=NULL){
        char now[50];
        memset(now,0,sizeof(now));
        get_local_time(now);
        fwrite(now,strlen(now)+1,1,fp);
        fwrite(buffer,buf_size,1,fp);
        fclose(fp);
        fp=NULL;
    }
}
