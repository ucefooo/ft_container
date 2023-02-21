#include <cstddef>  // for size_t
#include <algorithm>  // for std::copy, std::move
#include <memory>  // for std::unique_ptr

template<typename T>
class Vector {
 public:
  // Constructors
  Vector() = default;
  explicit Vector(size_t size);
  Vector(size_t size, const T& value);
  Vector(const Vector& other);
  Vector(Vector&& other);
  Vector& operator=(const Vector& other);
  Vector& operator=(Vector&& other);
  ~Vector();

  // Element access
  T& operator[](size_t index);
  const T& operator[](size_t index) const;
  T& at(size_t index);
  const T& at(size_t index) const;
  T* data();
  const T* data() const;
  T& front();
  const T& front() const;
  T& back();
  const T& back() const;

  // Iterators
  using iterator = T*;
  using const_iterator = const T*;
  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;

  // Capacity
  bool empty() const;
  size_t size() const;
  size_t capacity() const;
  void reserve(size_t newCapacity);
  void shrink_to_fit();

  // Modifiers
  void clear();
  iterator insert(const_iterator pos, const T& value);
  iterator insert(const_iterator pos, T&& value);
  iterator erase(const_iterator pos);
  iterator erase(const_iterator first, const_iterator last);
  void push_back(const T& value);
  void push_back(T&& value);
  void pop_back();
  void resize(size_t newSize);
  void resize(size_t newSize, const T& value);

 private:
  std::unique_ptr<T[]> data_;
  size_t size_ = 0;
  size_t capacity_ = 0;
};

// Implementations of the member functions go here