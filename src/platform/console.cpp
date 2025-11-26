// EXTERNAL INCLUDES
#ifdef _WIN32
#   include <windows.h>
#else
#   include <iostream>
#endif
// INTERNAL INCLUDES
#include "platform/console.h"

// ********************************************************************************
void Console::Clear()
{
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\033[2J\033[H";
#endif
}
// ********************************************************************************
void Console::SetColor(Color color)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD attributes = 7;

    switch (color)
    {
    case Color::Black:         attributes = 0;  break;
    case Color::Blue:          attributes = FOREGROUND_BLUE; break;
    case Color::Green:         attributes = FOREGROUND_GREEN; break;
    case Color::Cyan:          attributes = FOREGROUND_GREEN | FOREGROUND_BLUE; break;
    case Color::Red:           attributes = FOREGROUND_RED; break;
    case Color::Magenta:       attributes = FOREGROUND_RED | FOREGROUND_BLUE; break;
    case Color::Yellow:        attributes = FOREGROUND_RED | FOREGROUND_GREEN; break;
    case Color::White:         attributes = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE; break;

    case Color::BrightBlack:   attributes = FOREGROUND_INTENSITY; break;
    case Color::BrightBlue:    attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY; break;
    case Color::BrightGreen:   attributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY; break;
    case Color::BrightCyan:    attributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY; break;
    case Color::BrightRed:     attributes = FOREGROUND_RED | FOREGROUND_INTENSITY; break;
    case Color::BrightMagenta: attributes = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY; break;
    case Color::BrightYellow:  attributes = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY; break;
    case Color::BrightWhite:   attributes = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY; break;

    default: break;
    }

    SetConsoleTextAttribute(hConsole, attributes);

#else
    int code = 39;
    switch (color)
    {
    case Color::Black:         code = 30; break;
    case Color::Red:           code = 31; break;
    case Color::Green:         code = 32; break;
    case Color::Yellow:        code = 33; break;
    case Color::Blue:          code = 34; break;
    case Color::Magenta:       code = 35; break;
    case Color::Cyan:          code = 36; break;
    case Color::White:         code = 37; break;

    case Color::BrightBlack:   code = 90; break;
    case Color::BrightRed:     code = 91; break;
    case Color::BrightGreen:   code = 92; break;
    case Color::BrightYellow:  code = 93; break;
    case Color::BrightBlue:    code = 94; break;
    case Color::BrightMagenta: code = 95; break;
    case Color::BrightCyan:    code = 96; break;
    case Color::BrightWhite:   code = 97; break;

    default: break;
    }

    std::cout << "\033[" << code << "m";
#endif
}
// ********************************************************************************
void Console::MoveCursor(int row, int col)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { (SHORT)col, (SHORT)row };
    SetConsoleCursorPosition(hConsole, pos);
#else
    std::cout << "\033[" << row << ";" << col << "H";
#endif
}
// ********************************************************************************
void Console::GetSize(int& rows, int& cols)
{
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#else
    rows = 24;
    cols = 80;
#endif
}
// ********************************************************************************
