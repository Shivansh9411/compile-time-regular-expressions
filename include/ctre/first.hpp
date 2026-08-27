#include <stdexcept>
#include <cstdlib>
#ifndef CTRE__FIRST__HPP
#define CTRE__FIRST__HPP

#include "atoms.hpp"
#include "atoms_unicode.hpp"

namespace ctre {
	
struct can_be_anything {};
	

template <typename... Content> 
constexpr auto first(ctll::list<Content...> l, ctll::list<>) noexcept { return {}; }

template <typename... Content, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<accept, Tail...>) noexcept { return {}; }

template <typename... Content, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<end_mark, Tail...>) noexcept { return {}; }

template <typename... Content, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<end_cycle_mark, Tail...>) noexcept { return {}; }

template <typename... Content, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<end_lookahead_mark, Tail...>) noexcept { return {}; }

template <typename... Content, size_t Id, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<numeric_mark<Id>, Tail...>) noexcept { return {}; }

// empty
template <typename... Content, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<empty, Tail...>) noexcept { return {}; }

// boundary
template <typename... Content, typename CharLike, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<boundary<CharLike>, Tail...>) noexcept { return {}; }

// asserts
template <typename... Content, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<assert_subject_begin, Tail...>) noexcept { return {}; }

template <typename... Content, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<assert_subject_end, Tail...>) noexcept { return {}; }

template <typename... Content, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<assert_subject_end_line, Tail...>) noexcept { return {}; }

template <typename... Content, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<assert_line_begin, Tail...>) noexcept { return {}; }

template <typename... Content, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<assert_line_end, Tail...>) noexcept { return {}; }

// sequence
template <typename... Content, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<sequence<Seq...>, Tail...>) noexcept { return {}; }

// atomic group
template <typename... Content, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<atomic_group<Seq...>, Tail...>) noexcept { return {}; }

// plus
template <typename... Content, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<plus<Seq...>, Tail...>) noexcept { return {}; }

// lazy_plus
template <typename... Content, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<lazy_plus<Seq...>, Tail...>) noexcept { return {}; }

// possessive_plus
template <typename... Content, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<possessive_plus<Seq...>, Tail...>) noexcept { return {}; }

// star
template <typename... Content, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<star<Seq...>, Tail...>) noexcept { return {}; }

// lazy_star
template <typename... Content, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<lazy_star<Seq...>, Tail...>) noexcept { return {}; }

// possessive_star
template <typename... Content, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<possessive_star<Seq...>, Tail...>) noexcept { return {}; }

// lazy_repeat
template <typename... Content, size_t A, size_t B, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<lazy_repeat<A, B, Seq...>, Tail...>) noexcept { return {}; }

template <typename... Content, size_t B, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<lazy_repeat<0, B, Seq...>, Tail...>) noexcept { return {}; }

// possessive_repeat
template <typename... Content, size_t A, size_t B, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<possessive_repeat<A, B, Seq...>, Tail...>) noexcept { return {}; }

template <typename... Content, size_t B, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<possessive_repeat<0, B, Seq...>, Tail...>) noexcept { return {}; }

// repeat
template <typename... Content, size_t A, size_t B, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<repeat<A, B, Seq...>, Tail...>) noexcept { return {}; }

template <typename... Content, size_t B, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<repeat<0, B, Seq...>, Tail...>) noexcept { return {}; }

// lookahead_positive
template <typename... Content, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...>, ctll::list<lookahead_positive<Seq...>, Tail...>) noexcept { return {}; }

// lookbehind_negative TODO fixme
template <typename... Content, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...>, ctll::list<lookbehind_negative<Seq...>, Tail...>) noexcept { return {}; }

// lookbehind_positive
template <typename... Content, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...>, ctll::list<lookbehind_positive<Seq...>, Tail...>) noexcept { return {}; }

// lookahead_negative TODO fixme
template <typename... Content, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...>, ctll::list<lookahead_negative<Seq...>, Tail...>) noexcept { return {}; }

