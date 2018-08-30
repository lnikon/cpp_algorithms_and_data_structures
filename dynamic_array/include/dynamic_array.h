#pragma once

#include <iostream>
#include <cctype>

/* TODO LIST
 * * Add @default_size
 * * Add @defailt_capacity 
 * * Invent correct logic for them 
 * Thanks! :)
 */

template <class T>
class dynamic_array final
{
    public:
        /* Default ctor*/
        dynamic_array();

        /* Ctor with capacity specified */
        explicit dynamic_array(const std::size_t& capacity);

        /* Copy ctor (value copy or reference copy ???) */
        dynamic_array(const dynamic_array& source);

        /* Copy-assignment operator(value copy or reference copy ???) */
        /* Use swap technique 
         * (see standard C.60)
         */
        dynamic_array& operator=(const dynamic_array& source);

        /* Move ctor */
        dynamic_array(dynamic_array&& source);

        /* Move-assignment operator */
        dynamic_array&& operator=(dynamic_array&& source);

        /* Getters */
        std::size_t size() const;
        std::size_t capacity() const;

        /*
         * Utility functions for
         * class internal state debugging.
         * Should be removed, after when development is finished
         */
        void print_buffer_address_size_capacity() const
        {
            std::cout << "\n[" << m_buffer << " " << m_size << " " << m_capacity << "]\n";

        }

    private:
        T *m_buffer{nullptr};
        std::size_t m_size{0};
        std::size_t m_capacity{0};

        /*
         * Utility functions
         */
        void resize(std::size_t new_size);
};
/*
 * Public members listed 
 */
template <class T>
dynamic_array<T>::dynamic_array()
{ }

template <class T>
dynamic_array<T>::dynamic_array(const std::size_t& capacity)
    : m_buffer{new T[capacity]}, m_capacity{capacity}
{ }

template <class T>
dynamic_array<T>::dynamic_array(const dynamic_array<T>& source)
{
    m_capacity = source.m_capacity;
    m_size = source.m_size;
    
    m_buffer = new T[m_capacity];
    for(std::size_t i = 0; i < source.m_size; i++)
    {
        m_buffer[i] = source.m_buffer[i];
    }
}

template <class T>
dynamic_array<T>& dynamic_array<T>::operator=(const dynamic_array& source)
{
   if(this == &source) 
   {
       return *this;
   }

   dynamic_array tmp(source);

   std::swap(m_size, tmp.m_size);
   std::swap(m_capacity, tmp.m_capacity);
   std::swap(m_buffer, tmp.m_buffer);

   return *this;
}

template <class T>
dynamic_array<T>::dynamic_array(dynamic_array&& source)
{

}

    template <class T>
dynamic_array<T>&& dynamic_array<T>::operator=(dynamic_array&& source)
{

}

template <class T>
std::size_t dynamic_array<T>::size() const
{
    return m_size;
}

template <class T>
std::size_t dynamic_array<T>::capacity() const
{
    return m_capacity;
}

/* 
 * Privte members listed
 */
    template <class T>
void dynamic_array<T>::resize(std::size_t new_size)
{

}
