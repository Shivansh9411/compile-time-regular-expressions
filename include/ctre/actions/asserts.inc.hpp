#ifndef CTRE__ACTIONS__ASSERTS__HPP
#define CTRE__ACTIONS__ASSERTS__HPP

// push_assert_begin
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_assert_begin, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }

// push_assert_end
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_assert_end, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }

// push_assert_begin
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_assert_subject_begin, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }

// push_assert_subject_end
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_assert_subject_end, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }

// push_assert_subject_end_with_lineend
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_assert_subject_end_with_lineend, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }

#endif
