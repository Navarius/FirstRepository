#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

struct City;
typedef struct City* CityPosition;
typedef struct City {
    char name[MAX_LENGTH];
    int population;
    CityPosition next;
    CityPosition right;
    CityPosition left;
} City;

struct Country;
typedef struct Country* CountryPosition;
typedef struct Country {
    char name[MAX_LENGTH];
    CountryPosition next;
    CountryPosition right;
    CountryPosition left;
    CityPosition cityRootTree;
    CityPosition cityHead;
} Country;

CountryPosition readCountryFromFile(const char* filename) {
    // Implementation to read from the file and create the Country structure
    // You'll need to open the file, read its content, and populate the structures.
    // Don't forget to allocate memory for each element.
}

int main() {
    // Testing the readCountryFromFile function
    CountryPosition country = readCountryFromFile("Hrvatska.txt");
    // Add more tests for other countries if needed

    // Now, you can print the information to check if the reading is working correctly.

    return 0;
}
CountryPosition insertCountry(CountryPosition head, CountryPosition newCountry) {
    // Implementation to insert a country into a sorted linked list
    // The sorting should be based on the country names
}
void printCountriesAndCities(CountryPosition head) {
    // Implementation to print the information in the required format
}
