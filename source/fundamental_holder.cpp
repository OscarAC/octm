// <octm/holder.cpp>
// Copyright(c) 2015-present, Oscar A. Carrera.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
module;
#include <iostream>
#include <utility>

export module octm:fundamental_holder;

import :idioms;

/**
 * RAII for Fundamental Types
 * Enforces a single instance for a value of T to live
 * No copy is enforced
 * @tparam T type of value holded
 * @tparam Invalidator value to invalidate on release or acquisition of the fundamental value
 */
export template <fundamental Fundamental, Fundamental Invalidator>
class fundamental_holder
{    
public:
  using fundamental_t = Fundamental;
    
  fundamental_holder() : value(Invalidator) {}

  /**
   * Constructs an holder to acquire ownership of a value
   * @param value - T to acquire ownership of
   */
  explicit fundamental_holder(fundamental_t &other) noexcept
  {
    value = other;
    other = Invalidator;
  }
  
  fundamental_holder(fundamental_holder &) = delete;
  fundamental_holder &operator=(fundamental_holder &) = delete;
  fundamental_holder &operator=(fundamental_holder &) volatile = delete;

  fundamental_holder(fundamental_holder &&other) noexcept {
    std::swap(value, other.value);
    other.value = Invalidator;
  }

  fundamental_holder &operator=(fundamental_holder &&other) noexcept {
    std::swap(value, other.value);
    other.value = Invalidator;
    return *this;
  }
    
  constexpr const fundamental_t get() const noexcept { return value; }

  /**
   * Release ownership of descriptor
   * Invalidates internal descriptor
   * @return @prio_iodesc
   */
  constexpr fundamental_t release() noexcept {
    fundamental_t tmp = value;
    value = Invalidator;
    return tmp;
  }
  
  constexpr bool valid() const noexcept {
    return value != Invalidator;
  }
    
  ~fundamental_holder()
  {
    value = Invalidator;
  }

  
  std::ostream &operator<<(std::ostream &) noexcept;
  bool operator==(const fundamental_holder &) noexcept;    
  bool operator!=(const fundamental_holder &) noexcept;
  bool operator>(const fundamental_holder &) noexcept;
  bool operator>=(const fundamental_holder &) noexcept;
  bool operator<(const fundamental_holder &b) noexcept;
  bool operator<=(const fundamental_holder &) noexcept;

  /**
   * Unwanted operators
   */
  fundamental_holder &operator++() = delete;
  fundamental_holder operator++(int) = delete;
  fundamental_holder &operator+=(int) = delete;
  fundamental_holder &operator--() = delete;
  fundamental_holder operator--(int) = delete;
  fundamental_holder &operator-=(int) = delete;
  fundamental_holder &operator[](int) const = delete;

  private:
    fundamental_t value;
};

template <fundamental Fundamental, Fundamental Invalidator>
inline bool fundamental_holder<Fundamental, Invalidator>::operator==(const fundamental_holder<Fundamental, Invalidator> &b) noexcept {
    return get() == b.get();
}

template <fundamental Fundamental, Fundamental Invalidator>
inline bool fundamental_holder<Fundamental, Invalidator>::operator!=(const fundamental_holder<Fundamental, Invalidator> &b) noexcept {
    return get() != b.get();
}

template <fundamental Fundamental, Fundamental Invalidator>
inline bool fundamental_holder<Fundamental, Invalidator>::operator>(const fundamental_holder<Fundamental, Invalidator> &b) noexcept {
    return get() > b.get();
}

template <fundamental Fundamental, Fundamental Invalidator>
inline bool fundamental_holder<Fundamental, Invalidator>::operator>=(const fundamental_holder<Fundamental, Invalidator> &b) noexcept {
    return get() >= b.get();
}

template <fundamental Fundamental, Fundamental Invalidator>
inline bool fundamental_holder<Fundamental, Invalidator>::operator<(const fundamental_holder<Fundamental, Invalidator> &b) noexcept {
    return get() < b.get();
}

template <fundamental Fundamental, Fundamental Invalidator>
inline bool fundamental_holder<Fundamental, Invalidator>::operator<=(const fundamental_holder<Fundamental, Invalidator> &b) noexcept {
    return get() <= b.get();
}

template <fundamental Fundamental, Fundamental Invalidator>
inline std::ostream &operator<<(std::ostream &os, const fundamental_holder<Fundamental, Invalidator> &b) noexcept {
    os << b.get();
    return os;
}
