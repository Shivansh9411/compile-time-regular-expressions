#ifndef CTRE__ACTIONS__CAPTURE__HPP
#define CTRE__ACTIONS__CAPTURE__HPP

// prepare_capture
template <auto V, typename... Ts, size_t Counter> static constexpr auto apply(pcre::prepare_capture, ctll::term<V>, pcre_context<ctll::list<Ts...>, pcre_parameters<Counter>>) { return {}; }

// reset_capture
template <auto V, typename... Ts, size_t Id, size_t Counter> static constexpr auto apply(pcre::reset_capture, ctll::term<V>, pcre_context<ctll::list<capture_id<Id>, Ts...>, pcre_parameters<Counter>>) { return {}; }

// capture
template <auto V, typename A, size_t Id, typename... Ts, size_t Counter> static constexpr auto apply(pcre::make_capture, ctll::term<V>, pcre_context<ctll::list<A, capture_id<Id>, Ts...>, pcre_parameters<Counter>>) { return {}; }
// capture (sequence)
template <auto V, typename... Content, size_t Id, typename... Ts, size_t Counter> static constexpr auto apply(pcre::make_capture, ctll::term<V>, pcre_context<ctll::list<sequence<Content...>, capture_id<Id>, Ts...>, pcre_parameters<Counter>>) { return {}; }
// push_name
template <auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_name, ctll::term<V>, pcre_context<ctll::list<Ts...>, Parameters> subject) { return {}; }
// push_name (concat)
template <auto... Str, auto V, typename... Ts, typename Parameters> static constexpr auto apply(pcre::push_name, ctll::term<V>, pcre_context<ctll::list<id<Str...>, Ts...>, Parameters> subject) { return {}; }
// capture with name
template <auto... Str, auto V, typename A, size_t Id, typename... Ts, size_t Counter> static constexpr auto apply(pcre::make_capture_with_name, ctll::term<V>, pcre_context<ctll::list<A, id<Str...>, capture_id<Id>, Ts...>, pcre_parameters<Counter>>) { return {}; }
// capture with name (sequence)
template <auto... Str, auto V, typename... Content, size_t Id, typename... Ts, size_t Counter> static constexpr auto apply(pcre::make_capture_with_name, ctll::term<V>, pcre_context<ctll::list<sequence<Content...>, id<Str...>, capture_id<Id>, Ts...>, pcre_parameters<Counter>>) { return {}; }


#endif
