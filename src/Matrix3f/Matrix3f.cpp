#include "Matrix3f.h"
#include <iterator>

namespace DME
{
    Matrix3f::Matrix3f(float _m0, float _m3, float _m6,
                       float _m1, float _m4, float _m7,
                       float _m2, float _m5, float _m8)
    : 
        m_matrixData({_m0, _m1, _m2, _m3, _m4, _m5, _m6, _m7, _m8})
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
        unsigned char endIndex = 3;


        _os << std::endl << "[ ";
        
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

    Matrix3f Matrix3f::operator+(const Matrix3f _m) const
    {
        // TRCSCROPE HERE

        Matrix3f copyMatrix;

        copyMatrix.m_matrixData[0] = m_matrixData[0] + _m.m_matrixData[0];
        copyMatrix.m_matrixData[3] = m_matrixData[3] + _m.m_matrixData[3];
        copyMatrix.m_matrixData[6] = m_matrixData[6] + _m.m_matrixData[6];

        copyMatrix.m_matrixData[1] = m_matrixData[1] + _m.m_matrixData[1];
        copyMatrix.m_matrixData[4] = m_matrixData[4] + _m.m_matrixData[4];
        copyMatrix.m_matrixData[7] = m_matrixData[7] + _m.m_matrixData[7];

        copyMatrix.m_matrixData[2] = m_matrixData[2] + _m.m_matrixData[2];
        copyMatrix.m_matrixData[5] = m_matrixData[5] + _m.m_matrixData[5];
        copyMatrix.m_matrixData[8] = m_matrixData[8] + _m.m_matrixData[8];

        return copyMatrix;
    }

    void Matrix3f::operator+=(const Matrix3f _m)
    {
        // TRCSCROPE HERE

        m_matrixData[0] += _m.m_matrixData[0];
        m_matrixData[3] += _m.m_matrixData[3];
        m_matrixData[6] += _m.m_matrixData[6];

        m_matrixData[1] += _m.m_matrixData[1];
        m_matrixData[4] += _m.m_matrixData[4];
        m_matrixData[7] += _m.m_matrixData[7];

        m_matrixData[2] += _m.m_matrixData[2];
        m_matrixData[5] += _m.m_matrixData[5];
        m_matrixData[8] += _m.m_matrixData[8];
    }

    Matrix3f Matrix3f::operator-(const Matrix3f _m) const
    {
        // TRCSCROPE HERE

        Matrix3f copyMatrix;

        copyMatrix.m_matrixData[0] = m_matrixData[0] - _m.m_matrixData[0];
        copyMatrix.m_matrixData[3] = m_matrixData[3] - _m.m_matrixData[3];
        copyMatrix.m_matrixData[6] = m_matrixData[6] - _m.m_matrixData[6];

        copyMatrix.m_matrixData[1] = m_matrixData[1] - _m.m_matrixData[1];
        copyMatrix.m_matrixData[4] = m_matrixData[4] - _m.m_matrixData[4];
        copyMatrix.m_matrixData[7] = m_matrixData[7] - _m.m_matrixData[7];

        copyMatrix.m_matrixData[2] = m_matrixData[2] - _m.m_matrixData[2];
        copyMatrix.m_matrixData[5] = m_matrixData[5] - _m.m_matrixData[5];
        copyMatrix.m_matrixData[8] = m_matrixData[8] - _m.m_matrixData[8];

        return copyMatrix;
    }

    void Matrix3f::operator-=(const Matrix3f _m)
    {
        // TRCSCROPE HERE

        m_matrixData[0] -= _m.m_matrixData[0];
        m_matrixData[3] -= _m.m_matrixData[3];
        m_matrixData[6] -= _m.m_matrixData[6];

        m_matrixData[1] -= _m.m_matrixData[1];
        m_matrixData[4] -= _m.m_matrixData[4];
        m_matrixData[7] -= _m.m_matrixData[7];

        m_matrixData[2] -= _m.m_matrixData[2];
        m_matrixData[5] -= _m.m_matrixData[5];
        m_matrixData[8] -= _m.m_matrixData[8];
    }

