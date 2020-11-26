//
//  bill.c
//  restaurant
//
//  Created by DarXs微分 on 2020/11/27.
//

#include "func.h"

void ptbill(){
    fprintf(stdout,"\t\t************************************\n");
    fprintf(stdout,"\t\t|     Restaurant Bill System       |\n");
    fprintf(stdout,"\t\t|                                  |\n");
    fprintf(stdout,"\t\t|     1  By Table                  |\n");
    fprintf(stdout,"\t\t|     2  By List                   |\n");
    fprintf(stdout,"\t\t|                                  |\n");
    fprintf(stdout,"\t\t|     0  Exit                      |\n");
    fprintf(stdout,"\t\t|                                  |\n");
    fprintf(stdout,"\t\t************************************\n");
}

void bill( table tb[] ){
    char choice;
    int ID ;
    
    do{
        system("cls");
        ptbill();
        fprintf(stdout,"\t\tPlease enter your choice:  ");
        fflush(stdin);
        scanf("%c",&choice);
        switch(choice){
            case '0':
                break;
                
            case '1':
                fprintf(stdout,"\t\tPlease enter the table ID:");
                fflush(stdin);
                fscanf(stdin,"%d",&ID);
                
                bill_table( tb , ID );
                break;
                
            case '2':
                fprintf(stdout,"\t\tPlease enter the list ID:");
                fflush(stdin);
                fscanf(stdin,"%d",&ID);
                
                bill_list( tb , ID );
                break;
                
            default:
                fprintf(stdout,"\t\tWrong number.\n\n\t\tPlease enter a number BETWEEN 0 AND 2 !!!\n\n");
                system("pause");
                break;
                
        }
    }while( choice!='0' );
    puts("");
    fprintf(stdout,"\t\tExiting...\n");
}

void bill_table( table tb[] , int ID ){
    
}

void bill_list( table tb[] , int ID ){
}
