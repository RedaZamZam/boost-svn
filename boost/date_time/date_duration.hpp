#ifndef DATE_TIME_DATE_DURATION__
#define DATE_TIME_DATE_DURATION__
/* Copyright (c) 2000, 2003 CrystalClear Software, Inc.
 * Disclaimer & Full Copyright at end of file
 * Author: Jeff Garland, Bart Garst
 */


#include <boost/operators.hpp>

namespace boost {
namespace date_time {
  

  //! Duration type with date level resolution
  template<class duration_rep_traits>
  class date_duration : private
      boost::less_than_comparable<date_duration< duration_rep_traits> 
    , boost::equality_comparable< date_duration< duration_rep_traits>
    , boost::addable< date_duration< duration_rep_traits>
    , boost::subtractable< date_duration< duration_rep_traits>
    > > > >
  {
  public:
    typedef typename duration_rep_traits::int_type duration_rep_type;
    typedef typename duration_rep_traits::impl_type duration_rep;

    //! Construct from a day count
    explicit date_duration(duration_rep day_count) : days_(day_count) {};

    /*! construct from special_values - only works when 
     * instantiated with duration_traits_adapted */
    date_duration(special_values sv) : 
      days_(duration_rep::from_special(sv)) 
    {} 

    // copy constructor required for addable<> & subtractable<>
    //! Construct from another date_duration (Copy Constructor)
    date_duration(const date_duration<duration_rep_traits>& other) : 
      days_(other.days_)
    {}

    //! returns days_ as it's instantiated type - used for streaming
    duration_rep get_rep()const
    {
      return days_;
    }
    bool is_special()const
    {
      return days_.is_special();
    }
    //! returns days as value, not object.
    duration_rep_type days() const 
    {
      return duration_rep_traits::as_number(days_);
    }
    //! Returns the smallest duration -- used by to calculate 'end'
    static date_duration unit()
    {
      return date_duration<duration_rep_traits>(1);
    }
    //! Equality 
    bool operator==(const date_duration& rhs) const 
    {
      return days_ == rhs.days_;
    }
    //! Less 
    bool operator<(const date_duration& rhs) const 
    {
      return days_ < rhs.days_;
    }
	
    /* For shortcut operators (+=, -=, etc) simply using
     * "days_ += days_" may not work. If instantiated with
     * an int_adapter, shortcut operators are not present,
     * so this will not compile */
    
    //! Subtract another duration -- result is signed
    date_duration operator-=(const date_duration& rhs)
    {
      //days_ -= rhs.days_;
      days_ = days_ - rhs.days_;
      return *this;
    }
    //! Add a duration -- result is signed
    date_duration operator+=(const date_duration& rhs)
    {
      days_ = days_ + rhs.days_;
      return *this;
    }

    //! unary- Allows for dd = -date_duration(2); -> dd == -2
    date_duration operator-()const
    {
      return date_duration<duration_rep_traits>(get_rep() * (-1));
    }
    //! Division operations on a duration with an integer.
    date_duration<duration_rep_traits> operator/=(int divisor)
    {
      days_ = days_ / divisor;
      return *this;
    }
    date_duration<duration_rep_traits> operator/(int divisor)
    {
      return date_duration<duration_rep_traits>(days_ / divisor);
    }
    
    //! return sign information
    bool is_negative() const
    {
      return days_ < 0;
    }
  private:
    duration_rep days_;
  };  


  /*! Struct for instantiating date_duration with <b>NO</b> special values
   * functionality. Allows for transparent implementation of either
   * date_duration<long> or date_duration<int_adapter<long> > */
  struct duration_traits_long {
     typedef long int_type;
     typedef long impl_type;
     static int_type as_number(impl_type i) { return i; };
   };

  /*! Struct for instantiating date_duration <b>WITH</b> special values
   * functionality. Allows for transparent implementation of either
   * date_duration<long> or date_duration<int_adapter<long> > */
   struct duration_traits_adapted{
     typedef long int_type;
     typedef boost::date_time::int_adapter<long> impl_type;
     static int_type as_number(impl_type i) { return i.as_number(); };
   };


} } //namspace date_time

/* Copyright (c) 2000, 2001
 * CrystalClear Software, Inc.
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  CrystalClear Software makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 */

#endif

