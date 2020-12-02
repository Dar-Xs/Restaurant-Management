//
//  bill.c
//  restaurant
//
//  Created by DarXs微分 on 2020/11/27.
//

#include "func.h"


void bill( table tb[] ){


    int use[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} ;

    int i , j=0 ;
    for( i=0 ; i<10 ; i++ ){
        if( tb[i].use==1 ){
            use[j] = i ;
            j++;
        }
    }

    if( j==0 ){
        printf("\t\tSorry.\n\t\tNo table need to Bill.\n");
        system("pause");
        return ;
    }

    int ID ;
    while(1){
        system("cls");
        fprintf(stdout,"\t\t************************************\n");
        fprintf(stdout,"\t\t|         Uesd Table Info.         |\n");
        fprintf(stdout,"\t\t|                                  |\n");
        fprintf(stdout,"\t\t|   Table ID   Room   List ID      |\n");

        j=0;
        while( use[j]!=-1 && j<=9 ){
            fprintf(stdout,"\t\t|     %2d        %-2d      %-4d       |\n", use[j] , tb[ use[j] ].room , tb[ use[j] ].list->ID );
            j++;
        }

        fprintf(stdout,"\t\t|                                  |\n");
        fprintf(stdout,"\t\t************************************\n\n");
        fprintf(stdout,"\t\tWhich one do you want ?\n");
        fprintf(stdout,"\t\tEnter -1 to exit\n\n");
        fprintf(stdout,"\t\tPlease enter the table ID:");
        fflush(stdin);
        fscanf(stdin,"%d",&ID);

        if( tb[ ID ].use==1 && ID>=0 && ID<=9 ) {
            break ;
        }
        else if( ID == -1 ){
            fprintf(stdout,"\t\tExiting...\n");
            system("pause");
            return ;
        }
        else{
            fprintf(stdout,"\t\tWrong number.\n\n\t\tPlease enter a number ON the list !!!\n\n");
            system("pause");
        }
    }

    system("cls");
    fprintf(stdout,"\t\tThe dishes ordered are listed as follows:\n");
    ptdish( tb[ID].list->dishes );

    tb[ID].list->price = 0 ;
    dish *p = tb[ID].list->dishes->next ;
    while( p != NULL ){
        tb[ID].list->price += p->price ;

        p = p->next ;
    }

    float x ;
    do{
        fprintf(stdout,"\t\tYou need to pay  %-4.2f\n",tb[ID].list->price);
        fprintf(stdout,"\t\tTake:  ");
        fflush(stdin);
        fscanf(stdin,"%f",&x);
        if( x >= tb[ID].list->price ){
            break ;
        }
        printf("\t\tNot enough !!!\n");
        system("pause");
    }while(x < tb[ID].list->price);


    tb[ID].list->time_end = time(NULL);
    time_t d = tb[ID].list->time_end - tb[ID].list->time_start ;
    printf("\t\tTime used : %d hr %d min %d sec\n", d/3600 , (d/60)%60 , d%60 );

    FILE *fp ;
    fp = fopen("data","ab");
    list *lp = tb[ID].list ;
    dish *q = lp->dishes ;
    fwrite( lp , sizeof(list) , 1 , fp );
    while( q != NULL ){
        fwrite( q , sizeof(dish) , 1 , fp );
        q = q->next ;
    }

    fclose(fp);

    freedish( lp->dishes );
    free(lp);

    tb[ID].use = 0;

    fprintf(stdout,"\t\tChange:  %-4.2f\n\t\tWelcome !\n\n", x - (tb[ID].list->price) );
    system("pause");

}



void freedish( dish *head ){
    dish *p = head->next ;
    dish *q ;
    while( p!=NULL ){
        q = p->next;
        free(p);
        p = q ;
    }
    free(head);
}
