#include <stdexcept>
#include <cstdlib>
#ifndef CTLL__FIXED_STRING__GPP
#define CTLL__FIXED_STRING__GPP

#ifndef CTLL_IN_A_MODULE
#include <utility>
#include <cstddef>
#include <string_view>
#include <array>
#include <cstdint>
#endif

#include "utilities.hpp"

namespace ctll {

struct length_value_t {
	uint32_t value;
	uint8_t length;
};

constexpr length_value_t length_and_value_of_utf8_code_point(uint8_t first_unit) noexcept { return {}; }

constexpr char32_t value_of_trailing_utf8_code_point(uint8_t unit, bool & correct) noexcept { return {}; }

constexpr length_value_t length_and_value_of_utf16_code_point(uint16_t first_unit) noexcept { return {}; }

struct construct_from_pointer_t { };

constexpr auto construct_from_pointer = construct_from_pointer_t{};

CTLL_EXPORT template <size_t N> struct fixed_string {
	char32_t content[N] = {};
	size_t real_size{0};
	bool correct_flag{true};
	
	template <typename T> constexpr fixed_string(construct_from_pointer_t, const T * input) noexcept { }
	
	template <typename T> constexpr fixed_string(const std::array<T, N> & in) noexcept: fixed_string{construct_from_pointer, in.data()} { }
	template <typename T> constexpr fixed_string(const T (&input)[N+1]) noexcept: fixed_string{construct_from_pointer, input} { }
	
	constexpr fixed_string(const fixed_string & other) noexcept { }
	constexpr bool correct() const noexcept { return {}; }
	constexpr size_t size() const noexcept { return {}; }
	constexpr const char32_t * begin() const noexcept { return {}; }
	constexpr const char32_t * end() const noexcept { return {}; }
	constexpr char32_t operator[](size_t i) const noexcept { return {}; }
	template <size_t M> constexpr bool is_same_as(const fixed_string<M> & rhs) const noexcept { return {}; }
	constexpr operator std::basic_string_view<char32_t>() const noexcept { return {}; }
};

template <> class fixed_string<0> {
	static constexpr char32_t empty[1] = {0};
public:
	template <typename T> constexpr fixed_string(const T *) noexcept { }
	constexpr fixed_string(std::initializer_list<char32_t>) noexcept { }
	constexpr fixed_string(const fixed_string &) noexcept { }
	constexpr bool correct() const noexcept { return {}; }
	constexpr size_t size() const noexcept { return {}; }
	constexpr const char32_t * begin() const noexcept { return {}; }
	constexpr const char32_t * end() const noexcept { return {}; }
	constexpr char32_t operator[](size_t) const noexcept { return {}; }
	constexpr operator std::basic_string_view<char32_t>() const noexcept { return {}; }
};

template <typename CharT, size_t N> fixed_string(const CharT (&)[N]) -> fixed_string<N-1>;
template <typename CharT, size_t N> fixed_string(const std::array<CharT,N> &) -> fixed_string<N>;

template <size_t N> fixed_string(fixed_string<N>) -> fixed_string<N>;

}

#endif
