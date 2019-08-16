#include "math.h"

namespace DME
{
    namespace Math_Helper
    {
        const double PI = std::atan(1.0)*4;

        static long double ToRadians(const long double _d)
        {
            return (_d * PI) / 180L;
        }
    }
}