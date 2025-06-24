#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array
{
    private:
        
        size_t  _size;
        T*      _array;

    public: 
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        T &operator[](unsigned int index);
        ~Array();

        unsigned int size() const;
};

template<typename T>
Array<T>::Array() : _size(0),  _array(nullptr) 
{

}

template<typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
    if (size == 0)
        _array = nullptr;
    else
        _array = new T[size];
}

template<typename T>
Array<T>::Array(const Array &other) : _size(other._size)
{
    if (_size == 0)
        _array = nullptr;
    else 
    {
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; ++i)
            _array[i] = other._array[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this == &other)
        return *this;

    delete[] _array;
    _size = other._size;
    if (_size == 0)
        _array = nullptr;
    else
    {
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; ++i)
            _array[i] = other._array[i];
    }
    return *this;
}

template<typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template<typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Invalid index !");
    return _array[index];    
}

template<typename T>
unsigned int Array<T>::size() const {
    return _size;
}

#endif