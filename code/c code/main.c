#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"
#include "functions.h"
#include "medicine.h"
#include "queue.h" 

	

int main (void)
{
   
    struct card space;
    struct time temp={0,0,0,0,0,0};
    
    int i=1,j=1,choice;
    struct card *phead=&space,*pnew,*ptail;//,ph; //头 新 尾 遍历
    ptail=phead;
    for (i=1;i<4;i++)
    {
        for (j=1;j<11;j++)
        {
            pnew=(struct card *)malloc(sizeof (struct card));
            ptail->next=pnew;
            pnew->next=NULL;
            ptail=pnew;
            pnew->cardnum=i*1000+j;
            pnew->leftmon=100;
            pnew->num=0;
            pnew->money=0;
            pnew->retmoney=0;
            pnew->shopnum=59488;
            pnew->sum=0;
            pnew->ticmoney=0;
            pnew->strtime=temp;
            if (i==3&&j==10)
            {
                pnew=(struct card *)malloc(sizeof (struct card));
                ptail->next=pnew;
                pnew->next=NULL;
                ptail=pnew;
                pnew->cardnum=9999;
                pnew->leftmon=100;
                pnew->num=0;
                pnew->money=0;
                pnew->retmoney=0;
                pnew->shopnum=59488;
                pnew->sum=0;
                pnew->ticmoney=0;
                pnew->strtime=temp;
            }
        }
    }
    while (1)  //死循环 
    {
        choice=print();
        switch (choice)
		{
            case 1 :    add(phead);
                        break;
            case 2 :    store(phead);
                        break;
            case 3 :    read(phead);
                        break;
            case 4 :    del(phead);
                        break;
            case 5 :    seek(phead);
                        break;
            case 6 :    conclude(phead);
                        break;
            case 7 :    printf_return_info(phead);
                        break;
            case 8 :    print_time_info(phead);
                        break;
            case 9 :    change (phead);
                        break;
            case 10:    recharge (phead);
                        break;
            case 11:    med();
                        break;
            case 12:    library();
                        break;            
            case 0 :    return;
        };
    }
}
 