    Matrix3f Matrix3f::operator*(const float _s) const
    {
        // TRCSCROPE HERE

        Matrix3f copyMatrix;

        copyMatrix.m_matrixData[0] = m_matrixData[0] * _s;
        copyMatrix.m_matrixData[3] = m_matrixData[3] * _s;
        copyMatrix.m_matrixData[6] = m_matrixData[6] * _s;

        copyMatrix.m_matrixData[1] = m_matrixData[1] * _s;
        copyMatrix.m_matrixData[4] = m_matrixData[4] * _s;
        copyMatrix.m_matrixData[7] = m_matrixData[7] * _s;

        copyMatrix.m_matrixData[2] = m_matrixData[2] * _s;
        copyMatrix.m_matrixData[5] = m_matrixData[5] * _s;
        copyMatrix.m_matrixData[8] = m_matrixData[8] * _s;

        return copyMatrix;
    }

    void Matrix3f::operator*=(const float _s)
    {
        // TRCSCROPE HERE

        m_matrixData[0] *= _s;
        m_matrixData[3] *= _s;
        m_matrixData[6] *= _s;

        m_matrixData[1] *= _s;
        m_matrixData[4] *= _s;
        m_matrixData[7] *= _s;

        m_matrixData[2] *= _s;
        m_matrixData[5] *= _s;
        m_matrixData[8] *= _s;
    }

    Matrix3f Matrix3f::operator*(const Matrix3f _m) const
    {
        // TRCSCROPE HERE

        Matrix3f copyMatrix;

        // Calculate first row of resulting matrix
        copyMatrix.m_matrixData[0] = (m_matrixData[0] * _m.m_matrixData[0]) + 
                                     (m_matrixData[3] * _m.m_matrixData[1]) + 
                                     (m_matrixData[6] * _m.m_matrixData[2]);

        copyMatrix.m_matrixData[3] = (m_matrixData[0] * _m.m_matrixData[3]) + 
                                     (m_matrixData[3] * _m.m_matrixData[4]) + 
                                     (m_matrixData[6] * _m.m_matrixData[5]);

        copyMatrix.m_matrixData[6] = (m_matrixData[0] * _m.m_matrixData[6]) + 
                                     (m_matrixData[3] * _m.m_matrixData[7]) + 
                                     (m_matrixData[6] * _m.m_matrixData[8]);

        // Calculate second row of resulting matrix
        copyMatrix.m_matrixData[1] = (m_matrixData[1] * _m.m_matrixData[0]) + 
                                     (m_matrixData[4] * _m.m_matrixData[1]) + 
                                     (m_matrixData[7] * _m.m_matrixData[2]);

        copyMatrix.m_matrixData[4] = (m_matrixData[1] * _m.m_matrixData[3]) + 
                                     (m_matrixData[4] * _m.m_matrixData[4]) + 
                                     (m_matrixData[7] * _m.m_matrixData[5]);

        copyMatrix.m_matrixData[7] = (m_matrixData[1] * _m.m_matrixData[6]) + 
                                     (m_matrixData[4] * _m.m_matrixData[7]) + 
                                     (m_matrixData[7] * _m.m_matrixData[8]);

        // Calculate last row of resulting matrix
        copyMatrix.m_matrixData[2] = (m_matrixData[2] * _m.m_matrixData[0]) + 
                                     (m_matrixData[5] * _m.m_matrixData[1]) + 
                                     (m_matrixData[8] * _m.m_matrixData[2]);

        copyMatrix.m_matrixData[5] = (m_matrixData[2] * _m.m_matrixData[3]) + 
                                     (m_matrixData[5] * _m.m_matrixData[4]) + 
                                     (m_matrixData[8] * _m.m_matrixData[5]);

        copyMatrix.m_matrixData[8] = (m_matrixData[2] * _m.m_matrixData[6]) + 
                                     (m_matrixData[5] * _m.m_matrixData[7]) + 
                                     (m_matrixData[8] * _m.m_matrixData[8]);

        return copyMatrix;
    }

