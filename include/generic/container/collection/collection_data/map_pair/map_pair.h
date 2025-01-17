#pragma once

template < class type1, class type2 >
class map_pair
    extends public pair<const type1,type2>
{
    public: // Typedef
        struct pair_tag { };

    public: // Core
        using pair<const type1,type2>::pair;
        constexpr map_pair ( const map_pair&  ) = default;
        constexpr map_pair (       map_pair&& );
        constexpr map_pair& operator = ( const map_pair&  );
        constexpr map_pair& operator = (       map_pair&& );

    public: // Conversion
        template < class type3, class type4 >
        constexpr map_pair ( pair<type3,type4>&& )
            requires ( std::is_same<typename std::decay<type1>::type,typename std::decay<type3>::type>::value and
                       std::is_same<typename std::decay<type2>::type,typename std::decay<type4>::type>::value );
};

#include "map_pair.cpp"
