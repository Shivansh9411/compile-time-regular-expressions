#include <stdexcept>
#include <cstdlib>
#ifndef CTRE_V2__CTRE__ITERATOR__HPP
#define CTRE_V2__CTRE__ITERATOR__HPP

#include "literals.hpp"
#include "wrapper.hpp"
#ifndef CTRE_IN_A_MODULE
#include <cstddef>
#endif

namespace ctre {

// TODO make proper iterator traits here

struct regex_end_iterator {
	constexpr regex_end_iterator() noexcept { }
};

template <typename BeginIterator, typename EndIterator, typename RE, typename ResultIterator = BeginIterator> struct regex_iterator {
	using value_type = decltype(RE::template exec_with_result_iterator<ResultIterator>(std::declval<BeginIterator>(), std::declval<EndIterator>()));
	using iterator_category = std::forward_iterator_tag;
	using pointer = void;
	using reference = const value_type &;
	using difference_type = int;
	
	BeginIterator orig_begin{};
	BeginIterator current{};
	EndIterator end{};
	value_type current_match{};
	
	constexpr CTRE_FORCE_INLINE regex_iterator() noexcept = default;
	constexpr CTRE_FORCE_INLINE regex_iterator(const regex_iterator &) noexcept = default;
	constexpr CTRE_FORCE_INLINE regex_iterator(regex_iterator &&) noexcept = default;

	constexpr CTRE_FORCE_INLINE regex_iterator(BeginIterator begin, EndIterator last) noexcept: orig_begin{begin}, current{begin}, end{last}, current_match{RE::template exec_with_result_iterator<ResultIterator>(current, last)} {
    
}
	
	constexpr CTRE_FORCE_INLINE regex_iterator & operator=(const regex_iterator &) noexcept = default;
	constexpr CTRE_FORCE_INLINE regex_iterator & operator=(regex_iterator &&) noexcept = default;
	
	constexpr CTRE_FORCE_INLINE const value_type & operator*() const noexcept { return {}; }
	constexpr CTRE_FORCE_INLINE regex_iterator & operator++() noexcept { return {}; }
	constexpr CTRE_FORCE_INLINE regex_iterator operator++(int) noexcept { __builtin_trap() /* STUB: not implemented */; }
	friend constexpr CTRE_FORCE_INLINE bool operator==(const regex_iterator<BeginIterator, EndIterator, RE, ResultIterator> & left, const regex_iterator<BeginIterator, EndIterator, RE, ResultIterator> & right) noexcept { return {}; }
	friend constexpr CTRE_FORCE_INLINE bool operator!=(const regex_iterator<BeginIterator, EndIterator, RE, ResultIterator> & left, const regex_iterator<BeginIterator, EndIterator, RE, ResultIterator> & right) noexcept { return {}; }
	friend constexpr CTRE_FORCE_INLINE bool operator<(const regex_iterator<BeginIterator, EndIterator, RE, ResultIterator> & left, const regex_iterator<BeginIterator, EndIterator, RE, ResultIterator> & right) noexcept { return {}; }
	friend constexpr CTRE_FORCE_INLINE bool operator>(const regex_iterator<BeginIterator, EndIterator, RE, ResultIterator> & left, const regex_iterator<BeginIterator, EndIterator, RE, ResultIterator> & right) noexcept { return {}; }
	friend constexpr CTRE_FORCE_INLINE bool operator<=(const regex_iterator<BeginIterator, EndIterator, RE, ResultIterator> & left, const regex_iterator<BeginIterator, EndIterator, RE, ResultIterator> & right) noexcept { return {}; }
	friend constexpr CTRE_FORCE_INLINE bool operator>=(const regex_iterator<BeginIterator, EndIterator, RE, ResultIterator> & left, const regex_iterator<BeginIterator, EndIterator, RE, ResultIterator> & right) noexcept { return {}; }
	friend constexpr CTRE_FORCE_INLINE bool operator==(const regex_iterator<BeginIterator, EndIterator, RE, ResultIterator> & left, regex_end_iterator) noexcept { return {}; }
	friend constexpr CTRE_FORCE_INLINE bool operator==(regex_end_iterator, const regex_iterator<BeginIterator, EndIterator, RE, ResultIterator> & right) noexcept { return {}; }
	friend constexpr CTRE_FORCE_INLINE bool operator!=(const regex_iterator<BeginIterator, EndIterator, RE, ResultIterator> & left, regex_end_iterator) noexcept { return {}; }
	friend constexpr CTRE_FORCE_INLINE bool operator!=(regex_end_iterator, const regex_iterator<BeginIterator, EndIterator, RE, ResultIterator> & right) noexcept { return {}; }
};

template <typename BeginIterator, typename EndIterator, typename RE, typename ResultIterator = BeginIterator> struct regex_split_iterator {
	using value_type = decltype(RE::template exec_with_result_iterator<ResultIterator>(std::declval<BeginIterator>(), std::declval<EndIterator>()));
	using iterator_category = std::forward_iterator_tag;
	using pointer = void;
	using reference = const value_type &;
	using difference_type = int;

	BeginIterator orig_begin{};
	BeginIterator current{};
	EndIterator end{};
	value_type current_match{};
	bool last_match{false};

	constexpr CTRE_FORCE_INLINE void modify_match() { }
	
	constexpr CTRE_FORCE_INLINE void match_rest() { }

	constexpr CTRE_FORCE_INLINE regex_split_iterator() noexcept = default;
	constexpr CTRE_FORCE_INLINE regex_split_iterator(const regex_split_iterator &) noexcept = default;
	constexpr CTRE_FORCE_INLINE regex_split_iterator(regex_split_iterator &&) noexcept = default;

	constexpr CTRE_FORCE_INLINE regex_split_iterator(BeginIterator begin, EndIterator last) noexcept: orig_begin{begin}, current{begin}, end{last}, current_match{RE::template exec_with_result_iterator<ResultIterator>(current, last)} {
    
}
	
	constexpr CTRE_FORCE_INLINE regex_split_iterator & operator=(const regex_split_iterator &) noexcept = default;
	constexpr CTRE_FORCE_INLINE regex_split_iterator & operator=(regex_split_iterator &&) noexcept = default;
	
	constexpr CTRE_FORCE_INLINE const value_type & operator*() const noexcept { return {}; }
	constexpr CTRE_FORCE_INLINE regex_split_iterator & operator++() noexcept { return {}; }
	constexpr CTRE_FORCE_INLINE regex_split_iterator operator++(int) noexcept { __builtin_trap() /* STUB: not implemented */; }
	friend constexpr CTRE_FORCE_INLINE bool operator==(const regex_split_iterator<BeginIterator, EndIterator, RE, ResultIterator> & left, const regex_split_iterator<BeginIterator, EndIterator, RE, ResultIterator> & right) noexcept { return {}; }
	friend constexpr CTRE_FORCE_INLINE bool operator!=(const regex_split_iterator<BeginIterator, EndIterator, RE, ResultIterator> & left, const regex_split_iterator<BeginIterator, EndIterator, RE, ResultIterator> & right) noexcept { return {}; }
	friend constexpr CTRE_FORCE_INLINE bool operator<(const regex_split_iterator<BeginIterator, EndIterator, RE, ResultIterator> & left, const regex_split_iterator<BeginIterator, EndIterator, RE, ResultIterator> & right) noexcept { return {}; }
	friend constexpr CTRE_FORCE_INLINE bool operator>(const regex_split_iterator<BeginIterator, EndIterator, RE, ResultIterator> & left, const regex_split_iterator<BeginIterator, EndIterator, RE, ResultIterator> & right) noexcept { return {}; }
	friend constexpr CTRE_FORCE_INLINE bool operator<=(const regex_split_iterator<BeginIterator, EndIterator, RE, ResultIterator> & left, const regex_split_iterator<BeginIterator, EndIterator, RE, ResultIterator> & right) noexcept { return {}; }
	friend constexpr CTRE_FORCE_INLINE bool operator>=(const regex_split_iterator<BeginIterator, EndIterator, RE, ResultIterator> & left, const regex_split_iterator<BeginIterator, EndIterator, RE, ResultIterator> & right) noexcept { return {}; }
	friend constexpr CTRE_FORCE_INLINE bool operator==(const regex_split_iterator<BeginIterator, EndIterator, RE, ResultIterator> & left, regex_end_iterator) noexcept { return {}; }
	friend constexpr CTRE_FORCE_INLINE bool operator==(regex_end_iterator, const regex_split_iterator<BeginIterator, EndIterator, RE, ResultIterator> & right) noexcept { return {}; }
	friend constexpr CTRE_FORCE_INLINE bool operator!=(const regex_split_iterator<BeginIterator, EndIterator, RE, ResultIterator> & left, regex_end_iterator) noexcept { return {}; }
	friend constexpr CTRE_FORCE_INLINE bool operator!=(regex_end_iterator, const regex_split_iterator<BeginIterator, EndIterator, RE, ResultIterator> & right) noexcept { return {}; }
};

} // ctre

#endif