    void Matrix3f::operator*=(const Matrix3f _m)
    {
        // TRCSCROPE HERE

        // Calculate the first row of the resulting matrix 
        float elementOneForCurrentRow   = 0;
        float elementTwoForCurrentRow   = 0;
        float elementThreeForCurrentRow = 0;

        elementOneForCurrentRow   = (m_matrixData[0] * _m.m_matrixData[0]) + 
                                    (m_matrixData[3] * _m.m_matrixData[1]) + 
                                    (m_matrixData[6] * _m.m_matrixData[2]);

        elementTwoForCurrentRow   = (m_matrixData[0] * _m.m_matrixData[3]) + 
                                    (m_matrixData[3] * _m.m_matrixData[4]) + 
                                    (m_matrixData[6] * _m.m_matrixData[5]);

        elementThreeForCurrentRow = (m_matrixData[0] * _m.m_matrixData[6]) + 
                                    (m_matrixData[3] * _m.m_matrixData[7]) + 
                                    (m_matrixData[6] * _m.m_matrixData[8]);

        m_matrixData[0] = elementOneForCurrentRow;
        m_matrixData[3] = elementTwoForCurrentRow;
        m_matrixData[6] = elementThreeForCurrentRow;

        // Calculate the second row of the resulting matrix
        elementOneForCurrentRow   = (m_matrixData[1] * _m.m_matrixData[0]) + 
                                    (m_matrixData[4] * _m.m_matrixData[1]) + 
                                    (m_matrixData[7] * _m.m_matrixData[2]);

        elementTwoForCurrentRow   = (m_matrixData[1] * _m.m_matrixData[3]) + 
                                    (m_matrixData[4] * _m.m_matrixData[4]) + 
                                    (m_matrixData[7] * _m.m_matrixData[5]);

        elementThreeForCurrentRow = (m_matrixData[1] * _m.m_matrixData[6]) + 
                                    (m_matrixData[4] * _m.m_matrixData[7]) + 
                                    (m_matrixData[7] * _m.m_matrixData[8]);

        m_matrixData[1] = elementOneForCurrentRow;
        m_matrixData[4] = elementTwoForCurrentRow;
        m_matrixData[7] = elementThreeForCurrentRow;

        // Calculate the final row of the resulting matrix
        elementOneForCurrentRow   = (m_matrixData[2] * _m.m_matrixData[0]) + 
                                    (m_matrixData[5] * _m.m_matrixData[1]) + 
                                    (m_matrixData[8] * _m.m_matrixData[2]);

        elementTwoForCurrentRow   = (m_matrixData[2] * _m.m_matrixData[3]) + 
                                    (m_matrixData[5] * _m.m_matrixData[4]) + 
                                    (m_matrixData[8] * _m.m_matrixData[5]);

        elementThreeForCurrentRow = (m_matrixData[2] * _m.m_matrixData[6]) + 
                                    (m_matrixData[5] * _m.m_matrixData[7]) + 
                                    (m_matrixData[8] * _m.m_matrixData[8]);
        m_matrixData[2] = elementOneForCurrentRow;
        m_matrixData[5] = elementTwoForCurrentRow;
        m_matrixData[8] = elementThreeForCurrentRow;
    }

    bool Matrix3f::operator==(const Matrix3f& _m) const
    {
        // TRCSCROPE HERE

        return m_matrixData == _m.m_matrixData;
    }

    bool Matrix3f::operator!=(const Matrix3f& _m) const
    {
        // TRCSCROPE HERE

        return m_matrixData != _m.m_matrixData;
    }
}