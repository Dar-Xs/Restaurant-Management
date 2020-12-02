//
//  data.c
//  restaurant
//
//  Created by DarXs微分 on 2020/11/27.
//

#include "func.h"

void data(){

    log_in();

    FILE *fp ;
    fp = fopen("data","rb");
    list lp ;
    dish q ;
    int a ;
    time_t d ;

    while(!feof(fp)){
        system("cls");

        if(fread( &lp , sizeof(list) , 1 , fp ) != 1 ){
            break;
        }
        printf("\t\tList ID   : %d\n", lp.ID );
        printf("\t\tStart at  : %d\n", lp.time_start );
        printf("\t\tEnd at    : %d\n", lp.time_end );
        d = tb[ID].list->time_end - tb[ID].list->time_start ;
        printf("\t\tTime used : %d hr %d min %d sec\n", d/3600 , (d/60)%60 , d%60 );

        printf("\t\t*********************************************************\n");
        printf("\t\t|  %-40s  %s  %s  |\n","Dish Name","Price","ID");
        printf("\t\t| %50s    |\n","");

        fread( &q , sizeof(dish) , 1 , fp );

        do{
            fread( &q , sizeof(dish) , 1 , fp );
            printf("\t\t|  %-40s %6.2f  %2d  |\n",q.name,q.price,q.ID);
        }while( q.next != NULL );
        printf("\t\t| %50s    |\n","");
        printf("\t\t*********************************************************\n\n");
        printf("\t\tPrice : %-4.2f\n\n\n", lp.price );

        fprintf(stdout,"\t\tInput any number to continue.\n\t\tEnter 0 to exit\n\n\t\t");
        fflush(stdin);
        fscanf(stdin,"%d",&a);
        if( a==0 ){
            fprintf(stdout,"\t\tExiting...\n");
            system("pause");
            return ;
        }

    }

    fclose(fp);
    system("cls");
    fprintf(stdout,"\n\t\tOut of data !\n\n");
    system("pause");

}
