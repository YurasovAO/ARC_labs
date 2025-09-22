
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

bool get_sign_of_summ_operation(BigNumber* a,BigNumber b){

    char a_1[2];
    char b_1[2];
    a_1[1]='\0';
    b_1[1]='\0';

    int a_l=a->len;
    int b_l=b.len;

    bool res;

    if (a->len > b.len){
        printf("A sign:%d\n",a->sign);
        res=a->sign;
    }
    else if(b.len > a->len){
        printf("B sign:%d\n",b.sign);
        res=b.sign;
    }
    else{
        for(int i=0;i<b.len;i++){
            a_1[0]=a->num[i];
            b_1[0]=b.num[i];
            if(atoi(a_1) > atoi(b_1)){
                res=a->sign;
            }
            else if(atoi(a_1) < atoi(b_1)){
                res=b.sign;
            }
            if(i+1 == b.len){
                res=true;
            }
        }
    }
    return res;
}

bool get_sign_of_diff_operation(BigNumber* a,BigNumber b){
    char a_1[2];
    char b_1[2];
    a_1[1]='\0';
    b_1[1]='\0';

    int a_l=a->len;
    int b_l=b.len;

    if(a->sign ==false && b.sign == false){
        //-a-(-b)

        char a_1[2];
        char b_1[2];
        a_1[1]='\0';
        b_1[1]='\0';

        int a_l=a->len;
        int b_l=b.len;


        if (a->len > b.len){
            return false;
        }
        else if(b.len > a->len){
            return true;
        }
        else{
            for(int i=0;i<b.len;i++){
                a_1[0]=a->num[i];
                b_1[0]=b.num[i];
                if(atoi(a_1) > atoi(b_1)){
                    return false;
                }
                else if(atoi(a_1) < atoi(b_1)){
                    return true;
                }
                if(i+1 == b.len){
                    return true;
                }
            }
        }
    }
    else if(a->sign == true && b.sign ==true){
        //a-b

        char a_1[2];
        char b_1[2];
        a_1[1]='\0';
        b_1[1]='\0';

        int a_l=a->len;
        int b_l=b.len;


        if (a->len > b.len){
            return true;
        }
        else if(b.len > a->len){
            return false;
        }
        else{
            for(int i=0;i<b.len;i++){
                a_1[0]=a->num[i];
                b_1[0]=b.num[i];
                if(atoi(a_1) > atoi(b_1)){
                    return true;
                }
                else if(atoi(a_1) < atoi(b_1)){
                    return false;
                }
                if(i+1 == b.len){
                    return true;
                }
            }
        }

    }
    else if(a->sign == false && b.sign == true){

        //-a-b
        return false;
    }
    else if (a->sign == true && b.sign == false){
        //a-(-b)
        return true;
    }

    return 0;
}

bool get_sign_of_prod_operation(BigNumber* a,BigNumber b){

    if (a->sign == false || b.sign ==false ){
        return false;
    }
    else{
        return true;
    }
}

void BigNumber::summ_operation_plan(void){
    
    

}
void BigNumber::print_value(void){
    if(!this->sign){
        printf("-\t");
    }
   for(int i=0;i<this->num.size();i++){
        printf("%c",this->num[i]);
   }
   printf("\n");
}
//Здесь различные функции проверки