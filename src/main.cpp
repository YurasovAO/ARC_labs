#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "../include/BigNumber.h"

//использовать массивы строк с 1 столбцом


int main(int argc,char**argv){

    BigNumber num(argv[1]);
    BigNumber num2(argv[2]);
    BigNumber res =num;
    res.show_val();
    return 0;
}


