// Author: Diego Holguin
// <copyright>
// Purpose:

#ifndef VECTOR3F
#define VECTOR3F

#include <iostream>
#include <math.h>

/*! \namespace DME (DMath_Engine) namespace encapsulates all math related functionality. */
namespace DME
{
    /*! \brief Vector3f is a object for encapsulating a 3-D vector as float values */
    class Vector3f
    {
        public:
            float x; /*!< The X value for the 3-D Vector */
            float y; /*!< The Y value for the 3-D Vector */
            float z; /*!< The Z value for the 3-D Vector */

            //! Default constructor for the Vector3f class.
            /*!
                This constructor constructs a 3-D zero vector.
            */
            Vector3f() = default;
    
            //! Constructor for the Vector3f class.
            /*!
                This constructor constructs a 3-D vector based upon the _x, _y, _z values.
            */ 
            Vector3f(float _x, float _y, float _z);
            
            //! Deconstructor for the Vector3f class.
            /*!
                This deconstructor is called when the lifteime of this object ends.
            */ 
            ~Vector3f();

            //! Copy constuctor for the Vector3f class.
            /*!
                This copy constructor is called when we're initializing
                a Vector3f (object A) from another Vector3f (object B)
                via the constructor 
            */ 
            Vector3f(const Vector3f& _v);

            //! Copy constuctor for the Vector3f class.
            /*!
                This copy constructor is called when we're initializing
                a Vector3f (object A) from another Vector3f (object B)
                via the '=' operation. 
            */ 
            Vector3f& operator=(const Vector3f& _v);

            //! C++ standard library cout operator for the Vector3f class.
            /*!
                This operator defines how the Vector3f class is outputed to the
                C++ standard library's output stream.
            */ 
            friend std::ostream& operator<<(std::ostream& os, const Vector3f& dt);

            //! '==' operator for the Vector3f class. 
            /*!
                The '==' operator defines the implementation details for
                determinging whether two vectors are the same with respect to
                their X, Y, and Z values.
            */ 
            bool operator==(const Vector3f& _v) const;

            //! '!=' operator for the Vector3f class. 
            /*!
                The '!=' operator defines the implementation details for
                determinging whether two vectors are not the same with respect
                to their X, Y, and Z values.
            */ 
            bool operator!=(const Vector3f& _v) const;

            //! '+=' operator for the Vector3f class. 
            /*!
                The '+=' operator defines the implementation details for
                vector addition and assignment between two Vector3f's.
            */ 
            void operator+=(const Vector3f& _v);

            //! '+' operator for the Vector3f class.
            /*!
                The '+' operator defines the implementation details for
                vector addition between two Vector3f's.
            */ 
            Vector3f operator+(const Vector3f& _v) const;

            //! '-=' operator for the Vector3f class.
            /*!
                The '-=' operator defines the implementation details for
                vector subtraction and assignment between two Vector3f's.
            */
            void operator-=(const Vector3f& _v);

            //! '-' operator for the Vector3f class.
            /*!
                The '-' operator defines the implementation details for
                vector subtraction between two Vector3f's.
            */
            Vector3f operator-(const Vector3f& _v) const;

            //! '*=' operator used for multiplying a vector by a scalar value, with assignment.
            /*!
                The '*=' operator defines the implementation details for
                scalar multiplication and assignment for a specified scalar value.
             */
            void operator*=(const float _scalar);

            //! '*' operator used for multiplying a vector by a scalar value.
            /*!
                The '*' operator defines the implementation details for
                scalar multiplication for a specified scalar value.
             */
            Vector3f operator*(const float _scalar) const;

            //! '/=' operator used for dividing a vector by a scalar value.
            /*!
                The '/=' operator defines the implementation details for
                scalar division and assignment for a specified scalar value.
             */
            void operator/=(const float _scalar);

            //! '/' operator used for dividing a vector by a scalar value.
            /*!
                The '/' operator defines the implementation details for
                scalar multiplication for a specified scalar value.
             */
            Vector3f operator/(const float _scalar) const;
    };
}
#endif