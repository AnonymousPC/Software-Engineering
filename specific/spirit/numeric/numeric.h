#pragma once

namespace aux
{
    template < string_type type1, class type2 > class  symbol_map;
    template < class type >                     struct boost_spirit_basic_rule_helper;
    template < class type >                     using  boost_spirit_basic_rule = boost_spirit_basic_rule_helper<type>::type;
}

template < class type >
class numeric_expr;

template < number_type type >
class numeric_expr<type>
{
    public: // Core
        numeric_expr ( );
        numeric_expr ( const numeric_expr& ) = delete;

    public: // Interface
        type                 operator()       ( const string& ) const;
              map_type auto& constant         ( );
        const map_type auto& constant         ( )               const;
              map_type auto& nullary_function ( );
        const map_type auto& nullary_function ( )               const;
              map_type auto& unary_function   ( );
        const map_type auto& unary_function   ( )               const;
              map_type auto& binary_function  ( );
        const map_type auto& binary_function  ( )               const;

    private: // Data
        boost::spirit::qi::grammar<const char*,type(),boost::spirit::ascii::space_type>                              expression;
        boost::spirit::qi::rule   <const char*,type(),boost::spirit::ascii::space_type>                              token_1;
        boost::spirit::qi::rule   <const char*,type(),boost::spirit::ascii::space_type>                              token_2;
        boost::spirit::qi::rule   <const char*,type(),boost::spirit::ascii::space_type>                              token_3;
        boost::spirit::qi::rule   <const char*,type(),boost::spirit::ascii::space_type>                              token_4;
        boost::spirit::qi::rule   <const char*,type(),boost::spirit::ascii::space_type>                              token_5;
        boost::spirit::qi::rule   <const char*,type(),boost::spirit::ascii::space_type>                              token_5_p;
        boost::spirit::qi::rule   <const char*,type(),boost::spirit::ascii::space_type>                              token_6;
        boost::spirit::qi::rule   <const char*,type(),boost::spirit::ascii::space_type>                              token_6_p;
        boost::spirit::qi::symbols<char,type,                     aux::symbol_map<string,type>>                      token_con;
        boost::spirit::qi::symbols<char,function<type()>,         aux::symbol_map<string,function<type()>>>          token_fun_0;
        boost::spirit::qi::symbols<char,function<type(type)>,     aux::symbol_map<string,function<type(type)>>>      token_fun_1;
        boost::spirit::qi::symbols<char,function<type(type,type)>,aux::symbol_map<string,function<type(type,type)>>> token_fun_2;
        aux::boost_spirit_basic_rule<type>                                                                           type_;

    private: // Auxiliary
        static type multiply ( const type&, const type& );
        static type pow      ( const type&, const type& );
};



template < number_type type >
class numeric_expr<type(type)>
{
    public: // Core
        numeric_expr ( );

    public: // Interface
        function<type(type)>    operator()       ( const string& ) const;
              string_type auto& variable         ( );
        const string_type auto& variable         ( )               const;
              map_type    auto& constant         ( );
        const map_type    auto& constant         ( )               const;
              map_type    auto& nullary_function ( );
        const map_type    auto& nullary_function ( )               const;
              map_type    auto& unary_function   ( );
        const map_type    auto& unary_function   ( )               const;
              map_type    auto& binary_function  ( );
        const map_type    auto& binary_function  ( )               const;

    private: // Data
        template < int index > class var_con_map;
        string                                                                                                       var;
        map <string,type>                                                                                            con;
        boost::spirit::qi::grammar<const char*,function<type(type)>(),boost::spirit::ascii::space_type>              expression;
        boost::spirit::qi::rule   <const char*,function<type(type)>(),boost::spirit::ascii::space_type>              token_1;
        boost::spirit::qi::rule   <const char*,function<type(type)>(),boost::spirit::ascii::space_type>              token_2;
        boost::spirit::qi::rule   <const char*,function<type(type)>(),boost::spirit::ascii::space_type>              token_3;
        boost::spirit::qi::rule   <const char*,function<type(type)>(),boost::spirit::ascii::space_type>              token_4;
        boost::spirit::qi::rule   <const char*,function<type(type)>(),boost::spirit::ascii::space_type>              token_5;
        boost::spirit::qi::rule   <const char*,function<type(type)>(),boost::spirit::ascii::space_type>              token_5_p;
        boost::spirit::qi::rule   <const char*,function<type(type)>(),boost::spirit::ascii::space_type>              token_6;
        boost::spirit::qi::rule   <const char*,function<type(type)>(),boost::spirit::ascii::space_type>              token_6_p;
        boost::spirit::qi::symbols<char,function<type(type)>,     var_con_map<1>>                                    token_var;
        boost::spirit::qi::symbols<char,type,                     var_con_map<2>>                                    token_con;
        boost::spirit::qi::symbols<char,function<type()>,         aux::symbol_map<string,function<type()>>>          token_fun_0;
        boost::spirit::qi::symbols<char,function<type(type)>,     aux::symbol_map<string,function<type(type)>>>      token_fun_1;
        boost::spirit::qi::symbols<char,function<type(type,type)>,aux::symbol_map<string,function<type(type,type)>>> token_fun_2;
        aux::boost_spirit_basic_rule<type>                                                                           type_;

