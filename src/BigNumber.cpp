#include "../include/BigNumber.h"
#include <string.h>
#include <stdio.h>
#include "stdlib.h"
#include <math.h>
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
    number[0] == '-' ? sign=false: sign=true;
    return 0;
}

int BigNumber::get_size_of_number(char* number){
    int k=0;//итератор
    sign == true ? k= false : k=true;

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

    len=strlen(number)-k;//длина числа без учёта знака
    printf("Length of number without a sign : %d",len);
    num=number;
    return 0;
}

BigNumber::BigNumber(){
    num=(char*)calloc(2,sizeof(char));
    len=1;
    sign=true;
}

BigNumber::BigNumber(char* number){
    check_number(number);
    get_size_of_number(number);
    printf("Got number %s\n",number);
}

BigNumber::~BigNumber(){
    num=NULL;
};

void BigNumber::show_val(){
    printf("BigNumber is : %s\nLen is : %d\nSign is : %d",this->num,this->len,this->sign);
};

BigNumber BigNumber::operator+(BigNumber b){
    BigNumber result;

    int len_a=strlen(this->num);
    int len_b=strlen(b.num);

    if(len_a > len_b) { result.sign=this->sign;}
    else if(len_b > len_a) {result.sign=b.sign;}
    else {result.sign=true;}   
}

BigNumber BigNumber::operator*(BigNumber b){
    BigNumber result;

   if( (this->sign == false && b.sign ==false ) || (this->sign == true && b.sign == true )){
        result.sign=true;
    }
   else{
    result.sign=false;
   }

   result.len=floor(log10(this->len)+ log10(b.len)) + 1;
   int num_of_el=result.len+1+result.sign;
   //1- for \0

   result.num=(char*)realloc(result.num,(num_of_el)*sizeof(char));
   char* prom=(char*)calloc(this->len,sizeof(char)); 


   char p1_val[2];
   char p2_val[2];
   char p3_1_val[3];
   char p3_2_val[3];

    p1_val[1]='\0';
    p2_val[1]='\0';
    p3_1_val[2]='\0';
    p3_2_val[2]='\0';
   int num_res;
   bool perenos=false;
   int new_val=0;
   for(int o=0;o<b.len;o++){

        for(int q=0;q<this->len;q++){
            p1_val[0]=b.num[o];
            p2_val[0]=this->num[q];
            num_res=atoi(p1_val) * atoi(p2_val);
            snprintf(p3_1_val,sizeof(p3_1_val),"%d",num_res);
            strlen(p3_1_val) == 1 ? perenos=false : perenos=true;
            //new_val=atoi();
        }
    }

   return result;
}



BigNumber BigNumber::operator=(BigNumber b){
    this->num=b.num;
    this->sign=b.sign;
    this->len=b.len;

    return *this;

}