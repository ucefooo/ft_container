// #include "vector.hpp"
// #include "vector.hpp"
// #include <iostream>
#include <vector>
// class yes{
//     public:
//         int *t;
//     int c;
//     yes() { t = new int[5]; c = 5; }
//     yes(int cj) { t = new int[cj]; c = cj; }
//     yes(const yes& obj) {
//         this->c = obj.c;
//         this->t = new int[this->c];
//         std::copy(obj.t, obj.t + obj.c, this->t);
//     }
//     yes& operator=(const yes& obj) {
//         if (this != &obj) {
//             delete[] this->t;
//             this->c = obj.c;
//             this->t = new int[this->c];
//             std::copy(obj.t, obj.t + obj.c, this->t);
//         }
//         return (*this);
//     }
//     ~yes() {delete[] t;t=nullptr;}
// };
// std::ostream &operator<<(std::ostream &in,const yes &obj){in << obj.c;return(in);}
// void test1()
// {
//     ft::vector<yes> v(5,yes(2));
//     for (ft::vector<yes>::iterator it = v.begin(); it != v.end(); it++)
//         std::cout << it->c << " ";
//     std::cout << std::endl;

//     // v.push_back(7);
//     // for (ft::vector<yes>::iterator it = v.begin(); it != v.end(); it++)
//     //     std::cout << *it << " ";
//     // std::cout << std::endl;

//     // v.push_back(9);
//     // for (ft::vector<yes>::iterator it = v.begin(); it != v.end(); it++)
//     //     std::cout << *it << " ";
//     // std::cout << std::endl;

//     std::cout << "cap " << v.capacity() << " " <<v.size() <<std::endl;
//     v.resize(100);
//     for (ft::vector<yes>::iterator it = v.begin(); it != v.end(); it++)
//         std::cout << *it << " ";
//     std::cout << "cap " << v.capacity() << " " <<v.size() <<std::endl;
//     // std::cout << std::endl;

//     try {
//         v.at(12);
//     }
//     catch (std::out_of_range& e) {
//         std::cout << e.what() << std::endl;
//     }
// }

// void test2()
// {
//     ft::vector<std::string> v(2, "hello");
//     for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     v.push_back("world");
//     for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     v.push_back("foo");
//     for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     // std::cout<<v.capacity()<<" "<<v.size()<<std::endl;
//     v.resize(5);
//     // std::cout<<v.capacity()<<" "<<v.size()<<std::endl;
//     for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
//         std::cout << *it << " ";
//     std::cout << std::endl;
//     v.resize(2);
//     // std::cout<<v.capacity()<<" "<<v.size()<<std::endl;
//     for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     try {
//         v.at(10);
//     }
//     catch (std::out_of_range& e) {
//         std::cout << e.what() << std::endl;
//     }
// }

// int main()
// {
//     test1();
//     // test2();
//     return 0;
// }



// #include "vector.hpp"
// #include <iostream>
// #include <vector>


// int main()
// {
//     // Create a vector of integers
//     ft::vector<int> v;

//     // Add some elements to the vector
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(3);

//     // Print the size and capacity of the vector
//     std::cout << "Size: " << v.size() << "\n";
//     std::cout << "Capacity: " << v.capacity() << "\n";

//     // Print the elements of the vector using iterators
//     for (ft::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << "\n";

//     // Clear the vector
//     v.clear();

//     // Print the size and capacity of the vector
//     std::cout << "Size: " << v.size() << "\n";
//     std::cout << "Capacity: " << v.capacity() << "\n";

//     // Add some elements to the vector
//     v.push_back(4);
//     v.push_back(5);
//     v.push_back(6);

//     // Print the elements of the vector using range-based for loop
//     for (int x : v) {
//         std::cout << x << " ";
//     }
//     std::cout << "\n";

//     // Resize the vector
//     v.resize(2);

//     // Print the size and capacity of the vector
//     std::cout << "Size: " << v.size() << "\n";
//     std::cout << "Capacity: " << v.capacity() << "\n";

//     // Print the elements of the vector using range-based for loop
//     for (int x : v) {
//         std::cout << x << " ";
//     }
//     std::cout << "\n";

//     return 0;
// }

#include <iostream>
#include "vector.hpp"
#include <iostream>
#include <list>

// int main()
// {
//     try{
//     int myints[] = { 1,2,3,4,5};
//     int myints2[] = { 6,7,8,9,10};
//   ft::vector<int> v(1);
//   ft::vector<int> c(5,100);
//   v.swap(c);
//   ft::vector<int> k(c);
//   std::cout <<v.capacity()<<" "<<v.size()<<std::endl;
//   std::cout <<c.capacity()<<" "<<c.size()<<std::endl;
//   std::cout <<k.capacity()<<" "<<k.size()<<std::endl;

//   // v.push_back(23);
//   v.assign(myints,myints+5);
//   // it--;
//   // std::cout << *it <<std::endl;

//   for(int i=0;i<v.size();i++)
//     std::cout << v[i] << " ";
//   std::cout << std::endl;
// std::cout<<"here\n";
//   std::cout <<v.capacity()<<" "<<v.size()<<std::endl;
// std::cout<<"here\n";
//   ft::vector<int>::iterator it=v.end();
//   v.insert(it,myints2,myints2+5);
//   it=v.begin();
//   // it++;
// std::cout << *(v.erase(it,it+5)) <<  " =erase\n";
// std::cout<<"here\n";
//   std::cout <<v.capacity()<<" "<<v.size()<<std::endl;
// std::cout<<"here\n";

//   for(int i=0;i<v.size();i++)
//     std::cout << v[i] << " ";
//   std::cout << std::endl;

//   return 0;
// }

//     catch(std::exception &e)
//     {
//         std::cout << e.what() <<std::endl;
//     }
//     return 0;
// }

template <typename T>
void	printSize(ft::vector<T> const &vct, bool print_content = true)
{
	size_t size = vct.size();
	size_t capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename ft::vector<T>::const_iterator it = vct.begin();
		typename ft::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}
#define TESTED_TYPE int

int		main(void)
{
	ft::vector<TESTED_TYPE> vct(10);
	ft::vector<TESTED_TYPE> vct2;
	ft::vector<TESTED_TYPE> vct3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	printSize(vct);

	vct2.insert(vct2.end(), 42);
	vct2.insert(vct2.begin(), 2, 21);
	printSize(vct2);

	vct2.insert(vct2.end() - 2, 42);
	printSize(vct2);

	vct2.insert(vct2.end(), 2, 84);
	printSize(vct2);

	vct2.resize(4);
	printSize(vct2);

	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	vct.clear();
	printSize(vct2);

	printSize(vct);

	for (int i = 0; i < 5; ++i)
		vct3.insert(vct3.end(), i);
	vct3.insert(vct3.begin() + 1, 2, 111);
	printSize(vct3);

	return (0);
}
