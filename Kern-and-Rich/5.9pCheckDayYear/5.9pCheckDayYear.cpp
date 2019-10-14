/*Упражнение 5.9. Перепишите программы 
day_of_year и month_day, используя 
вместо индексов указатели.*/

#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char month_day(int *year, int *yearday, int *pmonth, int *pday);
int day_of_year(int *year, int *month, int *day);


int main() {
	int year, yearday, month, day;
	year = 20;
	month = 10;
	day = 13;
	if ((yearday = day_of_year(&year, &month, &day)) == -1) printf("date is incorrect.\n\n");
	 else printf("date is correct.\nday_of_year = %d\n\n", yearday);

	if (month_day(&year, &yearday, &month, &day) == 48) printf("date is incorrect.\n");
	 else printf("date write is correct\nday = %d, month = %d\n", day, month);
}

static char daytab[2][13] = {
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* month_day: ?????????? ????? ? ???? ?? ??? ???? */
char month_day(int *year, int *yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = *year % 4 == 0 && *year % 100 != 0 || *year % 400 == 0;

	if(leap) if (*yearday > 365 || *yearday < 0) return 48;
	else
		if (*yearday > 369 || *yearday < 0) return 48;
	
	for (i = 1; *yearday > daytab[leap][i]; i++)
		*yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = *yearday;
	return 49;
}

/* day_of_year: ?????????? ???? ???? ?? ?????? ? ??? */
int day_of_year(int *year, int *month, int *day)
{
	int i, leap;
	leap = *year % 4 == 0 && *year % 100 != 0 || *year % 400 == 0;
	if ((*month < 0 || *month > 12) || (*day < 0 || *day > daytab[leap][month])) return -1;
	for (i = 1; i < *month; i++)
		*day += daytab[leap][i];
	return *day;
}
