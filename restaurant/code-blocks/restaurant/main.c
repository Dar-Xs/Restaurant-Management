//
//  main.c
//  restaurant
//
//  Created by DarXs微分 on 2020/11/26.
//

#include "func.h"

int main(void) {

    table tb[10]={0};
    dish cai;

    FILE *fp;
    fp = fopen("table.txt", "r");

    int i ;
    for( i=0 ; i<=9 ; i++ ){
        fscanf(fp, "%d", &tb[i].room );
    }

    //log_in();
    menu( tb );

    printf("Hello, World!\n");
    return 0;
}

