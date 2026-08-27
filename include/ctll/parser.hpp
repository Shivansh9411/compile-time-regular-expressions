#ifndef CTLL__PARSER__HPP
#define CTLL__PARSER__HPP

#include "fixed_string.hpp"
#include "list.hpp"
#include "grammars.hpp"
#include "actions.hpp"

#ifndef CTLL_IN_A_MODULE
#include <limits>
#endif

namespace ctll {


enum class decision {
	reject,
	accept,
	undecided
};

struct placeholder { };

template <size_t> using index_placeholder = placeholder;

#if CTLL_CNTTP_COMPILER_CHECK
template <typename Grammar, ctll::fixed_string input, typename ActionSelector = empty_actions, bool IgnoreUnknownActions = false> struct parser { // in c++20
#else
template <typename Grammar, const auto & input, typename ActionSelector = empty_actions, bool IgnoreUnknownActions = false> struct parser {
#endif
	
	#ifdef __GNUC__ // workaround to GCC bug
		#if CTLL_CNTTP_COMPILER_CHECK
		static constexpr auto _input = input;  // c++20 mode
		#else
		static constexpr auto & _input = input; // c++17 mode
		#endif
	#else
		static constexpr auto _input = input; // everyone else
	#endif

	using Actions = ctll::conditional<IgnoreUnknownActions, ignore_unknown<ActionSelector>, identity<ActionSelector>>;
	using grammar = augment_grammar<Grammar>;
	
	template <size_t Pos, typename Stack, typename Subject, decision Decision> struct results {
	
		static constexpr bool is_correct = Decision == decision::accept;
	
		constexpr inline CTLL_FORCE_INLINE operator bool() const noexcept { return {}; }
		
		#ifdef __GNUC__ // workaround to GCC bug
			#if CTLL_CNTTP_COMPILER_CHECK
			static constexpr auto _input = input;  // c++20 mode
			#else
			static constexpr auto & _input = input; // c++17 mode
			#endif
		#else
			static constexpr auto _input = input; // everyone else
		#endif
	
		using output_type = Subject;
		static constexpr size_t position = Pos;
    
		constexpr auto operator+(placeholder) const noexcept { return {}; }
	};
	
	template <size_t Pos> static constexpr auto get_current_term() noexcept { return {}; }
	template <size_t Pos> static constexpr auto get_previous_term() noexcept { return {}; }
	// if rule is accept => return true and subject
	template <size_t Pos, typename Terminal, typename Stack, typename Subject> 
	static constexpr auto move(ctll::accept, Terminal, Stack, Subject) noexcept { return {}; }
	// if rule is reject => return false and subject
	template <size_t Pos, typename Terminal, typename Stack, typename Subject>
	static constexpr auto move(ctll::reject, Terminal, Stack, Subject) noexcept { return {}; }
	// if rule is pop_input => move to next character
	template <size_t Pos, typename Terminal, typename Stack, typename Subject>
	static constexpr auto move(ctll::pop_input, Terminal, Stack, Subject) noexcept { return {}; }
	// if rule is string => push it to the front of stack
	template <size_t Pos, typename... Content, typename Terminal, typename Stack, typename Subject>
	static constexpr auto move(push<Content...> string, Terminal, Stack stack, Subject subject) noexcept { return {}; }
	// if rule is epsilon (empty string) => continue
	template <size_t Pos, typename Terminal, typename Stack, typename Subject>
	static constexpr auto move(epsilon, Terminal, Stack stack, Subject subject) noexcept { return {}; }
	// if rule is string with current character at the beginning (term<V>) => move to next character 
	// and push string without the character (quick LL(1))
	template <size_t Pos, auto V, typename... Content, typename Stack, typename Subject>
	static constexpr auto move(push<term<V>, Content...>, term<V>, Stack stack, Subject) noexcept { return {}; }
	// if rule is string with any character at the beginning (compatible with current term<T>) => move to next character 
	// and push string without the character (quick LL(1))
	template <size_t Pos, auto V, typename... Content, auto T, typename Stack, typename Subject>
	static constexpr auto move(push<anything, Content...>, term<T>, Stack stack, Subject) noexcept { return {}; }
	// decide if we need to take action or move
	template <size_t Pos, typename Stack, typename Subject> static constexpr auto decide(Stack previous_stack, Subject previous_subject) noexcept { return {}; }
	
	// trampolines with folded expression
	template <typename Subject, size_t... Pos> static constexpr auto trampoline_decide(Subject, std::index_sequence<Pos...>) noexcept { return {}; }
	
	template <typename Subject = empty_subject> static constexpr auto trampoline_decide(Subject subject = {}) noexcept { return {}; }
	
	template <typename Subject = empty_subject> using output = decltype(trampoline_decide<Subject>());
	template <typename Subject = empty_subject> static inline constexpr bool correct_with = trampoline_decide<Subject>();

};

} // end of ctll namespace


#endif

