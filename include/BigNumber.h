#include <vector>
#include <iostream>
class BigNumber{
    std::vector<char> num;
    int len;
    bool sign;

    int check_number(char* number);
    int get_size_of_number(char* number);

    BigNumber summ_numbers(BigNumber* a,BigNumber b,BigNumber res,int offset);

    public:
        void show_val();
        BigNumber operator+(BigNumber b);
        BigNumber operator-(BigNumber b);
        BigNumber operator*(BigNumber b);
        BigNumber operator=(BigNumber a);
        BigNumber(char* number);
        BigNumber();
};