#include "Vector3f.h"

namespace DME
{
    Vector3f::Vector3f(float _x, 
                                     float _y,
                                     float _z)
    : 
      x(_x),
      y(_y),
      z(_z)
    {
        // TRCSCOPE HERE
    }

    Vector3f::~Vector3f()
    {
        // TRCSCOPE HERE
    }

    Vector3f::Vector3f(const Vector3f& _v)
    :
      x(_v.x),
      y(_v.y),
      z(_v.z)
    {
        // TRCSCOPE HERE
    }

    Vector3f& Vector3f::operator=(const Vector3f& _v)
    {
        // TRCSCROPE HERE

        x = _v.x;
        y = _v.y;
        z = _v.z;

        return *this;
    }

    std::ostream& operator<<(std::ostream& _os, const Vector3f& _v)
    {
        // TRCSCROPE HERE

        _os << "(" << _v.x << ", " << _v.y << ", " << _v.z << ")";

        return _os; 
    }

    bool Vector3f::operator==(const Vector3f& _v) const
    {
        // TRCSCROPE HERE
        bool comparison_result = true;

        comparison_result &= (x == _v.x);
        comparison_result &= (y == _v.y);
        comparison_result &= (z == _v.z);

        return comparison_result;
    }

    bool Vector3f::operator!=(const Vector3f& _v) const
    {
        // TRCSCROPE HERE
        bool comparison_result = true;

        comparison_result &= (x == _v.x);
        comparison_result &= (y == _v.y);
        comparison_result &= (z == _v.z);

        return !comparison_result;
    }

    void Vector3f::operator+=(const Vector3f& _v)
    {
        // TRCSCROPE HERE

        x += _v.x;
        y += _v.y;
        z += _v.z;
    }

    Vector3f Vector3f::operator+(const Vector3f& _v) const
    {
        // TRCSCROPE HERE

        return Vector3f(x + _v.x,
                        y + _v.y,
                        z + _v.z);
    }

    void Vector3f::operator-=(const Vector3f& _v)
    {
        // TRCSCROPE HERE

        x -= _v.x;
        y -= _v.y;
        z -= _v.z;
    }

    Vector3f Vector3f::operator-(const Vector3f& _v) const
    {
        // TRCSCROPE HERE
        
        return Vector3f(x - _v.x,
                        y - _v.y,
                        z - _v.z);
    }

    void Vector3f::operator*=(const float _scalar)
    {
        // TRCSCROPE HERE

        x *= _scalar;
        y *= _scalar;
        z *= _scalar;
    }

    Vector3f Vector3f::operator*(const float _scalar) const
    {
        // TRCSCROPE HERE
        
        return Vector3f(x * _scalar,
                        y * _scalar,
                        z * _scalar);
    }

    void Vector3f::operator/=(const float _scalar)
    {
        // TRCSCROPE HERE

        x /= _scalar;
        y /= _scalar;
        z /= _scalar;
    }

    Vector3f Vector3f::operator/(const float _scalar) const
    {
        // TRCSCROPE HERE
        
        return Vector3f(x / _scalar,
                        y / _scalar,
                        z / _scalar);
    }
}