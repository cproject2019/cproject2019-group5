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
    
    void printf_money (float b) //��Ǯȡ�� 
{
    printf("\t%dYuan%dJiao%dFen\t",((int)(b*100))/100,((int)(b*100))/10%10,((int)(b*100))%10);
}

int  print () //����̨���ѡ�� 
{
    printf("-----------------------------------------------------------");
    printf("-------------------------------------------------------------\n");
    printf("��ѡ��Ҫ������ѡ��\n");
    printf("1����add��¼��һ����Ϣ\n");
    printf("2����store������ǰ������Ϣ���浽�ļ�\n");
    printf("3����read�����ļ��ж�ȡ��Ϣ\n");
    printf("4����delete��ɾ��һ����Ϣ\n");
    printf("5����seek����У԰��˳���ӡĳ����Ϣ\n");
    printf("6����ͳ�ơ�ͳ��ÿ��ʳ�� ���� ԡ��Ӫҵ���γ��ļ�����\n");
    printf("7����������Ϣ��ͳ�����в������\n");
    printf("8����ĳ��ʱ�䷶Χ��ˢ����Ϣ����ӡĳ��ʱ�䷶Χ����ˢ����Ϣ\n");
    printf("9�����޸ġ��ܹ��޸�1��ˢ����Ϣ\n");
    printf("10������ֵ����ֵһ�ſ�\n");
    printf("11: ��УҽԺ��ҩƷ��ѯ\n");
    printf("12: ��ͼ��ݡ�������ԤԼ\n");
    printf("0�����˳���\n");
    printf("������λ \t��λ \t1����ʦ 2��ְ�� 3��ѧ��\n\t\t����λ 001��010\n");
    printf("�̵������λ \t��λ 1��ʳ�� 2������ 3��ԡ��\n");
    printf("-----------------------------------------------------------");
    printf("-------------------------------------------------------------\n");
    int choice;
    scanf("%d",&choice);
    return choice;
}

void recharge (struct card *phead)                  //�û����뿨�� ��ֵ���
{
    printf("-----------------------------------------------------------");
    printf("-------------------------------------------------------------\n");
    struct time re_time () ;
    printf("�������ֵ���� 4λ����\n");
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
        printf("�������ֵ���\n");
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
            printf("��ֵ�ɹ� ��ǰ���Ϊ");
            printf_money(pnew->leftmon);
            printf("\n");
        }
        else
        {
            printf("��ܰ��ʾ У԰�����ܳ���1000\n");
        }
        return ;
    }
    printf("�˿������� ����������\n");
}

int time_count (struct time timea,struct time timeb)  //�ж�ʱ�亯��  ͬ�·���1 ͬ�շ���2 ����Ϊ0
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

struct time re_time ()                                              //��ȡ��ǰʱ�䲢����
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

