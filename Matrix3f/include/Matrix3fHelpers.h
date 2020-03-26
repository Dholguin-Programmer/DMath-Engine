#include "Matrix3f.h"

namespace DME
{
    namespace Matrix3fHelpers
    {
            //! The Identity static function returns the identiy matrix
            /*!
                Note that performing Matrix Multiplication between Matrix M and
                Identify Matrix I results in Matrix M.For example, M x I = M
             */
            static DME::Matrix3f Identity();

            //! The Transpose static function takes each row and converts it to a corressponding column
            static void Transpose(DME::Matrix3f& _m);

            static DME::Matrix3f GetTranspose(const DME::Matrix3f& _m);
    }
}