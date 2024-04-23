#include<stdio.h>
#include<time.h>

    int main() {
        struct tm date1 = {0}, date2 = {0};
        time_t time1, time2;
        double seconds;

        // Set the first date
        date1.tm_year = 2022 - 1900;  // Year is year since 1900
        date1.tm_mon = 1;  // Month is 0 - 11
        date1.tm_mday = 1;  // Day of the month is 1 - 31

        // Set the second date
        date2.tm_year = 2022 - 1900;
        date2.tm_mon = 1;
        date2.tm_mday = 31;

        // Convert to time_t
        time1 = mktime(&date1);
        time2 = mktime(&date2);

        // Calculate the difference in seconds
        seconds = difftime(time2, time1);

        printf("Difference between dates is %.2f seconds\n", seconds);

        return 0;
    }
