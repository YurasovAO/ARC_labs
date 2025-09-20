#include "../include/arifmetic_functions.h"
#include "../include/BigNumber.h"
#include <string.h>
#include <stdlib.h>
//здесь разлинче вспомогательные функции связаный с арифметикой
//сюда-же добавить функции определния знака арифметических операций
BigNumber BigNumber::summ_numbers(BigNumber* a,BigNumber b,BigNumber res,int offset){

    bool perenos=false;

    char l_1[2];
    char s_1[2];
    char buff[2];
        
    l_1[1]='\0';
    s_1[1]='\0';
    buff[1]='\0';
    int res;

    int min=0;
    int max=0;
    {a->len > b.len ? max=a->len : max=b.len;};
    {a->len > b.len ? min=b.len : min=a->len;};
}
 