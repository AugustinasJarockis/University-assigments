#include <stdio.h>
#include <math.h>

int main()
{
    printf("Program for finding limits of all types\n");
    //Char
    char _char = 0;
    unsigned char u_char = 0;
    signed char s_char = 0;

    //Int
    int _int = 0;
    short int sh_int = 0;
    long int l_int = 0;
    long long int _ll_int = 0;
    unsigned int u_int = 0;
    unsigned short int u_sh_int = 0;
    unsigned long int u_l_int = 0;
    unsigned long long int u_ll_int = 0;
    signed int s_int = 0;
    signed short int s_sh_int = 0;
    signed long int s_l_int = 0;
    signed long long int s_ll_int = 0;

    //Misc
    long long _long_long = 0;
    long _long = 0;
    short _short = 0;
    unsigned long long u_long_long = 0;
    unsigned long u_long = 0;
    unsigned short u_short = 0;
    signed long long s_long_long = 0;
    signed long s_long = 0;
    signed short s_short = 0;

    //char
    unsigned long long int max_value = 0;
    signed long long int min_value = 0;
    _char = 1;
    while(_char > 0)
    {
        _char *= 2;
    }
    max_value = --_char;
    _char = -1;
    char prev_value = 0;
    while(_char < 0)
    {
        prev_value = _char;
        _char *= 2;
    }
    min_value = prev_value;
    printf("                   char range: [%I64d; %I64u]\n", min_value, max_value);

    // unsigned char
    max_value = 0;
    min_value = 0;
    u_char = 1;
    while(u_char > 0)
    {
        u_char *= 2;
    }
    max_value = --u_char;
    u_char = -1;
    unsigned char prev_value_u_char = 0;
    while(u_char < 0)
    {
        prev_value_u_char = u_char;
        u_char *= 2;
    }
    min_value = prev_value_u_char;
    printf("unsigned           char range: [%I64d; %I64u]\n", min_value, max_value);

    // signed char
    max_value = 0;
    min_value = 0;
    s_char = 1;
    while(s_char > 0)
    {
        s_char *= 2;
    }
    max_value = --s_char;
    s_char = -1;
    signed char prev_value_s_char = 0;
    while(s_char < 0)
    {
        prev_value_s_char = s_char;
        s_char *= 2;
    }
    min_value = prev_value_s_char;
    printf("  signed           char range: [%I64d; %I64u]\n", min_value, max_value);

    // int
    max_value = 0;
    min_value = 0;
    _int = 1;
    while(_int > 0)
    {
        _int *= 2;
    }
    max_value = --_int;
    _int = -1;
    int prev_value__int = 0;
    while(_int < 0)
    {
        prev_value__int = _int;
        _int *= 2;
    }
    min_value = prev_value__int;
    printf("                    int range: [%I64d; %I64u]\n", min_value, max_value);

    //short int
    max_value = 0;
    min_value = 0;
    sh_int = 1;
    while(sh_int > 0)
    {
        sh_int *= 2;
    }
    max_value = --sh_int;
    sh_int = -1;
    short int prev_value_sh_int = 0;
    while(sh_int < 0)
    {
        prev_value_sh_int = sh_int;
        sh_int *= 2;
    }
    min_value = prev_value_sh_int;
    printf("             short  int range: [%I64d; %I64u]\n", min_value, max_value);

    //long int
    max_value = 0;
    min_value = 0;
    l_int = 1;
    while(l_int > 0)
    {
        l_int *= 2;
    }
    max_value = --l_int;
    l_int = -1;
    long int prev_value_l_int = 0;
    while(l_int < 0)
    {
        prev_value_l_int = l_int;
        l_int *= 2;
    }
    min_value = prev_value_l_int;
    printf("              long  int range: [%I64d; %I64u]\n", min_value, max_value);


    //long long int
    max_value = 0;
    min_value = 0;
    _ll_int = 1;
    while(_ll_int > 0)
    {
        _ll_int *= 2;
    }
    max_value = --_ll_int;
    _ll_int = -1;
    long long int prev_value_ll_int = 0;
    while(_ll_int < 0)
    {
        prev_value_ll_int = _ll_int;
        _ll_int *= 2;
    }
    min_value = prev_value_ll_int;
    printf("         long long  int range: [%I64d; %I64u]\n", min_value, max_value);

    //unsigned int
    max_value = 0;
    min_value = 0;
    u_int = 1;
    while(u_int > 0)
    {
        u_int *= 2;
    }
    max_value = --u_int;
    u_int = -1;
    unsigned int prev_value_u_int = 0;
    while(u_int < 0)
    {
        prev_value_u_int = u_int;
        u_int *= 2;
    }
    min_value = prev_value_u_int;
    printf("unsigned            int range: [%I64d; %I64u]\n", min_value, max_value);

    //unsigned short int
    max_value = 0;
    min_value = 0;
    u_sh_int = 1;
    while(u_sh_int > 0)
    {
        u_sh_int *= 2;
    }
    max_value = --u_sh_int;
    u_sh_int = -1;
    unsigned short int prev_value_u_sh_int = 0;
    while(u_sh_int < 0)
    {
        prev_value_u_sh_int = u_sh_int;
        u_sh_int *= 2;
    }
    min_value = prev_value_u_sh_int;
    printf("unsigned     short  int range: [%I64d; %I64u]\n", min_value, max_value);

    //unsigned long int
    max_value = 0;
    min_value = 0;
    u_l_int = 1;
    while(u_l_int > 0)
    {
        u_l_int *= 2;
    }
    max_value = --u_l_int;
    u_l_int = -1;
    unsigned long int prev_value_u_l_int = 0;
    while(u_l_int < 0)
    {
        prev_value_u_l_int = u_l_int;
        u_l_int *= 2;
    }
    min_value = prev_value_u_l_int;
    printf("unsigned      long  int range: [%I64d; %I64u]\n", min_value, max_value);

    //unsigned long long int
    max_value = 0;
    min_value = 0;
    u_ll_int = 1;
    while(u_ll_int > 0)
    {
        u_ll_int *= 2;
    }
    max_value = --u_ll_int;
    u_ll_int = -1;
    unsigned long long int prev_value_u_ll_int = 0;
    while(u_ll_int < 0)
    {
        prev_value_u_ll_int = u_ll_int;
        u_ll_int *= 2;
    }
    min_value = prev_value_u_ll_int;
    printf("unsigned long long  int range: [%I64d; %I64u]\n", min_value, max_value);

    //signed int
    max_value = 0;
    min_value = 0;
    s_int = 1;
    while(s_int > 0)
    {
        s_int *= 2;
    }
    max_value = --s_int;
    s_int = -1;
    signed int prev_value_s_int = 0;
    while(s_int < 0)
    {
        prev_value_s_int = s_int;
        s_int *= 2;
    }
    min_value = prev_value_s_int;
    printf("  signed            int range: [%I64d; %I64u]\n", min_value, max_value);

    //signed short int
    max_value = 0;
    min_value = 0;
    s_sh_int = 1;
    while(s_sh_int > 0)
    {
        s_sh_int *= 2;
    }
    max_value = --s_sh_int;
    s_sh_int = -1;
    signed short int prev_value_s_sh_int = 0;
    while(s_sh_int < 0)
    {
        prev_value_s_sh_int = s_sh_int;
        s_sh_int *= 2;
    }
    min_value = prev_value_s_sh_int;
    printf("  signed     short  int range: [%I64d; %I64u]\n", min_value, max_value);

    //signed long int
    max_value = 0;
    min_value = 0;
    s_l_int = 1;
    while(s_l_int > 0)
    {
        s_l_int *= 2;
    }
    max_value = --s_l_int;
    s_l_int = -1;
    signed long int prev_value_s_l_int = 0;
    while(s_l_int < 0)
    {
        prev_value_s_l_int = s_l_int;
        s_l_int *= 2;
    }
    min_value = prev_value_s_l_int;
    printf("  signed      long  int range: [%I64d; %I64u]\n", min_value, max_value);

    //signed long long int
    max_value = 0;
    min_value = 0;
    s_ll_int = 1;
    while(s_ll_int > 0)
    {
        s_ll_int *= 2;
    }
    max_value = --s_ll_int;
    s_ll_int = -1;
    signed long long int prev_value_s_ll_int = 0;
    while(s_ll_int < 0)
    {
        prev_value_s_ll_int = s_ll_int;
        s_ll_int *= 2;
    }
    min_value = prev_value_s_ll_int;
    printf("  signed long long  int range: [%I64d; %I64u]\n", min_value, max_value);

    //long long
    max_value = 0;
    min_value = 0;
    _long_long = 1;
    while(_long_long > 0)
    {
        _long_long *= 2;
    }
    max_value = --_long_long;
    _long_long = -1;
    long long prev_value_ll = 0;
    while(_long_long < 0)
    {
        prev_value_ll = _long_long;
        _long_long *= 2;
    }
    min_value = prev_value_ll;
    printf("         long long      range: [%I64d; %I64u]\n", min_value, max_value);

    //long
    max_value = 0;
    min_value = 0;
    _long = 1;
    while(_long > 0)
    {
        _long *= 2;
    }
    max_value = --_long;
    _long = -1;
    long prev_value_l = 0;
    while(_long < 0)
    {
        prev_value_l = _long;
        _long *= 2;
    }
    min_value = prev_value_l;
    printf("              long      range: [%I64d; %I64u]\n", min_value, max_value);

    //short
    max_value = 0;
    min_value = 0;
    _short = 1;
    while(_short > 0)
    {
        _short *= 2;
    }
    max_value = --_short;
    _short = -1;
    short prev_value_sh = 0;
    while(_short < 0)
    {
        prev_value_sh = _short;
        _short *= 2;
    }
    min_value = prev_value_sh;
    printf("             short      range: [%I64d; %I64u]\n", min_value, max_value);

    //unsigned long long
    max_value = 0;
    min_value = 0;
    u_long_long = 1;
    while(u_long_long > 0)
    {
        u_long_long *= 2;
    }
    max_value = --u_long_long;
    u_long_long = -1;
    unsigned long long prev_value_u_ll = 0;
    while(u_long_long < 0)
    {
        prev_value_u_ll = u_long_long;
        u_long_long *= 2;
    }
    min_value = prev_value_u_ll;
    printf("unsigned long long      range: [%I64d; %I64u]\n", min_value, max_value);

    //unsigned long
    max_value = 0;
    min_value = 0;
    u_long = 1;
    while(u_long > 0)
    {
        u_long *= 2;
    }
    max_value = --u_long;
    u_long = -1;
    unsigned long prev_value_u_l = 0;
    while(u_long < 0)
    {
        prev_value_u_l = u_long;
        u_long *= 2;
    }
    min_value = prev_value_u_l;
    printf("unsigned long           range: [%I64d; %I64u]\n", min_value, max_value);

    //unsigned short
    max_value = 0;
    min_value = 0;
    u_short = 1;
    while(u_short > 0)
    {
        u_short *= 2;
    }
    max_value = --u_short;
    u_short = -1;
    unsigned short prev_value_u_sh = 0;
    while(u_short < 0)
    {
        prev_value_u_sh = u_short;
        u_short *= 2;
    }
    min_value = prev_value_u_sh;
    printf("unsigned     short      range: [%I64d; %I64u]\n", min_value, max_value);

    //signed long long
    max_value = 0;
    min_value = 0;
    s_long_long = 1;
    while(s_long_long > 0)
    {
        s_long_long *= 2;
    }
    max_value = --s_long_long;
    s_long_long = -1;
    signed long long prev_value_s_ll = 0;
    while(s_long_long < 0)
    {
        prev_value_s_ll = s_long_long;
        s_long_long *= 2;
    }
    min_value = prev_value_s_ll;
    printf("  signed long long      range: [%I64d; %I64u]\n", min_value, max_value);

    //signed long
    max_value = 0;
    min_value = 0;
    s_long = 1;
    while(s_long > 0)
    {
        s_long *= 2;
    }
    max_value = --s_long;
    s_long = -1;
    signed long prev_value_s_l = 0;
    while(s_long < 0)
    {
        prev_value_s_l = s_long;
        s_long *= 2;
    }
    min_value = prev_value_s_l;
    printf("  signed      long      range: [%I64d; %I64u]\n", min_value, max_value);

    //signed short
    max_value = 0;
    min_value = 0;
    s_short = 1;
    while(s_short > 0)
    {
        s_short *= 2;
    }
    max_value = --s_short;
    s_short = -1;
    signed short prev_value_s_sh = 0;
    while(s_short < 0)
    {
        prev_value_s_sh = s_short;
        s_short *= 2;
    }
    min_value = prev_value_s_sh;
    printf("  signed     short      range: [%I64d; %I64u]\n", min_value, max_value);
    return 0;
}
