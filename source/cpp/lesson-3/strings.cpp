#include <cctype>
#include <cassert>
#include <cstring>
#include <strings.h>

/* Copy a string from src to dest, returning a pointer to
   the end of the resulting string at dest. */
char *mystpcpy(char *dest, const char *src)
{
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }

    return dest;
}

/* Compare the strings s1 and s2 ignoring case. */
int mystrcasecmp(const char *s1, const char *s2)
{
    int c1 = 0, c2 = 0;

    while (*s1 && *s2) {
        c1 = tolower(*s1);
        c2 = tolower(*s2);
        if (c1 != c2)
            break;
        s1++;
        s2++;
    }

    return c1 - c2;
}

/* Compare the first n bytes of the strings s1 and s2 ignoring case. */
int mystrncasecmp(const char *s1, const char *s2, size_t n)
{
    int c1 = 0, c2 = 0;

    while (*s1 && *s2 && n > 0) {
        c1 = tolower(*s1);
        c2 = tolower(*s2);
        if (c1 != c2)
            break;

        s1++;
        s2++;
        n--;
    }

    return c1 - c2;
}

int main()
{
    char buf[100];
    const char *hello1 = "Hello, world!";

    char *result = mystpcpy(buf, hello1);
    char *expected = ::stpcpy(buf, hello1);

    assert(result == expected);
    assert(::strcmp(result, expected) == 0);

    const char *hello2 = "hello, world.";
    assert(mystrcasecmp(hello1, hello2) == ::strcasecmp(hello1, hello2));
    assert(mystrncasecmp(hello1, hello2, 5) == ::strncasecmp(hello1, hello2, 5));
}
