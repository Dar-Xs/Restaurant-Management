//
//  log_in.c
//  restaurant
//
//  Created by DarXs微分 on 2020/11/27.
//

#include "func.h"

void log_in(){
    char a[10]="admin";
    char p[10]="admin";

    char ai[10]="\0";
    char pi[10]="\0";

    int c=0 ;

    while(1){
        system("cls");
        fprintf(stdout,"\t\t************************************\n");
        fprintf(stdout,"\t\t|     Restaurant Server System     |\n");
        fprintf(stdout,"\t\t|                                  |\n");
        fprintf(stdout,"\t\t|             Log in               |\n");
        fprintf(stdout,"\t\t|                                  |\n");
        fprintf(stdout,"\t\t|     Account Name : ");

        fflush(stdin);
        gets(ai);

        fprintf(stdout,"\t\t|     Password     : ");

        fflush(stdin);
        gets(pi);

        fprintf(stdout,"\t\t|                                  |\n");
        fprintf(stdout,"\t\t************************************\n");

        if( strcmp(a,ai)!=0 && strcmp(p,pi)!=0 ){
            system("cls");
            fprintf(stdout,"\t\t************************************\n");
            fprintf(stdout,"\t\t|     Wrong passward               |\n");
            fprintf(stdout,"\t\t|     Please check your password   |\n");
            c++ ;
            if( c>=5){
                fprintf(stdout,"\t\t|     You have tried 5 times       |\n");
                fprintf(stdout,"\t\t|     System exited for security   |\n");
                fprintf(stdout,"\t\t************************************\n");
                exit(-1);
            }
            fprintf(stdout,"\t\t************************************\n");
            system("pause");
        }
        else{
            break ;
        }
    }

    system("cls");
}
