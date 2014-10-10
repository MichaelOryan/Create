#ifndef CREATE_H
#define CREATE_H

#include <iostream>

template<class T>
class Create
{

    typedef T* ptr_T;
    typedef const T& const_T;
    typedef const Create<T>& const_Create;


    T* t;

    void initalise(){this->t = NULL;}
    void destroy(){delete [] this->t;}
    void set(const_T t)
    {
        this->reset();
        this->t = new T(t);
    }

    void reset()
	{
		destroy();
		initalise();
	}

    T get()const
	{
		return this->isSet() ? *(this->t) : static_cast<T>(0);
	}

	T* getAddress()const
	{
		return this->t;
	}

    public:
    bool isSet()const
	{
		return this->getAddress() != NULL;
	};

    Create<T>()
	{
		this->t = NULL;
	}

    Create<T>(const_Create source)
	{
		this->initalise();
		set(source.get());
	}

    Create<T>(const_T source)
	{
		this->initalise();
		this->set(source);
	}

    ~Create()
	{
		destroy();
	}

	Create<T> operator=(const_Create create)
	{
		this->set(create.get());
		return Create(create.get());
	}

    T operator=(T t)
	{
		this->set(t);
		return t;
	}

    T* operator&()
	{
		return this->getAddress();
	}

    operator T()
	{
		return this->get();
	}

    template<class U>
    friend U& operator<<(U& u, const_Create create)
    {
        u << create.get();
        return u;
    }

    template<class U>
    friend U& operator>>(U& u, Create& create)
    {
        T t;
        u >> t;
        create = t;
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
};

#endif // CREATE_H
