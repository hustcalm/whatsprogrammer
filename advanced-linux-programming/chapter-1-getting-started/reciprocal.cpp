#include <cassert>
#include "reciprocal.hpp"

double reciprocal(int number)
{
    assert (number != 0);

    return 1.0/number;
}
