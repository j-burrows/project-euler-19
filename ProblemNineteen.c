/* ProblemNineteen.c*/
#include "ProblemNineteen.h"

/* function:	leap_year
 * @param:	year, the year that will be determined as a leap year or not.
 * @return:	is_leap_year, will be 1 if given year is a leap year, zero if not.
 *
 * Checks to see if the given year divisible by 4. If not, it is automatically not a leap year. If it is divisible
 * by four, it checks to see if it is divisible by 100 and 400. If divisible by 4 and 100 but not by 400, it is not a leap year.
 * If it is divisible by 4; or divisible by 4, 100, and 400, it is a leap year. One is returned if it is a leap year, zero
 * if it is not.
 */
int leap_year(int year){
	int is_leap_year;
	if((year%4) !=0){
		is_leap_year = 0;
	}
	else{
		if((year%100 == 0) && (year%400 !=0)){
			is_leap_year = 0;
		}
		else{
			is_leap_year = 1;
		}
	}
	return is_leap_year;
}

/* Subroutine:	add_month
 * @param:	day, a pointer to the day of the week, will be changed depending on month
 * 			month, a pointer to the month, will be incremented by one and set to 1 if the result is over 12
 *			year, a pointer to the year, will be incremented if the incrimented month exceeds 12.
 *
 * Adds to days the length of the current month. Such that April, June, September, and November have 30 day lengths, 
 * febuary is checked to be a leap year, adding 28 if not, 29 if it is; and the rest add 31. The days are modded with 
 * seven, and the month is incrimented. If the resulting month is over 12, it is set to 1, and the year is incrimented.
 */
void add_month(int* day, int* month, int* year){
	if( (*month) == 4 || (*month) == 6 || (*month) == 9 || (*month) == 11){
		(*day) += 30;
	}
	else if((*month)==2){
		if(leap_year(*year)){
			(*day) += 29;
		}
		else{
			(*day) += 28;
		}
	}
	else{
		(*day) +=31;
	}
	(*day) %= 7;
	
	(*month)++;
	if((*month)>12){
		(*month)=1;
		(*year)++;
	}
}

/* Subroutine:	first_of_month_sundays
 * @return:	sundays, the number of sundays that lie on the first of a month between jan 1st 1901 and dec 31st 2001.
 *
 * The date is initialised to the first of january, 1900. Then the date is continuosly incremented by 1 month to the year 2001.
 * After every incriment, if the date falls between jan 1st 1901 and dec 31st 2001, the day is checked to be a sunday. If it is
 * the number of sundays is incrimented by one. After reaching the year 2001 the total sundays are returned.
 */
int first_of_month_sundays(){
	int day, month, year, sundays;
	day = 2;
	month = 1;
	year = 1900;
	sundays = 0;
	while(year < 2001){
		/*Add only if it lies within the desired years.*/
		if(year >= 1901 && year <=2000){
			if((day %= 7)==1){
				sundays++;
			}
		}
		add_month(&day,&month,&year);
	}
	return sundays;
}

/* This program will calculate and display the number of sundays that lie on the first of the month, between Janurary 1st
 * 1901 and December 31st 2001. It will then close after a five second wait.*/
int main(){
	int sundays;
	int countdown;
	fprintf(stdout,"\nThis program will display the number of sundays that occured as the first of the month between the"
					" dates of January 1st 1901, and Decemeber 31st 2001; then close after five seconds.");
	
	sundays = first_of_month_sundays();
	fprintf(stdout, "\n\nTotal sundays that fell on the first of a month:\t%d",sundays);
	
	fprintf(stdout,"\n\n\nClosing in ");
	for(countdown = 5; countdown > 0; countdown--){
		fprintf(stdout,"%d..",countdown);
		sleep(1);
	}
	return 0;
}
