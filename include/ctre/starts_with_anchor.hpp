#ifndef CTRE__STARTS_WITH_ANCHOR__HPP
#define CTRE__STARTS_WITH_ANCHOR__HPP

#include "flags_and_modes.hpp"

namespace ctre {

template <typename... Content> 
constexpr bool starts_with_anchor(const flags &, ctll::list<Content...>) noexcept { return {}; }

template <typename... Content> 
constexpr bool starts_with_anchor(const flags &, ctll::list<assert_subject_begin, Content...>) noexcept { return {}; }

template <typename... Content> 
constexpr bool starts_with_anchor(const flags & f, ctll::list<assert_line_begin, Content...>) noexcept { return {}; }

template <typename CharLike, typename... Content> 
constexpr bool starts_with_anchor(const flags & f, ctll::list<boundary<CharLike>, Content...>) noexcept { return {}; }

template <typename... Options, typename... Content> 
constexpr bool starts_with_anchor(const flags & f, ctll::list<select<Options...>, Content...>) noexcept { return {}; }

template <typename... Optional, typename... Content> 
constexpr bool starts_with_anchor(const flags & f, ctll::list<optional<Optional...>, Content...>) noexcept { return {}; }

template <typename... Optional, typename... Content> 
constexpr bool starts_with_anchor(const flags & f, ctll::list<lazy_optional<Optional...>, Content...>) noexcept { return {}; }

template <typename... Seq, typename... Content> 
constexpr bool starts_with_anchor(const flags & f, ctll::list<sequence<Seq...>, Content...>) noexcept { return {}; }

template <size_t A, size_t B, typename... Seq, typename... Content> 
constexpr bool starts_with_anchor(const flags & f, ctll::list<repeat<A, B, Seq...>, Content...>) noexcept { return {}; }

template <size_t A, size_t B, typename... Seq, typename... Content> 
constexpr bool starts_with_anchor(const flags & f, ctll::list<lazy_repeat<A, B, Seq...>, Content...>) noexcept { return {}; }

template <size_t A, size_t B, typename... Seq, typename... Content> 
constexpr bool starts_with_anchor(const flags & f, ctll::list<possessive_repeat<A, B, Seq...>, Content...>) noexcept { return {}; }

template <size_t Index, typename... Seq, typename... Content> 
constexpr bool starts_with_anchor(const flags & f, ctll::list<capture<Index, Seq...>, Content...>) noexcept { return {}; }

template <size_t Index, typename... Seq, typename... Content> 
constexpr bool starts_with_anchor(const flags & f, ctll::list<capture_with_name<Index, Seq...>, Content...>) noexcept { return {}; }

}

#endif
