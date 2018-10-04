#include "bistromatic.h"
#define EXP_ERROR "Error -> exponent too large to process"

char                *iterate_power(char *o, int power, char *base)
{
    FUNC();
    int             i;
    
    i = 1;
    while (i < power)
    {
        o = multiplication(o, o, base);
        i += 1;
    }
    return (o);
}

char                *exponent(char *o, char *_power, char *base)
{
    FUNC();
    int             power;
    char            *result;
    
    if (ft_strlen(_power) > 5)
    {
        write(2, EXP_ERROR, ft_strlen(EXP_ERROR));
        return (NULL);
    }
    power = ft_atoi_base(_power, base);
    if (power == 0)
    {
        return ("1");
    }
    else if (power < 0)
    {
        return (ft_chardup(base[0]));
    }
    else
    {
        result = iterate_power(o, power, base);
    }
    return (result);
}
