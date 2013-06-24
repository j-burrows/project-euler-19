/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	ProblemNineteen.c
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
*/
#include "ProblemNineteen.h"

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	leap_year
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	add_month
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	add_month
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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

/* This program will calculate and display the number of sundays that lie on the first of 
   the month, between Janurary 1st 1901 and December 31st 2001. It will then close after 
   a five second wait.*/
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
