//
//  sum.c
//  restaurant
//
//  Created by DarXs微分 on 2020/11/27.
//

#include "func.h"

void sum( dish *head ){

    log_in();

    FILE *fp ;
    fp = fopen("data","rb");
    list lp ;
    dish q ;
    dish *p ;


    int i=0 ;
    p = head ;
    do{
        p = p->next ;
        i++;
    }while( p->next != NULL );

    int *times = malloc( sizeof(int) * i );
    int *times0 = malloc( sizeof(int) * i );
    int j ;
    for( j=0 ; j<i ; j++ ){
        times[j] = 0 ;
        times0[j] = 0 ;
    }


    while(!feof(fp)){

        fread( &lp , sizeof(list) , 1 , fp );
        do{
            fread( &q , sizeof(dish) , 1 , fp );

            p = head ;
            do{
                if( q.ID == p->ID){
                    times[p->ID]++ ;
                }
                p = p->next ;
            }while( p->next != NULL );

        }while( q.next != NULL );

    }
    fclose(fp);

    ptdish( head );

    int s=0 ;
    for( j=0 ; j<i ; j++ ){
        s += times[j] ;
    }


    for( j=0 ; j<i ; j++ ){
        times0[j] =  times[j]*50 / s ;
    }


    p = head->next ;
    printf("\t\t************************************************************\n");
    printf("\t\t|  ID  0          25           50          75          100 |\n");
    while( p != NULL ){
        printf("\t\t|  %2d  ", p->ID );
        ptblocks( times0[p->ID - 1] );
        printf(" |\n");
        p = p->next ;
    }
    printf("\t\t|                                                          |\n");
    printf("\t\t************************************************************\n");

    system("pause");
}

void ptblocks( int t ){
    int j ;
    for( j=0 ; j<=t ; j++ ){
        printf("%c",219);
    }

    for( ; j<=50 ; j++ ){
        printf(" ");
    }
}
