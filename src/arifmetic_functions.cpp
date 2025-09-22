#include "../include/arifmetic_functions.h"
#include "../include/BigNumber.h"
#include <string.h>
#include <stdlib.h>
#include <algorithm>  
//здесь разлинче вспомогательные функции связаный с арифметикой
//сюда-же добавить функции определния знака арифметических операций
std::vector<char> BigNumber::summ_numbers(BigNumber* a,BigNumber b){

    BigNumber res1;
    bool perenos=false;

    char l_1[2];
    char s_1[2];
    char buff[2];
        
    l_1[1]='\0';
    s_1[1]='\0';
    buff[1]='\0';

    int min=0;
    int max=0;

    int res=0;

    {this->len > b.len ? max=this->len,min=b.len : max=b.len,min=this->len;};

    for (int i=0;i<min;i++){
        //Поразрядное сложение
        l_1[0]=b.num[b.num.size()-1-i];
        s_1[0]=this->num[this->num.size()-1-i];

        res=atoi(l_1) + atoi(s_1) + perenos;

        if(res<10){
            sprintf(buff,"%d",res);
            res1.num.push_back(buff[0]);
            perenos =false;
        }
        else{
            sprintf(buff,"%d",res%10);
            res1.num.push_back(buff[0]);
            perenos =true;
        }
    }

    for(int j=0;j<max-min;j++){
        l_1[0]=this->num[this->num.size()-min-j-1];
        res=atoi(l_1) + perenos;
        if(res<10){
            sprintf(buff,"%d",res);
            res1.num.push_back(buff[0]);
            perenos =false;
        }
        else{
            sprintf(buff,"%d",res%10);
            res1.num.push_back(buff[0]);
            perenos =true;
        }

    }

    if(perenos){
        res1.num.push_back('1');
    }
    reverse(res1.num.begin(),res1.num.end());

    return res1.num;

}
 

std::vector<char>  BigNumber::diff_numbers(BigNumber* a,BigNumber b){
    BigNumber res1;

    bool zayem=false; 

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
            res1.num.push_back(buff[0]);
        }
        else{
            res=atoi(s_1) - atoi(l_1);
            sprintf(buff,"%d",res);
            res1.num.push_back(buff[0]);
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
                res1.num.push_back(buff[0]);
            }
            else{
                res = atoi(l_1) - zayem;
                sprintf(buff,"%d",res);
                res1.num.push_back(buff[0]);
                zayem=false;
            }
        }
    }

    reverse(res1.num.begin(),res1.num.end());

    for(int h=0;h<res1.num.size();h++){
        if(res1.num[0]=='0'){
            res1.num.erase(res1.num.begin());
        }
        else{
            break;
        }
    }

    return res1.num;
}

std::vector<char>   BigNumber::prod_numbers(std::vector<char> a, std::vector<char>b){

    BigNumber res1;
    int n1 = a.size();
    int n2 = b.size();
    std::vector<int> result_inter(n1 + n2, 0);

    // Перебираем цифры с конца (младшие разряды)
    for (int i = n1 - 1; i >= 0; --i) {
        for (int j = n2 - 1; j >= 0; --j) {
            int mul = (a[i] - '0') * (b[j] - '0') + result_inter[i + j + 1];
            result_inter[i + j + 1] = mul % 10;
            result_inter[i + j] += mul / 10;
        }
    }

    // Удаляем ведущие нули
    int start = 0;
    while (start < result_inter.size() - 1 && result_inter[start] == 0) {
        ++start;
    }

    // Формируем итоговое число
    for (int i = start; i < result_inter.size(); ++i) {
        res1.num.push_back(result_inter[i] + '0');
    }
    return res1.num;
}



 