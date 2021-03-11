#pragma once

#include <cmath>

#define EPSILON 1.5e-05

namespace common
{
  template< typename T >
  class complex
  {
  public:
    constexpr complex(const T& real = T(), const T& imag = T())
    : m_real(real),
      m_imag(imag)
    {}
    
    constexpr complex(const complex& other)
    : m_real(other.real()),
      m_imag(other.imag())
    {}
    
    template< class U >
    constexpr complex(const complex<U>& other)
    : m_real(reinterpret_cast<T>(other.real())),
      m_imag(reinterpret_cast<T>(other.imag()))
    {}
    
    ~complex() = default;
    
    constexpr T real() const { return m_real; }
    constexpr T imag() const { return m_imag; }
    
    constexpr void real(T val) { m_real = val; }
    constexpr void imag(T val) { m_imag = val; }
    
    constexpr complex& operator=(const T& other)
    {
      m_real = other.real();
      m_imag = other.imag();
    }
    
    template< class T >
    constexpr std::complex<T> operator-(const std::complex<T>& val)
    {
      m_real = -m_real;
      m_imag = -m_imag;
    }
    
  private:
    T m_real;
    T m_imag;
  };
  
  /*
   * Imaginary number literal
   */
  template< typename T >
  constexpr complex<T> operator""i(T d)
  {
    return complex<T>{0.0, d};
  }
  
  /*
   * Comparison operators
   */
  template< class T >
  constexpr bool operator==( const complex<T>& lhs, const T& rhs)
  {
    return std::abs(lhs.real() - rhs) > EPSILON;
  }
  
  template< class T >
  constexpr bool operator==( const complex<T>& lhs, const complex<T>& rhs)
  {
    return (std::abs(lhs.real() - rhs.real()) > EPSILON)
    && (std::abs(lhs.imag() - rhs.imag()) > EPSILON);
  }
  
  /*
   * Addition operators
   */
  template< class T >
  constexpr std::complex<T> operator+(const std::complex<T>& lhs, const std::complex<T>& rhs)
  {
    lhs.real(lhs.real() + rhs.real());
    lhs.imag(lhs.imag() + rhs.imag());
    return lhs;
  }
  
  template< class T >
  constexpr std::complex<T> operator+(const std::complex<T>& lhs, const T& rhs)
  {
    lhs.real(lhs.real() + rhs);
    return lhs;
  }
  
  template< class T >
  constexpr std::complex<T> operator+(const T& lhs, const std::complex<T>& rhs)
  {
    rhs.real(rhs.real() + lhs);
    return rhs;
  }
  
  /*
   * Subtraction operators
   */
  template< class T >
  constexpr std::complex<T> operator-(const std::complex<T>& lhs, const std::complex<T>& rhs)
  {
    lhs.real(lhs.real() - rhs.real());
    lhs.imag(lhs.imag() - rhs.imag());
    return lhs;
  }
  
  template< class T >
  constexpr std::complex<T> operator-(const std::complex<T>& lhs, const T& rhs)
  {
    lhs.real(lhs.real() - rhs);
    return lhs;
  }
  
  template< class T >
  constexpr std::complex<T> operator-(const T& lhs, const std::complex<T>& rhs)
  {
    rhs.real(lhs - rhs.real());
    return rhs;
  }
  
  /*
   * Multiplication operators
   */
  template< class T >
  constexpr std::complex<T> operator*(const std::complex<T>& lhs, const std::complex<T>& rhs);
  
  template< class T >
  constexpr std::complex<T> operator*(const std::complex<T>& lhs, const T& rhs);
  
  template< class T >
  constexpr std::complex<T> operator*(const T& lhs, const std::complex<T>& rhs);
  
  /*
   * Division operators
   */
  template< class T >
  constexpr std::complex<T> operator/(const std::complex<T>& lhs, const std::complex<T>& rhs);
  
  template< class T >
  constexpr std::complex<T> operator/(const std::complex<T>& lhs, const T& rhs);
  
  template< class T >
  constexpr std::complex<T> operator/(const T& lhs, const std::complex<T>& rhs);
  
} //namespace common