    private: // Auxiliary
        static function<type(type)> add         ( const function<type(type)>&, const function<type(type)>& );
        static function<type(type)> minus       ( const function<type(type)>&, const function<type(type)>& );
        static function<type(type)> multiply    ( const function<type(type)>&, const function<type(type)>& );
        static function<type(type)> divide      ( const function<type(type)>&, const function<type(type)>& );
        static function<type(type)> pow         ( const function<type(type)>&, const function<type(type)>& );
        static function<type(type)> unary_add   ( const function<type(type)>& );
        static function<type(type)> unary_minus ( const function<type(type)>& );
        static function<type(type)> make_con    ( const type& );
        static function<type(type)> make_fun_0  ( const function<type()>&                                                                    );
        static function<type(type)> make_fun_1  ( const function<type(type)>&,      const function<type(type)>&                              );
        static function<type(type)> make_fun_2  ( const function<type(type,type)>&, const function<type(type)>&, const function<type(type)>& );
};



template < number_type type >
class numeric_expr<type(type,type)>
{
    public: // Core
        numeric_expr ( );

    public: // Interface
        function<type(type,type)> operator()     ( const string& ) const;
              pair_type   auto& variable         ( );
        const pair_type   auto& variable         ( )               const;
              map_type    auto& constant         ( );
        const map_type    auto& constant         ( )               const;
              map_type    auto& nullary_function ( );
        const map_type    auto& nullary_function ( )               const;
              map_type    auto& unary_function   ( );
        const map_type    auto& unary_function   ( )               const;
              map_type    auto& binary_function  ( );
        const map_type    auto& binary_function  ( )               const;

    private: // Data
        template < int index > class var_con_map;
        pair<string,string>                                                                                               var;
        map <string,type>                                                                                                 con;
        boost::spirit::qi::grammar<const char*,function<type(type,type)>(),boost::spirit::ascii::space_type>              expression;
        boost::spirit::qi::rule   <const char*,function<type(type,type)>(),boost::spirit::ascii::space_type>              token_1;
        boost::spirit::qi::rule   <const char*,function<type(type,type)>(),boost::spirit::ascii::space_type>              token_2;
        boost::spirit::qi::rule   <const char*,function<type(type,type)>(),boost::spirit::ascii::space_type>              token_3;
        boost::spirit::qi::rule   <const char*,function<type(type,type)>(),boost::spirit::ascii::space_type>              token_4;
        boost::spirit::qi::rule   <const char*,function<type(type,type)>(),boost::spirit::ascii::space_type>              token_5;
        boost::spirit::qi::rule   <const char*,function<type(type,type)>(),boost::spirit::ascii::space_type>              token_5_p;
        boost::spirit::qi::rule   <const char*,function<type(type,type)>(),boost::spirit::ascii::space_type>              token_6;
        boost::spirit::qi::rule   <const char*,function<type(type,type)>(),boost::spirit::ascii::space_type>              token_6_p;
        boost::spirit::qi::symbols<char,function<type(type,type)>,     var_con_map<1>>                                    token_var;
        boost::spirit::qi::symbols<char,type,                          var_con_map<2>>                                    token_con;
        boost::spirit::qi::symbols<char,function<type()>,              aux::symbol_map<string,function<type()>>>          token_fun_0;
        boost::spirit::qi::symbols<char,function<type(type)>,          aux::symbol_map<string,function<type(type)>>>      token_fun_1;
        boost::spirit::qi::symbols<char,function<type(type,type)>,     aux::symbol_map<string,function<type(type,type)>>> token_fun_2;
        aux::boost_spirit_basic_rule<type>                                                                                type_;

    private: // Auxiliary
        static function<type(type,type)> add         ( const function<type(type,type)>&, const function<type(type,type)>& );
        static function<type(type,type)> minus       ( const function<type(type,type)>&, const function<type(type,type)>& );
        static function<type(type,type)> multiply    ( const function<type(type,type)>&, const function<type(type,type)>& );
        static function<type(type,type)> divide      ( const function<type(type,type)>&, const function<type(type,type)>& );
        static function<type(type,type)> pow         ( const function<type(type,type)>&, const function<type(type,type)>& );
        static function<type(type,type)> unary_add   ( const function<type(type,type)>& );
        static function<type(type,type)> unary_minus ( const function<type(type,type)>& );
        static function<type(type,type)> make_con    ( const type& );
        static function<type(type,type)> make_fun_0  ( const function<type()>&                                                                              );
        static function<type(type,type)> make_fun_1  ( const function<type(type)>&,      const function<type(type,type)>&                                   );
        static function<type(type,type)> make_fun_2  ( const function<type(type,type)>&, const function<type(type,type)>&, const function<type(type,type)>& );
};



#include "numeric.cpp"


