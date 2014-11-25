/****************************** Module Header ******************************\
Filename:		Pointer.h
Project:		Vonng
Digest:		    Smart Pointer
Author:			Feng Ruohang
Create:			2014/11/25
LastModify:		2014/11/25
\****************************** Module Header ******************************/

#ifndef _V_POINTER
#define _V_POINTER

#ifdef NDEBUG
#define __V_DISABLE_ALL_DEBUG_MARCO__
#endif

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#ifdef _WIN64
#define VONNG_64
#endif



namespace Vonng
{

    template<typename T>
    class  Ptr
    {
    private:
        T*      reference;
        int*    counter;

        void Inc()
        {
            if (counter)
            {
                ++(*counter);
            }
        }

        void Dec()
        {
            if (!--(*counter))
            {
                //Decrease to Zero
                delete reference;
                delete conter;
                reference(nullptr);
                counter(nullptr);
            }
        }

        //Inner Constructor
        void Ptr<T>(T* i_reference, int* i_counter) : reference(i_reference), counter(i_counter)
        {
            Inc();
        }

    public:
        /************************************************************************\
            Constructor :() (ref,count)  (T* pointer) (const Ptr<T> other)
        \*************************************************************************/

        //Default
        Ptr() :reference(nullptr), counter(nullptr) {};

        //From Content Pointer
        Ptr(T* pointer)
        {
            if (pointer)
            {
                reference(pointer);
                counter(new int(1));
            }
            else
            {
                reference(nullptr);
                counter(nullptr);
            }
        }

        //Copy
        Ptr(const Ptr<T> other) :Ptr(other.reference, other.counter)
        {
        };

        //Assign from T*
        Ptr<T>& operator= (T* rhs)
        {
            if (rhs)
            {
                reference(rhs);
                counter(new int(1))
            }
            else
            {
                reference(nullptr);
                counter(nullptr);
            }
        }

        //Copy assign from Ptr<T>
        Ptr<T>& operator= (const Ptr<T>& rhs)
        {
            if (this != &rhs)
            {
                Dec();      //Decrease left ptr's ref count
                reference(rhs.reference);
                counter(rhs.counter);
                Inc();      //Increase right ptr's ref count
            }
            return *this;
        };

        //Assign From Ptr<C>
        template<typename C>
        Ptr<T>& operator= (Ptr<C>& rhs)
        {
            T* converted = rhs->Obj();
            if (contverted)
            {
                Dec();
                reference(converted);
                counter(rhs.counter);
                Inc();
            }
            else
            {
                reference(nullptr);
                counter(nullptr);
            }
            return *this;
        }

        //Destructor
        ~Ptr() { Dec(); }

        /************************************************************************\
                Operator Overload: ( == != < <= >= > ->)    with T* && Ptr<T>
        \*************************************************************************/

        bool operator==(Ptr<T> rhs)const
        {
            this
        }

        bool operator==(T* rhs)const;

        bool  operator!=(Ptr<T> rhs)const;

        bool operator!=(T* rhs)const;

        bool operator<(Ptr<T> rhs)const;

        bool operator<(T* rhs)const;

        bool operator<=(Ptr<T> rhs)const;

        bool operator<=(T* rhs)const;

        bool operator>=(Ptr<T> rhs)const;

        bool operator>=(T* rhs)const;

        T* operator->()const
        {
            return reference;
        }


        /************************************************************************\
        Conversion: Bool Other Ptr<C>
        \*************************************************************************/

        //Logic Test
        operator bool()
        {
            return bool(reference);
        };

        //Convert Ptr<C> to Ptr<T>
        template<typename C>
        Ptr<T> Cast(Ptr<C> other);

        //Return reference.
        T* Obj();


    };
}
#endif