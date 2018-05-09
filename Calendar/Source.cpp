//#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

enum Month {
	Jan = 1, Feb, Mar, Apr, May, Jun,
	Jul, Aug, Sep, Oct, Nov, Dec
};
enum Day { Sun, Mon, Tue, Wed, Thu, Fri, Sat };

#define Day_1980_1_1 Tue
#define Start_Year 1980
#define Num_Of_Months 12
#define Num_Of_Days 7

string day_str[7] = {
	"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

string month_str[12] = { //Fixed spelling error in source code for January and February :)
	"January", "February", "March", "April",
	"May", "June", "July", "August",
	"September", "October", "November", "December"
};

int monthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

//check to see if year entered is a leap year
bool isLeapYear(int year);

// finds the first day in the given month and year
Day findFirstDay(Month month, int year);

// prints the calendar in the given month and year
void printMonthCalendar(Month month, Day weekDay);

//prints the header (month, stars, and days) in the given month
void printHeader(int month);

// Skip spaces at the start of each calendar if month start with Mon-Sat
void skipSpaces(int startDay);

// prints the calendar of the given year
void printYrCalendar(int year);

int main(int argc, char** argv)
{
	int year;
	if (argc != 2 || (year = atoi(argv[1])) < 1980 || (year = atoi(argv[1])) > 2099) {
		cout << "Please input the year number (>=1980) and (<=2099)!" << endl;
		return 1;
	}
	bool leap = isLeapYear(year);
	if (leap == true) {
		monthDays[1] = 29; //change the number of days in Feb to 29 if leap year
	}
	printYrCalendar(year);
	return 0;
}

bool isLeapYear(int year) {
	if (year % 4 == 0 && year % 100 != 100 || year % 400 == 0) {
		return true;
	}
	else {
		return false;
	}
}

Day findFirstDay(Month month, int year) {
	int m;
	m = month;
	if (m == 1) {
		m = 13;
		year--;
	}
	if (month == 2) {
		m = 14;
		year--;
	}
	int y;
	y = year % 100;
	int c;
	c = year / 100;
	int formula;
	formula = 1 + 13 * (m + 1) / 5 + y + y / 4 + c / 4 + 5 * c;
	formula = formula % 7;

	if (formula == 0) {
		return Sat;
	}
	else if (formula == 1) {
		return Sun;
	}
	else if (formula == 2) {
		return Mon;
	}
	else if (formula == 3) {
		return Tue;
	}
	else if (formula == 4) {
		return Wed;
	}
	else if (formula == 5) {
		return Thu;
	}
	else if (formula == 6) {
		return Fri;
	}
}

void printHeader(int month) {
	switch (month) {
	case 0:
		cout << setw(12) << "****** ";
		cout << "January";
		cout << setw(7) << " ******" << endl;
		break;
	case 1:
		cout << setw(12) << "****** ";
		cout << "February";
		cout << setw(7) << " ******" << endl;
		break;
	case 2:
		cout << setw(12) << "****** ";
		cout << "March";
		cout << setw(7) << " ******" << endl;
		break;
	case 3:
		cout << setw(12) << "****** ";
		cout << "April";
		cout << setw(7) << " ******" << endl;
		break;
	case 4:
		cout << setw(12) << "****** ";
		cout << "May";
		cout << setw(7) << " ******" << endl;
		break;
	case 5:
		cout << setw(12) << "****** ";
		cout << "June";
		cout << setw(7) << " ******" << endl;
		break;
	case 6:
		cout << setw(12) << "****** ";
		cout << "July";
		cout << setw(7) << " ******" << endl;
		break;
	case 7:
		cout << setw(12) << "****** ";
		cout << "August";
		cout << setw(7) << " ******" << endl;
		break;
	case 8:
		cout << setw(12) << "****** ";
		cout << "September";
		cout << setw(7) << " ******" << endl;
		break;
	case 9:
		cout << setw(12) << "****** ";
		cout << "October";
		cout << setw(7) << " ******" << endl;
		break;
	case 10:
		cout << setw(12) << "****** ";
		cout << "November";
		cout << setw(7) << " ******" << endl;
		break;
	case 11:
		cout << setw(12) << "****** ";
		cout << "December";
		cout << setw(7) << " ******" << endl;
		break;
	}
	for (int i = 0; i < 7; i++) { //prints Sun - Sat
		cout << setw(5) << day_str[i];
	}
	cout << endl;
}

void printMonthCalendar(Month month, Day firstDay) {

	int day = 1;
	int startDay = firstDay; //startDay is assigned the int value of firstDay
	skipSpaces(startDay); //skip spaces at the start of each month if necessary
	while (day <= monthDays[month - 1]) { //since I added 1 to all the values of enum Month, I have to subtract 1 to
										  //match the index of monthDays for that corresponding month
		cout << setw(5) << day; //prints 1, 2, 3...
		if (startDay == 6 && day < monthDays[month - 1]) { //if startDay is Sat, then endl and start printing again starting at Sun
														   //if the last day of the month is on Sat, endl is skipped
			cout << endl;
			startDay = 0;
		}
		else
			startDay++;
		day++;
	}
}

void skipSpaces(int startDay) {
	//Skip however many spaces needed to format calendar correctly 
	//at the start of every month
	startDay = startDay * 5;
	while (startDay > 0) {
		cout << " ";
		startDay--;
	}
}

void printYrCalendar(int year) {
	for (int i = 1; i <= 12; i++) { //loops all the methods 12 times to print all the months
		Day firstDayOfCurrentMonth = findFirstDay(Month(i), year);
		int currentMonth = i - 1;
		printHeader(currentMonth);
		printMonthCalendar(Month(i), firstDayOfCurrentMonth);
		cout << endl << endl;
		currentMonth++;
	}
}