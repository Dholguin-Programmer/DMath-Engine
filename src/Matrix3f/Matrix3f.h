// Author: Diego Holguin
// <copyright>
// Purpose:

#ifndef MATRIX3F
#define MATRIX3F

#include <iostream>
#include <array>
#include <math.h>

/*! \namespace DME (DMath_Engine) namespace encapsulates all math related functionality. */
namespace DME
{
    /*! \brief Matrix3f is a object for encapsulating a 3-D matrix of float values */
    class Matrix3f
    {
        public:
            /*!< This variable encapsulates the rows and columns of a 3-D Matrix */
            std::array<float,9> m_matrixData;

            //! Default constructor for the Matrix3f class.
            /*!
                This constructor constructs a 3x3 zero matrix.
            */
            Matrix3f() = default;
    
            //! Constructor for the Matrix3f class.
            /*!
                This constructor constructs a 3x3 matrix based upon the specified values.
            */ 
            Matrix3f(float _m0, float _m1, float _m2,
                     float _m3, float _m4, float _m5,
                     float _m6, float _m7, float _m8);
            
            //! Deconstructor for the Matrix3f class.
            /*!
                This deconstructor is called when the lifteime of this object ends.
            */ 
            ~Matrix3f();

            //! Copy constuctor for the Matrix3f class.
            /*!
                This copy constructor is called when we're initializing
                a Matrix3f (object A) from another Matrix3f (object B)
                via the constructor 
            */ 
            Matrix3f(const Matrix3f& _m);

            //! Copy constuctor for the Vector3f class.
            /*!
                This copy constructor is called when we're initializing
                a Matrix3f (object A) from another Matrix3f (object B)
                via the '=' operation. 
            */ 
            Matrix3f& operator=(const Matrix3f& _m);

            //! C++ standard library cout operator for the Matrix3f class.
            /*!
                This operator defines how the Matrix3f class is outputed to the
                C++ standard library's output stream.
            */ 
            friend std::ostream& operator<<(std::ostream& os, const Matrix3f& _m);

            //! '+' operator for the Matrix3f class.
            /*!
                The '+' operator defines the implementation details for
                Matrix addition between two Matrix3f's.
            */ 
            Matrix3f operator+(const Matrix3f _m) const;

            //! '+=' operator for the Matrix3f class. 
            /*!
                The '+=' operator defines the implementation details for
                Matrix addition and assignment between two Matrix3f's.
            */ 
            void operator+=(const Matrix3f _m);

            //! '-' operator for the Matrix3f class.
            /*!
                The '-' operator defines the implementation details for
                Matrix subtraction between two Matrix3f's.
            */
            Matrix3f operator-(const Matrix3f _m) const;

            //! '-=' operator for the Matrix3f class. 
            /*!
                The '-=' operator defines the implementation details for
                Matrix subtraction and assignment between two Matrix3f's.
            */
            void operator-=(const Matrix3f _m);

            //! '*' operator for the Matrix3f class for scalar multiplication. 
            /*!
                The '*' operator defines the implementation details for
                scalar multiplication for a specified scalar value.
             */
            Matrix3f operator*(const float _s) const;

            //! '*=' operator for the Matrix3f class for scalar multiplication. 
            /*!
              The '-=' operator defines the implementation details for
              Matrix multiplication and assignment based upon a specified scalar value.
             */
            void operator*=(const float _s);

            //! '*' operator for the Matrix3f class for Matrix multiplication. 
            /*!
                The '*' operator defines the implementation details for
                Matrix multiplication between two or more Matrix3f's.
             */
            Matrix3f operator*(const Matrix3f _m) const;

            //! '*=' operator for the Matrix3f class for Matrix multiplication. 
            /*!
              The '*=' operator defines the implementation details for
              Matrix multiplication and assignment between two Matrix3f's.
             */
            void operator*=(const Matrix3f _m);

            //! '==' operator for the Matrix3f class. 
            /*!
                The '==' operator defines the implementation details for
                determinging whether two or more Matrix3f are the same with respect to
                their matrix elements.
            */ 
            bool operator==(const Matrix3f& _m) const;

            //! '!=' operator for the Matrix3f class. 
            /*!
                The '!=' operator defines the implementation details for
                determinging whether two or more Matrix3f are not the same with respect
                to their matrix elements.
            */ 
            bool operator!=(const Matrix3f& _m) const;
    };
}
#endif