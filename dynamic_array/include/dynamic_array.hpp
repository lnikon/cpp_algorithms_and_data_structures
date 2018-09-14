#pragma once

#include <iostream>
#include <cctype>

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

        /* Main logic */
        void push_back(const T& value);
        T pop_back();
        void push_front(const T& value);
        T pop_front();

        void insert(std::size_t pos, const T& value);

        /* Getters */
        std::size_t size() const;
        std::size_t capacity() const;
        std::size_t default_capacity() const;

        /*
         * Utility functions for
         * class internal state debugging.
         * Should be removed, after when development is finished
         */
        void print_buffer_address_size_capacity() const;
        void print_internal_buffer() const;
        bool empty() const;
        bool full() const;

    private:
        static const std::size_t m_default_capacity = 4;
        
        std::size_t m_size{0};
        std::size_t m_capacity{m_default_capacity};
        T *m_buffer{nullptr};

        bool need_resize(std::size_t pos) const;
        void increase_capacity_by(std::size_t factor);
        void shift_right_by(std::size_t factor);
        void shift_left_by(std::size_t factor);
        void swap(dynamic_array& other) noexcept;

        friend void swap(dynamic_array& source, dynamic_array& dest)
        {
            source.swap(dest);
        }
};

/*
 * Public members listed 
 */
    template <class T>
dynamic_array<T>::dynamic_array()
    :m_size{0}, m_buffer{new T[m_default_capacity]}
{ }

    template <class T>
dynamic_array<T>::dynamic_array(const std::size_t& capacity)
    : m_buffer{new T[capacity]}, m_capacity{capacity}
{ }

    template <class T>
dynamic_array<T>::dynamic_array(const dynamic_array<T>& source)
    : m_size{source.m_size}, m_capacity{source.m_capacity}
{
    m_buffer = new T[m_capacity];
    std::copy(source.m_buffer, source.m_buffer + source.m_size, m_buffer);
}

    template <class T>
dynamic_array<T>& dynamic_array<T>::operator=(const dynamic_array& source)
{
    if(this == &source) 
    {
        return *this;
    }

    dynamic_array tmp(source);
    swap(*this, source);
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
void dynamic_array<T>::push_back(const T& value)
{
    insert(m_size, value);
}

template <class T>
T dynamic_array<T>::pop_back()
{
    T back_value = m_buffer[m_size - 1];
    m_buffer[m_size] = T();
    --m_size;
    return back_value;
}

    template <class T>
void dynamic_array<T>::push_front(const T& value)
{
    shift_right_by(1);
    insert(0, value);
}

template <class T>
T dynamic_array<T>::pop_front()
{
    T front_value = m_buffer[0];
    shift_left_by(1);
    return front_value;
}

    template <class T>
void dynamic_array<T>::insert(std::size_t pos, const T& value)
{
    /* Basic checks */
    if(pos < 0 || pos > m_capacity)
    {
        // For future, raise some exception
        return;
    }

    if(full())
    {
        std::size_t factor = 2;
        increase_capacity_by(factor);
    }

    m_buffer[pos] = value;
    ++m_size;
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

template <class T>
std::size_t dynamic_array<T>::default_capacity() const
{
    return m_default_capacity;
}

template <class T>
void dynamic_array<T>::print_buffer_address_size_capacity() const
{
    std::cout << "\n[" << "buffer pointer: " << m_buffer << 
        "\n" << "array size: " << m_size << 
        "\n" << "array capacity: " << m_capacity << "]\n";
}

template <class T>
void dynamic_array<T>::print_internal_buffer() const
{
    for(std::size_t i = 0; i < m_size; i++)
    {
        std::cout << m_buffer[i] << ' ';
    }
    std::cout << '\n';
}

template <class T>
bool dynamic_array<T>::empty() const
{
    return m_size == 0;
}

template <class T>
bool dynamic_array<T>::full() const
{
    return m_size == m_capacity;
}

/* 
 * Privte members listed
 */

template <class T>
bool dynamic_array<T>::need_resize(std::size_t pos) const
{
    return pos >= m_capacity || m_size == m_capacity;
}

    template <class T>
void dynamic_array<T>::increase_capacity_by(std::size_t factor)
{
    if(factor <= 1)
    {
        factor = 2;
    }

    std::size_t new_capacity = factor * m_capacity;
    T *new_buffer = new T[new_capacity];
    std::copy(m_buffer, m_buffer + m_size, new_buffer);

    delete[] m_buffer;
    m_buffer = new_buffer;

    m_capacity = new_capacity;
}

    template <class T>
void dynamic_array<T>::shift_right_by(std::size_t factor)
{
    if(2 * m_size + factor >= m_capacity)
    {
        // For future, raise an exception
        return;
    }
    std::size_t i;
    for(i = 0; i < m_size; i++)
    {
        m_buffer[m_size + i + factor] = m_buffer[m_size + i];
    }

    if(i == m_size - 1)
    {
        m_size += factor;
    }
}

    template <class T>
void dynamic_array<T>::shift_left_by(std::size_t factor)
{
    // Add some conditions to check @factor bounds
    
    for(std::size_t i = 0; i < m_size - factor + 1; i++)
    {
        m_buffer[i] = m_buffer[i + factor];
    }

    m_size -= factor;
}

template <class T>
void dynamic_array<T>::swap(dynamic_array& other) noexcept
{
    using std::swap;
    swap(m_size, other.m_size);
    swap(m_capacity, other.m_capacity);
    swap(m_buffer, other.m_buffer);
}
