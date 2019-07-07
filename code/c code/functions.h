#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

void add(struct card *phead);
void store(struct card *phead);
void read(struct card *phead);
void seek(struct card *phead);
void recharge (struct card *phead) ;
void conclude ( struct card *phead);
void printf_return_info (struct card *phead);
void print_time_info(struct card *phead);
void change(struct card *phead);
void del(struct card *phead) ;
int print (); 
    
    void printf_money (float b) //金钱取整 
{
    printf("\t%dYuan%dJiao%dFen\t",((int)(b*100))/100,((int)(b*100))/10%10,((int)(b*100))%10);
}

int  print () //控制台情况选择 
{
    printf("-----------------------------------------------------------");
    printf("-------------------------------------------------------------\n");
    printf("请选择要操作的选项\n");
    printf("1：【add】录入一条信息\n");
    printf("2：【store】将当前所有信息储存到文件\n");
    printf("3：【read】从文件中读取信息\n");
    printf("4：【delete】删除一条信息\n");
    printf("5：【seek】按校园卡顺序打印某人信息\n");
    printf("6：【统计】统计每个食堂 超市 浴池营业额形成文件报表\n");
    printf("7：【补贴信息】统计所有补贴情况\n");
    printf("8：【某段时间范围内刷卡信息】打印某段时间范围所有刷卡信息\n");
    printf("9：【修改】能够修改1次刷卡信息\n");
    printf("10：【充值】充值一张卡\n");
    printf("11: 【校医院】药品查询\n");
    printf("12: 【图书馆】会议室预约\n");
    printf("0：【退出】\n");
    printf("卡号四位 \t首位 \t1：教师 2：职工 3：学生\n\t\t后三位 001至010\n");
    printf("商店序号五位 \t首位 1：食堂 2：超市 3：浴池\n");
    printf("-----------------------------------------------------------");
    printf("-------------------------------------------------------------\n");
    int choice;
    scanf("%d",&choice);
    return choice;
}

void recharge (struct card *phead)                  //用户输入卡号 充值金额
{
    printf("-----------------------------------------------------------");
    printf("-------------------------------------------------------------\n");
    struct time re_time () ;
    printf("请输入充值卡号 4位数字\n");
    int cardnum=0,flag=0;
    scanf("%d",&cardnum);
    struct card *p=phead,*next=phead->next,*pnew;
    while (p->next!=NULL)
    {
        if (p->cardnum==cardnum)
            if (next->cardnum!=cardnum||next->next==NULL)
            {
                flag=1;
                break;
            }
        p=p->next;
        next=next->next;
    }
    if (flag)
    {
        printf("请输入充值金额\n");
        int plus=0;
        scanf("%d",&plus);
        if (p->leftmon+plus<=1000)
        {
            pnew=(struct card *)malloc(sizeof (struct card));
            pnew->leftmon=p->leftmon+plus;
            pnew->strtime=re_time();
            pnew->shopnum=99999;
            pnew->num=p->num+1;
            pnew->cardnum=cardnum;
            pnew->money=plus;
            printf("充值成功 当前余额为");
            printf_money(pnew->leftmon);
            printf("\n");
        }
        else
        {
            printf("温馨提示 校园卡余额不能超过1000\n");
        }
        return ;
    }
    printf("此卡不存在 请重新输入\n");
}

int time_count (struct time timea,struct time timeb)  //判断时间函数  同月返回1 同日返回2 否则为0
{
    int flag=0;
    if (timea.year==timeb.year)
    {
        if (timea.month==timeb.month)
        {
            flag=1;
            if (timea.day==timeb.day)
                flag=2;
        }
    }
    return flag;
}

