#ifndef HELPERUTILS_H
#define HELPERUTILS_H

template <typename T>
T Clamp(T min, T max, T value)
{
    if (value < min)
        value = min;
    if (value > max)
        value = max;

    return value;
}

template <typename T>
class Range
{
public:

    Range()
    {
    }
    Range(T min, T max, T value) :
        min(min),
        max(max),
        value(value)
    {
    }
    ~Range() {}

    T min;
    T max;
    T value;
};

#endif // HELPERUTILS_H
