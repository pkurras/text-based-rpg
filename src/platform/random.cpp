
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
#include "platform/random.h"

size_t Random::GetTrueRandomNumber()
{
#ifdef _WIN32
    size_t value = 0;
    BCryptGenRandom(
        NULL,
        (PUCHAR)&value,
        sizeof(value),
        BCRYPT_USE_SYSTEM_PREFERRED_RNG
    );
    return value;
#else
    size_t value;
    int fd = open("/dev/urandom", O_RDONLY);
    read(fd, &value, sizeof(value));
    close(fd);
    return value;
#endif
}
