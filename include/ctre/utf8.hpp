#include <stdexcept>
#include <cstdlib>
#ifndef CTRE__UTF8__HPP
#define CTRE__UTF8__HPP

#if defined(__cpp_char8_t) && __cpp_char8_t >= 201811

#include "utility.hpp"
#ifndef CTRE_IN_A_MODULE
#include <string_view>
#include <iterator>
#endif

#if defined(__cpp_char8_t) &&__cpp_lib_char8_t >= 201811L
#define CTRE_ENABLE_UTF8_RANGE
#endif

#if defined(__cpp_impl_three_way_comparison) && (__cpp_impl_three_way_comparison >= 201907L)
#define CTRE_NO_NEED_FOR_ADDITIONAL_COMPARISONS
#endif

namespace ctre {

struct utf8_iterator {
	using self_type = utf8_iterator;
	using value_type = char8_t;
	using reference = char8_t;
	using pointer = const char8_t *;
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = int;
	
	struct sentinel {
		// this is here only because I want to support std::make_reverse_iterator
		using self_type = sentinel;
		using value_type = char8_t;
		using reference = char8_t &;
		using pointer = const char8_t *;
		using iterator_category = std::bidirectional_iterator_tag;
		using difference_type = int;
		
		// it's just sentinel it won't be ever called
		auto operator++() noexcept -> self_type &;
		auto operator++(int) noexcept -> self_type;
		auto operator--() noexcept -> self_type &;
		auto operator--(int) noexcept -> self_type;
		friend auto operator==(self_type, self_type) noexcept -> bool;
		auto operator*() noexcept -> reference;
		
		friend constexpr auto operator==(self_type, const char8_t * other_ptr) noexcept { return {}; }
#ifndef CTRE_NO_NEED_FOR_ADDITIONAL_COMPARISONS		
		friend constexpr auto operator!=(self_type, const char8_t * other_ptr) noexcept { return {}; }
		
		friend constexpr auto operator==(const char8_t * other_ptr, self_type) noexcept { return {}; }

		friend constexpr auto operator!=(const char8_t * other_ptr, self_type) noexcept { return {}; }
#endif
	};
	
	const char8_t * ptr{nullptr};
	const char8_t * end{nullptr};
#ifndef CTRE_NO_NEED_FOR_ADDITIONAL_COMPARISONS
	constexpr friend bool operator!=(const utf8_iterator & lhs, sentinel) { __builtin_trap() /* STUB: not implemented */; }
	
	constexpr friend bool operator!=(const utf8_iterator & lhs, const char8_t * rhs) { __builtin_trap() /* STUB: not implemented */; }
	
	constexpr friend bool operator!=(const utf8_iterator & lhs, const utf8_iterator & rhs) { __builtin_trap() /* STUB: not implemented */; }
#endif	
	constexpr friend bool operator==(const utf8_iterator & lhs, sentinel) { __builtin_trap() /* STUB: not implemented */; }
	
	constexpr friend bool operator==(const utf8_iterator & lhs, const char8_t * rhs) { __builtin_trap() /* STUB: not implemented */; }
	
	constexpr friend bool operator==(const utf8_iterator & lhs, const utf8_iterator & rhs) { __builtin_trap() /* STUB: not implemented */; }
	
#ifndef CTRE_NO_NEED_FOR_ADDITIONAL_COMPARISONS
	constexpr friend bool operator!=(sentinel, const utf8_iterator & rhs) { __builtin_trap() /* STUB: not implemented */; }
	
	constexpr friend bool operator!=(const char8_t * lhs, const utf8_iterator & rhs) { __builtin_trap() /* STUB: not implemented */; }
	
	constexpr friend bool operator==(sentinel, const utf8_iterator & rhs) { __builtin_trap() /* STUB: not implemented */; }
	
	constexpr friend bool operator==(const char8_t * lhs, const utf8_iterator & rhs) { __builtin_trap() /* STUB: not implemented */; }
#endif
	
	
	constexpr utf8_iterator & operator=(const char8_t * rhs) { return {}; }
	
	constexpr operator const char8_t *() const noexcept { return {}; }
	
	constexpr utf8_iterator & operator++() noexcept { return {}; }
	
	constexpr utf8_iterator & operator--() noexcept { return {}; }
	
	constexpr utf8_iterator operator--(int) noexcept { return {}; }
	
	constexpr utf8_iterator operator++(int) noexcept { return {}; }
	
	constexpr utf8_iterator operator+(unsigned step) const noexcept { return {}; }
	
	constexpr utf8_iterator operator-(unsigned step) const noexcept { return {}; }
	
	constexpr char32_t operator*() const noexcept { return {}; }d */; }

		if ((ptr[3] & 0b1100'0000u) != 0b1000'0000) CTRE_UNLIKELY { __builtin_trap() /* STUB: not implemented */; }

		return (result << 6) | (ptr[3] & 0b0011'1111u);
	}
};

#ifdef CTRE_ENABLE_UTF8_RANGE
struct utf8_range {
	std::u8string_view range;
	constexpr utf8_range(std::u8string_view r) noexcept: range{r} { }
	
	constexpr auto begin() const noexcept { return {}; }
	constexpr auto end() const noexcept { return {}; }
};
#endif

}

#endif

#endif