struct time re_time ()                                              //获取当前时间并返还
{
    int m,s,d,mo,y,h;
    time_t t=time(0);
    char c[6][4];
    struct time sale_time;
    strftime(c[0],sizeof(c[0]),"%y",localtime(&t));
    strftime(c[1],sizeof(c[1]),"%m",localtime(&t));
    strftime(c[2],sizeof(c[2]),"%d",localtime(&t));
    strftime(c[3],sizeof(c[3]),"%H",localtime(&t));
    strftime(c[4],sizeof(c[4]),"%M",localtime(&t));
    strftime(c[5],sizeof(c[5]),"%S",localtime(&t));
    sale_time.year=(c[0][0]-48)*10+c[0][1]-48;
    sale_time.month=(c[1][0]-48)*10+c[1][1]-48;
    sale_time.day=(c[2][0]-48)*10+c[2][1]-48;
    sale_time.hour=(c[3][0]-48)*10+c[3][1]-48;
    sale_time.minute=(c[4][0]-48)*10+c[4][1]-48;
    sale_time.second=(c[5][0]-48)*10+c[5][1]-48;
    return sale_time;
}

void add(struct card *phead)                                    //用户输入卡号 商家序号 消费金额  （时间自动获取）
{
    printf("-----------------------------------------------------------");
    printf("-------------------------------------------------------------\n");
    int time_count (struct time ,struct time );                 
    struct card *front=phead,*next=phead->next,*pnew;           //front为前节点 next为后节点
    int cardnum,shopnum;
    float sale=0;
    printf("请输入卡号:");
    scanf("%d",&cardnum);
    while (front->cardnum!=cardnum||next->cardnum==cardnum)     //寻找该卡节点
    {
        front=front->next;
        next=next->next;
        if (next==NULL)                                         //未找到或最后一张卡
            break;
    }
    if (front->cardnum==cardnum)                                //找到该卡
    {
        printf("请输入商店序号:");
        scanf("%d",&shopnum);
        if (shopnum/10000==1)                               //食堂
        {
            printf("请输入消费金额:");
            scanf("%f",&sale);
            if (sale>50)                                    
            {
                printf("单次消费金额超过50元\n");
                return ;
            }
            int sum=0;                                      //判断今日已消费金额
            struct time time_temp=re_time();
            if (time_count(time_temp,front->strtime)==2)
            {
                sum=front->sum;
                }
            if (sale+sum>100)                               //今日消费金额超过100
            {
                printf("今日总消费金额不可超过100元\n");
                return ;
            }
            if (front->leftmon>sale)                        //卡内余额充足
            {
                pnew=(struct card *)malloc(sizeof (struct card));
                pnew->cardnum=front->cardnum;
                if ((cardnum/1000==1||cardnum/1000==2)&&sale>=20)       //满足返还条件 返还应先消费 消费成功后再返还
                {
                    pnew->money=-sale;
                    pnew->retmoney=5;
                    //return_money[cardnum/1000-1][cardnum%1000-1]+=5;
                }
                else                                                    //未满足条件
                {
                    pnew->money=-sale;
                    pnew->retmoney=0;
                }
                pnew->leftmon=front->leftmon+pnew->money+pnew->retmoney;
                pnew->num=front->num+1;
                pnew->shopnum=shopnum;
                pnew->strtime=time_temp;
                pnew->sum=sum+sale;
                front->next=pnew;
                pnew->next=next;
                printf("消费成功\n");
                printf("卡号\t余额\t\t序号\t商家编号\t消费时间\t\t消费金额\t\t返还金额\n");
                printf("%d",pnew->cardnum);
                printf_money(pnew->leftmon);
                printf("%d\t%d\t%d年%d月%d日%d时%d分%d秒\t",pnew->num,pnew->shopnum,pnew->strtime.year,pnew->strtime.month,pnew->strtime.day,pnew->strtime.hour,pnew->strtime.minute,pnew->strtime.second);
                printf_money(pnew->money);
                printf_money(pnew->retmoney);
                printf("\n");
            }
            else
            {
                printf("卡内余额不足 请充值\n");
                return ;
            }
        }
        if (shopnum/10000==2)                                   //超市
        {
            printf("请输入消费金额:");
            scanf("%f",&sale);
            int sum=0;                                          //判断今日消费金额
            struct time time_temp=re_time();
            if (time_count(time_temp,front->strtime)==2)
            {
                sum=front->sum;
            }
            if (sale+sum>100)
            {
                printf("今日总消费金额超过100元\n");
                return ;
            }
            if (front->leftmon>sale)
            {
                pnew=(struct card *)malloc(sizeof (struct card));
                pnew->cardnum=front->cardnum;
                pnew->money=-sale;
                pnew->retmoney=0;
                pnew->leftmon=front->leftmon+pnew->money;
                pnew->num=front->num+1;
                pnew->shopnum=shopnum;
                pnew->strtime=time_temp;
                pnew->sum=sum+sale;
                front->next=pnew;
                pnew->next=next;
                printf("消费成功\n");
                printf("卡号\t余额\t\t序号\t商家编号\t消费时间\t\t消费金额\n");
                printf("%d",pnew->cardnum);
                printf_money(pnew->leftmon);
                printf("%d\t%d\t%d年%d月%d日%d时%d分%d秒\t",pnew->num,pnew->shopnum,pnew->strtime.year,pnew->strtime.month,pnew->strtime.day,pnew->strtime.hour,pnew->strtime.minute,pnew->strtime.second);
                printf_money(pnew->money);
                printf("\n");

            }
            else
            {
                printf("卡内余额不足 请充值\n");
                return ;
            }
        }
        if (shopnum/10000==3)                                           //浴池消费
        {
            printf("请输入洗漱时间（未满一分钟按一分钟计）\n");        
            int wash_time=0;
            scanf("%d",&wash_time);
            if (wash_time<=10)                                          
                sale=2;
            else
                sale=0.2*wash_time;
            int sum=0;
            struct time time_temp=re_time();                            //获取时间
            if (time_count(time_temp,front->strtime)==2)                //传递今日消费总额
            {
                sum=front->sum;
            }
            if (cardnum/1000==3)                                        //学生
            {
                int ticket=100;                                         
                if (time_count(time_temp,next->strtime)>0)
                    ticket=next->ticmoney;
                if (ticket+front->leftmon>=sale)                        
                {
                    pnew=(struct card *)malloc(sizeof (struct card));
                    pnew->cardnum=front->cardnum;
                    if (ticket>=sale)                                   
                    {
                        //ticket_use[pnew->cardnum%1000-1]+=sale;
                        ticket-=sale;
                        pnew->leftmon=front->leftmon;
                    }
                    else                                                //券金额不足
                    {
                        //ticket_use[pnew->cardnum%1000-1]+=ticket;
                        pnew->leftmon=front->leftmon+ticket-sale;
                        ticket=0;
                    }
                    next->ticmoney=ticket;                              //在其后节点储存券信息
                    next->strtime=time_temp;
                    pnew->strtime=time_temp;
                    pnew->sum=sum;
                    pnew->retmoney=0;
                    pnew->ticmoney=ticket;
                    pnew->money=-sale;
                    pnew->num=front->num+1;
                    pnew->shopnum=shopnum;
                    pnew->next=next;
                    front->next=pnew;
                    printf("消费成功\n");
                    printf("卡号\t余额\t\t序号\t商家编号\t消费时间\t\t消费金额\n");
                    printf("%d",pnew->cardnum);
                    printf_money(pnew->leftmon);
                    printf("%d\t%d\t%d年%d月%d日%d时%d分%d秒\t",pnew->num,pnew->shopnum,pnew->strtime.year,pnew->strtime.month,pnew->strtime.day,pnew->strtime.hour,pnew->strtime.minute,pnew->strtime.second);
                    printf_money(pnew->money);
                    printf_money(pnew->ticmoney);
                    printf("\n");
                }

                else
                {
                    printf("卡内余额不足 请充值\n");
                }
            }                                                                               //学生消费
            else                                                                            
            {
                    if (front->leftmon>sale)
                {
                    pnew=(struct card *)malloc(sizeof (struct card));
                    pnew->cardnum=front->cardnum;
                    pnew->money=-sale;
                    pnew->retmoney=front->retmoney;
                    pnew->leftmon=front->leftmon+pnew->money;
                    pnew->num=front->num+1;
                    pnew->shopnum=shopnum;
                    pnew->strtime=time_temp;
                    pnew->sum=sum+sale;
                    pnew->retmoney=0;
                    front->next=pnew;
                    pnew->next=next;
                    printf("消费成功\n");
                    printf("卡号\t余额\t\t序号\t商家编号\t消费时间\t\t消费金额\n");
                    printf("%d",pnew->cardnum);
                    printf_money(pnew->leftmon);
                    printf("%d\t%d\t%d年%d月%d日%d时%d分%d秒\t",pnew->num,pnew->shopnum,pnew->strtime.year,pnew->strtime.month,pnew->strtime.day,pnew->strtime.hour,pnew->strtime.minute,pnew->strtime.second);
                    printf_money(pnew->money);
                    printf_money(pnew->retmoney);
                    printf("\n");
                }
                else
                {
                    printf("卡内余额不足 请充值\n");
                    return ;
                }
            }
        }                                                                                   //浴池消费
    }
    else
    {
        printf("未找到该卡 请重新选择\n");
    }                                                                                  //未找到该卡

}

