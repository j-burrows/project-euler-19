/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	ProblemNineteen.h
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	To have a program that calculates and displays how many sundays fell on the 
 |				first of a month
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Author:		Jonathan Burrows
 |	Date:		November 12th 2012
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
*/

#ifndef PROBLEMNINETEEN_H
#define PROBLEMNINETEEN_H 1
#include <stdio.h>
#include <unistd.h>
#include <windows.h>
/*sleep waits for one second for every x*/
#define sleep(x) Sleep(1000*x)

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	leap_year
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Returns a 1 if the given year is a leap year, zero if not.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		year, 		the year that will be determined as a leap year or not.
 | 	@return:	is_leap_year, will be 1 if given year is a leap year, zero if not.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Algorithm:	Checks to see if the given year divisible by 4. If not, it is automatically 
 |				not a leap year. If it is divisible by four, it checks to see if it is 
 |				divisible by 100 and 400. If divisible by 4 and 100 but not by 400, it is 
 |				not a leap year. If it is divisible by 4; or divisible by 4, 100, and 400, 
 |				it is a leap year. One is returned if it is a leap year, zeroif it is not.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
*/
int leap_year(int year);

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	add_month
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	incriments the given date by 1 month.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		year, 		the year that will be determined as a leap year or not.
 | 	@return:	is_leap_year, will be 1 if given year is a leap year, zero if not.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Algorithm:	Checks to see if the given year divisible by 4. If not, it is automatically 
 |				not a leap year. If it is divisible by four, it checks to see if it is 
 |				divisible by 100 and 400. If divisible by 4 and 100 but not by 400, it is 
 |				not a leap year. If it is divisible by 4; or divisible by 4, 100, and 400, 
 |				it is a leap year. One is returned if it is a leap year, zero if it is not.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
*/
void add_month(int* day, int* month, int* year);
/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	add_month
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Counts all the sundays that lie on the first of a month between January 1st 
 |				1901 and December 31st 2001
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@return:	sundays, 	the number of sundays that lie on the first of a month between  
 |							jan 1st 1901 and dec 31st 2001.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Algorithm:	The date is initialised to the first of january, 1900. Then the date is 
 |				continuosly incremented by 1 month to the year 2001. After every incriment, 
 |				if the date falls between jan 1st 1901 and dec 31st 2001, the day is checked 
 |				to be a sunday. If it is the number of sundays is incrimented by one. After 
 |				reaching the year 2001 the total sundays are returned.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
*/
int first_of_month_sundays();

#endif
