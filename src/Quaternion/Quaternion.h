// Author: Diego Holguin
// <copyright>
// Purpose:

#ifndef QUATERNION
#define QUATERNION

#include "Vector3f.h"
#include <iostream>
#include <math.h>

/*! \namespace DME (DMath_Engine) namespace encapsulates all math related functionality. */
namespace DME
{
    /*! \brief Quaternion is a object encapsulating a 3-D vector and a scalar */
    class Quaternion
    {
        public:
            float qScalar;    /*!< The scalar value for this Quaternion */
            Vector3f qVector; /*!< The 3-D vector for this Quaternion */        

            //! Default constructor for the Quaternion class.
            /*!
                This constructor constructs a 3-D zero vector.
            */
            Quaternion() = default;
    
            //! Constructor for the Quaternion class.
            /*!
                This constructor constructs a 3-D vector based upon the _x, _y, _z values.
            */ 
            Quaternion(const float _s, Vector3f& _v);

            //! Deconstructor for the Quaternion class.
            /*!
                This deconstructor is called when the lifteime of this object ends.
            */ 
            ~Quaternion();

            //! Copy constuctor for the Quaternion class.
            /*!
                This copy constructor is called when we're initializing
                a Quaternion (object A) from another Quaternion (object B)
                via the constructor 
            */ 
            Quaternion(const Quaternion& _q);

            //! Copy constuctor for the Quaternion class.
            /*!
                This copy constructor is called when we're initializing
                a Quaternion (object A) from another Quaternion (object B)
                via the '=' operation. 
            */ 
            Quaternion& operator=(const Quaternion& _q);

            //! C++ standard library cout operator for the Quaternion class.
            /*!
                This operator defines how the Quaternion class is outputed to the
                C++ standard library's output stream.
            */ 
            friend std::ostream& operator<<(std::ostream& os, const Quaternion& _q);

            //! '==' operator for the Quaternion class. 
            /*!
                The '==' operator defines the implementation details for
                determinging whether two quaternions are the same with respect to
                their scalar and 3-D vector values.
            */ 
            bool operator==(const Quaternion& _q) const;

            //! '!=' operator for the Quaternion class. 
            /*!
                The '!=' operator defines the implementation details for
                determinging whether two quaternions are not the same with respect to
                their scalar and 3-D vector values.
            */ 
            bool operator!=(const Quaternion& _q) const;

            //! '+=' operator for the Quaternion class. 
            /*!
                The '+=' operator defines the implementation details for
                quaternion addition and assignment between two Quaternion's.
            */ 
            void operator+=(const Quaternion& _q);

            //! '+' operator for the Quaternion class.
            /*!
                The '+' operator defines the implementation details for
                quaternion addition between two Quaternion's.
            */ 
            Quaternion operator+(const Quaternion& _q) const;

            //! '-=' operator for the Quaternion class. 
            /*!
                The '-=' operator defines the implementation details for
                quaternion subtraction and assignment between two Quaternion's.
            */ 
            void operator-=(const Quaternion& _q);

            //! '-' operator for the Quaternion class.
            /*!
                The '+' operator defines the implementation details for
                quaternion subtraction between two Quaternion's.
            */ 
            Quaternion operator-(const Quaternion& _q) const;              
    };
}

#endif