#ifndef CTRE_V2__CTRE__LITERALS__HPP
#define CTRE_V2__CTRE__LITERALS__HPP

#include "../ctll.hpp"
#include "pcre_actions.hpp"
#include "evaluation.hpp"
#include "wrapper.hpp"
#include "id.hpp"

#ifndef __EDG__

namespace ctre {

// in C++17 (clang & gcc with gnu extension) we need translate character pack into ctll::fixed_string
// in C++20 we have `class nontype template parameters`

#if !CTRE_CNTTP_COMPILER_CHECK
template <typename CharT, CharT... input> static inline constexpr auto _fixed_string_reference = ctll::fixed_string< sizeof...(input)>({input...});
#endif	

namespace literals {
	
// clang and GCC <9 supports LITERALS with packs

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgnu-string-literal-operator-template"
#define CTRE_ENABLE_LITERALS
#endif
  
#ifdef _MSC_VER
#ifdef _MSVC_LANG
#if _MSVC_LANG >= 202002L
#define CTRE_ENABLE_LITERALS
#endif
#else
#define CTRE_ENABLE_LITERALS
#endif
#endif

#ifdef __INTEL_COMPILER
// not enable literals
#elif defined __GNUC__
#if __GNUC__ < 9
#define CTRE_ENABLE_LITERALS
#elif __GNUC__ >= 10
#if !CTRE_CNTTP_COMPILER_CHECK 
// newer versions of GCC will give error when trying to use GNU extension
#else
#define CTRE_ENABLE_LITERALS
#endif	
#endif
#endif

#ifdef CTRE_ENABLE_LITERALS
	
// add this when we will have concepts
// requires ctll::parser<ctre::pcre, _fixed_string_reference<CharT, charpack...>, ctre::pcre_actions>::template correct_with<pcre_context<>>

#if !CTRE_CNTTP_COMPILER_CHECK
template <typename CharT, CharT... charpack> CTRE_FLATTEN constexpr CTRE_FORCE_INLINE auto operator""_ctre() noexcept { return {}; }

namespace test_literals {
	
#ifdef CTRE_ENABLE_LITERALS

#if !CTRE_CNTTP_COMPILER_CHECK
template <typename CharT, CharT... charpack> CTRE_FLATTEN constexpr inline auto operator""_ctre_test() noexcept {
	constexpr auto & _input = _fixed_string_reference<CharT, charpack...>;
#else
template <ctll::fixed_string input> CTRE_FLATTEN constexpr inline auto operator""_ctre_test() noexcept { return {}; }

#if !CTRE_CNTTP_COMPILER_CHECK
template <typename CharT, CharT... charpack> CTRE_FLATTEN constexpr inline auto operator""_ctre_gen() noexcept { return {}; } // ctre

#endif

#endif
