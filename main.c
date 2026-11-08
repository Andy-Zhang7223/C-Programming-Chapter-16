#include <stdio.h>
#include <string.h>

struct date {
    int month;
    int day;
    int year;
};

struct date get_date[] = {
    {0,0,0},
    {0,0,0}
};

int day_of_the_year(char dat[], struct date d[], int which_date) {
    int store_date[9] = {0,0,0,0,0,0,0,0};
    for (int i = 0; i < sizeof(dat); i++) {
        store_date[i] = dat[i] - '0';
    }
    d[which_date].month = store_date[0] * 10 + store_date[1];
    d[which_date].day = store_date[3] * 10 + store_date[4];
    d[which_date].year = store_date[6] * 10 + store_date[7];
}

int exact_day(struct date d[], int which_date) {
    int x = 0;
    if (d[which_date].month == 2) {
        x = 31;
    }
    else if (d[which_date].month == 3) {
        x = 60;
    }
    else if (d[which_date].month == 4) {
        x = 91;
    }
    else if (d[which_date].month == 5) {
        x = 121;
    }
    else if (d[which_date].month == 6) {
        x = 152;
    }
    else if (d[which_date].month == 7) {
        x = 182;
    }
    else if (d[which_date].month == 8) {
        x = 213;
    }
    else if (d[which_date].month == 9) {
        x = 244;
    }
    else if (d[which_date].month == 10) {
        x = 274;
    }
    else if (d[which_date].month == 11) {
        x = 305;
    }
    else{
        x = 335;
    }
    x += d[which_date].day;
    return x;
}

int date_comparer() {
    char date1[10] = "00/00/00 ";
    char date2[10] = "00/00/00" ;

    printf("Enter First Date: ");
    fgets(date1, 10, stdin);
    printf("Enter Second Date: ");
    fgets(date2, 10, stdin);

    day_of_the_year(date1, get_date, 0);
    day_of_the_year(date2, get_date, 1);

    int exact_date1 = exact_day(get_date, 0);
    int exact_date2 = exact_day(get_date, 1);


    if (get_date[0].year < get_date[1].year) {
        printf("%s is earlier than %s", date1, date2);
    }
    else if (get_date[0].year > get_date[1].year) {
        printf("%s is earlier than %s", date2, date1);
    }

    else {
    if (exact_date1 < exact_date2) {
        printf("%s is earlier than %s", date1, date2);
    }
    else if (exact_date1 > exact_date2) {
        printf("%s is earlier than %s", date2, date1);
    }
        else {
            printf("Both dates are the same.");
        }
    }
}


int main() {
    date_comparer();
    return 0;
}