void conclude ( struct card * phead)
{
    printf("-----------------------------------------------------------");
    printf("-------------------------------------------------------------\n");
    float canteen[10][10],shop[5],bathroom[5][20];
    int i,j,kind,numa,numb;
    for (i=0;i<10;i++)
    {
        for (j=0;j<10;j++)
            canteen[i][j]=0;
    }
    for (i=0;i<5;i++)
    {
        shop[i]=0;
    }
    for (i=0;i<5;i++)
    {
        for (j=0;j<20;j++)
            bathroom[i][j]=0;
    }
    struct card * p=phead->next;
    while (p)
    {
        kind=p->shopnum/10000;
        numa=p->shopnum/100%100;
        numb=p->shopnum%100;
        switch (kind)
        {
            case 1 :    canteen[numa-1][numb-1]+=p->money;
                        break;
            case 2 :    shop[numa-1]+=p->money;
                        break;
            case 3 :    bathroom[numa-1][numb-1]+=p->money;
        }
        p=p->next;
    }
    printf("请选择显示方式 1：屏幕输出 2：形成文件\n");
    int choice=0;
    scanf("%d",&choice);
    if (choice==1)
    {
        printf("食堂营业额如下\n食堂编号\t商家编号\t\t营业额\n");
        for (i=0;i<10;i++)
            for (j=0;j<10;j++)
            {
                printf("%d     \t \t%2d       \t",i+1,j+1);
                printf_money(canteen[i][j]);
                printf("\n");
            }
        printf("\n\n超市营业额如下\n超市编号\t\t营业额\n");
        for (i=0;i<5;i++)
        {
                printf("%d     \t \t",i+1);
                printf_money(shop[i]);
                printf("\n");
        }
        printf("\n\n浴池营业额如下\n浴池编号\t洗漱间编号\t\t营业额\n");
        for (i=0;i<5;i++)
            for (j=0;j<20;j++)
            {
                printf("%d     \t \t%2d       \t",i+1,j+1);
                printf_money(bathroom[i][j]);
                printf("\n");
            }
    }
    else if (choice==2)
    {
        FILE *fp=fopen("D:\\conclude.txt","w");
        if (fp==NULL)
        {
            printf("文件打开失败\n");
            exit(0);
        }
        printf("文件打开成功\n");
        fprintf(fp,"食堂营业额如下\n食堂编号\t商家编号\t营业额\n");
        for (i=0;i<10;i++)
            for (j=0;j<10;j++)
                fprintf(fp,"%d   \t\t   %2d    \t    %.2f\n",i+1,j+1,canteen[i][j]);
        fprintf(fp,"超市营业额如下\n超市编号\t营业额\n");
        for (i=0;i<5;i++)
            fprintf(fp,"%d   \t\t  %.2f\n",i+1,shop[i]);
        fprintf(fp,"浴池营业额如下\n浴池编号\t洗漱间编号\t\t营业额\n");
        for (i=0;i<5;i++)
            for (j=0;j<20;j++)
                fprintf(fp,"%d   \t \t  %d   \t \t \t   %.2f\n",i+1,j+1,bathroom[i][j]);
    }
    else
    printf("输入错误\n");
}


