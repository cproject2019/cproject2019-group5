#include<stdio.h>
#include<string.h>
int a[5][7][11][101]={0};
int b[5][7][11]={0};
void main()
{
void menu();
b[1][2][4]=1,b[1][2][8]=1,b[1][3][1]=1,b[1][3][3]=1,b[1][4][6]=1,
b[1][4][5]=1,b[2][3][4]=1,b[2][5][7]=1,b[2][6][6]=1,b[3][2][3]=1,
b[3][4][5]=1,b[3][5][6]=1,b[4][2][4]=1,b[4][2][7]=1,b[4][3][5]=1,b[4][3][8]=1,b[4][5][5]=1;
menu();
}
void menu()
{
void menu_guanliyuan();
void menu_xuesheng();
int i;
printf("1.管理人员入口/n");
printf("2.学生占座入口/n");
printf("3.退出占座系统/n");
printf("请输入数字1-3进行选择：/n");
scanf("%d",&i);
switch(i)
{
case 1:menu_guanliyuan();break;
case 2:menu_xuesheng();break;
case 3:break;
}}
void menu_guanliyuan()
{
void tianjia();
void chongzhi();
int i;
printf("1.查询已占座位/n");
printf("2.重置座位信息/n");
printf("3.返回/n");
    printf("请输入数字1-3进行选择:/n");
scanf("%d",&i);
switch(i)
{
    case 1:tianjia();break;
    case 2:chongzhi();break;
    case 3:menu();
}}
void tianjia()
{
printf("已占座情况：");
int x=1,y=1,z=1;
int t=x*100+z;
for(x=1;x<5;x++)
{
for(y=1;y<7;y++)
{
for(z=1;z<11;z++)
{
if(b[x][y][z]==1)
printf("图书馆%d楼%d阅览室/n",&x&t);
}}}
void chongzhi()
{
        int x=1,y=1,z=1;
for(x=1;x<5;x++)
{
for(y=1;y<7;y++)
{
for(z=1;z<11;z++)
{
b[x][y][z]=0;
}}}
printf("重置成功，学生已离开座位/n");
menu_guanliyuan();
}
void menu_xuesheng()
{
void zhanzuo();
printf("1.占座/n");
printf("2.返回/n");
int i;
scanf("%d",&i);
switch(i)
{
    case 1:zhanzuo();break;
    case 2:menu();
}}
void zhanzuo()
{
int w,x,y,z；
printf("请输入数字1-4确认你想占座的楼层/n");
printf("1 一楼/n");
printf("2 二楼/n");
printf("3 三楼/n");
printf("4 四楼/n");
scanf("%d",&w);
printf("请输入数字1-6确认图书馆%d楼的阅览室编号",&w);
scanf("%d",&x);
if(b[w][x][y]==0)
{
printf("请选择你要占的座位号(1~100)：");
scanf("%d",&z);
if(a[w][x][y][z]==0)
printf("占座成功，你占的座位是图书馆%d楼%d阅览室%d号位",&w&x&z);
else
{
printf("此座位正在使用或暂时不可用，请选择其他座位/n");
            menu_xuesheng();
}}
else
{
printf("此阅览室已封闭，请选择其他阅览室/n");
    menu_xuesheng();
}}}