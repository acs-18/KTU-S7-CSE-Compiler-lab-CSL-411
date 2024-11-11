%{
#include <stdio.h>
#include <stdlib.h>

void check_date(int year, int month, int day);
%}

%%

[0-9]{4}-[0-9]{2}-[0-9]{2} {
    int year, month, day;
    sscanf(yytext, "%4d-%2d-%2d", &year, &month, &day);
    check_date(year, month, day);
}

.|\n  ;

%%

int main() {
    yylex();
    return 0;
}

void check_date(int year, int month, int day) {
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
        printf("Invalid date: %04d-%02d-%02d\n", year, month, day);
        return;
    }

    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        days_in_month[1] = 29; 
    }

    if (day > days_in_month[month - 1]) {
        printf("Invalid date: %04d-%02d-%02d\n", year, month, day);
    } else {
        printf("Valid date: %04d-%02d-%02d\n", year, month, day);
    }
}