void add(struct card *phead)                                    //�û����뿨�� �̼���� ���ѽ��  ��ʱ���Զ���ȡ��
{
    printf("-----------------------------------------------------------");
    printf("-------------------------------------------------------------\n");
    int time_count (struct time ,struct time );                 
    struct card *front=phead,*next=phead->next,*pnew;           //frontΪǰ�ڵ� nextΪ��ڵ�
    int cardnum,shopnum;
    float sale=0;
    printf("�����뿨��:");
    scanf("%d",&cardnum);
    while (front->cardnum!=cardnum||next->cardnum==cardnum)     //Ѱ�Ҹÿ��ڵ�
    {
        front=front->next;
        next=next->next;
        if (next==NULL)                                         //δ�ҵ������һ�ſ�
            break;
    }
    if (front->cardnum==cardnum)                                //�ҵ��ÿ�
    {
        printf("�������̵����:");
        scanf("%d",&shopnum);
        if (shopnum/10000==1)                               //ʳ��
        {
            printf("���������ѽ��:");
            scanf("%f",&sale);
            if (sale>50)                                    
            {
                printf("�������ѽ���50Ԫ\n");
                return ;
            }
            int sum=0;                                      //�жϽ��������ѽ��
            struct time time_temp=re_time();
            if (time_count(time_temp,front->strtime)==2)
            {
                sum=front->sum;
                }
            if (sale+sum>100)                               //�������ѽ���100
            {
                printf("���������ѽ��ɳ���100Ԫ\n");
                return ;
            }
            if (front->leftmon>sale)                        //����������
            {
                pnew=(struct card *)malloc(sizeof (struct card));
                pnew->cardnum=front->cardnum;
                if ((cardnum/1000==1||cardnum/1000==2)&&sale>=20)       //���㷵������ ����Ӧ������ ���ѳɹ����ٷ���
                {
                    pnew->money=-sale;
                    pnew->retmoney=5;
                    //return_money[cardnum/1000-1][cardnum%1000-1]+=5;
                }
                else                                                    //δ��������
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
                printf("���ѳɹ�\n");
                printf("����\t���\t\t���\t�̼ұ��\t����ʱ��\t\t���ѽ��\t\t�������\n");
                printf("%d",pnew->cardnum);
                printf_money(pnew->leftmon);
                printf("%d\t%d\t%d��%d��%d��%dʱ%d��%d��\t",pnew->num,pnew->shopnum,pnew->strtime.year,pnew->strtime.month,pnew->strtime.day,pnew->strtime.hour,pnew->strtime.minute,pnew->strtime.second);
                printf_money(pnew->money);
                printf_money(pnew->retmoney);
                printf("\n");
            }
            else
            {
                printf("�������� ���ֵ\n");
                return ;
            }
        }
        if (shopnum/10000==2)                                   //����
        {
            printf("���������ѽ��:");
            scanf("%f",&sale);
            int sum=0;                                          //�жϽ������ѽ��
            struct time time_temp=re_time();
            if (time_count(time_temp,front->strtime)==2)
            {
                sum=front->sum;
            }
            if (sale+sum>100)
            {
                printf("���������ѽ���100Ԫ\n");
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
                printf("���ѳɹ�\n");
                printf("����\t���\t\t���\t�̼ұ��\t����ʱ��\t\t���ѽ��\n");
                printf("%d",pnew->cardnum);
                printf_money(pnew->leftmon);
                printf("%d\t%d\t%d��%d��%d��%dʱ%d��%d��\t",pnew->num,pnew->shopnum,pnew->strtime.year,pnew->strtime.month,pnew->strtime.day,pnew->strtime.hour,pnew->strtime.minute,pnew->strtime.second);
                printf_money(pnew->money);
                printf("\n");

            }
            else
            {
                printf("�������� ���ֵ\n");
                return ;
            }
        }
        if (shopnum/10000==3)                                           //ԡ������
        {
            printf("������ϴ��ʱ�䣨δ��һ���Ӱ�һ���Ӽƣ�\n");        
            int wash_time=0;
            scanf("%d",&wash_time);
            if (wash_time<=10)                                          
                sale=2;
            else
                sale=0.2*wash_time;
            int sum=0;
            struct time time_temp=re_time();                            //��ȡʱ��
            if (time_count(time_temp,front->strtime)==2)                //���ݽ��������ܶ�
            {
                sum=front->sum;
            }
            if (cardnum/1000==3)                                        //ѧ��
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
                    else                                                //ȯ����
                    {
                        //ticket_use[pnew->cardnum%1000-1]+=ticket;
                        pnew->leftmon=front->leftmon+ticket-sale;
                        ticket=0;
                    }
                    next->ticmoney=ticket;                              //�����ڵ㴢��ȯ��Ϣ
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
                    printf("���ѳɹ�\n");
                    printf("����\t���\t\t���\t�̼ұ��\t����ʱ��\t\t���ѽ��\n");
                    printf("%d",pnew->cardnum);
                    printf_money(pnew->leftmon);
                    printf("%d\t%d\t%d��%d��%d��%dʱ%d��%d��\t",pnew->num,pnew->shopnum,pnew->strtime.year,pnew->strtime.month,pnew->strtime.day,pnew->strtime.hour,pnew->strtime.minute,pnew->strtime.second);
                    printf_money(pnew->money);
                    printf_money(pnew->ticmoney);
                    printf("\n");
                }

                else
                {
                    printf("�������� ���ֵ\n");
                }
            }                                                                               //ѧ������
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
                    printf("���ѳɹ�\n");
                    printf("����\t���\t\t���\t�̼ұ��\t����ʱ��\t\t���ѽ��\n");
                    printf("%d",pnew->cardnum);
                    printf_money(pnew->leftmon);
                    printf("%d\t%d\t%d��%d��%d��%dʱ%d��%d��\t",pnew->num,pnew->shopnum,pnew->strtime.year,pnew->strtime.month,pnew->strtime.day,pnew->strtime.hour,pnew->strtime.minute,pnew->strtime.second);
                    printf_money(pnew->money);
                    printf_money(pnew->retmoney);
                    printf("\n");
                }
                else
                {
                    printf("�������� ���ֵ\n");
                    return ;
                }
            }
        }                                                                                   //ԡ������
    }
    else
    {
        printf("δ�ҵ��ÿ� ������ѡ��\n");
    }                                                                                  //δ�ҵ��ÿ�

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
    printf("��ѡ����ʾ��ʽ 1����Ļ��� 2���γ��ļ�\n");
    int choice=0;
    scanf("%d",&choice);
    if (choice==1)
    {
        printf("ʳ��Ӫҵ������\nʳ�ñ��\t�̼ұ��\t\tӪҵ��\n");
        for (i=0;i<10;i++)
            for (j=0;j<10;j++)
            {
                printf("%d     \t \t%2d       \t",i+1,j+1);
                printf_money(canteen[i][j]);
                printf("\n");
            }
        printf("\n\n����Ӫҵ������\n���б��\t\tӪҵ��\n");
        for (i=0;i<5;i++)
        {
                printf("%d     \t \t",i+1);
                printf_money(shop[i]);
                printf("\n");
        }
        printf("\n\nԡ��Ӫҵ������\nԡ�ر��\tϴ������\t\tӪҵ��\n");
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
            printf("�ļ���ʧ��\n");
            exit(0);
        }
        printf("�ļ��򿪳ɹ�\n");
        fprintf(fp,"ʳ��Ӫҵ������\nʳ�ñ��\t�̼ұ��\tӪҵ��\n");
        for (i=0;i<10;i++)
            for (j=0;j<10;j++)
                fprintf(fp,"%d   \t\t   %2d    \t    %.2f\n",i+1,j+1,canteen[i][j]);
        fprintf(fp,"����Ӫҵ������\n���б��\tӪҵ��\n");
        for (i=0;i<5;i++)
            fprintf(fp,"%d   \t\t  %.2f\n",i+1,shop[i]);
        fprintf(fp,"ԡ��Ӫҵ������\nԡ�ر��\tϴ������\t\tӪҵ��\n");
        for (i=0;i<5;i++)
            for (j=0;j<20;j++)
                fprintf(fp,"%d   \t \t  %d   \t \t \t   %.2f\n",i+1,j+1,bathroom[i][j]);
    }
    else
    printf("�������\n");
}


