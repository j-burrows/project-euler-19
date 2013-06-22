/* ProblemNineteen.h
 * 
 * Purpose: To have a program that calculates and displays how many sundays fell on the first  of a month  */
#ifndef PROBLEMNINETEEN_H
#define PROBLEMNINETEEN_H 1
#include <stdio.h>
#include <unistd.h>
#include <windows.h>
/*sleep waits for one second for every x*/
#define sleep(x) Sleep(1000*x)

/*Returns a 1 if the given year is a leap year, zero if not.*/
int leap_year(int year);

/* incriments the given date by 1 month.*/
void add_month(int* day, int* month, int* year);

/* Counts all the sundays that lie on the first of a month between January 1st 1901 and December 31st 2001*/
int first_of_month_sundays();

#endif
