#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>

class Date
{
    private:
        int month;
        int year;
        int day;
        std::string monthName[12]{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    public:
        //mutator that sets the variables month, day and year to the parameter values
        void set(int month, int day, int year)
        {
            this->month = month;
            this->day = day;
            this->year = year;
        } // end void set()

        int getDay() const { return day; }
        int getMonth() const { return month; }
        int getYear() const { return year; }

        /* overloaded < relational operator. (d1 < d2) is true if and only if date d2 comes after date
        d1 chronologically. For example, (03/08/2200) < (03/09/2200).
        */
        bool operator<(const Date &rdate)
        {
            if(year < rdate.year)
                return true;

            else if(year == rdate.year && month < rdate.month)
                return true;

            else if(year == rdate.year && month == rdate.month && day < rdate.day)
                return true;

            return false;
        } // end bool operator<()

        /*Different months have a different amount of days in them this function takes the dates month and shows
        days are up to that month*/
        int monthDayCounter(int month)
        {
            int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int total = 0;

            for(int i = 0; i < month - 1; i++)
            {
                total += daysInMonths[i];
            }

            return total;
        } // end int monthDayCounter()

        /*Prints the date in the format “month d, yyyy”, where month is the month’s name.
        For example: March 9, 2100. The function print() should use the static array monthName.*/
        void print()
        {
           std::cout << monthName[month - 1] << " " << day << ", " << year;
        } // end void print()

    protected:
}; // end Date.h

#endif // DATE_H
