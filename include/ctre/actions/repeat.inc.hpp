#ifndef CTRE__ACTIONS__REPEAT__HPP
#define CTRE__ACTIONS__REPEAT__HPP

// repeat 1..N
template <auto V, typename A, typename... Ts, typename Parameters> static constexpr auto apply(pcre::repeat_plus, ctll::term<V>, pcre_context<ctll::list<A, Ts...>, Parameters> subject) { return {}; }
// repeat 1..N (sequence)
template <auto V, typename... Content, typename... Ts, typename Parameters> static constexpr auto apply(pcre::repeat_plus, ctll::term<V>, pcre_context<ctll::list<sequence<Content...>, Ts...>, Parameters> subject) { return {}; }

// repeat 0..N
template <auto V, typename A, typename... Ts, typename Parameters> static constexpr auto apply(pcre::repeat_star, ctll::term<V>, pcre_context<ctll::list<A, Ts...>, Parameters> subject) { return {}; }
// repeat 0..N (sequence)
template <auto V, typename... Content, typename... Ts, typename Parameters> static constexpr auto apply(pcre::repeat_star, ctll::term<V>, pcre_context<ctll::list<sequence<Content...>, Ts...>, Parameters> subject) { return {}; }

// create_number (seed)
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::create_number, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// push_number
template <auto V, size_t N, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_number, ctll::term<V>, pcre_context<ctll::list<number<N>, Ts...>, Parameters> subject) { return {}; }

// repeat A..B
template <auto V, typename Subject, size_t A, size_t B, typename... Ts, typename Parameters> static constexpr auto apply(pcre::repeat_ab, ctll::term<V>, pcre_context<ctll::list<number<B>, number<A>, Subject, Ts...>, Parameters> subject) { return {}; }
// repeat A..B (sequence)
template <auto V, typename... Content, size_t A, size_t B, typename... Ts, typename Parameters> static constexpr auto apply(pcre::repeat_ab, ctll::term<V>, pcre_context<ctll::list<number<B>, number<A>, sequence<Content...>, Ts...>, Parameters> subject) { return {}; }

// repeat_exactly 
template <auto V, typename Subject, size_t A, typename... Ts, typename Parameters> static constexpr auto apply(pcre::repeat_exactly, ctll::term<V>, pcre_context<ctll::list<number<A>, Subject, Ts...>, Parameters> subject) { return {}; }
// repeat_exactly A..B (sequence)
template <auto V, typename... Content, size_t A, typename... Ts, typename Parameters> static constexpr auto apply(pcre::repeat_exactly, ctll::term<V>, pcre_context<ctll::list<number<A>, sequence<Content...>, Ts...>, Parameters> subject) { return {}; }

// repeat_at_least (A+) 
template <auto V, typename Subject, size_t A, typename... Ts, typename Parameters> static constexpr auto apply(pcre::repeat_at_least, ctll::term<V>, pcre_context<ctll::list<number<A>, Subject, Ts...>, Parameters> subject) { return {}; }
// repeat_at_least (A+) (sequence)
template <auto V, typename... Content, size_t A, typename... Ts, typename Parameters> static constexpr auto apply(pcre::repeat_at_least, ctll::term<V>, pcre_context<ctll::list<number<A>, sequence<Content...>, Ts...>, Parameters> subject) { return {}; }

// make_lazy (plus)
template <auto V, typename... Subject, typename... Ts, typename Parameters> static constexpr auto apply(pcre::make_lazy, ctll::term<V>, pcre_context<ctll::list<plus<Subject...>, Ts...>, Parameters> subject) { return {}; }

// make_lazy (star)
template <auto V, typename... Subject, typename... Ts, typename Parameters> static constexpr auto apply(pcre::make_lazy, ctll::term<V>, pcre_context<ctll::list<star<Subject...>, Ts...>, Parameters> subject) { return {}; }

// make_lazy (repeat<A,B>)
template <auto V, typename... Subject, size_t A, size_t B, typename... Ts, typename Parameters> static constexpr auto apply(pcre::make_lazy, ctll::term<V>, pcre_context<ctll::list<repeat<A,B,Subject...>, Ts...>, Parameters> subject) { return {}; }

// make_possessive (plus)
template <auto V, typename... Subject, typename... Ts, typename Parameters> static constexpr auto apply(pcre::make_possessive, ctll::term<V>, pcre_context<ctll::list<plus<Subject...>, Ts...>, Parameters> subject) { return {}; }

// make_possessive (star)
template <auto V, typename... Subject, typename... Ts, typename Parameters> static constexpr auto apply(pcre::make_possessive, ctll::term<V>, pcre_context<ctll::list<star<Subject...>, Ts...>, Parameters> subject) { return {}; }

// make_possessive (repeat<A,B>)
template <auto V, typename... Subject, size_t A, size_t B, typename... Ts, typename Parameters> static constexpr auto apply(pcre::make_possessive, ctll::term<V>, pcre_context<ctll::list<repeat<A,B,Subject...>, Ts...>, Parameters> subject) { return {}; }


#endif
