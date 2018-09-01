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

        /* Copy ctor */
        dynamic_array(const dynamic_array& source);

        /* Copy-assignment operator */
        dynamic_array& operator=(const dynamic_array& source);

        /* Move ctor */
        dynamic_array(dynamic_array&& source) noexcept;

        /* Move-assignment operator */
        dynamic_array& operator=(dynamic_array&& source) noexcept;

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
         * Taken from "Princeton. Algorithms, Part 1" course
         */
        void resize(std::size_t new_size);
        void swap(dynamic_array& other) noexcept;
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
    
    // assigning newly created 'gsl::owner<>' to non-owner 'T *' ???
    m_buffer = new T[m_capacity];
    std::copy(m_buffer, m_buffer + m_size, source.m_buffer);
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
dynamic_array<T>::dynamic_array(dynamic_array&& source) noexcept
    : m_size{0}, m_capacity{0}, m_buffer{nullptr}
{   
    source.swap(*this);
}

template <class T>
dynamic_array<T>& dynamic_array<T>::operator=(dynamic_array&& source) noexcept
{
    source.swap(*this);

    return *this;
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
    new_size = 0;
}

template <class T>
void dynamic_array<T>::swap(dynamic_array& other) noexcept
{
    using std::swap;
    swap(m_size, other.m_size);
    swap(m_capacity, other.m_capacity);
    swap(m_buffer, other.m_buffer);
}
