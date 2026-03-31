#pragma once
#include <iostream>
#include <string>

class Date {
private:
    int month;
    int day;
    int year;

    bool dateValid(int m, int d, int y) const;

public:
    // Constructors
    Date(int m = 1, int d = 1, int y = 1900);

    // Prefix and postfix increment/decrement
    Date& operator++();       // prefix increment
    Date operator++(int);     // postfix increment
    Date& operator--();       // prefix decrement
    Date operator--(int);     // postfix decrement

    // Subtraction operator (difference in days)
    int operator-(const Date& other) const;

    // Stream operators
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    friend std::istream& operator>>(std::istream& is, Date& date);

    // Setters and getters
    void setDate(int m, int d, int y);
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    // Leap year check
    bool isLeapYear() const;
    bool isLeapYear(int y) const;

    // Last day of month
    int lastDayOfMonth() const;
    int lastDayOfMonth(int m, int y) const;

    // Formatting
    std::string formatMMDDYYYY() const;
    std::string formatMonthDayYear() const;
    std::string formatDayMonthYear() const;
};