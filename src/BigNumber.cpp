#include "../include/BigNumber.h"
#include <string.h>
#include <stdio.h>
#include "stdlib.h"
#include <math.h>


#define max(a,b) {a>b ? a : b}
#define min(a,b) {a<b ? a : b}
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
    num=NULL;
    len=0;
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

    ssize_t len_a=strlen(this->num);
    ssize_t len_b=strlen(b.num);

    //Определение знака результата операции
    if(len_a > len_b) { result.sign=this->sign;}
    else if(len_b > len_a) {result.sign=b.sign;}
    else {  
        if(this->sign == true && b.sign == true){
            result.sign =true;
        }
        else if (this->sign == false && b.sign == false){
            result.sign=false;
        }
        else{
            result.num[0]='0';
            result.num[1]='\0';
        }
    }

    int l=max(len_a,len_b);
    l+=2;//1 под возможный перенос из-за увеличения разрядности и 1 для \0
    result.num=(char*)calloc(l,sizeof(char));
    result.num[strlen(result.num)-1]='\0';


    bool perenos=false;
    char* lead=NULL;
    char* submit=NULL;

    int submit_len=0;

    char l_1[2];
    char s_1[2];

    l_1[1]='\0';
    s_1[1]='\0';
    
    ssize_t min=0;
    if(len_a > len_b){
        min=b.len;
        lead=b.num;
        submit=this->num;
        submit_len=this->len;

    }
    else{
        min=this->len;
        lead=this->num;
        submit=b.num;
        submit_len=b.len;
    } 
    for(int u=0;u<strlen(result.num) - min;u++){
        result.num[u]='0';
    }
    ssize_t res;
    char buff[2];
    buff[1]='\0';

    
    for (int i=0;i< min;i++){
        
        //Проверка наличия переноса из предыдущего разряда

        //Поразрядное сложение
        l_1[0]=lead[strlen(lead)-i-1];
        s_1[0]=submit[strlen(submit)-i-1];
        res=atoi(l_1) + atoi(s_1) + perenos;

        if(res<10){
            sprintf(buff,"%d",res);
            result.num[strlen(result.num)-i-1]=buff[0];
            printf("The sum res is :%c\n",result.num[strlen(result.num)-i-1]);
            perenos =false;
        }
        else{
            sprintf(buff,"%d",res%10);
            result.num[strlen(result.num)-i-1]=buff[0];
            printf("The sum res is :%c\n",result.num[strlen(result.num)-i-1]);
            perenos =true;
        }
    }
    printf("The perenos : %d\n",perenos);
    printf("Result : %s\n",result.num);
    
    for(int y=0;y<strlen(result.num);y++){
        if(result.num[y]=='\0'){
            printf("yy%c\n",'\0');
        }
        else{
            printf("%c\n",result.num[y]);
        }
    }
    // for(int j=0;j<submit_len -min;j++){
    //     if(perenos){
    //         s_1[0]=submit[strlen(submit)-min-j-2];
    //         res=atoi(s_1) + perenos;
    //         if(res>=10) {sprintf(buff,"%d",res%10);perenos=true;} else {sprintf(buff,"%d",res);perenos=false;}
    //         printf("The res:%d",res);
    //         result.num[strlen(result.num)-min-j-2]=buff[0];
    //         printf("The result: %c\n",result.num[strlen(result.num)-min-j-2]);

    //     }
    //     else{
    //         s_1[0]=submit[strlen(submit)-min-j-2];
    //         res=atoi(s_1);
    //         sprintf(buff,"%d",res);
    //         result.num[strlen(result.num)-min-j-1]=buff[0];
    //         printf("The result: %c\n",result.num[strlen(result.num)-min-j-2]);
    //     }
         
    // }
}



//work in progress
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





//Этот работает
BigNumber BigNumber::operator=(BigNumber b){
    this->num=b.num;
    this->sign=b.sign;
    this->len=b.len;

    return *this;

}