void printf_return_info (struct card *phead)
{
    printf("-----------------------------------------------------------");
    printf("-------------------------------------------------------------\n");
    int i,j;
    printf("返还情况如下\n教职工卡号\t\t返还金额\n");
    for (i=0;i<2;i++)
    {
        for (j=0;j<10;j++)
        {
            printf("%d\t\t",(i+1)*1000+j+1);
            //printf_money(return_money[i][j]);
            printf("\n");
        }
    }
    printf("消费券使用情况如下\n学生卡号\t\t抵消金额\n");
    for (i=0;i<10;i++)
    {
        printf("%d\t\t",1001+i);
        //printf_money(ticket_use[i]);
        printf("\n");
    }

}

void store(struct card *phead)
{
    FILE*fp=fopen("E:\\source.txt","w");

    if(fp==NULL)
    {
        printf("文件打开失败!\n\n");
        exit(0);
    }
    printf("文件打开成功!\n\n");

    struct card *pu;
    pu=(struct card*)malloc(sizeof(struct card));
    pu=phead;
    pu=pu->next;
    fwrite (pu,10*sizeof(float),1,fp); //size 目标文件指针 
    //fwrite (retmoney,20*sizeof(float),1,fp);
    fprintf(fp,"卡号\t余额\t编号\t商家号\t\t时间\t\t消费金额\t券金额\t\t补贴金额\t\n");

    while(pu)
    {
        fprintf(fp,"%d\t%.2f\t%d\t%d\t%d年%d月%d日%d时%d分%d秒\t%f\t%f\t%f\n",
           pu->cardnum,pu->leftmon,pu->num,pu->shopnum,pu->strtime.year,pu->strtime.month,pu->strtime.day,pu->strtime.hour,pu->strtime.minute,pu->strtime.second,pu->money,pu->ticmoney,pu->retmoney);
        pu=pu->next;
    }

    int a=fclose(fp);
    if(a!=0)
    {
        printf("文件关闭失败!\n\n");
        exit(0);
    }
    printf("文件关闭成功!\n");

    }



