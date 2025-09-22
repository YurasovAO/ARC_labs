#include <vector>
#include <iostream>
class BigNumber{
    std::vector<char> num;
    int len;
    bool sign;

    int check_number(char* number);
    int get_size_of_number(char* number);

    std::vector<char>  summ_numbers(BigNumber* a,BigNumber b);
    std::vector<char>  diff_numbers(BigNumber* a,BigNumber b);
    std::vector<char>  diff_numbers(BigNumber a,BigNumber* b);
    std::vector<char>  prod_numbers(std::vector<char> a, std::vector<char>b);

    void summ_operation_plan(void);
    public:
        BigNumber operator+(BigNumber b);
        BigNumber operator-(BigNumber b);
        BigNumber operator*(BigNumber b);
        BigNumber operator=(BigNumber a);

        friend bool get_sign_of_summ_operation(BigNumber* a,BigNumber b);
        friend bool get_sign_of_diff_operation(BigNumber* a,BigNumber b);
        friend bool get_sign_of_prod_operation(BigNumber* a,BigNumber b);

        void print_value(void);

        BigNumber(char* number);
        BigNumber();
};