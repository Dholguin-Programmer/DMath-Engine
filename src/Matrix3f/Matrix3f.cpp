#include "Matrix3f.h"
#include <iterator>

namespace DME
{
    Matrix3f::Matrix3f(float _m0, float _m3, float _m6,
                       float _m1, float _m4, float _m7,
                       float _m2, float _m5, float _m8)
    : 
        m_matrixData({_m0, _m3, _m6, _m1, _m4, _m7, _m2, _m5, _m8})
    {
        // TRCSCOPE HERE
    }

    Matrix3f::~Matrix3f()
    {
        // TRCSCOPE HERE
    }

    Matrix3f::Matrix3f(const Matrix3f& _m)
    :
        m_matrixData(_m.m_matrixData)
    {
        // TRCSCOPE HERE
    }

    Matrix3f& Matrix3f::operator=(const Matrix3f& _m)
    {
        // TRCSCROPE HERE

        m_matrixData = _m.m_matrixData;

        return *this;
    }

    std::ostream& operator<<(std::ostream& _os, const Matrix3f& _m)
    {
        // TRCSCROPE HERE

        unsigned char startIndex = 0;
        unsigned char endIndex = 2;


        _os << "[ ";
        
        // Print first row
        std::copy(_m.m_matrixData.cbegin() + startIndex,
                  _m.m_matrixData.cbegin() + endIndex,
                   std::ostream_iterator<float>(_os, " "));
        
        // Update index to second row
        startIndex+=3;
        endIndex+=3;

        _os << std::endl << "  ";

        std::copy(_m.m_matrixData.cbegin() + startIndex,
                  _m.m_matrixData.cbegin() + endIndex,
                   std::ostream_iterator<float>(_os, " "));

        _os << std::endl << "  ";

        // Update index to last row
        startIndex+=3;
        endIndex+=3;

        std::copy(_m.m_matrixData.cbegin() + startIndex,
                  _m.m_matrixData.cbegin() + endIndex,
                   std::ostream_iterator<float>(_os, " "));

        _os << " ]";

        return _os; 
    }

    bool Matrix3f::operator==(const Matrix3f& _v) const
    {
        // TRCSCROPE HERE

        return m_matrixData == _v.m_matrixData;
    }

    bool Matrix3f::operator!=(const Matrix3f& _v) const
    {
        // TRCSCROPE HERE

        return m_matrixData != _v.m_matrixData;
    }
}