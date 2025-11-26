#ifndef SINGLETON_H
#define SINGLETON_H

// EXTERNAL INCLUDES
// INTERNAL INCLUDES

#define DECLARE_SINGLETON(classname)                    \
public:                                                 \
    static classname& GetInstance()                     \
    {                                                   \
        static classname instance;                      \
        return instance;                                \
    }                                                   \
private:                                                \
    classname() = default;                              \
    ~classname() = default;                             \
    classname(const classname&) = delete;               \
    classname& operator=(const classname&) = delete;    \
    classname(classname&&) = delete;                    \
    classname& operator=(classname&&) = delete;

#endif // SINGLETON_H
