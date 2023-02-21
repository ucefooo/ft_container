#pragma once

#include <iostream>
#include <vector>
#include <iterator>

namespace ft
{
    template <bool B, class T = void>
        struct enable_if {};

    template <class T>
        struct enable_if<true, T> { typedef T type; };

    template<class T>struct is_integral {static const bool value = false;};

    template<>struct is_integral<int> {static const bool value = true;};

    template<>struct is_integral<unsigned int> {static const bool value = true;};
    
    template<>struct is_integral<size_t> {static const bool value = true;};
    
    template<>struct is_integral<bool> {static const bool value = true;};

    template<>struct is_integral<char> {static const bool value = true;};
    template<>struct is_integral<signed char> {static const bool value = true;};
    template<>struct is_integral<unsigned char> {static const bool value = true;};
    template<>struct is_integral<short> {static const bool value = true;};
    template<>struct is_integral<unsigned short> {static const bool value = true;};
    template<>struct is_integral<long> {static const bool value = true;};
    template<>struct is_integral<long long> {static const bool value = true;};
    
    template<class T, class Allocator = std::allocator<T> >
    class vector
    {
        private:
            T *myArr;
            size_t mySize;
            size_t myCap;
            Allocator allocator;
        public:
            typedef Allocator										allocator_type;
            typedef T												value_type;

            typedef typename allocator_type::pointer           		pointer;
            typedef typename allocator_type::const_pointer     		const_pointer;

			typedef pointer											iterator;
			typedef const_pointer									const_iterator;

            typedef typename allocator_type::reference         		reference;
            typedef typename allocator_type::const_reference   		const_reference;

            typedef typename allocator_type::size_type         		size_type;

			typedef std::reverse_iterator<iterator>					reverse_iterator;
			typedef std::reverse_iterator<const_iterator>			const_reverse_iterator;

            // typedef typename allocator_type::difference_type		difference_type;
            typedef ptrdiff_t difference_type; 
            // typedef typename std::iterator_traits<T*>::difference_type difference_type;

			
            




            void clear(){for(size_t i=0;i<myCap;i++)allocator.destroy(&myArr[i]);mySize=0;}
// cons fucntions *******************************************************************

            vector(const allocator_type& alloc = allocator_type()){mySize=0;myCap=0;myArr=nullptr;allocator=alloc;};
            vector(size_t sz,const value_type &val = value_type(), const allocator_type& alloc = allocator_type()){myArr = allocator.allocate(sz);mySize=sz;myCap=sz;allocator=alloc;for(size_t i=0;i<mySize;i++)allocator.construct(&myArr[i],val);}
            vector(const vector& obj){mySize=obj.size();myCap=obj.capacity();myArr = allocator.allocate(myCap);for(size_t i=0;i < mySize;i++)allocator.construct(&myArr[i],obj[i]);}
			template <class InputIterator>
        	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),typename ft::enable_if<!std::is_integral<InputIterator>::value>::type* = 0){allocator=alloc;size_t sz=std::distance(first,last);mySize=sz;myCap=sz;myArr=allocator.allocate(sz);
			size_t i=0;for(InputIterator it = first;it!=last;it++)allocator.construct(&myArr[i++],*it);
			};

            ~vector(){for(size_t i=0;i<myCap;i++)allocator.destroy(&myArr[i]);allocator.deallocate(myArr,myCap);}

            vector &operator=(const vector& obj){if (this==&obj)return (*this);if (myCap < obj.size()){this->resize(obj.size());this->clear();mySize=obj.size();myCap=obj.size();
            for(size_t i=0;i<myCap;i++)allocator.construct(&myArr[i],obj[i]);return (*this);}this->clear();mySize=obj.size();
            for(size_t i=0;i<mySize;i++)allocator.construct(&myArr[i],obj[i]);return (*this);
			}

