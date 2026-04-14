#include <stdio.h>
#include <limits.h>
#include <stdbool.h>


int main() 
{
    printf("BOOL_MIN: %d\n", BOOL_MIN);
    printf("BOOL_MAX: %d\n", BOOL_MAX);
    printf("CHAR_MIN: %d\n", CHAR_MIN);
    printf("CHAR_MAX: %d\n", CHAR_MAX);
    printf("SHRT_MIN: %d\n", SHRT_MIN);
    printf("SHRT_MAX: %d\n", SHRT_MAX);
    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);
    printf("FLOAT_MIN: %d\n", FLOAT_MIN);
    printf("FLOAT_MAX: %d\n", FLOAT_MAX);
    printf("LONG_MIN: %d\n", LONG_MIN);
    printf("LONG_MAX: %d\n"; LONG_MAX);
    printf("LONGLONG_MIN %d\n", LONGLONG_MIN);
    printf("LONGLONG_MAX %d\n", LONGLONG_MAX);
    printf("LONG DOUBLE %d\n", LONGDUBLE_MIN);
    printf("LOND DOUBLE %d\n", LONGDUBLE_MAX);


    printf("\n");
    
    printf("bool: %zu bytes\n", sizeof(_Bool));
    printf("char: %zu bytes\n", sizeof(char));
    printf("short: %zu bytes\n", sizeof(short));
    printf("int: %zu bytes\n", sizeof(int));
    printf("float: %zu bytes\n", sizeof(float));
    printf("long: %zu bytes\n", sizeof(long));
    printf("long long: %zu bytes\n", sizeof(long long));
    printf("double: %zu bytes\n", sizeof(double));
    printf("long double: %zu bytes\n", sizeof(long double));

    printf("\n");
    bool x;
    printf("bool: %zu bytes\n", sizeof(bool));
}





#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>

int main(void)
{
    /* Valores mínimos y máximos de tipos enteros */
    printf("CHAR_MIN: %d\n", CHAR_MIN);
    printf("CHAR_MAX: %d\n", CHAR_MAX);

    printf("SCHAR_MIN: %d\n", SCHAR_MIN);
    printf("SCHAR_MAX: %d\n", SCHAR_MAX);
    printf("UCHAR_MAX: %u\n", UCHAR_MAX);

    printf("SHRT_MIN: %d\n", SHRT_MIN);
    printf("SHRT_MAX: %d\n", SHRT_MAX);
    printf("USHRT_MAX: %u\n", USHRT_MAX);

    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);
    printf("UINT_MAX: %u\n", UINT_MAX);

    printf("LONG_MIN: %ld\n", LONG_MIN);
    printf("LONG_MAX: %ld\n", LONG_MAX);
    printf("ULONG_MAX: %lu\n", ULONG_MAX);

    printf("LLONG_MIN: %lld\n", LLONG_MIN);
    printf("LLONG_MAX: %lld\n", LLONG_MAX);
    printf("ULLONG_MAX: %llu\n", ULLONG_MAX);

    printf("\n");

    /* Valores mínimos y máximos de tipos flotantes */
    printf("FLT_MIN: %e\n", FLT_MIN);
    printf("FLT_MAX: %e\n", FLT_MAX);

    printf("DBL_MIN: %e\n", DBL_MIN);
    printf("DBL_MAX: %e\n", DBL_MAX);

    printf("LDBL_MIN: %Le\n", LDBL_MIN);
    printf("LDBL_MAX: %Le\n", LDBL_MAX);

    printf("\n");

    /* Tamaños en bytes */
    printf("bool: %zu bytes\n", sizeof(bool));
    printf("_Bool: %zu bytes\n", sizeof(_Bool));
    printf("char: %zu bytes\n", sizeof(char));
    printf("short: %zu bytes\n", sizeof(short));
    printf("int: %zu bytes\n", sizeof(int));
    printf("long: %zu bytes\n", sizeof(long));
    printf("long long: %zu bytes\n", sizeof(long long));
    printf("float: %zu bytes\n", sizeof(float));
    printf("double: %zu bytes\n", sizeof(double));
    printf("long double: %zu bytes\n", sizeof(long double));
    printf("size_t: %zu bytes\n", sizeof(size_t));
    printf("ssize_t (si existe): %zu bytes\n", sizeof(ssize_t));

    return 0;
}
