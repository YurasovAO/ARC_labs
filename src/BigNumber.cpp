#include "../include/BigNumber.h"
#include "../include/arifmetic_functions.h"


#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>    

#define max(a,b) {a>b ? a : b}
#define min(a,b) {a<b ? a : b}

//здесь оставить все арифметические операции (сложение,вычитание, умножение)

//Эта функция выполняет проверку на наличие искобчительно цифровых символов, а также проверку на отсутствие нуля 
//в рязрядах младше первого(нулевого)



BigNumber::BigNumber(char* number){
    check_number(number);
    get_size_of_number(number);
    printf("Got number %s\n",number);
    for(int i=0;i<strlen(number);i++){
        num.push_back(number[i]);
    }

}

BigNumber::BigNumber(){
    sign=true;
    len=0;
}

//finished
 BigNumber BigNumber::operator+(BigNumber b){
    BigNumber result;

    ssize_t len_a=this->len;
    ssize_t len_b=b.len;
    //Определение знака результата операции
    // if(len_a > len_b) { result.sign=this->sign;}
    // else if(len_b > len_a) {result.sign=b.sign;}
    // else {  
    //     if(this->sign == true && b.sign == true){
    //         result.sign =true;
    //     }
    //     else if (this->sign == false && b.sign == false){
    //         result.sign=false;
    //     }
    //     else{
    //         //Тут переделать под проверку под первое число
    //         result.num.clear();
    //         result.num.push_back('0');
    //     }
    // }


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

    {this->len > b.len ? max=this->len,min=b.len : max=b.len,min=this->len;};


    for (int i=0;i<min;i++){
        //Поразрядное сложение
        l_1[0]=b.num[b.num.size()-1-i];
        s_1[0]=this->num[this->num.size()-1-i];

        res=atoi(l_1) + atoi(s_1) + perenos;

        if(res<10){
            sprintf(buff,"%d",res);
            result.num.push_back(buff[0]);
            perenos =false;
        }
        else{
            sprintf(buff,"%d",res%10);
            result.num.push_back(buff[0]);
            perenos =true;
        }
    }

    
    if(len_a > len_b){
        
        for(int j=0;j<max-min;j++){
            l_1[0]=this->num[this->num.size()-min-j-1];
            res=atoi(l_1) + perenos;
            if(res<10){
                sprintf(buff,"%d",res);
                result.num.push_back(buff[0]);
                perenos =false;
            }
            else{
                sprintf(buff,"%d",res%10);
                result.num.push_back(buff[0]);
                perenos =true;
            }

        }
        if(perenos){
            result.num.push_back('1');
        }
        reverse(result.num.begin(),result.num.end());

         for(int o=0;o<result.num.size();o++){
             printf("%c\n",result.num[o]);
         }

    }
    else if (len_b>len_a){
        for(int j=0;j<max-min;j++){
            l_1[0]=b.num[b.num.size()-j-min-1];
            res=atoi(l_1) + perenos;
            if(res<10){
                sprintf(buff,"%d",res);
                result.num.push_back(buff[0]);
                perenos =false;
            }
            else{
                sprintf(buff,"%d",res%10);
                result.num.push_back(buff[0]);
                perenos =true;
            }
        }
        if(perenos){
            result.num.push_back('1');
        }
        reverse(result.num.begin(),result.num.end());

        
    }

    else{
        if(perenos){
            result.num.push_back('1');
        }
        reverse(result.num.begin(),result.num.end());

         for(int o=0;o<result.num.size();o++){
             printf("%c\n",result.num[o]);
        }
    }

    return result;
}

BigNumber BigNumber::operator-(BigNumber b){

    BigNumber result;

    bool zayem; 

    ssize_t len_a=this->len;
    ssize_t len_b=b.len;

    char l_1[2];
    char s_1[2];
    char buff[2];
        
    l_1[1]='\0';
    s_1[1]='\0';
    buff[1]='\0';
    int res;

    int min=0;
    int max=0;

    {this->len > b.len ? max=this->len,min=b.len : max=b.len,min=this->len;};

    for (int i=0;i<min;i++){

        l_1[0]=b.num[len_b-1-i];
        s_1[0]=this->num[len_a-1-i];
        
        if(atoi(s_1) - atoi(l_1) < 0){
            zayem=true;
            res=atoi(s_1) - atoi(l_1) + 10;
            sprintf(buff,"%d",res);
            result.num.push_back(buff[0]);
        }
        else{
            res=atoi(s_1) - atoi(l_1);
            sprintf(buff,"%d",res);
            result.num.push_back(buff[0]);
        }

        //блок измнения остальной части числа, с которой ещё не проводилась операция вычитания
        if(zayem){
            for(int l=0;l<len_a-i-1;l++){
                s_1[0]=this->num[(len_a-i-2)-l];
                if(s_1[0] == '0'){
                    this->num[this->num.size()-i-2-l] = '9';
                }
                else{
                    res=atoi(s_1)-1;
                    sprintf(buff,"%d",res);
                    this->num[(len_a-i-2)-l]=buff[0];
                    break;
                    

                }
            }
            zayem=false;
        }

      

    }


    if(len_a != len_b){
    for(int a=0;a<max-min;a++){
            s_1[0]=this->num[this->num.size()-min-a-1];
            if(atoi(l_1) - zayem < 0){
                res = atoi(l_1) - zayem +10;
                sprintf(buff,"%d",res);
                result.num.push_back(buff[0]);
            }
            else{
                res = atoi(l_1) - zayem;
                sprintf(buff,"%d",res);
                result.num.push_back(buff[0]);
                zayem=false;
            }
        }
    }

    reverse(result.num.begin(),result.num.end());
    if(result.num[0]=='-'){
        result.num.erase(result.num.begin());
    }
    return 0;

}








//finished
BigNumber BigNumber::operator=(BigNumber b){
    this->num=b.num;
    this->sign=b.sign;
    this->len=b.len;
    return *this;
}

// //сделать функцию сложения и вычитания числа в разряде
