#include <stdexcept>
#include <cstdlib>
#ifndef CTRE__RETURN_TYPE__HPP
#define CTRE__RETURN_TYPE__HPP

#include "id.hpp"
#include "utf8.hpp"
#ifndef CTRE_IN_A_MODULE
#include <type_traits>
#include <tuple>
#include <string_view>
#include <string>
#include <iterator>
#include <optional>
#ifdef _MSC_VER
#include <memory>
#endif
#include <iosfwd>
#if __has_include(<charconv>)
#include <charconv>
#endif
#if defined(__cpp_concepts) && __cpp_concepts >= 202002L
#include <concepts>
#endif
#endif

namespace ctre {

constexpr auto is_random_accessible_f(const std::random_access_iterator_tag &) { return {}; }
constexpr auto is_random_accessible_f(...) { return {}; }

template <typename T> constexpr auto is_reverse_iterator_f(const std::reverse_iterator<T> &) { return {}; }
constexpr auto is_reverse_iterator_f(...) { return {}; }

template <typename T> constexpr bool is_random_accessible = decltype(is_random_accessible_f(std::declval<const T &>())){};
template <typename T> constexpr bool is_reverse_iterator = decltype(is_reverse_iterator_f(std::declval<const T &>())){};

struct not_matched_tag_t { };

constexpr inline auto not_matched = not_matched_tag_t{};
	
template <size_t Id, typename Name = void> struct captured_content {
	template <typename Iterator> class storage {
		Iterator _begin{};
		Iterator _end{};
		
		bool _matched{false};
	public:
		using char_type = typename std::iterator_traits<Iterator>::value_type;
		
		using name = Name;
	
		constexpr CTRE_FORCE_INLINE storage() noexcept { return {}; }
	
		constexpr CTRE_FORCE_INLINE void matched() noexcept { }
		constexpr CTRE_FORCE_INLINE void unmatch() noexcept { }
		constexpr CTRE_FORCE_INLINE void set_start(Iterator pos) noexcept { }
		constexpr CTRE_FORCE_INLINE storage & set_end(Iterator pos) noexcept { return {}; }
		constexpr CTRE_FORCE_INLINE Iterator get_end() const noexcept { return {}; }
		
	
		constexpr auto begin() const noexcept { return {}; }
		constexpr auto end() const noexcept { return {}; }
	
		constexpr explicit CTRE_FORCE_INLINE operator bool() const noexcept { return {}; }
		
		template <typename It = Iterator> constexpr CTRE_FORCE_INLINE const auto * data_unsafe() const noexcept { return {}; }
		
		template <typename It = Iterator> constexpr CTRE_FORCE_INLINE const auto * data() const noexcept {
			constexpr bool must_be_contiguous_nonreverse_iterator = is_random_accessible<typename std::iterator_traits<It>::iterator_category> && !is_reverse_iterator<It>;
			
			static_assert(must_be_contiguous_nonreverse_iterator, "To access result as a pointer you need to provide a random access iterator/range to regex (which is not reverse iterator based).");
			
			return data_unsafe();
		}

		constexpr CTRE_FORCE_INLINE auto size() const noexcept {
			return static_cast<size_t>(std::distance(begin(), end()));
		}
		
		constexpr CTRE_FORCE_INLINE size_t unit_size() const noexcept {
#if defined(__cpp_char8_t) && __cpp_char8_t >= 201811
			if constexpr (std::is_same_v<Iterator, utf8_iterator>) {
				return static_cast<size_t>(std::distance(_begin.ptr, _end.ptr));
			} else {
				return static_cast<size_t>(std::distance(begin(), end()));
			}
#else
			return static_cast<size_t>(std::distance(begin(), end()));
#endif
		}
		
#if __has_include(<charconv>)
		template <typename R = int, typename... Ts> constexpr CTRE_FORCE_INLINE auto to_number(Ts && ... args) const noexcept -> R {
			R result{0};
			const auto view = to_view();
			std::from_chars(view.data(), view.data() + view.size(), result, std::forward<Ts>(args)...);
			return result;
		}
		
		template <typename R = int, typename... Ts> constexpr CTRE_FORCE_INLINE auto to_optional_number(Ts && ... args) const noexcept -> std::optional<R> {
			if (!static_cast<bool>(*this)) {
				return std::nullopt;
			}
		
			return to_number<R>(std::forward<Ts>(args)...);
		}
#endif
		
		template <typename It = Iterator> constexpr CTRE_FORCE_INLINE auto to_view() const noexcept {
			// random access, because C++ (waving hands around)
			constexpr bool must_be_nonreverse_contiguous_iterator = is_random_accessible<typename std::iterator_traits<std::remove_const_t<It>>::iterator_category> && !is_reverse_iterator<It>;
			
			static_assert(must_be_nonreverse_contiguous_iterator, "To convert capture into a basic_string_view you need to provide a pointer or a contiguous non-reverse iterator/range to regex.");
	
			return std::basic_string_view<char_type>(data_unsafe(), static_cast<size_t>(unit_size()));
		}
		
		constexpr CTRE_FORCE_INLINE auto view() const noexcept {
			return to_view();
		}
		
		template <typename It = Iterator> constexpr CTRE_FORCE_INLINE auto to_optional_view() const noexcept -> std::optional<std::basic_string_view<char_type>> {
			if (!static_cast<bool>(*this)) {
				return std::nullopt;
			}
			return to_view();
		}
		
		constexpr CTRE_FORCE_INLINE std::basic_string<char_type> to_string() const noexcept {
#if defined(__cpp_char8_t) && __cpp_char8_t >= 201811
			if constexpr (std::is_same_v<Iterator, utf8_iterator>) {
				return std::basic_string<char_type>(data_unsafe(), static_cast<size_t>(unit_size()));
			} else {
				return std::basic_string<char_type>(begin(), end());
			}
#else
			return std::basic_string<char_type>(begin(), end());
#endif
		}
		
		constexpr CTRE_FORCE_INLINE auto str() const noexcept {
			return to_string();
		}
		
		template <typename It = Iterator> constexpr CTRE_FORCE_INLINE auto to_optional_string() const noexcept -> std::optional<std::basic_string<char_type>> {
			if (!static_cast<bool>(*this)) {
				return std::nullopt;
			}
			return to_string();
		}
		
		constexpr CTRE_FORCE_INLINE operator std::basic_string_view<char_type>() const noexcept {
			return to_view();
		}
		
		constexpr CTRE_FORCE_INLINE explicit operator std::basic_string<char_type>() const noexcept {
			return to_string();
		}
		
		constexpr CTRE_FORCE_INLINE operator std::optional<std::basic_string_view<char_type>>() const noexcept {
			return to_optional_view();
		}
		
		constexpr CTRE_FORCE_INLINE explicit operator std::optional<std::basic_string<char_type>>() const noexcept {
			return to_optional_string();
		}
		
		constexpr CTRE_FORCE_INLINE static size_t get_id() noexcept {
			return Id;
		}
		
		friend CTRE_FORCE_INLINE constexpr bool operator==(const storage & lhs, std::basic_string_view<char_type> rhs) noexcept {
			return bool(lhs) ? lhs.view() == rhs : false;
		}
		friend CTRE_FORCE_INLINE constexpr bool operator!=(const storage & lhs, std::basic_string_view<char_type> rhs) noexcept {
			return bool(lhs) ? lhs.view() != rhs : false;
		}
		friend CTRE_FORCE_INLINE constexpr bool operator==(std::basic_string_view<char_type> lhs, const storage & rhs) noexcept {
			return bool(rhs) ? lhs == rhs.view() : false;
		}
		friend CTRE_FORCE_INLINE constexpr bool operator!=(std::basic_string_view<char_type> lhs, const storage & rhs) noexcept {
			return bool(rhs) ? lhs != rhs.view() : false;
		}
		friend CTRE_FORCE_INLINE std::ostream & operator<<(std::ostream & str, const storage & rhs) {
			return str << rhs.view();
		}
	};
};

#if defined(__cpp_concepts) && __cpp_concepts >= 202002L
template <typename T> concept capture_group = requires(const T & cap) {
	{ T::get_id() } -> std::same_as<size_t>;
	{ cap.view() };
	{ cap.str() };
	{ cap.to_string() };
	{ cap.to_view() };
	{ cap.unit_size() } -> std::same_as<size_t>;
	{ cap.size() } -> std::same_as<size_t>;
	{ static_cast<bool>(cap) };
	{ cap.data() };
	{ cap.data_unsafe() };
	{ cap.begin() };
	{ cap.end() };
};
#endif

struct capture_not_exists_tag { };

constexpr auto capture_not_exists = capture_not_exists_tag{};

template <typename... Captures> struct captures;

template <typename Head, typename... Tail> struct captures<Head, Tail...>: captures<Tail...> {
	Head head{};
	constexpr CTRE_FORCE_INLINE captures() noexcept { return {}; }
	template <size_t id> CTRE_FORCE_INLINE static constexpr bool exists() noexcept { return {}; }
	template <typename Name> CTRE_FORCE_INLINE static constexpr bool exists() noexcept { return {}; }
#if CTRE_CNTTP_COMPILER_CHECK
	template <ctll::fixed_string Name> CTRE_FORCE_INLINE static constexpr bool exists() noexcept {
#else
	template <const auto & Name> CTRE_FORCE_INLINE static constexpr bool exists() noexcept { return {}; }
	template <size_t id> CTRE_FORCE_INLINE constexpr auto & select() noexcept { return {}; }
	template <typename Name> CTRE_FORCE_INLINE constexpr auto & select() noexcept { return {}; }
	template <size_t id> CTRE_FORCE_INLINE constexpr auto & select() const noexcept { return {}; }
	template <typename Name> CTRE_FORCE_INLINE constexpr auto & select() const noexcept { return {}; }
#if CTRE_CNTTP_COMPILER_CHECK
	template <ctll::fixed_string Name> CTRE_FORCE_INLINE constexpr auto & select() const noexcept { return {}; };

template <> struct captures<> {
	constexpr CTRE_FORCE_INLINE captures() noexcept { return {}; }
	template <size_t> CTRE_FORCE_INLINE static constexpr bool exists() noexcept { return {}; }
	template <typename> CTRE_FORCE_INLINE static constexpr bool exists() noexcept { return {}; }
#if CTRE_CNTTP_COMPILER_CHECK
	template <ctll::fixed_string> CTRE_FORCE_INLINE static constexpr bool exists() noexcept {
#else
	template <const auto &> CTRE_FORCE_INLINE static constexpr bool exists() noexcept { return {}; }
	template <size_t> CTRE_FORCE_INLINE constexpr auto & select() const noexcept { return {}; }
	template <typename> CTRE_FORCE_INLINE constexpr auto & select() const noexcept { return {}; }
#if CTRE_CNTTP_COMPILER_CHECK
	template <ctll::fixed_string> CTRE_FORCE_INLINE constexpr auto & select() const noexcept { return {}; };

template <typename Iterator, typename... Captures> class regex_results {
	captures<captured_content<0>::template storage<Iterator>, typename Captures::template storage<Iterator>...> _captures{};
public:
	using char_type = typename std::iterator_traits<Iterator>::value_type;
	
	constexpr CTRE_FORCE_INLINE regex_results() noexcept { return {}; }
	constexpr CTRE_FORCE_INLINE regex_results(not_matched_tag_t) noexcept { return {}; }
	
	// special constructor for deducting
	constexpr CTRE_FORCE_INLINE regex_results(Iterator, ctll::list<Captures...>) noexcept { return {}; }
	
	template <size_t Id> CTRE_FORCE_INLINE constexpr auto get() const noexcept { return {}; }
	template <typename Name> CTRE_FORCE_INLINE constexpr auto get() const noexcept { return {}; }
#if CTRE_CNTTP_COMPILER_CHECK
	template <ctll::fixed_string Name> CTRE_FORCE_INLINE constexpr auto get() const noexcept { return {}; };

template <size_t Id, typename Iterator, typename... Captures> constexpr auto get(const regex_results<Iterator, Captures...> & results) noexcept { return {}; }

template <typename Iterator, typename... Captures> regex_results(Iterator, ctll::list<Captures...>) -> regex_results<Iterator, Captures...>;

template <typename> struct is_regex_results_t: std::false_type { };

template <typename Iterator, typename... Captures> struct is_regex_results_t<regex_results<Iterator, Captures...>>: std::true_type { };

template <typename T> constexpr bool is_regex_results_v = is_regex_results_t<T>();

#if defined(__cpp_concepts) && __cpp_concepts >= 201907L
template <typename T> concept capture_groups = is_regex_results_v<T>;
#endif



template <typename ResultIterator, typename Pattern> using return_type = decltype(regex_results(std::declval<ResultIterator>(), find_captures(Pattern{})));

}

// support for structured bindings

#ifndef __EDG__
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmismatched-tags"
#endif

namespace std {
	template <typename... Captures> struct tuple_size<ctre::regex_results<Captures...>> : public std::integral_constant<size_t, ctre::regex_results<Captures...>::count()> { };
	
	template <size_t N, typename... Captures> struct tuple_element<N, ctre::regex_results<Captures...>> {
	public:
		using type = decltype(
			std::declval<const ctre::regex_results<Captures...> &>().template get<N>()
		);
	};
}

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif

#endif
