#include <iostream>

template<int I>
struct sign
{
    enum {value = (I % 2) == 0 ? 1 : -1};
};

template<int I, int J>
struct pi_calc
{
    inline static double value ()
    {
        return (pi_calc<I-1, J>::value () + pi_calc<I-1, J+1>::value ()) / 2.0;
    }
};

template<int J>
struct pi_calc<0, J>
{
    inline static double value ()
    {
        return (sign<J>::value * 4.0) / (2.0 * J + 1.0) + pi_calc<0, J-1>::value ();
    }
};


template<>
struct pi_calc<0, 0>
{
    inline static double value ()
    {
        return 4.0;
    }
};

template<int I>
struct pi
{
    inline static double value ()
    {
        return pi_calc<I, I>::value ();
    }
};

int main ()
{
    std::cout.precision (12);

    const double pi_value = pi<10>::value ();

    std::cout << "pi ~ " << pi_value << std::endl;

    return 0;
}


