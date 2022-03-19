#include <cassert>
#include <cstddef>
#include <initializer_list>

template <typename T>
class vector {
public:
    vector(): m_capacity(0),
              m_size(0),
              m_data(nullptr) {}

    vector(const vector& other): m_size(other.m_size),
                                 m_capacity(other.m_capacity),
                                 m_data(m_capacity == 0 ? nullptr : new T[other.m_capacity])
    {
        for (std::size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }

    vector(std::size_t, const T&); // homework
    vector(std::initializer_list<T> list); // homework
    ~vector(); // homework

    vector& operator=(const vector&); // homework
    T& operator[](std::size_t index) {
        assert(index < m_size);
        return m_data[index];
    }
    const T& operator[](std::size_t) const; // homework

    void clear(); // homework

    void push_back(const T& value) {
        if (m_size == m_capacity) {
            m_capacity = m_capacity == 0 ? 1 : 2 * m_capacity;
            
            T* new_data = new T[m_capacity];
            for (std::size_t i = 0; i < m_size; ++i) {
                new_data[i] = m_data[i];
            }

            delete[] m_data;
            m_data = new_data;
        }

        m_data[m_size++] = value;
    }

    void pop_back(); // homework
    
    void resize(std::size_t size) {
        if (size > m_size) {
            if (size > m_capacity) {
                m_capacity = size;
                T* new_data = new T[m_capacity];

                for (std::size_t i = 0; i < m_size; ++i) {
                    new_data[i] = m_data[i];
                }

                delete[] m_data;
                m_data = new_data;
            }
        }
        m_size = size;
    }
    
    void reserve(std::size_t); // homework
    
    std::size_t size() const {
        return m_size;
    }

private:
    std::size_t m_capacity;
    std::size_t m_size;
    T* m_data;
};