#!/bin/bash
IFSOLD=$IFS
IFS=$'\n'
rm loga.log mylog.tar.gz
cd ../release

tar  -zcvf  ../build/mylog.tar.gz     loga.log  
cd ../build

tar -zxvf mylog.tar.gz 


count=0;
for i in $(cat loga.log |tr '\0' ' ' |grep "学号:")
do
echo $i
count=`expr $count + 1`
done

echo -e "用户修改学生信息有:\n"$count"条记录\n"

count=0;
for i in $(cat loga.log |tr '\0' ' ' |grep "课程号")
do
echo $i
count=`expr $count + 1`
done

echo -e "用户修改课程信息有:\n"$count"条记录\n"

read -p "请输入你想查找的学号 :" stu_id
echo -e  "该学生的修改信息如下：\n"
cat loga.log |tr '\0' ' ' |grep $stu_id 

read -p "请输入你要查找的课程(号)信息" cla_id
echo -e "该课程的修改信息如下:\n"
cat loga.log |tr '\0' ' ' |grep "课程号:$cla_id"
IFS=$IFSOLD
