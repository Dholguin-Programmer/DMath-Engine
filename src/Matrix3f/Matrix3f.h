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

            //! Default constructor for the Vector3f class.
            /*!
                This constructor constructs a 3-D zero vector.
            */
            Matrix3f() = default;
    
            //! Constructor for the Vector3f class.
            /*!
                This constructor constructs a 3-D matrix based upon the specified values.
            */ 
            Matrix3f(float _m0, float _m3, float _m6,
                     float _m1, float _m4, float _m7,
                     float _m2, float _m5, float _m8);
            
            //! Deconstructor for the Vector3f class.
            /*!
                This deconstructor is called when the lifteime of this object ends.
            */ 
            ~Matrix3f();

            //! Copy constuctor for the Vector3f class.
            /*!
                This copy constructor is called when we're initializing
                a Vector3f (object A) from another Vector3f (object B)
                via a constructor 
            */ 
            Matrix3f(const Matrix3f& _v);

            //! Copy constuctor for the Vector3f class.
            /*!
                This copy constructor is called when we're initializing
                a Vector3f (object A) from another Vector3f (object B)
                via the = operation. 
            */ 
            Matrix3f& operator=(const Matrix3f& _v);

            //! C++ standard library cout operator for the Vector3f class.
            /*!
                This operator defines how the Vector3f class is outputed to the
                C++ standard library's output stream.
            */ 
            friend std::ostream& operator<<(std::ostream& os, const Matrix3f& dt);

            //! '==' operator for the Vector3f class. 
            /*!
                The '==' operator defines the implementation details for
                determinging whether two vectors are the same with respect to
                their X, Y, and Z values.
            */ 
            bool operator==(const Matrix3f& _v) const;

            //! '!=' operator for the Vector3f class. 
            /*!
                The '!=' operator defines the implementation details for
                determinging whether two vectors are not the same with respect
                to their X, Y, and Z values.
            */ 
            bool operator!=(const Matrix3f& _v) const;
    };
}
#endif