#include "Matrix3f.h"

namespace DME
{
    namespace Matrix3f_Statics
    {
            //! The Identity static function returns the identiy matrix
            /*!
                Note that performing Matrix Multiplication between Matrix M and
                Identify Matrix I results in Matrix M.For example, M x I = M
             */
            static DME::Matrix3f Identity()
            {
                // TRCSCROPE HERE

                return DME::Matrix3f(1,0,0,
                                     0,1,0,
                                     0,0,1);
            }

            static void Transpose(DME::Matrix3f& _m)
            {
                // TRCSCROPE HERE

                /* 
                    Before Transpose
                    ------------
                    | 0, 3, 6, |
                    | 1, 4, 7, |
                    | 2, 5, 8  |
                    ------------

                    After Transpose
                    ------------
                    | 0, 1, 2, |
                    | 3, 4, 5, |
                    | 6, 7, 8  |
                    ------------
                */

                std::array<float, 9> cache = _m.m_matrixData;

                // Leave 0th index alone as it's position does not change
                _m.m_matrixData[3] = cache[1];
                _m.m_matrixData[6] = cache[2];

                _m.m_matrixData[1] = cache[3];
                _m.m_matrixData[4] = cache[4];
                _m.m_matrixData[7] = cache[5];

                _m.m_matrixData[2] = cache[6];
                _m.m_matrixData[5] = cache[7];
                _m.m_matrixData[8] = cache[8];

            }

            static DME::Matrix3f GetTranspose(const DME::Matrix3f& _m)
            {
                // TRCSCROPE HERE
            
                DME::Matrix3f copyMatrix (_m.m_matrixData[0], _m.m_matrixData[3], _m.m_matrixData[6],
                                          _m.m_matrixData[1], _m.m_matrixData[4], _m.m_matrixData[7],
                                          _m.m_matrixData[2], _m.m_matrixData[5], _m.m_matrixData[8]);
                Transpose(copyMatrix);
                return copyMatrix;
            }
    }
}