// Iterators fucntions *******************************************************************

            iterator begin(){return &myArr[0];}
            const_iterator begin()const{return &myArr[0];}
			const_iterator cbegin() const{return &myArr[0];};

            iterator end(){return &myArr[mySize];}
            const_iterator end()const{return &myArr[mySize];}
            const_iterator cend()const{return &myArr[mySize];}

			reverse_iterator rbegin(){return reverse_iterator(end());};
			const_reverse_iterator rbegin() const{return const_reverse_iterator(end());};
			const_reverse_iterator crbegin() const{return const_reverse_iterator(end());};
			
			reverse_iterator rend(){return reverse_iterator(begin());};
			const_reverse_iterator rend() const{return const_reverse_iterator(begin());};
			const_reverse_iterator crend() const{return const_reverse_iterator(begin());};;

// size fucntions *******************************************************************

            size_t size() const{return mySize;}
			size_t max_size()const{return allocator.max_size();} 
			void resize(size_t newSize, value_type val = value_type()){if(newSize<0)throw std::out_of_range("ft::vector");if(newSize<=mySize){for(size_t i=newSize;i<mySize;i++)allocator.destroy(&myArr[i]);mySize=newSize;return;}
				T* tmp=allocator.allocate(newSize);for(size_t i=0;i<mySize&&i<newSize;i++)allocator.construct(&tmp[i], myArr[i]);for (size_t i = 0; i < myCap; i++)allocator.destroy(&myArr[i]);
                allocator.deallocate(myArr,myCap);myArr=tmp;for(size_t i=mySize;i<newSize;i++)allocator.construct(&tmp[i],val);mySize=newSize;myCap=newSize;
            }
            size_t capacity() const{return myCap;}
            bool empty() const{if(mySize == 0)return true;return false;}
            void reserve(size_t newCap) {if (newCap > myCap) {T* newArr = allocator.allocate(newCap);for (size_t i = 0; i < mySize; ++i)allocator.construct(&newArr[i],myArr[i]);
                    for(size_t i=0;i<myCap;i++)allocator.destroy(&myArr[i]);allocator.deallocate(myArr, myCap);myArr = newArr;myCap = newCap;}
            }
			void shrink_to_fit(){if (mySize==myCap)return;T* tmp=allocator.allocate(mySize);for(size_t i=0;i<mySize;i++)allocator.construct(&tmp[i],myArr[i]);
			for(size_t i=0;i<myCap;i++)allocator.destroy(&myArr[i]);allocator.deallocate(myArr,myCap);myCap=mySize;myArr=tmp;
			}

// element acces funtions *******************************************************************

			reference operator[](size_t i){return myArr[i];}
			const_reference operator[](size_t i) const{return myArr[i];}
			reference at(size_t index){if (index < 0 || index >= mySize)throw std::out_of_range("ft::vector out of range");return myArr[index];}
			const_reference at(size_t index) const{if (index < 0 || index >= mySize)throw std::out_of_range("ft::vector out of range");return myArr[index];}
			reference front(){return myArr[0];}
			const_reference front() const{return myArr[0];}
			reference back(){return myArr[mySize-1];}
			const_reference back() const{return myArr[mySize-1];}
			pointer data(){return myArr;}
            const_pointer data()const{return myArr;}