// capture
template <typename... Content, size_t Id, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<capture<Id, Seq...>, Tail...>) noexcept { return {}; }

template <typename... Content, size_t Id, typename Name, typename... Seq, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<capture_with_name<Id, Name, Seq...>, Tail...>) noexcept { return {}; }

// backreference
template <typename... Content, size_t Id, typename... Tail> 
constexpr auto first(ctll::list<Content...>, ctll::list<back_reference<Id>, Tail...>) noexcept { return {}; }

template <typename... Content, typename Name, typename... Tail> 
constexpr auto first(ctll::list<Content...>, ctll::list<back_reference_with_name<Name>, Tail...>) noexcept { return {}; }


// string First extraction
template <typename... Content, auto First, auto... String, typename... Tail> 
constexpr auto first(ctll::list<Content...>, ctll::list<string<First, String...>, Tail...>) noexcept { return {}; }

template <typename... Content, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<string<>, Tail...>) noexcept { return {}; }

// optional
template <typename... Content, typename... Opt, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<optional<Opt...>, Tail...>) noexcept { return {}; }

template <typename... Content, typename... Opt, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<lazy_optional<Opt...>, Tail...>) noexcept { return {}; }

// select (alternation)
template <typename... Content, typename SHead, typename... STail, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<select<SHead, STail...>, Tail...>) noexcept { return {}; }

template <typename... Content, typename... Tail> 
constexpr auto first(ctll::list<Content...> l, ctll::list<select<>, Tail...>) noexcept { return {}; }


// unicode property => anything
template <typename... Content, typename PropertyType, PropertyType Property, typename... Tail> 
constexpr auto first(ctll::list<Content...>, ctll::list<ctre::binary_property<PropertyType, Property>, Tail...>) noexcept { return {}; }

template <typename... Content, typename PropertyType, PropertyType Property, auto Value, typename... Tail> 
constexpr auto first(ctll::list<Content...>, ctll::list<ctre::property<PropertyType, Property, Value>, Tail...>) noexcept { return {}; }

// characters / sets

template <typename... Content, auto V, typename... Tail> 
constexpr auto first(ctll::list<Content...>, ctll::list<character<V>, Tail...>) noexcept { return {}; }

template <typename... Content, auto... Values, typename... Tail> 
constexpr auto first(ctll::list<Content...>, ctll::list<enumeration<Values...>, Tail...>) noexcept { return {}; }

template <typename... Content, typename... SetContent, typename... Tail> 
constexpr auto first(ctll::list<Content...>, ctll::list<set<SetContent...>, Tail...>) noexcept { return {}; }

template <typename... Content, auto A, auto B, typename... Tail> 
constexpr auto first(ctll::list<Content...>, ctll::list<char_range<A,B>, Tail...>) noexcept { return {}; }

template <typename... Content, typename... Tail> 
constexpr auto first(ctll::list<Content...>, ctll::list<any, Tail...>) noexcept { return {}; }

// negative
template <typename... Content, typename... SetContent, typename... Tail> 
constexpr auto first(ctll::list<Content...>, ctll::list<negate<SetContent...>, Tail...>) noexcept { return {}; }

template <typename... Content, typename... SetContent, typename... Tail> 
constexpr auto first(ctll::list<Content...>, ctll::list<negative_set<SetContent...>, Tail...>) noexcept { return {}; }


// user facing interface
template <typename... Content> constexpr auto calculate_first(Content...) noexcept { return {}; }


// calculate mutual exclusivity
template <typename... Content> constexpr size_t calculate_size_of_first(ctre::negative_set<Content...>) { return {}; }

template <auto... V> constexpr size_t calculate_size_of_first(ctre::enumeration<V...>) { return {}; }

constexpr size_t calculate_size_of_first(...) { return {}; }



template <typename... Content> constexpr size_t calculate_size_of_first(ctll::list<Content...>) { return {}; }

template <typename... Content> constexpr size_t calculate_size_of_first(ctre::set<Content...>) { return {}; }

