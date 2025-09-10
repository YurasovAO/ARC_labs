#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>

//использовать массивы строк с 1 столбцом

#define max(a,b) (a > b ? a : b)
#define min(a,b)  (a < b ? a : b)

using namespace std;

int main(int argc,char**argv){
    
    char* a;
    char* b;                                                  
    
    int pr_res;
    
    int8_t a_size=strlen(argv[1]);
    int8_t b_size=strlen(argv[3]);

    a=(char*)calloc(1,sizeof(char));
    b=(char*)calloc(1,sizeof(char));


    for (int i=0; i < a_size ; i++){
        a[i]=argv[1][i];
        a=(char*)realloc(a,sizeof(char));
    }
    a[a_size]='\0';

    for (int j=0; j < b_size ; j++){
        b[j]=argv[3][j];
        b=(char*)realloc(b,sizeof(char));
    }
    b[b_size]='\0';

    char a_p[2];
    char b_p[2];

    a_p[0]=argv[1][0];
    b_p[0]=argv[3][0];

    a_p[1]='\0';
    b_p[1]='\0';
    
    pr_res = atoi(a_p)  + atoi(b_p);

    printf("a_p:%s",a_p);
    printf("b_p:%s",b_p);

    printf("Result: %d",pr_res);





    free(a);
    free(b);
    return 0;
}


// "9223372036854775807"
//                         "5807"
//                         ""
//                         "10000"
// register       " " "0000"