void printf_return_info (struct card *phead)
{
    printf("-----------------------------------------------------------");
    printf("-------------------------------------------------------------\n");
    int i,j;
    printf("�����������\n��ְ������\t\t�������\n");
    for (i=0;i<2;i++)
    {
        for (j=0;j<10;j++)
        {
            printf("%d\t\t",(i+1)*1000+j+1);
            //printf_money(return_money[i][j]);
            printf("\n");
        }
    }
    printf("����ȯʹ���������\nѧ������\t\t�������\n");
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
        printf("�ļ���ʧ��!\n\n");
        exit(0);
    }
    printf("�ļ��򿪳ɹ�!\n\n");

    struct card *pu;
    pu=(struct card*)malloc(sizeof(struct card));
    pu=phead;
    pu=pu->next;
    fwrite (pu,10*sizeof(float),1,fp); //size Ŀ���ļ�ָ�� 
    //fwrite (retmoney,20*sizeof(float),1,fp);
    fprintf(fp,"����\t���\t���\t�̼Һ�\t\tʱ��\t\t���ѽ��\tȯ���\t\t�������\t\n");

    while(pu)
    {
        fprintf(fp,"%d\t%.2f\t%d\t%d\t%d��%d��%d��%dʱ%d��%d��\t%f\t%f\t%f\n",
           pu->cardnum,pu->leftmon,pu->num,pu->shopnum,pu->strtime.year,pu->strtime.month,pu->strtime.day,pu->strtime.hour,pu->strtime.minute,pu->strtime.second,pu->money,pu->ticmoney,pu->retmoney);
        pu=pu->next;
    }

    int a=fclose(fp);
    if(a!=0)
    {
        printf("�ļ��ر�ʧ��!\n\n");
        exit(0);
    }
    printf("�ļ��رճɹ�!\n");

    }



