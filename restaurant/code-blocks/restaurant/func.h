//
//  menu.h
//  restaurant
//
//  Created by DarXs微分 on 2020/11/26.
//

#ifndef func_h
#define func_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Dish{
    int ID ;
    char name[10] ;
    float price ;
    struct Dish *next ;
};

struct List{
    int ID ;
    unsigned long long time_start ;
    unsigned long long time_end ;
    float price ;
    struct Dish *dish ;
};

struct Table{
    int room ;
    int use ;
    struct List *list ;
};

typedef struct Dish dish ;
typedef struct List list ;
typedef struct Table table ;

void log_in(void);

void ptmenu(void);
void menu( table tb[] );

void ptorder(void);
void order( table tb[] );
void new_order( table tb[] );
void add_order( table tb[] , int ID );

void ptbill(void);
void bill( table tb[] );
void bill_table( table tb[] , int ID );
void bill_list( table tb[] , int ID );

void sum(void);
void data(void);


#endif







