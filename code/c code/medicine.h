#ifndef _MEDICINE_H_
#define _MEDICINE_H_

struct Med  //存一个药的结构体
{
  int num,left;  //left是剩下的数量
  char name[100],type[50];
  double price;
};
struct Med meds[500];     //存所有的药
struct Med medstemp[500];  //暂时存一个类型的药
struct Med tmed;



int is_inc(struct Med a,struct Med b,char sortby)
/*
比较函数，按照某个项比较a，b大小
如果
  a<b就是递增的关系，返回1
  a=b 返回 0
  a>b 返回 -1*/ 

{
  if(sortby=='p') // price
  {
    if(a.price<b.price)
      return 1;
    if(a.price>b.price)
      return -1;
    return 0;
  }

  if(sortby=='l') // left
  {
    if(a.left<b.left)
      return 1;
    if(a.left>b.left)
      return -1;
    return 0;
  }

  return 0;
}

int is_dec(struct Med a,struct Med b,char sortby)
{
  return -is_inc(a,b,sortby);
}


void swap(struct Med *a, struct Med *b)   //交换的必须是传进来的两个指针位置的药
{
    struct Med temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(struct Med arr[] ,int start, int end,char sortby)
{
    struct Med arrBase;
    int arrMiddle;

    int tempStart = start,
        tempEnd = end;

    if(tempStart >= tempEnd) //返回条件 
        return;
    arrBase = arr[start];
    while(start < end)
    {
        while(start < end && (is_dec(arr[end],arrBase,sortby)==1) )
            end--;
        if(start < end)
        {
            swap(&arr[start], &arr[end]);
            start++;
        }

        while(start < end && (is_inc(arr[start],arrBase,sortby)==1))
            start++;
        if(start < end)
        {
            swap(&arr[start], &arr[end]);
            end--;
        }
    }
    arr[start] = arrBase;
    arrMiddle = start;
    quickSort(arr,tempStart,arrMiddle-1,sortby); //递归 
    quickSort(arr,arrMiddle+1,tempEnd,sortby);
}

void show(struct Med arr[],int i)  //展示arr里的第i个药
{
  // printf("\n--------------\n");
  printf("%5d  %-45s  %-15s  %-15lf  %d\n",arr[i].num,arr[i].name,arr[i].type,arr[i].price,arr[i].left);
  // printf("\n--------------\n");
}

int extract(char type[],int tot)//快排范围，t-1 
{
  int t=0;
  int i;
  for(i=0;i<tot;i++)
    if(strcmp(meds[i].type,type)==0)
      medstemp[t++]=meds[i];
  return t;
}

int med()
{
	FILE *fin;
	fin = fopen("drug.txt","rb");

  int tnum;
  int med_tot=0;

	while(fscanf(fin, "%d", &tnum ) == 1)   
  {
		fscanf(fin,"%s%s%lf%d",meds[med_tot].name,meds[med_tot].type,&meds[med_tot].price,&meds[med_tot].left);
    meds[med_tot].num=tnum;

    med_tot++;
	}
  med_tot--;  


  int t=extract("片剂",med_tot);
  int i;
  quickSort(medstemp,0,t-1,'l');

  for(i=0;i<t;i++)
    show(medstemp,i);

  return 0;

}

#endif 