void read(struct card *phead)
{
    printf("-----------------------------------------------------------");
    printf("-------------------------------------------------------------\n");
    FILE *fp=fopen("E:\\source.txt","r");

    if(fp==NULL)
    {
        printf("文件打开失败!\n");
        exit(0);
    }
    printf("文件打开成功!\n");

    char ch;
    fread (fp,10*sizeof(float),1,fp);
    fread (fp,20*sizeof(float),1,fp);
    while(!feof(fp))
    {
        ch=fgetc(fp);
        printf("%c",ch);
    }

    int a=fclose(fp);
    if(a!=0)
    {
        printf("文件关闭失败!\n");
    }
    printf("文件关闭成功!\n");

}
//打印某人信息
void seek(struct card *phead)                             
{
    int flag=0,cardnum;                                  //flag用来判断整个链表中是否有学生信息
    struct card *pnew;
    pnew=phead->next;
    puts("请输入用户卡号\n");
    scanf("%d",&cardnum);
    while(pnew)
    {
        if(pnew->next==NULL)                              //不打印尾节点
        break;
        if(pnew->cardnum==cardnum)
        {
            printf("%d",pnew->cardnum);
            printf_money(pnew->leftmon);                 
            printf("%d\t%d\t%d年%d月%d日%d时%d分%d秒\t",pnew->num,pnew->shopnum,pnew->strtime.year,pnew->strtime.month,pnew->strtime.day,pnew->strtime.hour,pnew->strtime.minute,pnew->strtime.second);
            printf_money(pnew->money);
            printf("\t");
            printf_money(pnew->retmoney);
            printf("\t");
            printf_money(pnew->ticmoney);
            printf("\n");
            flag=1;
        }
        pnew=pnew->next;
    }
    if (!flag)                                                        //考虑到没有学生信息的情况
        puts("没有该学生信息\n");
}
//打印某段时间范围内所有学生信息
int search(struct time begin,struct time end,struct card *p);         
void print_time_info(struct card *phead)
{
    struct time begin,end;                                            //设置起止时间
    int flag=0;                                                       
    struct card *pnew;
    pnew=phead->next;
    puts("请输入想查询的时间段(依次输入年、月、日、时、分、秒)");
    scanf("%d%d%d%d%d%d",&begin.year,&begin.month,&begin.day,&begin.hour,&begin.minute,&begin.second);       //输入想查询的时间段
    scanf("%d%d%d%d%d%d",&end.year,&end.month,&end.day,&end.hour,&end.minute,&end.second);
    while(pnew)
    {
        if ((pnew->shopnum!=59488)&&pnew->next!=NULL)                                                        //不打印空结点和尾结点
            if(search(begin,end,pnew))                                                                      
            {
                printf("%d",pnew->cardnum);
                printf_money(pnew->leftmon);
                printf("%d\t%d\t%d年%d月%d日%d时%d分%d秒\t",pnew->num,pnew->shopnum,pnew->strtime.year,pnew->strtime.month,pnew->strtime.day,pnew->strtime.hour,pnew->strtime.minute,pnew->strtime.second);
                printf_money(pnew->money);
                printf("\t");
                printf_money(pnew->retmoney);
                printf("\t");
                printf_money(pnew->ticmoney);
                printf("\n");
                flag=1;
            }
        pnew=pnew->next;
    }
    if (!flag)
        printf("在此时间范围内无任何信息\n");
}
//换算时间函数
long long change_time (struct time from)                                                                                  //秒的计数很大，要用long long型
{
    long long second =0;
     second=(((((from.year*12+from.month)*31+from.day)*24+from.hour)*60+from.minute)*60+from.second);                     
    return second ;
}
//比较时间点是否在某时间范围内函数
int search(struct time begin,struct time end,struct card *p)
           {
               long long begin_time=change_time(begin),end_time=change_time(end),p_time=change_time(p->strtime);          //换算时间
               if (begin_time<=p_time)
                    if (end_time>=p_time)
                    return 1;
                    return 0;
           }

