#include <stdio.h>
#include <time.h>

int main() {
  time_t current_time = time(NULL);
  struct tm today = *localtime(&current_time);

  struct tm input_date = {0};

  printf("Enter your birth year: ");
  scanf("%d", &input_date.tm_year);
  input_date.tm_year -= 1900;

  printf("Enter your birth month: ");
  scanf("%d", &input_date.tm_mon);
  input_date.tm_mon -= 1;

  printf("Enter your birth day: ");
  scanf("%d", &input_date.tm_mday);

  struct tm birthdate_in_current_year = {
      .tm_year = today.tm_year,
      .tm_mon = input_date.tm_mon,
      .tm_mday = input_date.tm_mday,
  };

  struct tm birthdate_in_next_year = {
      .tm_year = today.tm_year + 1,
      .tm_mon = input_date.tm_mon,
      .tm_mday = input_date.tm_mday,
  };

  // Convert to time_t
  time_t input_time = mktime(&input_date);
  time_t current_birthtime = mktime(&birthdate_in_current_year);
  time_t next_birthtime = mktime(&birthdate_in_next_year);

  // Calculate the age
  double seconds = difftime(current_time, input_time);
  double age = seconds / (60 * 60 * 24 * 365);

  double next_seconds, next_age;
  // Check if today is the birthday
  if (current_time < current_birthtime) {
    next_seconds = difftime(current_birthtime, current_time);
  } else {
    next_seconds = difftime(next_birthtime, current_time);
  }
  next_age = (next_seconds / (60 * 60 * 24 * 365)) + age;

  // Calculate the remaining_days until the next birthday
  double remaining_days = next_seconds / (60 * 60 * 24);

  if (today.tm_mon == input_date.tm_mon &&
      today.tm_mday == input_date.tm_mday) {
    printf("Happy Birthday! \nYou are %.2f years old today.\n", age);
  } else {
    printf("You are %.2f years old.\nYou will be %.0f in %0.f days.\n\n", age,
           next_age, remaining_days);
  }

  return 0;
}
