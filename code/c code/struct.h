#ifndef _STRUCT_H_
#define _STRUCT_H_

struct time{
	int year,
		month,
		day,
		hour,
		minute,
		second;
};
struct money{
	int yuan,
		jiao,
		fen;
};
struct card{
    int cardnum;                //����        //��һλ��ʾ��� ����λ��001��010 ��30�ſ�
    float leftmon;              //���
    int num;                    //���
    int shopnum;                //�̼����   /10000  /100%100   %100
    struct time  strtime;       //ʱ��ṹ��
    float money;                //���
	struct money strmon;        //���ṹ��
	float ticmoney;             //ȯ���
	float sum;                  //���������ѽ�ʳ��+���У�
	float retmoney;             //�������
	struct card *next;             //ָ��
};



#endif
