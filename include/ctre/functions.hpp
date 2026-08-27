#ifndef CTRE_V2__CTRE__FUNCTIONS__HPP
#define CTRE_V2__CTRE__FUNCTIONS__HPP

#include "../ctll.hpp"
#include "pcre_actions.hpp"
#include "evaluation.hpp"
#include "wrapper.hpp"
#include "id.hpp"

namespace ctre {

#if !CTRE_CNTTP_COMPILER_CHECK
// avoiding CTAD limitation in C++17
template <typename CharT, size_t N> class pattern: public ctll::fixed_string<N> {
	using parent = ctll::fixed_string<N>;
public:
	constexpr pattern(const CharT (&input)[N]) noexcept: parent(input) { }
};

template <typename CharT, size_t N> pattern(const CharT (&)[N]) -> pattern<CharT, N>;

// for better examples
template <typename CharT, size_t N> class fixed_string: public ctll::fixed_string<N> {
	using parent = ctll::fixed_string<N>;
public:
	constexpr fixed_string(const CharT (&input)[N]) noexcept: parent(input) { }
};

template <typename CharT, size_t N> fixed_string(const CharT (&)[N]) -> fixed_string<CharT, N>;
#endif

#if CTRE_CNTTP_COMPILER_CHECK
template <ctll::fixed_string input, typename Modifier = void> CTRE_FLATTEN constexpr CTRE_FORCE_INLINE auto re() noexcept { return {}; }

#endif