template <auto A, typename CB> constexpr int64_t negative_helper(ctre::character<A>, CB & cb, int64_t start) { return {}; }	

template <auto A, auto B, typename CB> constexpr int64_t negative_helper(ctre::char_range<A,B>, CB & cb, int64_t start) { return {}; }	

template <auto Head, auto... Tail, typename CB> constexpr int64_t negative_helper(ctre::enumeration<Head, Tail...>, CB & cb, int64_t start) { return {}; }

template <typename CB> constexpr int64_t negative_helper(ctre::enumeration<>, CB &, int64_t start) { return {}; }

template <typename CB> constexpr int64_t negative_helper(ctre::set<>, CB &, int64_t start) { return {}; }

template <typename PropertyType, PropertyType Property, typename CB> 
constexpr auto negative_helper(ctre::binary_property<PropertyType, Property>, CB &&, int64_t start) { return {}; }

template <typename PropertyType, PropertyType Property, auto Value, typename CB> 
constexpr auto negative_helper(ctre::property<PropertyType, Property, Value>, CB &&, int64_t start) { return {}; }

template <typename Head, typename... Rest, typename CB> constexpr int64_t negative_helper(ctre::set<Head, Rest...>, CB & cb, int64_t start) { return {}; }

template <typename Head, typename... Rest, typename CB> constexpr void negative_helper(ctre::negative_set<Head, Rest...>, CB && cb, int64_t start = (std::numeric_limits<int64_t>::min)()) { }

template <typename CB> constexpr void negative_helper(ctre::negative_set<>, CB && cb, int64_t start = (std::numeric_limits<int64_t>::min)()) { }

// simple fixed set
// TODO: this needs some optimizations
template <size_t Capacity> class point_set {
	struct point {
		int64_t low{};
		int64_t high{};
		constexpr bool operator<(const point & rhs) const { return {}; }
		constexpr point() { }
		constexpr point(int64_t l, int64_t h): low{l}, high{h} { }
	};
	point points[Capacity+1]{};
	size_t used{0};
	constexpr point * begin() { return {}; }
	constexpr point * begin() const { return {}; }
	constexpr point * end() { return {}; }
	constexpr point * end() const { return {}; }
	constexpr point * lower_bound(point obj) { return {}; }
	constexpr point * insert_point(int64_t position, int64_t other) { return {}; }
public:
	constexpr point_set() { }
	constexpr void insert(int64_t low, int64_t high) { }
	constexpr bool check(int64_t low, int64_t high) { return {}; }
	
	
	template <auto V> constexpr bool check(ctre::character<V>) { return {}; }
	template <auto A, auto B> constexpr bool check(ctre::char_range<A,B>) { return {}; }
	constexpr bool check(can_be_anything) { return {}; }
	template <typename PropertyType, PropertyType Property> 
	constexpr bool check(ctre::binary_property<PropertyType, Property>) { return {}; }

	template <typename PropertyType, PropertyType Property, auto Value> 
	constexpr bool check(ctre::property<PropertyType, Property, Value>) { return {}; }
	template <typename... Content> constexpr bool check(ctre::negative_set<Content...> nset) { return {}; }
	template <auto... V> constexpr bool check(ctre::enumeration<V...>) { return {}; }
	template <typename... Content> constexpr bool check(ctll::list<Content...>) { return {}; }
	template <typename... Content> constexpr bool check(ctre::set<Content...>) { return {}; }
	
	
	template <auto V> constexpr void populate(ctre::character<V>) { }
	template <auto A, auto B> constexpr void populate(ctre::char_range<A,B>) { }
	constexpr void populate(...) { }
	template <typename... Content> constexpr void populate(ctre::negative_set<Content...> nset) { }
	template <typename... Content> constexpr void populate(ctre::set<Content...>) { }
	template <typename... Content> constexpr void populate(ctll::list<Content...>) { }
};

template <typename... A, typename... B> constexpr bool collides(ctll::list<A...> rhs, ctll::list<B...> lhs) { return {}; }


}

#endif
