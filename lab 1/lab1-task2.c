#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

bool check_palindrome(int num);
int generate_number(int digits);

int main(int argc, char *argv[]){
    time_t t;
    srand((unsigned) time(&t));
    int len=atoi(argv[1]);
    char c;

    int num = generate_number(len);
    printf("%lli\n", num);
    if (check_palindrome(num)){
        printf("It is a Palindrome\n");
    }
    else{
        printf("It is not a palindrome\n");
    }

}

bool check_palindrome(int num){
    int temp = num, reversed_num = 0;
    while (num > 0){
        int digit = num % 10;
        reversed_num = reversed_num * 10 + digit;
        num /= 10;

    }

    return reversed_num == temp;

}

int generate_number(int digits){
    int min = pow(10, digits - 1);
    int max = pow(10, digits) - 1;
    return min + rand() % (max - min + 1);
}

