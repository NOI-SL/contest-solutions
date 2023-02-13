#include <bits/stdc++.h>

using namespace std;

int main()
{
  // Getting number of testcases from first line
  int t;
  char s[30];
  fgets ( s, 30, stdin );
  sscanf ( s, "%d", &t );

  while ( t-- ) {
    // Getting line
    fgets ( s, 30, stdin );

    // Declaring and initializing variables
    int arr[4] = {0, 0, 0, 0};
    int found_space = -1;
    bool found_digit = false;
    bool broken = false;
    bool malf = false;

    // Checking for digits, spaces and other characters
    for ( auto i = 0; i < 4; ++i ) {
      if ( s[i] >= '0' && s[i] <= '9' ) {
        found_digit = true;
        arr[i] = s[i] - '0';
      } else if ( s[i] == ' ' ) {
        if ( found_digit ) {
          // if a digit was already found to the left, it's broken
          broken = true;
        } else {
          found_space = i;
        }
      } else {
        // Not a digit or space
        malf = true;
      }
    }

    if ( found_digit == false && !malf ) {
      // Only spaces
      cout << "Dead\n";
    } else if ( malf ) {
      // Other character found
      cout << "Malfunctioning\n";
    } else if ( broken ) {
      cout << "Broken\n";
    } else {

      // Calculate number of digits
      int digits = 3 - found_space;

      // Check Day, Month, Temperature and 24hr conditions
      if ( digits == 1 ) {
        if ( arr[3] >= 1 && arr[3] <= 7 ) {
          cout << "Day\n";
        } else {
          cout << "Broken\n";
        }
      }

      else if ( digits == 2 ) {
        // Converting last 2 digits to month(integer)
        int mon = arr[3] + 10 * arr[2];
        if ( mon >= 1 && mon <= 12 ) {
          cout << "Month\n";
        } else {
          cout << "Broken\n";
        }
      }

      else if ( digits == 3 ) {
        // Converting last 3 digits to temperature(integer)
        int temp = arr[3] + 10 * arr[2] + 100 * arr[1];
        if ( temp >= 0 && temp <= 100 ) {
          cout << "Temperature\n";
        } else {
          cout << "Broken\n";
        }
      }

      else if ( digits == 4 ) {
        // Converting first 2 digits to hour(integer)
        int hour = arr[1] + 10 * arr[0];
        // Converting last 2 digits to minutes(integer)
        int mins = arr[3] + 10 * arr[2];
        if ( mins >= 0 && mins <= 59 && hour >= 0 && hour <= 23 ) {
          cout << "24hr\n";
        } else {
          cout << "Broken\n";
        }
      }

      else {
        cout << "Broken\n";
      }
    }
  }
}