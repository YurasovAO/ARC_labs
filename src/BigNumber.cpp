#include "../include/BigNumber.h"
#include "../include/arifmetic_functions.h"


#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>    


BigNumber::BigNumber(char* number){
    check_number(number);
    get_size_of_number(number);
    printf("Got number %s\n",number);
    int start=0;
    if (number[0]=='-'){
        start=1;
    }
    for(int i=start;i<strlen(number);i++){
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
    result.sign=get_sign_of_summ_operation(this,b);
    result.num=summ_numbers(this,b);
    result.print_value();
    return result;
}

BigNumber BigNumber::operator-(BigNumber b){
    BigNumber result;
    result.sign=get_sign_of_diff_operation(this,b);
    result.num=diff_numbers(this,b);
    result.print_value();
    return result;


}

BigNumber BigNumber::operator*(BigNumber b){
    BigNumber result;
    result.sign=get_sign_of_prod_operation(this,b);
    result.num=prod_numbers(this->num,b.num);
    result.print_value();

    return result;
}






//finished
BigNumber BigNumber::operator=(BigNumber b){
    this->num=b.num;
    this->sign=b.sign;
    this->len=b.len;
    return *this;
}

