#pragma once
#include "error.h"
#include "concept.h"

/** Some notes:
  * Category 2 types of range by minusable<type> instead of
  * initializer ways avoids crashes below:
  *
  * for ( float i in range ( 1.0, 2.5 ) ) ...;
  *
  * In initializer category mode, here decltype(range::step) == int, and
  * second scope in ( auto iter = range.begin(), "iter != range.end()" )
  * calls iter -> data != range.end() -> data instead of operator <=. Thus,
  * an unexpected infinity for scope occured.
  */


/// Range (raw: no definition)

template < class type, bool continuous = false >
class range;



/// Range with continuous == true

template < class type >
    requires minusable<type>
class range<type,true>
{
    public: // Typedef
        using value_type      = type;
        using difference_type = minus_result<type,type>;
        class iterator;
        using const_iterator  = iterator;
        struct range_tag { };

    private: // Data
        value_type low  = type();
        value_type high = type();

    public: // Core
        constexpr range ( ) = default;
        constexpr range ( value_type );
        constexpr range ( value_type, value_type );

    public: // Conversion
        constexpr operator range<type,false> ( ) const;

    public: // Member
        constexpr iterator    begin       ( )     const;
        constexpr iterator    end         ( )     const;
        constexpr int         size        ( )     const;
        constexpr bool        empty       ( )     const;

        constexpr       type  operator [] ( int ) const;
        constexpr const type& min         ( )     const;
        constexpr const type& max         ( )     const;
};

template < class type >
    requires minusable<type>
class range<type,true>::iterator
{
    public: // Typedef
        using iterator_category = std::random_access_iterator_tag;
        using value_type        = range<type>::value_type;
        using difference_type   = range<type>::difference_type;
        using pointer           = type*;
        using reference         = type&;

    private: // Data
        type data;

    public: // Core
        constexpr iterator ( type );
        constexpr iterator ( const iterator& ) = default;
        constexpr type&     operator *  ( );
        constexpr type*     operator -> ( );
        constexpr bool      operator != ( const iterator& ) const;
        constexpr iterator& operator ++ ( );
        constexpr iterator  operator ++ ( int );
        constexpr iterator& operator -- ( );
        constexpr iterator  operator -- ( int );
        constexpr iterator  operator +  ( int ) const;
        constexpr iterator  operator -  ( int ) const;
        constexpr int       operator -  ( const iterator& ) const;
};







/// Range with continuous == false

template < class type >
    requires minusable<type>
class range<type>
{
    public: // Typedef
        using value_type      = type;
        using difference_type = minus_result<type,type>;
        class iterator;
        using const_iterator  = iterator;
        struct range_tag { };

    private: // Range
        value_type      low  = type();
        value_type      high = type();
        difference_type step = type();

    public: // Constructor
        constexpr range ( ) = default;
        constexpr range ( value_type );
        constexpr range ( value_type, value_type, difference_type = 1 );

    public: // Member
        constexpr iterator begin ( ) const;
        constexpr iterator end   ( ) const;
        constexpr int      size  ( ) const;
        constexpr bool     empty ( ) const;

        constexpr       value_type  operator [] ( int ) const;
        constexpr const value_type&      min ( ) const;
        constexpr const value_type&      max ( ) const;
        constexpr const difference_type& sep ( ) const;
};

template < class type >
    requires minusable<type>
class range<type>::iterator
{
    public: // Typedef
        using iterator_category = std::random_access_iterator_tag;
        using value_type        = range<type>::value_type;
        using difference_type   = range<type>::difference_type;
        using pointer           = value_type*;
        using reference         = value_type&;

    private: // Data
        value_type      data;
        difference_type step;

    public: // Core
        constexpr iterator ( value_type, difference_type );
        constexpr iterator ( const iterator& ) = default;
        constexpr type&     operator *  ( );
        constexpr type*     operator -> ( );
        constexpr bool      operator != ( const iterator& ) const;
        constexpr iterator& operator ++ ( );
        constexpr iterator  operator ++ ( int );
        constexpr iterator& operator -- ( );
        constexpr iterator  operator -- ( int );
        constexpr iterator  operator +  ( int ) const;
        constexpr iterator  operator -  ( int ) const;
        constexpr int       operator -  ( const iterator& ) const;
};







/// Template deduction

template < class type > range ( type )                                -> range<type,true>;
template < class type > range ( type, type )                          -> range<type,true>;
template < class type > range ( type, type, minus_result<type,type> ) -> range<type>;

                        range ( size_t                 ) -> range<int,true>; // 0
                        range ( size_t, size_t         ) -> range<int,true>; // 00
                        range ( size_t, int            ) -> range<int,true>; // 01
                        range ( int,    size_t         ) -> range<int,true>; // 10
                        range ( size_t, size_t, size_t ) -> range<int>;      // 000
                        range ( size_t, size_t, int    ) -> range<int>;      // 001
                        range ( size_t, int,    size_t ) -> range<int>;      // 010
                        range ( size_t, int,    int    ) -> range<int>;      // 011
                        range ( int,    size_t, size_t ) -> range<int>;      // 100
                        range ( int,    size_t, int    ) -> range<int>;      // 101
                        range ( int,    int,    size_t ) -> range<int>;      // 111;

#include "range.cpp"