// modifiers funtions *******************************************************************

            void assign (size_type n, const value_type& val){if(n<=myCap){this->clear();for(size_t i=0;i<n;i++)allocator.construct(&myArr[i],val);mySize=n;return;}
            if(n>myCap){this->clear();this->resize(n);for(size_t i=0;i<myCap;i++)allocator.construct(&myArr[i],val);return;}
            }
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,typename ft::enable_if<!std::is_integral<InputIterator>::value>::type* = 0){size_t sz=std::distance(first,last);if(sz<=myCap){this->clear();size_t i=0;for(InputIterator it=first;it!=last&&i<sz;it++)allocator.construct(&myArr[i++],*it);
			mySize=sz;return;}
			this->resize(sz);this->clear();size_t i=0;for(InputIterator it=first;it!=last&&i<sz;it++)allocator.construct(&myArr[i++],*it);mySize=sz;myCap=sz;
			}

	        void push_back(const T &toAdd){if (myCap==0){myCap++;mySize++;myArr=allocator.allocate(1);allocator.construct(&myArr[0],toAdd);return;}
		        if (myCap==mySize){T *tmp = allocator.allocate(myCap*2);for(size_t i=0;i < mySize;i++)allocator.construct(&tmp[i],myArr[i]);for(size_t i=0;i < myCap;i++)allocator.destroy(&myArr[i]);allocator.deallocate(myArr,myCap);myCap*=2;myArr=tmp;}
		        allocator.construct(&myArr[mySize],toAdd);mySize++;
            }
            void pop_back(){if (mySize > 0)--mySize;allocator.destroy(myArr + mySize);}// look out for return value
            iterator insert (iterator position, const value_type& val){difference_type tm=position-&(*myArr);if (mySize<myCap){;value_type tmp=val;for(iterator it=position;it!=end();it++){value_type tmp1=*it;allocator.destroy(it);allocator.construct(it,tmp);tmp=tmp1;}
            allocator.destroy(&myArr[mySize]);allocator.construct(&myArr[mySize],tmp);mySize++;return myArr+tm;}
            else
                this->reserve(myCap+1);return insert(myArr+tm,val);
            }
            void insert (iterator position, size_type n, const value_type& val){for(difference_type i=0;i<(difference_type)n;i++){position=insert(position,val);}}
            
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last,typename ft::enable_if<!std::is_integral<InputIterator>::value>::type* = 0){
                for (; first != last; ++first)
                {
                    position = insert(position, *first);
                    position++;
                }
            }

            iterator erase (iterator position){mySize--;for(size_t i=position-&(*myArr);i<mySize;i++){allocator.destroy(&myArr[i]);allocator.construct(&myArr[i],myArr[i+1]);}allocator.destroy(&myArr[mySize]);return (position);}
            iterator erase (iterator first, iterator last){size_t dis=std::distance(first,last);mySize-=dis;size_t i=first-&(*myArr);for(size_t i=first-&(*myArr);i<=dis;i++){allocator.destroy(&myArr[i]);allocator.construct(&myArr[i],myArr[i+dis]);first++;}allocator.destroy(&myArr[mySize]);return (&myArr[i]);}

            void swap (vector& x){std::swap(myArr,x.myArr);std::swap(mySize,x.mySize);std::swap(myCap,x.myCap);std::swap(allocator,x.allocator);}

// alloca getter *******************************************************************

            allocator_type get_allocator() const{return allocator_type();}

    };
    template< class T, class Alloc >
        bool operator==( const ft::vector<T, Alloc>& first,const ft::vector<T, Alloc>& second){if (first.size() != second.size())return false;
        for(size_t i=0;i<first.size();i++)
            if(first[i]!=second[i])
                return false;
        return true;
        }
    
    template< class T, class Alloc >
        bool operator!=( const ft::vector<T, Alloc>& first, const ft::vector<T, Alloc>& second){return !(first==second);}
    
    template< class T, class Alloc >
        bool operator<( const ft::vector<T, Alloc>& first,const ft::vector<T, Alloc>& second)
        {
            for(size_t i=0;i<first.size()&&i<second.size();i++){if(first[i]>second[i])return false;if (first[i]<second[i])return true;}
            if (first.size() < second.size())return true;return false;
        }

    template< class T, class Alloc >
        bool operator>( const ft::vector<T, Alloc>& first,const ft::vector<T, Alloc>& second)
        {
            for(size_t i=0;i<first.size()&&i<second.size();i++){if(first[i]<second[i])return false;if (first[i]>second[i])return true;}
            if (first.size() > second.size())return true;return false;
        }
    
    template< class T, class Alloc >
        bool operator<=( const ft::vector<T, Alloc>& first,const ft::vector<T, Alloc>& second){return !(first>second);}

    template< class T, class Alloc >
        bool operator>=( const ft::vector<T, Alloc>& first,const ft::vector<T, Alloc>& second){return !(first<second);}
}