//修改函数
void change(struct card *phead)                  //函数定义
{
    int time_count (struct time ,struct time );
    int i,kind,cnum,num;                         //kind为信息种类，cnum为要修改的卡号，num为要修改的序号
    int shopnum;                                 
    float sale=0;                                
    struct card *t,*front,*next;                 //t指向要修改的节点，front指向前一个节点，next指向后一个节点
    for(i=1;i<=120;i++)
    {
        printf("-");
    }
    printf("\n");                               
    printf("请输入你要修改的卡号\n");
    scanf("%d",&cnum);                          
    front=phead;
    t=front->next;
    next=t->next;                               //初始化指针
    while((t->cardnum!=cnum||t->next->cardnum==cnum)&&next!=NULL)
    {
          t=t->next;                            //使t指向要修改的节点
          front=front->next;                    //使front指向前一个节点
          next=next->next;                      //使next指向下一个节点
    }
    if(next==NULL)
    {
        printf("未找到该卡号\n");
        return ;
    }
    if(t->shopnum==59488)
    {
        printf("该卡暂无消费信息\n");
        return ;
    }
    printf("请输入商家序号\n");
    scanf("%d",&shopnum);             //获取商家序号
    if(!(shopnum>=10000&&shopnum<=99999))
    {
        return ;
    }
    kind=shopnum/10000;               //判断消费种类
    switch(kind)                           
    {
        case 1:t->leftmon=front->leftmon;      
               t->sum=front->sum;               //把今日消费余额恢复为上次状态
                t->retmoney=front->retmoney;
                break;
        case 2:t->leftmon=front->leftmon;         
                t->sum=front->sum;                 
                break;
        case 3: if(front->leftmon==t->leftmon)          
                {
                    next->ticmoney=next->ticmoney+t->money;
                }
                else
                {
                    if(front->leftmon-t->leftmon==-(t->money))//全部使用了余额消费
                    {
                        t->leftmon=front->leftmon;
                    }
                    else
                    {
                        t->leftmon=front->leftmon+t->money+next->ticmoney;
                       next->ticmoney=0;
                    }
                }
                break;
        case 5:t->leftmon=front->leftmon;
                break;
    }
    if(kind==1)
    {
        printf("请输入消费金额:");
        scanf("%f",&sale);              //获取消费金额
        if (sale>50)                    //单词消费超过50
        {
            printf("单次消费金额超过50元了\n");
            return ;
        }
        int sum=0;                                      //初始化今日总消费
        struct time time_temp=re_time();                   //获取消费时间
        if (time_count(time_temp,front->strtime)==2)        //若与上一条信息为同一天
        {
            sum=front->sum;                                 //将今日消费总额初始化为上一条信息的今日消费总额
        }
        if (sale+sum>100)                               //今日消费金额超过100
        {
            printf("今日总消费金额超过100元了\n");
            return ;
        }
       if (front->leftmon>sale)                        //卡内余额充足
        {
            if ((t->cardnum/1000==1||t->cardnum/1000==2)&&sale>=20)       //满足返还条件 返还应先消费 消费成功后再返还
            {
                t->money=-sale;
                t->retmoney=5;
            }
            else                                                    
            {
                t->money=-sale;
                t->retmoney=0;
            }
            t->leftmon=front->leftmon+t->money+t->retmoney;
            t->shopnum=shopnum;
            t->strtime=time_temp;
            t->sum=sum+sale;
            t->strmon.fen=(int)(sale)%10;
            t->strmon.jiao=(int)(sale)/10%10;
            t->strmon.yuan=(int)(sale)/100;               //修改余额，商家序号，时间，今日消费总额，消费金额
            printf("修改成功\n");                           
            printf("卡号\t余额\t序号\t商家编号\t消费时间\t消费金额\t返还金额\n");
            printf("%d\t%.2f\t%d\t%d\t%d年%d月%d日%d时%d分%d秒\t%f\t%f\n",t->cardnum,t->leftmon,t->num,t->shopnum,t->strtime.year,t->strtime.month,t->strtime.day,t->strtime.hour,t->strtime.minute,t->strtime.second,t->money,t->retmoney);
        }
        else
        {                                                   //余额不足，提醒充值
            printf("卡内余额不足 请充值\n");
            return ;
        }
    }
    if(kind==2)                            //超市消费
    {
        printf("请输入消费金额:");
        scanf("%f",&sale);                      //获取消费金额
        int sum=0;                                         
        struct time time_temp=re_time();                //获取时间
        if (time_count(time_temp,front->strtime)==2)        
        {
            sum=front->sum;                                 //将今日消费总额初始化为上一条信息的今日消费总额
        }
        if (sale+sum>100)                                  
        {
            printf("今日总消费金额超过100元\n");
            return ;
        }
        if (front->leftmon>sale)                            //余额充足
        {
            t->money=-sale;
            t->retmoney=0;
            t->leftmon=front->leftmon+t->money;
            t->shopnum=shopnum;
            t->strtime=time_temp;
            t->sum=sum+sale;
            t->strmon.fen=(int)(sale)%10;
            t->strmon.jiao=(int)(sale)/10%10;
            t->strmon.yuan=(int)(sale)/100;                    
            printf("修改成功\n");
            printf("卡号\t余额\t序号\t商家编号\t消费时间\t消费金额\n");
            printf("%d\t%.2f\t%d\t%d\t%d年%d月%d日%d时%d分%d秒\t%f\t%f\n",t->cardnum,t->leftmon,t->num,t->shopnum,t->strtime.year,t->strtime.month,t->strtime.day,t->strtime.hour,t->strtime.minute,t->strtime.second,t->money);
        }
        else
        {
            printf("卡内余额不足 请充值\n");
            return ;
        }
    }
    if(kind==3)                        //浴池消费
    {
        printf("请输入洗漱时间（未满一分钟按一分钟计）\n");        
        int wash_time=0;
        scanf("%d",&wash_time);
        if (wash_time<=10)                                          //计算消费金额
            sale=2;
        else
            sale=0.2*wash_time;
        int sum=0;
        struct time time_temp=re_time();                            //获取时间
        if (time_count(time_temp,front->strtime)==2)                //传递今日消费总额
        {
            sum=front->sum;
        }
        if (t->cardnum/1000==3)                                        //若为学生
        {
            int ticket=100;                                        
            if (time_count(time_temp,next->strtime)>0)
                ticket=next->ticmoney;
            if (ticket+front->leftmon>=sale)                        
            {
                if (ticket>=sale)                                   
                {
                    ticket-=sale;
                    t->leftmon=front->leftmon;
                }
                else                                                
                {
                    t->leftmon=front->leftmon+ticket-sale;
                    ticket=0;
                }
                next->ticmoney=ticket;                              
                next->strtime=time_temp;                            
                t->sum=sum;
                t->retmoney=0;
                t->ticmoney=ticket;
                t->money=-sale;
                t->shopnum=shopnum;                                 //修改今日消费总额，补贴金额，劵金额，消费金额，商家序号
                printf("修改成功\n");
                printf("卡号\t余额\t序号\t商家编号\t消费时间\t消费金额\t消费券余额\n");
                printf("%d\t%.2f\t%d\t%d\t%d年%d月%d日%d时%d分%d秒\t%f\t%f\t%f\n",t->cardnum,t->leftmon,t->num,t->shopnum,t->strtime.year,t->strtime.month,t->strtime.day,t->strtime.hour,t->strtime.minute,t->strtime.second,t->money,t->ticmoney);
            }

            else
            {
                printf("卡内余额不足 请充值\n");
            }
        }                                                                               //学生消费
        else                                                                            //非学生消费
        {
            if (front->leftmon>sale)                   //余额足够本次消费
            {
                t->money=-sale;
                t->leftmon=front->leftmon+t->money;
                t->shopnum=shopnum;
                t->strtime=time_temp;
                t->sum=sum+sale;
                t->retmoney=0;                           //修改消费金额，补贴金额，余额，商家序号，时间，今日消费总额
                printf("修改成功\n");                     //打印最新信息
                printf("卡号\t余额\t序号\t商家编号\t消费时间\t消费金额\t返还金额\n");
                printf("%d\t%.2f\t%d\t%d\t%d年%d月%d日%d时%d分%d秒\t%f\t%f\n",t->cardnum,t->leftmon,t->num,t->shopnum,t->strtime.year,t->strtime.month,t->strtime.day,t->strtime.hour,t->strtime.minute,t->strtime.second,t->money,t->retmoney);
            }
            else
            {                                           //余额不足
                printf("卡内余额不足 请充值\n");
                return ;
            }
        }
    }                                                    //浴池消费
}

