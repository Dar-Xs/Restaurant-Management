//
//  order.c
//  restaurant
//
//  Created by DarXs微分 on 2020/11/27.
//

#include "func.h"


void ptorder(){
    fprintf(stdout,"\t\t************************************\n");
    fprintf(stdout,"\t\t|     Restaurant Order System      |\n");
    fprintf(stdout,"\t\t|                                  |\n");
    fprintf(stdout,"\t\t|     1  Add Order                 |\n");
    fprintf(stdout,"\t\t|     2  New Order                 |\n");
    fprintf(stdout,"\t\t|                                  |\n");
    fprintf(stdout,"\t\t|     0  Exit                      |\n");
    fprintf(stdout,"\t\t|                                  |\n");
    fprintf(stdout,"\t\t************************************\n");
}


void order( table tb[] ){

    char choice;
    do{
        system("cls");
        ptorder();
        fprintf(stdout,"\t\tPlease enter your choice:  ");
        fflush(stdin);
        scanf("%c",&choice);
        switch(choice){
            case '0':
                break;

            case '1':
                fprintf(stdout,"\t\tPlease enter the table ID:");
                int ID ;
                fflush(stdin);
                fscanf(stdin,"%d",&ID);
                add_order( tb , ID );
                break;

            case '2':
                fprintf(stdout,"\t\tCalling the function to creat a new Order...\n");
                new_order( tb );
                break;

            default:
                fprintf(stdout,"\t\tWrong number.\n\n\t\tPlease enter a number BETWEEN 0 AND 2 !!!\n\n");
                system("pause");
                break;
        }
    }while( choice!='0' );
    puts("");
    fprintf(stdout,"\t\tExiting...\n");
    system("pause");
}


void new_order( table tb[] ){
    int fre[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} ;
    int j=0 ;

    int i ;
    for( i=0 ; i<=10 ; i++ ){
        if( tb[i].use==0 ){
            fre[j] = i ;
            j++;
        }
    }

    if( j==0 ){
        printf("\t\tSorry.\n\n\t\tThe tables are all full.");
        system("pause");
        return ;
    }

    int ID ;
    while(1){
        system("cls");
        fprintf(stdout,"\t\t************************************\n");
        fprintf(stdout,"\t\t|         Free Table Info.         |\n");
        fprintf(stdout,"\t\t|                                  |\n");
        fprintf(stdout,"\t\t|     ID      Room                 |\n");

        j=0;
        while( fre[j]!=-1 &&j<=9){
        fprintf(stdout,"\t\t|     %2d      %d                    |\n", fre[j] , tb[ fre[j] ].room);
            j++;
        }

        fprintf(stdout,"\t\t|                                  |\n");
        fprintf(stdout,"\t\t************************************\n\n");
        fprintf(stdout,"\t\tWhich one do you want ?\n");
        fprintf(stdout,"\t\tEnter -1 to exit\n\n");
        fprintf(stdout,"\t\tPlease enter the table ID:");
        fflush(stdin);
        fscanf(stdin,"%d",&ID);

        if( tb[ID].use==0 && ID>=0 && ID<=9 ) {
            break ;
        }
        else if( ID == -1 ){
            fprintf(stdout,"\t\tExiting...\n");
            system("pause");
            return ;
        }
        else{
            fprintf(stdout,"\t\tWrong number.\n\n\t\tPlease enter a number IN the list !!!\n\n");
            system("pause");
        }
    }

    tb[ID].use = 1 ;

    fprintf(stdout,"\t\tPeople number :");
    fflush(stdin);
    fscanf(stdin,"%d",&ID);


}

void add_order(  table tb[] , int ID ){

}

