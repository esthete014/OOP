#pragma once
// Color.h
// da eto ne moi code
// no krasivo je))
// author: https://www.codeproject.com/Articles/16431/Add-color-to-your-std-cout

#include <iostream>
#include <windows.h>

inline std::ostream& azure(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE
        | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& red(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
        FOREGROUND_RED | FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& green(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
        FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& yellow(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
        FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& white(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return s;
}

/// ////////////////////////////                  my custom
inline std::ostream& darkViolet(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
        FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    return s;
}

inline std::ostream& darkBlue(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
        FOREGROUND_BLUE | FOREGROUND_GREEN);
    return s;
}

inline std::ostream& blue(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
        FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& violet(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
        FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
    return s;
}
/// ///////////////////////////                  end

struct color {
    color(WORD attribute) :m_color(attribute) {};
    WORD m_color;
};

template <class _Elem, class _Traits>
std::basic_ostream<_Elem, _Traits>&
operator<<(std::basic_ostream<_Elem, _Traits>& i, color& c)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout, c.m_color);
    return i;
}
