#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef struct card_data{
    uint8_t CHD[25];
    uint8_t PAN[20];
    uint8_t CED[6];
}card_data;

typedef struct terminal_data{
    double TA;
    double MTA;
    uint8_t TrD[11];
}terminal_data;

typedef enum trans_stat{
    DECLINED,APPROVED
}trans_stat;

typedef struct transaction{
    card_data cardHolderData;
    terminal_data transData;
    trans_stat transStat;
}transaction;

typedef struct account_balance
{
    uint8_t PAN[20];
    double balance;
}account_balance;

extern void card(struct card_data *card);

extern uint8_t terminal(struct card_data *card, struct terminal_data *terminal);
extern uint8_t checkDate(uint8_t expirationDate[6], uint8_t terminalDate[11]);

extern uint8_t server(struct account_balance *dataBase,struct card_data *card, struct terminal_data *terminal);
extern uint8_t linearSearch(struct account_balance *dataBase, uint8_t size,uint8_t *target);
extern void printArray(struct account_balance *dataBase, uint32_t size);