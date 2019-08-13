#include "Quaternion.h"
#include "Vector3f.h"

namespace DME
{
    Quaternion::Quaternion(const float _s, Vector3f& _v)
    : qScalar(_s),
      qVector(_v)
    {
        // TRCSCOPE HERE
    }

    Quaternion::~Quaternion()
    {
        // TRCSCOPE HERE
    }

    Quaternion::Quaternion(const Quaternion& _q)
    {
        // TRCSCOPE HERE

        qScalar = _q.qScalar;
        qVector = _q.qVector;
    }

    Quaternion& Quaternion::operator=(const Quaternion& _q)
    {
        // TRCSCOPE HERE
   
        qScalar = _q.qScalar;
        qVector = _q.qVector;

        return *this;
    }

    std::ostream& operator<<(std::ostream& _os, const Quaternion& _q)
    {
        // TRCSCOPE HERE

        _os << "Q[" << _q.qScalar << ", " << 
                    "(" << _q.qVector.x << ", " 
                        << _q.qVector.y << ", " 
                        << _q.qVector.z << ")]";

        return _os;
    }

    bool Quaternion::operator==(const Quaternion& _q) const
    {
        // TRCSCROPE HERE
        bool comparison_result = true;

        comparison_result &= (qScalar == _q.qScalar);
        comparison_result &= (qVector == _q.qVector);

        return comparison_result;
    }

    bool Quaternion::operator!=(const Quaternion& _q) const
    {
        // TRCSCROPE HERE
        bool comparison_result = true;

        comparison_result &= (qScalar == _q.qScalar);
        comparison_result &= (qVector == _q.qVector);

        return !comparison_result;
    }

    void Quaternion::operator+=(const Quaternion& _q)
    {
        // TRCSCROPE HERE

        qScalar += _q.qScalar;
        qVector += _q.qVector;
    }

    Quaternion Quaternion::operator+(const Quaternion& _q) const
    {
        // TRCSCROPE HERE

        float newScalar = qScalar + _q.qScalar;
        Vector3f newVector = qVector + _q.qVector;

        return Quaternion(newScalar, newVector);
    }         

    void Quaternion::operator-=(const Quaternion& _q)
    {
        // TRCSCROPE HERE

        qScalar -= _q.qScalar;
        qVector -= _q.qVector;
    }

    Quaternion Quaternion::operator-(const Quaternion& _q) const
    {
        // TRCSCROPE HERE

        float newScalar = qScalar - _q.qScalar;
        Vector3f newVector = qVector - _q.qVector;

        return Quaternion(qScalar, newVector);
    } 
}