#ifndef DATA_HPP
#define DATA_HPP

#include <utility>

template<typename T>

class Data {
    private:
        T m_data;

    public:
        Data(T data) : m_data { std::move(data) } {}
        virtual ~Data() = 0;

        virtual void setData(T data) { m_data = std::move(data); }
        virtual T getData() const { return m_data; }

};

template <typename T>
Data<T>::~Data() = default;

#endif