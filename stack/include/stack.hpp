#pragma once

#include <cctype>
#include <algorithm>

template <class T>
class stack final
{
public:
    stack();
    explicit stack(std::size_t capacity);
    stack(const stack& source);
    stack& operator=(const stack& source);

    stack(stack&&) noexcept;
    stack& operator=(stack&& source) noexcept;

    virtual ~stack() noexcept;

    bool empty() const;

    int size() const;

    std::size_t capacity() const;

    void push(const T& value);

    void push(T&& value);

    void pop();

    const T& top() const;

private:
    static const std::size_t growth_factor {2};
    std::size_t m_capacity{4};

    int m_size{-1};

    T *m_buffer{nullptr};

    void swap(stack& other) noexcept;
    bool full() const;
    void resize_internal_buffer();
};

template<class T>
stack<T>::stack()
    : m_buffer{new T[m_capacity]}
{ }

template<class T>
stack<T>::stack(std::size_t capacity)
    : m_capacity{capacity}, m_buffer{new T[m_capacity]}
{ }

template<class T>
stack<T>::stack(const stack<T> &source)
{
    m_buffer = new T[source.capacity()];
    std::copy(source.m_buffer, source.m_buffer + source.size(), m_buffer);
}

template<class T>
stack<T> &stack<T>::operator=(const stack<T> &source)
{
    stack<T> copy(source);
    swap(*this);
    return *this;
}

template<class T>
stack<T>::stack(stack<T> &&source) noexcept
{

}

template<class T>
stack<T> &stack<T>::operator=(stack &&source) noexcept
{

}

template<class T>
stack<T>::~stack() noexcept
{
    delete[] m_buffer;
}

template<class T>
bool stack<T>::empty() const
{
    return size() == 0;
}

template<class T>
int stack<T>::size() const
{
    return m_size;
}

template<class T>
std::size_t stack<T>::capacity() const
{
    return m_capacity;
}

template<class T>
void stack<T>::push(const T& value)
{
    if(full())
    {
        resize_internal_buffer();
    }

    m_buffer[++m_size] = value;
}

template<class T>
void stack<T>::push(T &&value)
{

}

template<class T>
void stack<T>::pop()
{

}

template<class T>
const T& stack<T>::top() const
{
    return m_buffer[m_size];
}

template<class T>
bool stack<T>::full() const
{
    return size() == capacity();
}

template<class T>
void stack<T>::resize_internal_buffer()
{
    T* dest = new T[growth_factor * capacity()];
    std::copy(m_buffer, m_buffer + m_size, dest);

    delete[] m_buffer;
    m_buffer = dest;
}

template<class T>
void stack<T>::swap(stack<T> &other) noexcept
{
    using std::swap;

    swap(m_size, other.m_size);
    swap(m_capacity, other.m_capacity);
    swap(m_buffer, other.m_buffer);
}
