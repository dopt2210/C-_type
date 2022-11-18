#include<bits/stdc++.h>

using namespace std;

#ifndef __vector__cpp__
#define __vector__cpp__

template <class T>
class vector_reverse_iterator
{
    T *curr;
public:
    vector_reverse_iterator(T *c=0){curr=c;}
    vector_reverse_iterator<T> &operator=(vector_reverse_iterator<T> it){
        this->curr=it.curr;
        return *this;
    }
    vector_reverse_iterator<T> operator++(){
        curr--;
        return curr;
    }
    vector_reverse_iterator<T> operator++(int){
        vector_reverse_iterator<T> tmp=curr;
        curr--;
        return tmp;
    }
    T &operator*(){return *curr;}
    bool operator!=(vector_reverse_iterator<T> t){
        return curr!=t.curr;
    }
};

template<class T>
class Vector
{
private:
    int cap,num;
    T *buff;
public:
    Vector(){
        cap=num=0;
        buff=0;
    }
    Vector(int k,T x){
        cap=num=k;
        buff=new T[k];
        for(int i=0; i<k; i++)
            buff[i]=x;
    }
    ~Vector(){
        if(buff)
            delete[]buff;
    }
    int capacity(){return cap;}
    int size(){return num;}
    bool empty(){return num==0;}
    void pop_back(){if(num>0) num--;}
    void extend(int new_cap){
        if(new_cap<cap)
            return;
        cap=new_cap;
        T *temp=new T[cap];
        for(int i=0; i<num; i++)
            temp[i]=buff[i];
        if(buff)
            delete []buff;
        buff= temp;
    }
    T &back(){return buff[num-1];}
    void push_back(T x){
        if(num==cap)
            extend(cap*2+5);
        buff[num++]=x;
    }
    T &operator[](int k){return buff[k];}
    void insert(int k,T x){
        if(cap==num)
            extend(cap*2+5);
        for(int i=num-1; i>=k; i--)
            buff[i+1]=buff[i];
        buff[k]=x;
        num++;
    }
    Vector &operator=(Vector<T> V){
        this->num=V.num;
        this->cap=V.cap;
        if(cap)
        {
            this->buff=new T[cap];
            for(int i=0; i<num; i++)
                this->buff[i]=V.buff[i];
        }
        else
            this->buff=0;
        return *this;
    }
    typedef T *iterator;
    iterator begin(){return buff;}
    iterator end(){return buff+num;}
    typedef vector_reverse_iterator<T> reverse_iterator;
    reverse_iterator rbegin(){return reverse_iterator(buff+num-1);}
    reverse_iterator rend(){return reverse_iterator(buff-1);}
};
#endif
