#include "Vector3fHelpers.h"

namespace DME
{
    namespace Vector3fHelpers
    {
        //! The Dot static function perfoms the dot product between two vectors
        /*!
            The dot product operation tells us the direction of each vector.
            For example, if the dot product is equal to 1, it means that both vectors
            have the same direciton. If the dot product is 0, it means that both
            vectors are perpendicular to each other. If the dot product is -1, it means
            that both vectors are heading in the opposite directions.
         */
        static float Dot(const DME::Vector3f& _left, const DME::Vector3f& _right)
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
        static DME::Vector3f Cross(const DME::Vector3f& _l, const DME::Vector3f& _r)
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
        static float Magnitude(const DME::Vector3f& _v)
        {
            // TRCSCROPE HERE

            return std::sqrt((_v.x * _v.x) + 
                             (_v.y * _v.y) +
                             (_v.z * _v.z));
        }

        //! The Normalize static function normalizes a specified vector into a unit vector
        /*!
            Note that the unit vector is just a vector of length 1. 
         */
        static void Normalize(DME::Vector3f& _v)
        {
            // TRCSCROPE HERE

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
    }
}