#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array
{
    private:
        T *arr;
        unsigned int length;

    public:
        // Default constructor
        Array()
        {
            length = 0;
            arr = new T[0];
        }

        // Destructor
        ~Array()
        {
            delete[] arr;
        }

        // Parametarizd constructor
        Array(unsigned int n)
        {
            length = n;
            arr = new T[n];
            for (unsigned int i = 0; i < n; i++)
                arr[i] = T();
        }

        // Copy constructor
        Array(const Array &to_copy)
        {
            length = to_copy.size();
            arr = new T[length];
            for (unsigned int i = 0; i < length; i++)
                arr[i] = to_copy.arr[i];
        }

        // Copy assignment operator
        Array &operator=(const Array &to_copy)
        {
            if (this != &to_copy)
            {
                length = to_copy.size();
                delete[] arr;
                arr = new T[length];
                for (unsigned int i = 0; i < length; i++)
                    arr[i] = to_copy.arr[i];
            }

            return *this;
        }

        // Overload of non-const [] operator
        T &operator[](unsigned int i)
        {
            if (i >= length)
                throw OutOfBoundsException();
            return arr[i];
        }

        // Overload of const [] operator
        const T &operator[](unsigned int i) const
        {
            if (i >= length)
                throw OutOfBoundsException();
            return arr[i];
        }

        // Size
        unsigned int size() const
        {
            return length;
        }

        // Exception
            class OutOfBoundsException : public std::exception
            {
                public:
                    const char* what() const throw()
                    {
                        return "Trying to access invalid index.";
                    }
            };

};

#endif