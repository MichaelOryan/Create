#ifndef CREATEARRAY_H
#define CREATEARRAY_H

#include <iostream>

template<class I, class T>
class CreateArray
{

    typedef T* ptr_T;
    typedef I* ptr_I;

    typedef const T& const_T;
    typedef const I& const_I;
    typedef const CreateArray<I, T>& const_CreateArray;


    T* t;
    I size;


    void initalise(){this->t = NULL;}
    void destroy(){delete [] this->t;}

    void initalise(const_I i){this->t[i] = NULL;}
    void destroy(const_I i){delete this->t[i];}

    void set(const_I i)
    {
        this->size = i;
    }

    void set(const_T t, const_I i)
    {
        this->reset(i);
        this->t[i] = new T(t);
    }

    void set(ptr_T t, const_I size)
    {
        this->reset();
        this->t = new T[size];
        this->set(size);
        copy(this->get(), t, this->getSize());
    }

    void copy(ptr_T t, ptr_T s, I size)
    {
        while(size-- > 0)
            *t++ = *s++;
    }

    void reset(const_I i)
	{
		destroy(i);
		initalise(i);
	}

    T get()const
	{
		return this->isSet() ? *(this->t) : static_cast<T>(0);
	}

    const_I getSize() const
    {
        return this->size;
    }


	ptr_T getAddress()const
	{
		return this->t;
	}

    public:
    bool isSet()const
	{
		return this->getAddress() != NULL;
	};

    CreateArray<I, T>()
	{
		this->t = NULL;
		this->size = 0;
	}

    CreateArray<I, T>(const_CreateArray source)
	{
		this->initalise();
		set(source.get());
	}

    CreateArray<I, T>(const_T source)
	{
		this->initalise();
		this->set(source);
	}

    ~CreateArray()
	{
		destroy();
	}

	CreateArray<I, T> operator=(const_CreateArray createArray)
	{
		this->set(createArray.get(), createArray.getSize());
		return CreateArray(createArray.get());
	}

    T operator=(T t)
	{
		this->set(t);
		return t;
	}

    ptr_T operator&()
	{
		return this->getAddress();
	}

    operator T()
	{
		return this->get();
	}

    template<class U>
    friend U& operator<<(U& u, const_CreateArray createArray)
    {
        u << createArray.get();
        return u;
    }

    template<class U>
    friend U& operator>>(U& u, CreateArray& createArray)
    {
        T t;
        u >> t;
        createArray = t;
        return u;
    }

    template<class U>
    T operator<<(U u)
    {

        return this->get() << u;
    }

    template<class U>
    T operator>>(U u)
    {
        return this->get() >> u;
    }

    //ptr_T
};

#endif // CREATEARRAY_H
