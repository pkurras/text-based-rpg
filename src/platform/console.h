#ifndef PLATFORM_CONSOLE_H
#define PLATFORM_CONSOLE_H

// EXTERNAL INCLUDES
// INTERNAL INCLUDES

class Console
{
public:
    enum class Color
    {
        Default = 0,

        Black, Blue, Green, Cyan,
        Red, Magenta, Yellow, White,

        BrightBlack, BrightBlue, BrightGreen, BrightCyan,
        BrightRed, BrightMagenta, BrightYellow, BrightWhite
    };

    static void Clear();
    static void SetColor(Color color);
    static void MoveCursor(int row, int col);
    static void GetSize(int& rows, int& cols);
};

#endif // PLATFORM_CONSOLE_H
