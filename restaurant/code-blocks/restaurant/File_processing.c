#include "func.h"

dish *mkdish(){

    dish cai;

    FILE *fp;
    fp = fopen("dish.txt", "r");

    FILE *fq;
    fq = fopen("dish","wb");

    int i=1 ;
    while( !feof(fp) ){
        fscanf(fp, "%s%f", cai.name , &cai.price );
        cai.ID = i++;
        fwrite( &cai , sizeof(dish) , 1 , fq );
    }

    fclose(fp);
    fclose(fq);

    dish *head ;
    dish *pnew ;
    pnew = malloc(sizeof(dish)) ;
    head = pnew ;


    fp = fopen("dish", "rb");
    fread( &cai , sizeof(dish) , 1 , fp );
    while( !feof(fp) ){
        pnew->next = malloc(sizeof(dish)) ;
        pnew = pnew->next ;
        strcpy( pnew->name , cai.name );
        pnew->price = cai.price ;
        pnew->ID = cai.ID ;
        fread( &cai , sizeof(dish) , 1 , fp );
    }
    pnew->next = NULL ;

    fclose(fp);

    return head ;
}

void ptdish( dish *head ){
    dish *p = head->next ;

    if(p == NULL){
        printf("\t\t*********************************************************\n");
        printf("\t\t|                  Empty dish list.                     |\n");
        printf("\t\t*********************************************************\n");
        return ;
    }

    printf("\t\t*********************************************************\n");
    printf("\t\t|  %-40s  %s  %s  |\n","Dish Name","Price","ID");
    printf("\t\t| %50s    |\n","");
    while( p != NULL ){
        printf("\t\t|  %-40s %6.2f  %2d  |\n",p->name,p->price,p->ID);
        p = p->next ;
    }
    printf("\t\t| %50s    |\n","");
    printf("\t\t*********************************************************\n");
}

void loadtable( table tb[] ){
    int i ;
    FILE *fp;
    fp = fopen("table.txt", "r");
    for( i=0 ; i<10 ; i++ ){
        fscanf(fp, "%d", &tb[i].room );
    }

    fclose(fp);
}
