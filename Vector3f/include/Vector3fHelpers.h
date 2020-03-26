#include "Vector3f.h"

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
        static float Dot(const DME::Vector3f& _left, const DME::Vector3f& _right);

        //! The Cross static function perfoms the cross product between two vectors
        /*!
            The cross product operation produces a vector that is perpendicular 
            to both vectors. Note that the cross product is specific to 3-D vectors
            only.
         */
        static DME::Vector3f Cross(const DME::Vector3f& _l, const DME::Vector3f& _r);

        //! The Magnitude static function returns the magnitude of a specified vector
        /*!
            The cross product operation produces a vector that is perpendicular 
            to both vectors. Note that the cross product is specific to 3-D vectors
            only.
         */
        static float Magnitude(const DME::Vector3f& _v);

        //! The Normalize static function normalizes a specified vector into a unit vector
        /*!
            Note that the unit vector is just a vector of length 1. 
         */
        static void Normalize(DME::Vector3f& _v);
    }
}