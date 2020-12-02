//
//  menu.c
//  restaurant
//
//  Created by DarXs微分 on 2020/11/26.
//

#include "func.h"

void ptmenu(){
    fprintf(stdout,"\t\t************************************\n");
    fprintf(stdout,"\t\t|        Restaurant System         |\n");
    fprintf(stdout,"\t\t|                                  |\n");
    fprintf(stdout,"\t\t|     1  Order                     |\n");
    fprintf(stdout,"\t\t|     2  Bill                      |\n");
    fprintf(stdout,"\t\t|     3  Data                      |\n");
    fprintf(stdout,"\t\t|     4  Sum                       |\n");
    fprintf(stdout,"\t\t|                                  |\n");
    fprintf(stdout,"\t\t|     0  Exit                      |\n");
    fprintf(stdout,"\t\t|                                  |\n");
    fprintf(stdout,"\t\t************************************\n");
}

void menu( table tb[] , dish *head ){
    char choice;
    int i , t=0 ;
    do{
        system("cls");
        ptmenu();
        fprintf(stdout,"\n\t\tPlease enter your choice:  ");
        fflush(stdin);
        scanf("%c",&choice);
        switch(choice){
            case '0':
                for( i=0 ; i<10 ; i++ ){
                    if( tb[i].use == 1 ){
                        fprintf(stdout,"\n\t\ttable[%d] didn\'t bill yet !\n", i );
                        t++;
                    }
                }
                if(t!=0){
                    choice = '1' ;
                    t = 0 ;
                    system("pause");
                }
                break;

            case '1':
                order( tb , head );
                break;

            case '2':
                fprintf(stdout,"\n\t\tCalling the function to Bill...\n");
                bill( tb );
                break;

            case '3':
                fprintf(stdout,"\n\t\tCalling the function to Data...\n");
                data();
                break;

            case '4':
                fprintf(stdout,"\n\t\tCalling the function to Sum...\n");
                sum( head );
                break;

            default:
                fprintf(stdout,"\t\tWrong number.\n\n\t\tPlease enter a number BETWEEN 0 AND 3 !!!\n\n");
                system("pause");
                break;

        }
    }while( choice!='0' );
    puts("");
    fprintf(stdout,"\t\tExiting...\n");
}