//删除函数
void del(struct card *phead)          //函数定义
{
    int cnum,num,i,kind;                  //cnum为要删除的卡号，num为要删除的序号
    struct card *t,*front,*next;                 //p0为工作指针
    for(i=1;i<=120;i++)
    {
        printf("-");
    }
    printf("\n");                         
    printf("请输入你要删除的信息的卡号\n");
    scanf("%d",&cnum);
    t=phead->next;
    next=t->next;
    front=phead;                            //初始化
    while((t->cardnum!=cnum||t->next->cardnum==cnum)&&next!=NULL)//若找到要删除的节点或者到达链表末端结束
    {
        front=t;
        t=t->next;
        next=next->next ;                      //遍历链表
    }
    if(next==NULL)
    {
        printf("未找到该卡号\n");
        return ;
    }
    if(t->shopnum==59488)
    {
        printf("该卡暂无消费信息\n");
        return ;
    }
    kind=(t->shopnum)/10000;
    if(kind==3)                                 //若修改的是洗漱消费
    {
        if(front->leftmon-t->leftmon==-(t->money))         
        {
            next->ticmoney=next->ticmoney-t->money;
        }
        else
        {
            if(front->leftmon-t->leftmon<-(t->money)&&front->leftmon!=t->leftmon)
            {
                next->ticmoney=next->ticmoney+(front->leftmon-t->leftmon);//一部分使用洗漱劵一部分使用余额消费
            }
        }
    }
    front->next=t->next;
    free(t);
    for(i=1;i<=120;i++)
    {
        printf("-");
    }
    printf("\n");                          
    printf("删除成功\n");
}
#endif
