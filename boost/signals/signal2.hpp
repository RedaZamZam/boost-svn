// Boost.Signals library

// Copyright Doug Gregor 2001-2003. Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// For more information, see http://www.boost.org

#ifndef BOOST_SIGNALS_SIGNAL2_HEADER
#define BOOST_SIGNALS_SIGNAL2_HEADER

#define BOOST_SIGNALS_NUM_ARGS 2
#define BOOST_SIGNALS_TEMPLATE_PARMS typename T1, typename T2
#define BOOST_SIGNALS_TEMPLATE_ARGS T1, T2
#define BOOST_SIGNALS_PARMS T1 a1, T2 a2
#define BOOST_SIGNALS_ARGS a1, a2
#define BOOST_SIGNALS_BOUND_ARGS args->a1, args->a2
#define BOOST_SIGNALS_ARGS_AS_MEMBERS T1 a1;T2 a2;
#define BOOST_SIGNALS_COPY_PARMS T1 ia1, T2 ia2
#define BOOST_SIGNALS_INIT_ARGS :a1(ia1), a2(ia2)
#define BOOST_SIGNALS_ARG_TYPES typedef T1 arg2_type; typedef T2 arg3_type;

#include <boost/signals/signal_template.hpp>

#undef BOOST_SIGNALS_ARG_TYPES
#undef BOOST_SIGNALS_INIT_ARGS
#undef BOOST_SIGNALS_COPY_PARMS
#undef BOOST_SIGNALS_ARGS_AS_MEMBERS
#undef BOOST_SIGNALS_BOUND_ARGS
#undef BOOST_SIGNALS_ARGS
#undef BOOST_SIGNALS_PARMS
#undef BOOST_SIGNALS_TEMPLATE_ARGS
#undef BOOST_SIGNALS_TEMPLATE_PARMS
#undef BOOST_SIGNALS_NUM_ARGS

#endif // BOOST_SIGNALS_SIGNAL2_HEADER
