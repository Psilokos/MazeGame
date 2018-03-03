//
// GLFunction.hpp for MazeGame in /home/lecouv_v/MazeGame
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Fri Jan  6 20:41:12 2017 Victorien LE COUVIOUR--TUFFET
// Last update Fri Jan  6 23:22:11 2017 Victorien LE COUVIOUR--TUFFET
//

#pragma once

#include <exception>
#include <GL/glew.h>
#include <map>
#include <tuple>
#include <CompileTime.hpp>

template<typename> class _GLFunction;

template<typename Ret, typename... Args>
class	_GLFunction<Ret(*)(Args...)>
{
  typedef Ret(*GLfunc)(Args...);

public:
  _GLFunction(GLfunc f, Args... args) : _f(f), _args(args...) {}

  template<typename _Ret = Ret>
  _Ret	operator()(typename std::enable_if<!std::is_same<_Ret, void>::value>::type * = nullptr)	{ return _exec(ct::Indexer<sizeof...(Args)>()); }

  template<typename _Ret = Ret>
  _Ret	operator()(typename std::enable_if<std::is_same<_Ret, void>::value>::type * = nullptr)	{ _exec(ct::Indexer<sizeof...(Args)>()); }

private:
  GLfunc m_fct;
  std::tuple<Args...> m_args;

private:
  template<unsigned... idx, typename _Ret = Ret>
  _Ret
  _exec(ct::Index<idx...>&&, typename std::enable_if<!std::is_same<_Ret, void>::value>::type * = nullptr)
  {
    Ret			ret = m_fct(std::get<idx>(_args)...);
    GLenum const	err = glGetError();

    if (err)
      throw Error(err);
    return ret;
  }

  template<unsigned... idx, typename _Ret = Ret>
  _Ret
  _exec(ct::Index<idx...>&&, typename std::enable_if<std::is_same<_Ret, void>::value>::type * = nullptr)
  {
    GLenum	err;

    m_fct(std::get<idx>(_args)...);
    err = glGetError();
    if (err)
      throw Error(err);
  }
};

template<typename Ret, typename... Args>
std::map<GLenum, char const *> const	GLError::msgs =
  {
    { GL_NO_ERROR,			"No error has been recorded." },
    { GL_INVALID_ENUM,			"An unacceptable value is specified for an enumerated argument." },
    { GL_INVALID_VALUE,			"A numeric argument is out of range." },
    { GL_INVALID_OPERATION,		"The specified operation is not allowed in the current state." },
    { GL_INVALID_FRAMEBUFFER_OPERATION,	"The framebuffer object is not complete." },
    { GL_OUT_OF_MEMORY,			"There is not enough memory left to execute the command." },
    { GL_STACK_UNDERFLOW,		"An attempt has been made to perform an operation that would cause an internal stack to underflow." },
    { GL_STACK_OVERFLOW,		"An attempt has been made to perform an operation that would cause an internal stack to overflow." }
  };

template<typename Sig, bool = std::is_pointer<Sig>::value> class	GLFunction;

template<typename Sig>
class	GLFunction<Sig, false>
{
public:
  template<typename... Args>
  GLFunction(typename std::add_pointer<Sig>::type f, Args... args)
    : m_fct(_GLFunction<typename std::add_pointer<Sig>::type>(f, args...))
  {
  }

  template<typename _Sig = Sig>
  typename std::result_of<_GLFunction<typename std::add_pointer<_Sig>::type>(void *)>::type
  operator()(typename std::enable_if<!std::is_same<typename std::result_of<_GLFunction<typename std::add_pointer<_Sig>::type>(void *)>::type, void>::value>::type * = nullptr) { return _f(); }

  template<typename _Sig = Sig>
  typename std::result_of<_GLFunction<typename std::add_pointer<_Sig>::type>(void *)>::type
  operator()(typename std::enable_if<std::is_same<typename std::result_of<_GLFunction<typename std::add_pointer<_Sig>::type>(void *)>::type, void>::value>::type * = nullptr) { _f(); }

private:
  _GLFunction<typename std::add_pointer<Sig>::type>	_f;
};

template<typename FP>
class	GLFunction<FP, true>
{
public:
  template<typename... Args>
  GLFunction(FP f, Args... args)
    : m_fct(_GLFunction<FP>(f, args...))
  {
  }

  template<typename _FP = FP>
  typename std::result_of<_GLFunction<_FP>(void *)>::type
  operator()(typename std::enable_if<!std::is_same<typename std::result_of<_GLFunction<_FP>(void *)>::type, void>::value>::type * = nullptr)
  {
      return m_fct();
  }

  template<typename _FP = FP>
  typename std::result_of<_GLFunction<_FP>(void *)>::type
  operator()(typename std::enable_if<std::is_same<typename std::result_of<_GLFunction<_FP>(void *)>::type, void>::value>::type * = nullptr)
  {
      m_fct();
  }

private:
  _GLFunction<FP> m_fct;
};

class GLError : public std::exception
{
public:
  Error(GLenum err) noexcept : m_what(Error::msgs.at(err)) {}

  char const * what(void) const noexcept { return m_what; }

private:
  char const * const m_what;

public:
  static std::map<GLenum, char const *> const msgs;
};
