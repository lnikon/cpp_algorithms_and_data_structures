#pragma once
#include <iostream>
#include <limits>
#include <memory>
#include <utility>

template <class T>
class singly_linked_list
{
private:
    struct Node
    {
        T data = T();
        std::unique_ptr<Node> next{ nullptr };

        Node() = default;
        Node(T _data) : data(_data) {}
    };

    std::unique_ptr<Node> head{ nullptr };

public:
    singly_linked_list() = default;
    virtual ~singly_linked_list() = default;

    singly_linked_list(const singly_linked_list &) = delete;
    singly_linked_list &operator=(const singly_linked_list &) = delete;

    singly_linked_list(singly_linked_list &&) = default;
    singly_linked_list &operator=(singly_linked_list &&) = default;

    void push_back(T value);

    /*
     * Don't implemented yet
     * */
    void pop_back() = delete;

    void push_front(T value);
    std::unique_ptr<Node> pop_front();
    void traverse() const;
    void insert();

private:
    /* Utility functions */
    std::unique_ptr<Node> make_unique_ptr_to_node() const;
    std::unique_ptr<Node> make_unique_ptr_to_node(T value) const;
    Node* get_tail_ptr() const;
};

template <class T>
void singly_linked_list<T>::push_back(T value)
{
    auto temp = make_unique_ptr_to_node();
    temp->data = value;

    if (head == nullptr)
    {
        head = std::move(temp);
    }
    else
    {
        auto *p = get_tail_ptr();
        p->next = std::move(temp);
    }
}

template<class T>
void singly_linked_list<T>::push_front(T value)
{
    if (head == nullptr)
    {
        push_back(value);
    }
    else
    {
        auto new_head = make_unique_ptr_to_node(value);
        new_head->next = std::move(head);
        head = std::move(new_head);
    }
}

template<class T>
std::unique_ptr<typename singly_linked_list<T>::Node> singly_linked_list<T>::pop_front()
{
    auto temp = make_unique_ptr_to_node();
    if (head)
    {
        temp = std::move(head);
        head = std::move(temp->next);
    }
    return temp;
}

template <class T>
void singly_linked_list<T>::insert()
{
    
}

template <class T>
std::unique_ptr<typename singly_linked_list<T>::Node> singly_linked_list<T>::make_unique_ptr_to_node() const
{
    return std::make_unique<typename singly_linked_list<T>::Node>();
}

template <class T>
std::unique_ptr<typename singly_linked_list<T>::Node> singly_linked_list<T>::make_unique_ptr_to_node(T value) const
{
    return std::make_unique<typename singly_linked_list<T>::Node>(value);
}

template <class T>
typename singly_linked_list<T>::Node* singly_linked_list<T>::get_tail_ptr() const
{
    auto *p = head.get();
    while (p->next != nullptr)
    {
        p = p->next.get();
    }
    return p;
}

template <class T>
void singly_linked_list<T>::traverse() const
{
    Node *temp = head.get();

    while (temp)
    {
        std::cout << temp->data << ' ' << std::endl;
        temp = temp->next.get();
    }
}

