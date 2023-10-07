#include <iostream>

int getlen(int num) {
    int length = 0;
    while (num > 0 )
    {
        num = num / 10;
        length = length + 1;
    }
    return length;
}

char* intToDec(int num) {
    bool is_negative = (num < 0) ? true : false;
    int total_length;

    if (is_negative) {
        total_length = getlen(num) + 3;
    } else {
        total_length = getlen(num) + 2;
    }

    char * result = new char[total_length + 1];
    result[total_length + 1] = 0;
    
    int dopsymbols;
    if (is_negative) {
        num = num * (-1);
        result[0] = '-';
        result[1] = '0';
        result[2] = 'd';
        dopsymbols = getlen(num) + 2;
    } else {
        result[0] = '0';
        result[1] = 'd';
        dopsymbols = getlen(num) + 1;
    }

    while (num > 0){
         int ost = num % 10;
         char resultdel;

         resultdel = 48 + ost;
         result[dopsymbols]=resultdel;

         num = num / 10;
         dopsymbols = dopsymbols - 1;
    }

    return result;
}

int main() {
    int number = 1000;


    std::cout << intToDec(number) << std::endl;
    
}