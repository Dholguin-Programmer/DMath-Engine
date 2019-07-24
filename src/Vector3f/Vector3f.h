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
                via a constructor 
            */ 
            Vector3f(const Vector3f& _v);

            //! Copy constuctor for the Vector3f class.
            /*!
                This copy constructor is called when we're initializing
                a Vector3f (object A) from another Vector3f (object B)
                via the = operation. 
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

            //! '*' operator used for multiplying the vector by a scalar value.
            /*!
                The '*' operator defines the implementation details for
                scalar multiplication for a specified scalar value.
             */
            Vector3f operator*(const float _scalar) const;

            //! '/=' operator used for multiplying the vector by a.
            /*!
                The '/=' operator defines the implementation details for
                scalar division and assignment for a specified scalar value.
             */
            void operator/=(const float _scalar);

            //! '/' operator used for multiplying the vector by a.
            /*!
                The '/' operator defines the implementation details for
                scalar multiplication for a specified scalar value.
             */
            Vector3f operator/(const float _scalar) const;

            //! The Dot static function perfoms the dot product between two vectors
            /*!
                The the dot product operation tells us the direction of each vector.
                For example, if the dot product is equal to 1, it means that both vectors
                have the same direciton. If the dot product is 0, it means that both
                vectors are perpendicular to each other. If the dot product is -1, it means
                that both vectors are heading in the opposite directions.
             */
            static float Dot(const Vector3f& _left, const Vector3f& _right)
            {
                // TRCSCROPE HERE
                
                return (_left.x * _right.x) + 
                       (_left.y * _right.y) + 
                       (_left.z * _right.z);
            }

            //! The Cross static function perfoms the cross product between two vectors
            /*!
                The cross product operation produces a vector that is perpendicular 
                to both vectors. Note that the cross product is specific to 3-D vectors
                only.
             */
            static Vector3f Cross(const Vector3f& _l, const Vector3f& _r)
            {
                // TRCSCROPE HERE

                return Vector3f((_l.y * _r.z) - (_l.z * _r.y),
                                (_l.z * _r.x) - (_l.x * _r.z),
                                (_l.x * _r.y) - (_l.y * _r.x));
            }

            //! The Magnitude static function returns the magnitude of a specified vector
            /*!
                The cross product operation produces a vector that is perpendicular 
                to both vectors. Note that the cross product is specific to 3-D vectors
                only.
             */
            static float Magnitude(const Vector3f& _v)
            {
                return std::sqrt((_v.x * _v.x) + 
                                 (_v.y * _v.y) +
                                 (_v.z * _v.z));
            }

            //! The Normalize static function normalizes a specified vector into a unit vector
            /*!
                Note that the unit vector is just a vector of length 1. 
             */
            static void Normalize(Vector3f& _v)
            {
                float mag = Magnitude(_v);

                if (mag > 0.0f)
                {
                    float oneOverMag = 1.0f/mag;

                    _v.x *= oneOverMag;
                    _v.y *= oneOverMag;
                    _v.z *= oneOverMag;
                }
                else
                {
                    // PRINT ERROR
                }
            }
    };
}
#endif