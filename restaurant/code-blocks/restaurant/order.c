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


void order( table tb[] , dish *head ){

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
                add_order( tb , head );
                break;

            case '2':
                new_order( tb , head );
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


void new_order( table tb[] , dish *head ){
    int fre[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} ;
    int j=0 ;

    int n ;
    fprintf(stdout,"\t\tHow many people ?\n\t\t");
    fflush(stdin);
    fscanf(stdin,"%d",&n);

    int i ;
    for( i=0 ; i<=10 ; i++ ){
        if( tb[i].use==0 && tb[i].room>=n ){
            fre[j] = i ;
            j++;
        }
    }

    if( j==0 ){
        printf("\t\tSorry.\n\t\tNo suitable table.\n");
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
        while( fre[j]!=-1 && j<=9 ){
            fprintf(stdout,"\t\t|     %2d      %-2d                   |\n", fre[j] , tb[ fre[j] ].room);
            j++;
        }

        fprintf(stdout,"\t\t|                                  |\n");
        fprintf(stdout,"\t\t************************************\n\n");
        fprintf(stdout,"\t\tWhich one do you want ?\n");
        fprintf(stdout,"\t\tEnter -1 to exit\n\n");
        fprintf(stdout,"\t\tPlease enter the table ID:");
        fflush(stdin);
        fscanf(stdin,"%d",&ID);

        if( tb[ ID ].room>=n && ID>=0 && ID<=9 ) {
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

    tb[ID].use = 1 ;
    list *p ;
    int t ;
    p = (list*)malloc(sizeof(list));

    FILE *fp;
    fp = fopen("list number.txt","r");
    fscanf( fp , "%d" , &t );
    fclose(fp);
    fp = fopen("list number.txt","w");
    fprintf( fp , "%d" , t+1 );

    tb[ID].list = p ;
    p->ID = t + 1 ;
    p->time_start = time(NULL);
    p->dishes = (dish*)malloc(sizeof(dish));
    p->dishes->next = NULL ;
    p->dish_end = p->dishes ;

    fclose(fp);

    system("cls");
    adddish( head , p );
}

void add_order(  table tb[] , dish *head ){
    int use[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} ;

    int i , j=0 ;
    for( i=0 ; i<10 ; i++ ){
        if( tb[i].use==1 ){
            use[j] = i ;
            j++;
        }
    }

    if( j==0 ){
        printf("\t\tSorry.\n\t\tNo table used.\n");
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
    fprintf(stdout,"\t\tThe dishes ordered before are listed as follows:\n");
    ptdish( tb[ID].list->dishes );
    adddish( head , tb[ID].list );

}

void adddish( dish *head , list *plist ){
    ptdish( head );
    fprintf(stdout,"\t\tWhich dish would you like to add ?\n");
    fprintf(stdout,"\t\tEnter -1 to stop\n\n");
    fprintf(stdout,"\t\tPlease enter the ID of it:  ");

    int ID ;
    fflush(stdin);
    fscanf(stdin,"%d",&ID);
    while( ID!=-1 ){
        int t=0 ;
        dish *p = head->next ;
        while( p != NULL ){
            if( p->ID == ID ){
                t++ ;
                break ;
            }
            p = p->next ;
        }
        if( t==1 ){
            dish *ndish = malloc(sizeof(dish));
            *ndish = *p ;
            ndish->next = NULL ;
            plist->dish_end->next = ndish ;
            plist->dish_end = ndish ;
        }
        else{
            fprintf(stdout,"\t\tDish ID not found.\n\n\t\tPlease enter a number ON the menu !!!\n\n");
        }
        fprintf(stdout,"\t\t");
        //fflush(stdin);
        fscanf(stdin,"%d",&ID);
    }

    system("cls");
    fprintf(stdout,"\t\tThe dishes ordered are listed as follows:\n");
    ptdish( plist->dishes );
    system("pause");
}