void read(struct card *phead)
{
    printf("-----------------------------------------------------------");
    printf("-------------------------------------------------------------\n");
    FILE *fp=fopen("E:\\source.txt","r");

    if(fp==NULL)
    {
        printf("�ļ���ʧ��!\n");
        exit(0);
    }
    printf("�ļ��򿪳ɹ�!\n");

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
        printf("�ļ��ر�ʧ��!\n");
    }
    printf("�ļ��رճɹ�!\n");

}
//��ӡĳ����Ϣ
void seek(struct card *phead)                             
{
    int flag=0,cardnum;                                  //flag�����ж������������Ƿ���ѧ����Ϣ
    struct card *pnew;
    pnew=phead->next;
    puts("�������û�����\n");
    scanf("%d",&cardnum);
    while(pnew)
    {
        if(pnew->next==NULL)                              //����ӡβ�ڵ�
        break;
        if(pnew->cardnum==cardnum)
        {
            printf("%d",pnew->cardnum);
            printf_money(pnew->leftmon);                 
            printf("%d\t%d\t%d��%d��%d��%dʱ%d��%d��\t",pnew->num,pnew->shopnum,pnew->strtime.year,pnew->strtime.month,pnew->strtime.day,pnew->strtime.hour,pnew->strtime.minute,pnew->strtime.second);
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
    if (!flag)                                                        //���ǵ�û��ѧ����Ϣ�����
        puts("û�и�ѧ����Ϣ\n");
}
//��ӡĳ��ʱ�䷶Χ������ѧ����Ϣ
int search(struct time begin,struct time end,struct card *p);         
void print_time_info(struct card *phead)
{
    struct time begin,end;                                            //������ֹʱ��
    int flag=0;                                                       
    struct card *pnew;
    pnew=phead->next;
    puts("���������ѯ��ʱ���(���������ꡢ�¡��ա�ʱ���֡���)");
    scanf("%d%d%d%d%d%d",&begin.year,&begin.month,&begin.day,&begin.hour,&begin.minute,&begin.second);       //�������ѯ��ʱ���
    scanf("%d%d%d%d%d%d",&end.year,&end.month,&end.day,&end.hour,&end.minute,&end.second);
    while(pnew)
    {
        if ((pnew->shopnum!=59488)&&pnew->next!=NULL)                                                        //����ӡ�ս���β���
            if(search(begin,end,pnew))                                                                      
            {
                printf("%d",pnew->cardnum);
                printf_money(pnew->leftmon);
                printf("%d\t%d\t%d��%d��%d��%dʱ%d��%d��\t",pnew->num,pnew->shopnum,pnew->strtime.year,pnew->strtime.month,pnew->strtime.day,pnew->strtime.hour,pnew->strtime.minute,pnew->strtime.second);
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
        printf("�ڴ�ʱ�䷶Χ�����κ���Ϣ\n");
}
//����ʱ�亯��
long long change_time (struct time from)                                                                                  //��ļ����ܴ�Ҫ��long long��
{
    long long second =0;
     second=(((((from.year*12+from.month)*31+from.day)*24+from.hour)*60+from.minute)*60+from.second);                     
    return second ;
}
//�Ƚ�ʱ����Ƿ���ĳʱ�䷶Χ�ں���
int search(struct time begin,struct time end,struct card *p)
           {
               long long begin_time=change_time(begin),end_time=change_time(end),p_time=change_time(p->strtime);          //����ʱ��
               if (begin_time<=p_time)
                    if (end_time>=p_time)
                    return 1;
                    return 0;
           }

//�޸ĺ���
void change(struct card *phead)                  //��������
{
    int time_count (struct time ,struct time );
    int i,kind,cnum,num;                         //kindΪ��Ϣ���࣬cnumΪҪ�޸ĵĿ��ţ�numΪҪ�޸ĵ����
    int shopnum;                                 
    float sale=0;                                
    struct card *t,*front,*next;                 //tָ��Ҫ�޸ĵĽڵ㣬frontָ��ǰһ���ڵ㣬nextָ���һ���ڵ�
    for(i=1;i<=120;i++)
    {
        printf("-");
    }
    printf("\n");                               
    printf("��������Ҫ�޸ĵĿ���\n");
    scanf("%d",&cnum);                          
    front=phead;
    t=front->next;
    next=t->next;                               //��ʼ��ָ��
    while((t->cardnum!=cnum||t->next->cardnum==cnum)&&next!=NULL)
    {
          t=t->next;                            //ʹtָ��Ҫ�޸ĵĽڵ�
          front=front->next;                    //ʹfrontָ��ǰһ���ڵ�
          next=next->next;                      //ʹnextָ����һ���ڵ�
    }
    if(next==NULL)
    {
        printf("δ�ҵ��ÿ���\n");
        return ;
    }
    if(t->shopnum==59488)
    {
        printf("�ÿ�����������Ϣ\n");
        return ;
    }
    printf("�������̼����\n");
    scanf("%d",&shopnum);             //��ȡ�̼����
    if(!(shopnum>=10000&&shopnum<=99999))
    {
        return ;
    }
    kind=shopnum/10000;               //�ж���������
    switch(kind)                           
    {
        case 1:t->leftmon=front->leftmon;      
               t->sum=front->sum;               //�ѽ����������ָ�Ϊ�ϴ�״̬
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
                    if(front->leftmon-t->leftmon==-(t->money))//ȫ��ʹ�����������
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
        printf("���������ѽ��:");
        scanf("%f",&sale);              //��ȡ���ѽ��
        if (sale>50)                    //�������ѳ���50
        {
            printf("�������ѽ���50Ԫ��\n");
            return ;
        }
        int sum=0;                                      //��ʼ������������
        struct time time_temp=re_time();                   //��ȡ����ʱ��
        if (time_count(time_temp,front->strtime)==2)        //������һ����ϢΪͬһ��
        {
            sum=front->sum;                                 //�����������ܶ��ʼ��Ϊ��һ����Ϣ�Ľ��������ܶ�
        }
        if (sale+sum>100)                               //�������ѽ���100
        {
            printf("���������ѽ���100Ԫ��\n");
            return ;
        }
       if (front->leftmon>sale)                        //����������
        {
            if ((t->cardnum/1000==1||t->cardnum/1000==2)&&sale>=20)       //���㷵������ ����Ӧ������ ���ѳɹ����ٷ���
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
            t->strmon.yuan=(int)(sale)/100;               //�޸����̼���ţ�ʱ�䣬���������ܶ���ѽ��
            printf("�޸ĳɹ�\n");                           
            printf("����\t���\t���\t�̼ұ��\t����ʱ��\t���ѽ��\t�������\n");
            printf("%d\t%.2f\t%d\t%d\t%d��%d��%d��%dʱ%d��%d��\t%f\t%f\n",t->cardnum,t->leftmon,t->num,t->shopnum,t->strtime.year,t->strtime.month,t->strtime.day,t->strtime.hour,t->strtime.minute,t->strtime.second,t->money,t->retmoney);
        }
        else
        {                                                   //���㣬���ѳ�ֵ
            printf("�������� ���ֵ\n");
            return ;
        }
    }
    if(kind==2)                            //��������
    {
        printf("���������ѽ��:");
        scanf("%f",&sale);                      //��ȡ���ѽ��
        int sum=0;                                         
        struct time time_temp=re_time();                //��ȡʱ��
        if (time_count(time_temp,front->strtime)==2)        
        {
            sum=front->sum;                                 //�����������ܶ��ʼ��Ϊ��һ����Ϣ�Ľ��������ܶ�
        }
        if (sale+sum>100)                                  
        {
            printf("���������ѽ���100Ԫ\n");
            return ;
        }
        if (front->leftmon>sale)                            //������
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
            printf("�޸ĳɹ�\n");
            printf("����\t���\t���\t�̼ұ��\t����ʱ��\t���ѽ��\n");
            printf("%d\t%.2f\t%d\t%d\t%d��%d��%d��%dʱ%d��%d��\t%f\t%f\n",t->cardnum,t->leftmon,t->num,t->shopnum,t->strtime.year,t->strtime.month,t->strtime.day,t->strtime.hour,t->strtime.minute,t->strtime.second,t->money);
        }
        else
        {
            printf("�������� ���ֵ\n");
            return ;
        }
    }
    if(kind==3)                        //ԡ������
    {
        printf("������ϴ��ʱ�䣨δ��һ���Ӱ�һ���Ӽƣ�\n");        
        int wash_time=0;
        scanf("%d",&wash_time);
        if (wash_time<=10)                                          //�������ѽ��
            sale=2;
        else
            sale=0.2*wash_time;
        int sum=0;
        struct time time_temp=re_time();                            //��ȡʱ��
        if (time_count(time_temp,front->strtime)==2)                //���ݽ��������ܶ�
        {
            sum=front->sum;
        }
        if (t->cardnum/1000==3)                                        //��Ϊѧ��
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
                t->shopnum=shopnum;                                 //�޸Ľ��������ܶ�������������ѽ��̼����
                printf("�޸ĳɹ�\n");
                printf("����\t���\t���\t�̼ұ��\t����ʱ��\t���ѽ��\t����ȯ���\n");
                printf("%d\t%.2f\t%d\t%d\t%d��%d��%d��%dʱ%d��%d��\t%f\t%f\t%f\n",t->cardnum,t->leftmon,t->num,t->shopnum,t->strtime.year,t->strtime.month,t->strtime.day,t->strtime.hour,t->strtime.minute,t->strtime.second,t->money,t->ticmoney);
            }

            else
            {
                printf("�������� ���ֵ\n");
            }
        }                                                                               //ѧ������
        else                                                                            //��ѧ������
        {
            if (front->leftmon>sale)                   //����㹻��������
            {
                t->money=-sale;
                t->leftmon=front->leftmon+t->money;
                t->shopnum=shopnum;
                t->strtime=time_temp;
                t->sum=sum+sale;
                t->retmoney=0;                           //�޸����ѽ����������̼���ţ�ʱ�䣬���������ܶ�
                printf("�޸ĳɹ�\n");                     //��ӡ������Ϣ
                printf("����\t���\t���\t�̼ұ��\t����ʱ��\t���ѽ��\t�������\n");
                printf("%d\t%.2f\t%d\t%d\t%d��%d��%d��%dʱ%d��%d��\t%f\t%f\n",t->cardnum,t->leftmon,t->num,t->shopnum,t->strtime.year,t->strtime.month,t->strtime.day,t->strtime.hour,t->strtime.minute,t->strtime.second,t->money,t->retmoney);
            }
            else
            {                                           //����
                printf("�������� ���ֵ\n");
                return ;
            }
        }
    }                                                    //ԡ������
}

//ɾ������
void del(struct card *phead)          //��������
{
    int cnum,num,i,kind;                  //cnumΪҪɾ���Ŀ��ţ�numΪҪɾ�������
    struct card *t,*front,*next;                 //p0Ϊ����ָ��
    for(i=1;i<=120;i++)
    {
        printf("-");
    }
    printf("\n");                         
    printf("��������Ҫɾ������Ϣ�Ŀ���\n");
    scanf("%d",&cnum);
    t=phead->next;
    next=t->next;
    front=phead;                            //��ʼ��
    while((t->cardnum!=cnum||t->next->cardnum==cnum)&&next!=NULL)//���ҵ�Ҫɾ���Ľڵ���ߵ�������ĩ�˽���
    {
        front=t;
        t=t->next;
        next=next->next ;                      //��������
    }
    if(next==NULL)
    {
        printf("δ�ҵ��ÿ���\n");
        return ;
    }
    if(t->shopnum==59488)
    {
        printf("�ÿ�����������Ϣ\n");
        return ;
    }
    kind=(t->shopnum)/10000;
    if(kind==3)                                 //���޸ĵ���ϴ������
    {
        if(front->leftmon-t->leftmon==-(t->money))         
        {
            next->ticmoney=next->ticmoney-t->money;
        }
        else
        {
            if(front->leftmon-t->leftmon<-(t->money)&&front->leftmon!=t->leftmon)
            {
                next->ticmoney=next->ticmoney+(front->leftmon-t->leftmon);//һ����ʹ��ϴ����һ����ʹ���������
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
    printf("ɾ���ɹ�\n");
}
#endif
