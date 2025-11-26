
#ifndef PLATFORM_RANDOM_H
#define PLATFORM_RANDOM_H

// EXTERNAL INCLUDES
#ifdef _WIN32
#   include <windows.h>
#   include <bcrypt.h>
#else
#   include <stdio.h>
#   include <stdint.h>
#   include <fcntl.h>
#   include <unistd.h>
#endif
// INTERNAL INCLUDES

class Random
{
public:
    static size_t GetTrueRandomNumber();
};

#endif // PLATFORM_RANDOM_H
