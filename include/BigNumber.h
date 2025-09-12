class BigNumber{
    char* num;
    int len;
    bool sign;
    int check_number(char* number);
    int get_size_of_number(char* number);
    BigNumber operator+(BigNumber b);
    BigNumber operator*(BigNumber b);
    BigNumber operator=(BigNumber a);
public:
    void show_val();
    BigNumber(char* number);
    BigNumber();
    ~BigNumber();
};