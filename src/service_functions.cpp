
#include "../include/BigNumber.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int BigNumber::check_number(char* number){

    for(int i=0;i < strlen(number);i++){
        switch(number[i]){
            case '-':continue;
            case '0':continue;
            case '1':continue;
            case '2':continue;
            case '3':continue;
            case '4':continue;
            case '5':continue;
            case '6':continue;
            case '7':continue;
            case '8':continue;
            case '9':continue;
            default:
                fprintf(stderr,"Invalid symbol %c detected\n",number[i]);
                abort();
        }

    }
    for(int j=1;j < strlen(number);j++){
        if(number[j] == '-'){
            fprintf(stderr,"Invalid format of number");
            abort();
        }
    }
    number[0] == '-' ? this->sign=false: this->sign=true;
    return 0;
}

int BigNumber::get_size_of_number(char* number){
    int k=0;//итератор
    this->sign == true ? k= false : k=true;

    if(sign){
        if(number[k]=='0' && strlen(number) > 1){
            fprintf(stderr,"Invalid format of number\n");
            abort();
        }
    }
     else{
        if(number[k]=='0' ){
            fprintf(stderr,"Invalid format of number\n");
            abort();
        }
    }

    this->len=strlen(number)-k;//длина числа без учёта знака
    printf("Length of number without a sign : %d\n",len);
    return 0;
}

void BigNumber::show_val(){
     printf("Len is : %ld\nSign is : %d",this->num.size(),this->sign);
};

//Здесь различные функции проверки