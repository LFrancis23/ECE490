// Name: Landyn Francis
// Class: ECE490
// File: days.c
// Purpose: The main function calls the days() function which takes a
// date, passed a struct with 3 member ints representing month, day, 
// and year, and determines the number of days since 
// The Turn of the Century(1/1/2000). This program uses the assumption
// that each year has 360 days, and each month has 30 days. 

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//Date Struct
struct date {
    int month;
    int day;
    int year;
};

long days(struct date testDate);

int main(){
    //Test today
    struct date Test;
    Test.year = 2023;
    Test.month = 1;
    Test.day = 20;
    printf("Days since today = %ld\n",days(Test));

    // Test every day in the century
    // Start with the turn of the century
    Test.year = 2000;
    Test.month = 1;
    Test.day = 1;
    //Keep track of true days
    long count = 0;
    while (Test.year != 2100){
        Test.day++; //Increment day
        count++;
        if (Test.day == 31){ //Increment month
            Test.month++;
            Test.day = 1;
        }
        if (Test.month == 13){ //Increment year
            Test.year++;
            Test.month = 1;
        }
        if (count == days(Test)){
            printf("Date: %d/%d/%d\tdays(Test): %ld\n",Test.month,Test.day,Test.year,days(Test));
            continue;
        }
        else{
            printf("Failed at %d/%d/%d\nCount=%ld \t days(Test)=%ld\n",Test.month,Test.day,Test.year,count,days(Test));
            return -1;
        }
        
        
    }
    printf("Pass!\n");
}
//Determine the number of days from the turn of the century for any date within the century (2000<=Year<3000)
long days(struct date testDate){
    //Make a struct for the turn of the century
    struct date turn;
    turn.month = 1;
    turn.day = 1;
    turn.year = 2000;
    long days = 0;
    //Determine how many years, months, and day difference there are between the dates, and add them up.
    days += (testDate.year - turn.year)*360;
    days += (testDate.month - turn.month)*30;
    days += (testDate.day - turn.day);
    return days;
}