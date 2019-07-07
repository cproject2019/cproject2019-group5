#ifndef _QUEUE_H_
#define _QUEUE_H_
typedef struct {
	int data[5];
	int front,rear;
}SqQueue;

//void InitQueue(SqQueue que){
//	que.front = 0;
//	que.rear = 0; 
//}
int QueueEmpty(SqQueue que){
	return (que.front == que.rear);
}
int EnQueue(SqQueue que, int x){
	if((que.rear + 1)%5 == que.front) 
	return 0;
	que.data[que.rear] = x;
	que.rear = (que.rear +1) %5;
	return 1;
} 

int library(){
	int x; 
	int ret;
	SqQueue que;
	que.front =0;
	que.rear =0;
	while(1){
		printf("������ѧ��:");
		scanf("%d",&x);
		printf("%d",x);
		ret = EnQueue(que, x);
		 if( ret== 0)
					printf("ԤԼ�����Ѵ����ޣ�\n");
		 else if(ret == 1)		
			        printf("ԤԼ�ɹ���\n");
	} 

		}
		
#endif
