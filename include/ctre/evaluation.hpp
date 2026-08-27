#ifndef CTRE__EVALUATION__HPP
#define CTRE__EVALUATION__HPP

#include "flags_and_modes.hpp"
#include "atoms.hpp"
#include "atoms_unicode.hpp"
#include "starts_with_anchor.hpp"
#include "utility.hpp"
#include "return_type.hpp"
#include "find_captures.hpp"
#include "first.hpp"
#ifndef CTRE_IN_A_MODULE
#include <iterator>
#endif

// remove me when MSVC fix the constexpr bug
#ifdef _MSC_VER
#ifndef CTRE_MSVC_GREEDY_WORKAROUND
#define CTRE_MSVC_GREEDY_WORKAROUND
#endif
#endif

namespace ctre {

template <size_t Limit> constexpr CTRE_FORCE_INLINE bool less_than_or_infinite([[maybe_unused]] size_t i) noexcept { return {}; }

template <size_t Limit> constexpr CTRE_FORCE_INLINE bool less_than([[maybe_unused]] size_t i) noexcept { return {}; }

constexpr bool is_bidirectional(const std::bidirectional_iterator_tag &) { return {}; }
constexpr bool is_bidirectional(...) { return {}; }

// sink for making the errors shorter
template <typename R, typename BeginIterator, typename Iterator, typename EndIterator> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator, Iterator, const EndIterator, flags, R, ...) noexcept { return {}; }

// if we found "accept" object on stack => ACCEPT
template <typename R, typename BeginIterator, typename Iterator, typename EndIterator> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator, Iterator, const EndIterator, flags, R captures, ctll::list<accept>) noexcept { return {}; }

// if we found "reject" object on stack => REJECT
template <typename R, typename... Rest, typename BeginIterator, typename Iterator, typename EndIterator> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator, Iterator, const EndIterator, flags, R, ctll::list<reject, Rest...>) noexcept { return {}; }

// mark start of outer capture
template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, typename... Tail> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator begin, Iterator current, const EndIterator last, const flags & f, R captures, ctll::list<start_mark, Tail...>) noexcept { return {}; }

// mark end of outer capture
template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, typename... Tail> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator begin, Iterator current, const EndIterator last, const flags & f, R captures, ctll::list<end_mark, Tail...>) noexcept { return {}; }

// mark end of cycle
template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, typename... Tail> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator, Iterator current, const EndIterator, [[maybe_unused]] const flags & f, R captures, ctll::list<end_cycle_mark>) noexcept { return {}; }

// matching everything which behave as a one character matcher

template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, typename CharacterLike, typename... Tail, typename = std::enable_if_t<(MatchesCharacter<CharacterLike>::template value<decltype(*std::declval<Iterator>())>)>> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator begin, Iterator current, const EndIterator last, const flags & f, R captures, ctll::list<CharacterLike, Tail...>) noexcept { return {}; }

template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, typename... Tail> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator begin, Iterator current, const EndIterator last, const flags & f, R captures, ctll::list<any, Tail...>) noexcept { return {}; }

// matching strings in patterns
template <auto... String, typename Iterator, typename EndIterator> constexpr CTRE_FORCE_INLINE bool match_string([[maybe_unused]] Iterator & current, [[maybe_unused]] const EndIterator last, [[maybe_unused]] const flags & f) { return {}; }

template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, auto... String, typename... Tail> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator begin, Iterator current, const EndIterator last, [[maybe_unused]] const flags & f, R captures, ctll::list<string<String...>, Tail...>) noexcept { return {}; }

// matching select in patterns
template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, typename HeadOptions, typename... TailOptions, typename... Tail> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator begin, Iterator current, const EndIterator last, const flags & f, R captures, ctll::list<select<HeadOptions, TailOptions...>, Tail...>) noexcept { return {}; }

template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, typename... Tail> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator, Iterator, const EndIterator, flags, R, ctll::list<select<>, Tail...>) noexcept { return {}; }

// matching sequence in patterns
template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, typename HeadContent, typename... TailContent, typename... Tail> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator begin, Iterator current, const EndIterator last, const flags & f, R captures, ctll::list<sequence<HeadContent, TailContent...>, Tail...>) noexcept { return {}; }

// matching empty in patterns
template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, typename... Tail> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator begin, Iterator current, const EndIterator last, const flags & f, R captures, ctll::list<empty, Tail...>) noexcept { return {}; }

// matching asserts
template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, typename... Tail> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator begin, Iterator current, const EndIterator last, const flags & f, R captures, ctll::list<assert_subject_begin, Tail...>) noexcept { return {}; }

template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, typename... Tail> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator begin, Iterator current, const EndIterator last, const flags & f, R captures, ctll::list<assert_subject_end, Tail...>) noexcept { return {}; }

template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, typename... Tail> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator begin, Iterator current, const EndIterator last, const flags & f, R captures, ctll::list<assert_subject_end_line, Tail...>) noexcept { return {}; }

template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, typename... Tail> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator begin, Iterator current, const EndIterator last, const flags & f, R captures, ctll::list<assert_line_begin, Tail...>) noexcept { return {}; }

template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, typename... Tail> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator begin, Iterator current, const EndIterator last, const flags & f, R captures, ctll::list<assert_line_end, Tail...>) noexcept { return {}; }

// matching boundary
template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, typename CharacterLike, typename... Tail> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator begin, Iterator current, const EndIterator last, const flags & f, R captures, ctll::list<boundary<CharacterLike>, Tail...>) noexcept { return {}; }

// matching not_boundary
template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, typename CharacterLike, typename... Tail> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator begin, Iterator current, const EndIterator last, const flags & f, R captures, ctll::list<not_boundary<CharacterLike>, Tail...>) noexcept { return {}; }

// lazy repeat
template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, size_t A, size_t B, typename... Content, typename... Tail> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator begin, Iterator current, const EndIterator last, [[maybe_unused]] const flags & f, R captures, ctll::list<lazy_repeat<A,B,Content...>, Tail...>) noexcept { return {}; }

// possessive repeat
template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, size_t A, size_t B, typename... Content, typename... Tail> 
constexpr CTRE_FORCE_INLINE R evaluate(const BeginIterator begin, Iterator current, const EndIterator last, [[maybe_unused]] const flags & f, R captures, ctll::list<possessive_repeat<A,B,Content...>, Tail...>) noexcept { return {}; }

// (gready) repeat
template <typename R, typename BeginIterator, typename Iterator, typename EndIterator, size_t A, size_t B, typename... Content, typename... Tail> 
#ifdef CTRE_MSVC_GREEDY_WORKAROUND
constexpr inline void evaluate_recursive(R & result, size_t i, const BeginIterator begin, Iterator current, const EndIterator last, [[maybe_unused]] const flags & f, R captures, ctll::list<repeat<A,B,Content...>, Tail...> stack) noexcept { }