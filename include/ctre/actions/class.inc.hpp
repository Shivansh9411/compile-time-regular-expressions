#ifndef CTRE__ACTIONS__CLASS__HPP
#define CTRE__ACTIONS__CLASS__HPP

// class_digit
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::class_digit, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// class_non_digit
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::class_nondigit, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// class_space
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::class_space, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// class_nonspace
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::class_nonspace, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }

// class_horizontal_space
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::class_horizontal_space, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// class_horizontal_nonspace
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::class_non_horizontal_space, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// class_vertical_space
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::class_vertical_space, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// class_vertical_nonspace
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::class_non_vertical_space, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }

// class_word
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::class_word, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// class_nonword
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::class_nonword, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// class_nonnewline
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::class_nonnewline, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }

#endif
