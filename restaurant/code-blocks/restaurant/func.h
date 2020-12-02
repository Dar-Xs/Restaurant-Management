//
//  menu.h
//  restaurant
//
//  Created by DarXsÎ¢·Ö on 2020/11/26.
//

#ifndef __func_h__
#define __func_h__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>



struct Dish{
    int ID ;
    char name[40] ;
    float price ;
    struct Dish *next ;
};

struct List{
    int ID ;
    time_t time_start ;
    time_t time_end ;
    float price ;
    struct Dish *dishes ;
    struct Dish *dish_end ;
};

struct Table{
    int room ;
    int use ;
    struct List *list ;
};

typedef struct Dish dish ;
typedef struct List list ;
typedef struct Table table ;

void ptdish( dish *head );
dish *mkdish(void);
void loadtable( table tb[] );

void log_in(void);

void ptmenu(void);
void menu( table tb[] , dish *head );

void ptorder(void);
void order( table tb[] , dish *head );
void new_order( table tb[] , dish *head );
void add_order( table tb[] , dish *head );
void adddish( dish *head , list *plist ) ;

void bill( table tb[] );
void freedish( dish *head );

void sum( dish *head );
void ptblocks( int t );
void data(void);


#endif







