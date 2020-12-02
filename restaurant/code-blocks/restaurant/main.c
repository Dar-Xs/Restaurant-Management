//
//  main.c
//  restaurant
//
//  Created by DarXs微分 on 2020/11/26.
//

#include "func.h"

int main(void) {

    SetConsoleOutputCP(437);

    table tb[10]={0};
    loadtable( tb );

    dish *caihead = mkdish();

    menu( tb , caihead );

    return 0;
}

