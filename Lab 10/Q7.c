#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
}Date;

int leapYear(int year);
int validDate(Date date);
int daysFromStart(Date date);
int daysBetween(Date d1, Date d2);
char* dayOfWeek(Date date);

int main() {
    Date d1 = {11, 1, 2007};
    Date d2 = {12, 12, 2024};
    printf("Days between: %d\n", daysBetween(d1, d2));
    printf("Day of week: %s\n", dayOfWeek(d2));
    printf("Valid date: %d\n", validDate(d2));
    return 0;
}

int leapYear(int year) {
	if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
		printf("It is a Leap Year\n");	
	}
	else{
		printf("Not a leap year\n");
	}
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int validDate(Date date) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (leapYear(date.year)) daysInMonth[1] = 29;
    return date.year >= 1 && date.month >= 1 && date.month <= 12 &&
           date.day >= 1 && date.day <= daysInMonth[date.month - 1];
}

int daysFromStart(Date date) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = date.day;
    for (int i = 0; i < date.month - 1; i++) days += daysInMonth[i];
    if (date.month > 2 && leapYear(date.year)) days++;
    return days + (date.year - 1) * 365 + (date.year - 1) / 4 - (date.year - 1) / 100 + (date.year - 1) / 400;
}

int daysBetween(Date d1, Date d2) {
    return daysFromStart(d2) - daysFromStart(d1);
}

char* dayOfWeek(Date date) {
    char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int d = date.day, m = date.month, y = date.year;
    if (m < 3) { m += 12; y--; }
    int k = y % 100, j = y / 100;
    int dayIndex = (d + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;
    return days[(dayIndex + 7) % 7];
}
