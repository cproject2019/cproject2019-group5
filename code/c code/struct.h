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
    int cardnum;                //卡号        //第一位表示身份 后三位由001至010 共30张卡
    float leftmon;              //余额
    int num;                    //序号
    int shopnum;                //商家序号   /10000  /100%100   %100
    struct time  strtime;       //时间结构体
    float money;                //金额
	struct money strmon;        //金额结构体
	float ticmoney;             //券金额
	float sum;                  //今日总消费金额（食堂+超市）
	float retmoney;             //补贴金额
	struct card *next;             //指针
};



#endif
