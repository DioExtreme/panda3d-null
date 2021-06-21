/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         dnayyparse
#define yylex           dnayylex
#define yyerror         dnayyerror
#define yydebug         dnayydebug
#define yynerrs         dnayynerrs
#define yylval          dnayylval
#define yychar          dnayychar

/* First part of user prologue.  */
#line 1 "dna.yxx"

#include "dnaLexerDefs.h"
#include "dnaParserDefs.h"

// #define DO_YYDEBUG

#ifdef DO_YYDEBUG
#define YYDEBUG 1
#endif
#include "dna_yxx.hxx"

#include "DNAVisGroup.h"
#include "DNANode.h"
#include "DNAProp.h"
#include "DNASign.h"
#include "DNASignText.h"
#include "DNASignBaseline.h"
#include "DNASignGraphic.h"
#include "DNAWall.h"
#include "DNAWindows.h"
#include "DNALandmarkBuilding.h"
#include "DNAFlatBuilding.h"
#include "DNADoor.h"
#include "DNAFlatDoor.h"
#include "DNAStreet.h"
#include "DNAAnimBuilding.h"
#include "DNAAnimProp.h"
#include "DNAInteractiveProp.h"
#include "DNACornice.h"

#include "texturePool.h"
#include "fontPool.h"

// Because our token type contains objects of type string, which
// require correct copy construction (and not simply memcpying), we
// cannot use bison's built-in auto-stack-grow feature.  As an easy
// solution, we ensure here that we have enough yacc stack to start
// with, and that it doesn't ever try to grow.
#define YYINITDEPTH 1000
#define YYMAXDEPTH 1000

////////////////////////////////////////////////////////////////////
// Static variables
////////////////////////////////////////////////////////////////////

static DNALoader* _loader = nullptr;
static DNAStorage* _store = nullptr;
static PT(DNAGroup) _cur_comp = nullptr;
static PT(DNAGroup) _sign_text = nullptr;
static std::string _model_name, _model_type;

////////////////////////////////////////////////////////////////////
// Defining the interface to the parser.
////////////////////////////////////////////////////////////////////

void dna_init_parser(std::istream &in, const std::string &filename,
                     DNALoader* loader, DNAStorage* store,
                     PT(DNAGroup) root) {
#ifdef DO_YYDEBUG
  dnayydebug = 1;
#endif
  dna_init_lexer(in, filename);
  _loader = loader;
  _store = store;
  _cur_comp = root;
}

void dna_cleanup_parser() {
  _loader = nullptr;
  _store = nullptr;
  _cur_comp = nullptr;
  _sign_text = nullptr;
  _model_name = "";
  _model_type = "";
}

static void _store_model(const std::string& root, const std::string &code, const std::string& search) {
  _store->store_catalog_code(root, code);

  Filename filename(_model_name);
  if (!filename.get_extension().size())
    filename.set_extension("bam");

  if (_model_type == "hood_model")
    _store->store_hood_node(filename, search, code);

  else if (_model_type == "place_model")
    _store->store_place_node(filename, search, code);

  else
    _store->store_node(filename, search, code);
}

static block_number_t _get_visgroup_zoneid(PT(DNAGroup) g) {
  if (!g->get_vis_group()) {
    dnayywarning("landmarkbuilding not in visgroup");
    return 0;
  }

  std::string name = g->get_vis_group()->get_name();
  auto idx = name.find(':');
  if (idx != std::string::npos)
    name = name.substr(0, idx);

  return atoi(name.c_str());
}


#line 187 "dna_yxx.cxx"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "dna_yxx.hxx"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SIGNED_INTEGER = 3,             /* SIGNED_INTEGER  */
  YYSYMBOL_UNSIGNED_INTEGER = 4,           /* UNSIGNED_INTEGER  */
  YYSYMBOL_FLOAT_REAL = 5,                 /* FLOAT_REAL  */
  YYSYMBOL_UNQUOTED_STRING = 6,            /* UNQUOTED_STRING  */
  YYSYMBOL_QUOTED_STRING = 7,              /* QUOTED_STRING  */
  YYSYMBOL_STORE_SUIT_POINT = 8,           /* STORE_SUIT_POINT  */
  YYSYMBOL_GROUP = 9,                      /* GROUP  */
  YYSYMBOL_VISGROUP = 10,                  /* VISGROUP  */
  YYSYMBOL_VIS = 11,                       /* VIS  */
  YYSYMBOL_DNA_STREET_POINT = 12,          /* DNA_STREET_POINT  */
  YYSYMBOL_DNA_FRONT_DOOR_POINT = 13,      /* DNA_FRONT_DOOR_POINT  */
  YYSYMBOL_DNA_SIDE_DOOR_POINT = 14,       /* DNA_SIDE_DOOR_POINT  */
  YYSYMBOL_DNA_COGHQ_IN_POINT = 15,        /* DNA_COGHQ_IN_POINT  */
  YYSYMBOL_DNA_COGHQ_OUT_POINT = 16,       /* DNA_COGHQ_OUT_POINT  */
  YYSYMBOL_SUIT_EDGE = 17,                 /* SUIT_EDGE  */
  YYSYMBOL_BATTLE_CELL = 18,               /* BATTLE_CELL  */
  YYSYMBOL_PROP = 19,                      /* PROP  */
  YYSYMBOL_POS = 20,                       /* POS  */
  YYSYMBOL_HPR = 21,                       /* HPR  */
  YYSYMBOL_SCALE = 22,                     /* SCALE  */
  YYSYMBOL_CODE = 23,                      /* CODE  */
  YYSYMBOL_COLOR = 24,                     /* COLOR  */
  YYSYMBOL_MODEL = 25,                     /* MODEL  */
  YYSYMBOL_STORE_NODE = 26,                /* STORE_NODE  */
  YYSYMBOL_SIGN = 27,                      /* SIGN  */
  YYSYMBOL_BASELINE = 28,                  /* BASELINE  */
  YYSYMBOL_WIDTH = 29,                     /* WIDTH  */
  YYSYMBOL_HEIGHT = 30,                    /* HEIGHT  */
  YYSYMBOL_STOMP = 31,                     /* STOMP  */
  YYSYMBOL_STUMBLE = 32,                   /* STUMBLE  */
  YYSYMBOL_INDENT = 33,                    /* INDENT  */
  YYSYMBOL_WIGGLE = 34,                    /* WIGGLE  */
  YYSYMBOL_KERN = 35,                      /* KERN  */
  YYSYMBOL_TEXT = 36,                      /* TEXT  */
  YYSYMBOL_LETTERS = 37,                   /* LETTERS  */
  YYSYMBOL_STORE_FONT = 38,                /* STORE_FONT  */
  YYSYMBOL_FLAT_BUILDING = 39,             /* FLAT_BUILDING  */
  YYSYMBOL_WALL = 40,                      /* WALL  */
  YYSYMBOL_WINDOWS = 41,                   /* WINDOWS  */
  YYSYMBOL_COUNT = 42,                     /* COUNT  */
  YYSYMBOL_CORNICE = 43,                   /* CORNICE  */
  YYSYMBOL_LANDMARK_BUILDING = 44,         /* LANDMARK_BUILDING  */
  YYSYMBOL_TITLE = 45,                     /* TITLE  */
  YYSYMBOL_ARTICLE = 46,                   /* ARTICLE  */
  YYSYMBOL_BUILDING_TYPE = 47,             /* BUILDING_TYPE  */
  YYSYMBOL_DOOR = 48,                      /* DOOR  */
  YYSYMBOL_STORE_TEXTURE = 49,             /* STORE_TEXTURE  */
  YYSYMBOL_STREET = 50,                    /* STREET  */
  YYSYMBOL_TEXTURE = 51,                   /* TEXTURE  */
  YYSYMBOL_GRAPHIC = 52,                   /* GRAPHIC  */
  YYSYMBOL_HOODMODEL = 53,                 /* HOODMODEL  */
  YYSYMBOL_PLACEMODEL = 54,                /* PLACEMODEL  */
  YYSYMBOL_FLAGS = 55,                     /* FLAGS  */
  YYSYMBOL_NODE = 56,                      /* NODE  */
  YYSYMBOL_FLAT_DOOR = 57,                 /* FLAT_DOOR  */
  YYSYMBOL_ANIM = 58,                      /* ANIM  */
  YYSYMBOL_CELL_ID = 59,                   /* CELL_ID  */
  YYSYMBOL_ANIM_PROP = 60,                 /* ANIM_PROP  */
  YYSYMBOL_INTERACTIVE_PROP = 61,          /* INTERACTIVE_PROP  */
  YYSYMBOL_ANIM_BUILDING = 62,             /* ANIM_BUILDING  */
  YYSYMBOL_63_ = 63,                       /* '['  */
  YYSYMBOL_64_ = 64,                       /* ','  */
  YYSYMBOL_65_ = 65,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_dna = 67,                       /* dna  */
  YYSYMBOL_object = 68,                    /* object  */
  YYSYMBOL_number = 69,                    /* number  */
  YYSYMBOL_lpoint3f = 70,                  /* lpoint3f  */
  YYSYMBOL_suitpoint = 71,                 /* suitpoint  */
  YYSYMBOL_suitpointtype = 72,             /* suitpointtype  */
  YYSYMBOL_string = 73,                    /* string  */
  YYSYMBOL_dnagroupdef = 74,               /* dnagroupdef  */
  YYSYMBOL_dnanodedef = 75,                /* dnanodedef  */
  YYSYMBOL_visgroupdef = 76,               /* visgroupdef  */
  YYSYMBOL_dnagroup = 77,                  /* dnagroup  */
  YYSYMBOL_visgroup = 78,                  /* visgroup  */
  YYSYMBOL_string_opt_list = 79,           /* string_opt_list  */
  YYSYMBOL_vis = 80,                       /* vis  */
  YYSYMBOL_empty = 81,                     /* empty  */
  YYSYMBOL_group = 82,                     /* group  */
  YYSYMBOL_dnanode = 83,                   /* dnanode  */
  YYSYMBOL_dnanode_grp = 84,               /* dnanode_grp  */
  YYSYMBOL_sign = 85,                      /* sign  */
  YYSYMBOL_signgraphic = 86,               /* signgraphic  */
  YYSYMBOL_prop = 87,                      /* prop  */
  YYSYMBOL_signbaseline = 88,              /* signbaseline  */
  YYSYMBOL_signtext = 89,                  /* signtext  */
  YYSYMBOL_flatbuilding = 90,              /* flatbuilding  */
  YYSYMBOL_wall = 91,                      /* wall  */
  YYSYMBOL_windows = 92,                   /* windows  */
  YYSYMBOL_cornice = 93,                   /* cornice  */
  YYSYMBOL_landmarkbuilding = 94,          /* landmarkbuilding  */
  YYSYMBOL_street = 95,                    /* street  */
  YYSYMBOL_door = 96,                      /* door  */
  YYSYMBOL_propdef = 97,                   /* propdef  */
  YYSYMBOL_animpropdef = 98,               /* animpropdef  */
  YYSYMBOL_interactivepropdef = 99,        /* interactivepropdef  */
  YYSYMBOL_flatbuildingdef = 100,          /* flatbuildingdef  */
  YYSYMBOL_walldef = 101,                  /* walldef  */
  YYSYMBOL_windowsdef = 102,               /* windowsdef  */
  YYSYMBOL_cornicedef = 103,               /* cornicedef  */
  YYSYMBOL_landmarkbuildingdef = 104,      /* landmarkbuildingdef  */
  YYSYMBOL_animbuildingdef = 105,          /* animbuildingdef  */
  YYSYMBOL_doordef = 106,                  /* doordef  */
  YYSYMBOL_flatdoordef = 107,              /* flatdoordef  */
  YYSYMBOL_streetdef = 108,                /* streetdef  */
  YYSYMBOL_signdef = 109,                  /* signdef  */
  YYSYMBOL_signgraphicdef = 110,           /* signgraphicdef  */
  YYSYMBOL_baselinedef = 111,              /* baselinedef  */
  YYSYMBOL_textdef = 112,                  /* textdef  */
  YYSYMBOL_suitedge = 113,                 /* suitedge  */
  YYSYMBOL_battlecell = 114,               /* battlecell  */
  YYSYMBOL_subgroup_list = 115,            /* subgroup_list  */
  YYSYMBOL_subvisgroup_list = 116,         /* subvisgroup_list  */
  YYSYMBOL_pos = 117,                      /* pos  */
  YYSYMBOL_hpr = 118,                      /* hpr  */
  YYSYMBOL_scale = 119,                    /* scale  */
  YYSYMBOL_flags = 120,                    /* flags  */
  YYSYMBOL_dnanode_sub = 121,              /* dnanode_sub  */
  YYSYMBOL_dnaprop_sub = 122,              /* dnaprop_sub  */
  YYSYMBOL_dnaanimprop_sub = 123,          /* dnaanimprop_sub  */
  YYSYMBOL_dnainteractiveprop_sub = 124,   /* dnainteractiveprop_sub  */
  YYSYMBOL_anim = 125,                     /* anim  */
  YYSYMBOL_baseline_sub = 126,             /* baseline_sub  */
  YYSYMBOL_text_sub = 127,                 /* text_sub  */
  YYSYMBOL_signgraphic_sub = 128,          /* signgraphic_sub  */
  YYSYMBOL_flatbuilding_sub = 129,         /* flatbuilding_sub  */
  YYSYMBOL_wall_sub = 130,                 /* wall_sub  */
  YYSYMBOL_windows_sub = 131,              /* windows_sub  */
  YYSYMBOL_cornice_sub = 132,              /* cornice_sub  */
  YYSYMBOL_landmarkbuilding_sub = 133,     /* landmarkbuilding_sub  */
  YYSYMBOL_animbuilding_sub = 134,         /* animbuilding_sub  */
  YYSYMBOL_door_sub = 135,                 /* door_sub  */
  YYSYMBOL_street_sub = 136,               /* street_sub  */
  YYSYMBOL_texture = 137,                  /* texture  */
  YYSYMBOL_street_color = 138,             /* street_color  */
  YYSYMBOL_title = 139,                    /* title  */
  YYSYMBOL_article = 140,                  /* article  */
  YYSYMBOL_building_type = 141,            /* building_type  */
  YYSYMBOL_lb_wall_color = 142,            /* lb_wall_color  */
  YYSYMBOL_ab_anim = 143,                  /* ab_anim  */
  YYSYMBOL_windowcount = 144,              /* windowcount  */
  YYSYMBOL_baseline_width = 145,           /* baseline_width  */
  YYSYMBOL_signgraphic_width = 146,        /* signgraphic_width  */
  YYSYMBOL_flatbuilding_width = 147,       /* flatbuilding_width  */
  YYSYMBOL_baseline_height = 148,          /* baseline_height  */
  YYSYMBOL_signgraphic_height = 149,       /* signgraphic_height  */
  YYSYMBOL_wall_height = 150,              /* wall_height  */
  YYSYMBOL_stomp = 151,                    /* stomp  */
  YYSYMBOL_indent = 152,                   /* indent  */
  YYSYMBOL_kern = 153,                     /* kern  */
  YYSYMBOL_stumble = 154,                  /* stumble  */
  YYSYMBOL_wiggle = 155,                   /* wiggle  */
  YYSYMBOL_prop_code = 156,                /* prop_code  */
  YYSYMBOL_landmarkbuilding_code = 157,    /* landmarkbuilding_code  */
  YYSYMBOL_baseline_code = 158,            /* baseline_code  */
  YYSYMBOL_door_code = 159,                /* door_code  */
  YYSYMBOL_signgraphic_code = 160,         /* signgraphic_code  */
  YYSYMBOL_cornice_code = 161,             /* cornice_code  */
  YYSYMBOL_street_code = 162,              /* street_code  */
  YYSYMBOL_wall_code = 163,                /* wall_code  */
  YYSYMBOL_windows_code = 164,             /* windows_code  */
  YYSYMBOL_prop_color = 165,               /* prop_color  */
  YYSYMBOL_baseline_color = 166,           /* baseline_color  */
  YYSYMBOL_door_color = 167,               /* door_color  */
  YYSYMBOL_signgraphic_color = 168,        /* signgraphic_color  */
  YYSYMBOL_cornice_color = 169,            /* cornice_color  */
  YYSYMBOL_wall_color = 170,               /* wall_color  */
  YYSYMBOL_windows_color = 171,            /* windows_color  */
  YYSYMBOL_subprop_list = 172,             /* subprop_list  */
  YYSYMBOL_subanimprop_list = 173,         /* subanimprop_list  */
  YYSYMBOL_subinteractiveprop_list = 174,  /* subinteractiveprop_list  */
  YYSYMBOL_subbaseline_list = 175,         /* subbaseline_list  */
  YYSYMBOL_subtext_list = 176,             /* subtext_list  */
  YYSYMBOL_subdnanode_list = 177,          /* subdnanode_list  */
  YYSYMBOL_subsigngraphic_list = 178,      /* subsigngraphic_list  */
  YYSYMBOL_subflatbuilding_list = 179,     /* subflatbuilding_list  */
  YYSYMBOL_subwall_list = 180,             /* subwall_list  */
  YYSYMBOL_subwindows_list = 181,          /* subwindows_list  */
  YYSYMBOL_subcornice_list = 182,          /* subcornice_list  */
  YYSYMBOL_sublandmarkbuilding_list = 183, /* sublandmarkbuilding_list  */
  YYSYMBOL_subanimbuilding_list = 184,     /* subanimbuilding_list  */
  YYSYMBOL_subdoor_list = 185,             /* subdoor_list  */
  YYSYMBOL_substreet_list = 186,           /* substreet_list  */
  YYSYMBOL_modeldef = 187,                 /* modeldef  */
  YYSYMBOL_model = 188,                    /* model  */
  YYSYMBOL_modelnode_list = 189,           /* modelnode_list  */
  YYSYMBOL_node = 190,                     /* node  */
  YYSYMBOL_store_texture = 191,            /* store_texture  */
  YYSYMBOL_font = 192                      /* font  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  87
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1328

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  127
/* YYNRULES -- Number of rules.  */
#define YYNRULES  230
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  496

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    64,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    65,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   181,   181,   182,   185,   186,   187,   188,   189,   192,
     196,   200,   205,   211,   216,   222,   227,   232,   237,   242,
     248,   252,   257,   266,   275,   284,   289,   294,   299,   304,
     311,   314,   315,   316,   317,   318,   319,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   334,   339,   344,
     349,   353,   357,   362,   367,   370,   375,   380,   385,   390,
     394,   399,   404,   408,   413,   422,   431,   440,   449,   458,
     467,   476,   490,   504,   513,   523,   532,   541,   550,   560,
     571,   580,   586,   587,   590,   591,   592,   593,   594,   597,
     602,   607,   612,   617,   618,   619,   620,   623,   624,   627,
     630,   635,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   649,   652,   657,   658,   659,   660,   663,   666,   667,
     668,   671,   672,   673,   676,   677,   680,   681,   682,   683,
     684,   687,   690,   691,   694,   695,   696,   699,   704,   710,
     717,   724,   731,   737,   742,   747,   752,   757,   762,   767,
     772,   777,   782,   787,   792,   797,   802,   807,   812,   817,
     822,   827,   832,   837,   842,   847,   853,   859,   865,   871,
     877,   883,   889,   890,   891,   894,   895,   896,   897,   900,
     901,   902,   903,   904,   907,   908,   909,   912,   913,   914,
     917,   918,   921,   922,   923,   926,   927,   928,   931,   932,
     933,   936,   937,   938,   941,   942,   943,   946,   947,   948,
     951,   952,   953,   954,   957,   958,   959,   962,   963,   964,
     967,   972,   977,   983,   986,   987,   990,   994,   999,  1003,
    1009
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SIGNED_INTEGER",
  "UNSIGNED_INTEGER", "FLOAT_REAL", "UNQUOTED_STRING", "QUOTED_STRING",
  "STORE_SUIT_POINT", "GROUP", "VISGROUP", "VIS", "DNA_STREET_POINT",
  "DNA_FRONT_DOOR_POINT", "DNA_SIDE_DOOR_POINT", "DNA_COGHQ_IN_POINT",
  "DNA_COGHQ_OUT_POINT", "SUIT_EDGE", "BATTLE_CELL", "PROP", "POS", "HPR",
  "SCALE", "CODE", "COLOR", "MODEL", "STORE_NODE", "SIGN", "BASELINE",
  "WIDTH", "HEIGHT", "STOMP", "STUMBLE", "INDENT", "WIGGLE", "KERN",
  "TEXT", "LETTERS", "STORE_FONT", "FLAT_BUILDING", "WALL", "WINDOWS",
  "COUNT", "CORNICE", "LANDMARK_BUILDING", "TITLE", "ARTICLE",
  "BUILDING_TYPE", "DOOR", "STORE_TEXTURE", "STREET", "TEXTURE", "GRAPHIC",
  "HOODMODEL", "PLACEMODEL", "FLAGS", "NODE", "FLAT_DOOR", "ANIM",
  "CELL_ID", "ANIM_PROP", "INTERACTIVE_PROP", "ANIM_BUILDING", "'['",
  "','", "']'", "$accept", "dna", "object", "number", "lpoint3f",
  "suitpoint", "suitpointtype", "string", "dnagroupdef", "dnanodedef",
  "visgroupdef", "dnagroup", "visgroup", "string_opt_list", "vis", "empty",
  "group", "dnanode", "dnanode_grp", "sign", "signgraphic", "prop",
  "signbaseline", "signtext", "flatbuilding", "wall", "windows", "cornice",
  "landmarkbuilding", "street", "door", "propdef", "animpropdef",
  "interactivepropdef", "flatbuildingdef", "walldef", "windowsdef",
  "cornicedef", "landmarkbuildingdef", "animbuildingdef", "doordef",
  "flatdoordef", "streetdef", "signdef", "signgraphicdef", "baselinedef",
  "textdef", "suitedge", "battlecell", "subgroup_list", "subvisgroup_list",
  "pos", "hpr", "scale", "flags", "dnanode_sub", "dnaprop_sub",
  "dnaanimprop_sub", "dnainteractiveprop_sub", "anim", "baseline_sub",
  "text_sub", "signgraphic_sub", "flatbuilding_sub", "wall_sub",
  "windows_sub", "cornice_sub", "landmarkbuilding_sub", "animbuilding_sub",
  "door_sub", "street_sub", "texture", "street_color", "title", "article",
  "building_type", "lb_wall_color", "ab_anim", "windowcount",
  "baseline_width", "signgraphic_width", "flatbuilding_width",
  "baseline_height", "signgraphic_height", "wall_height", "stomp",
  "indent", "kern", "stumble", "wiggle", "prop_code",
  "landmarkbuilding_code", "baseline_code", "door_code",
  "signgraphic_code", "cornice_code", "street_code", "wall_code",
  "windows_code", "prop_color", "baseline_color", "door_color",
  "signgraphic_color", "cornice_color", "wall_color", "windows_color",
  "subprop_list", "subanimprop_list", "subinteractiveprop_list",
  "subbaseline_list", "subtext_list", "subdnanode_list",
  "subsigngraphic_list", "subflatbuilding_list", "subwall_list",
  "subwindows_list", "subcornice_list", "sublandmarkbuilding_list",
  "subanimbuilding_list", "subdoor_list", "substreet_list", "modeldef",
  "model", "modelnode_list", "node", "store_texture", "font", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    91,    44,    93
};
#endif

#define YYPACT_NINF (-310)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1266,   -44,    59,    59,    59,    59,  -310,  -310,  -310,   -37,
      59,  -310,  -310,  -310,    59,  -310,   -13,    59,  -310,    59,
      59,    59,  -310,    59,    59,    59,    43,  -310,  -310,    -2,
       0,     6,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,     9,
      14,    15,    17,    22,    25,    26,    27,    31,    35,    38,
      46,    49,    51,    52,    53,    54,  -310,  -310,  -310,    41,
    -310,  -310,  -310,  -310,  -310,  -310,    59,  -310,  -310,    59,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,   -17,    59,    59,  -310,  1221,  -310,  1149,  -310,
    1185,  -310,   806,  -310,   605,  -310,   502,  -310,  1051,  -310,
     659,  -310,   708,  -310,   855,  -310,   217,  -310,   163,  -310,
     904,   953,  -310,   757,  1002,  -310,   556,  -310,   114,  -310,
    1100,  -310,   -16,    44,    59,    -1,  -310,  -310,    55,    56,
      57,  -310,  -310,  -310,  -310,  -310,  -310,    58,    62,    63,
    -310,  -310,  -310,  -310,  -310,    64,    66,  -310,  -310,  -310,
    -310,  -310,    67,  -310,  -310,  -310,  -310,  -310,    68,  -310,
    -310,  -310,  -310,  -310,    76,  -310,  -310,  -310,  -310,    77,
      93,    96,  -310,  -310,  -310,  -310,  -310,  -310,    97,    98,
     100,  -310,  -310,  -310,  -310,  -310,  -310,   102,   104,  -310,
    -310,  -310,  -310,  -310,   105,   115,   117,   118,   125,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,   126,  -310,  -310,
    -310,  -310,  -310,   129,   130,  -310,  -310,  -310,  -310,  -310,
    -310,   131,   132,   133,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,   134,   135,   137,   138,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,   142,   149,   151,   153,   154,   155,   159,   166,
     168,   169,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,   170,  -310,  -310,  -310,   171,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,   113,    37,  -310,
      42,    41,    41,    41,    59,    41,    41,    59,    41,    59,
      41,    41,    59,    41,    41,    59,    41,    41,    59,    41,
      59,    41,    59,    59,    59,    59,    59,    41,    59,    41,
      59,    59,    41,    41,    41,    59,    41,    41,    41,    41,
      41,    41,    41,    41,    59,    59,    59,    41,  -310,  -310,
      41,   165,   177,   178,  -310,    41,    41,   181,    41,   182,
     183,   184,   185,    41,   186,   187,    41,   189,   190,    41,
     194,    41,   201,   203,   205,   206,   207,    41,   210,    41,
     211,   215,    41,   216,   218,   219,    41,   221,   222,   223,
     224,   225,   227,   229,   231,   235,    59,    10,    41,  -310,
    -310,  -310,     2,  -310,   237,    41,  -310,    41,  -310,  -310,
    -310,  -310,    41,  -310,  -310,    41,  -310,  -310,    41,  -310,
      41,  -310,  -310,  -310,  -310,  -310,    41,  -310,    41,  -310,
    -310,    41,  -310,  -310,  -310,    41,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,    48,    41,  -310,  -310,  -310,
    -310,  -310,   239,    41,    41,    41,    41,    41,    41,    41,
      41,    41,  -310,   241,   244,  -310,   247,   253,   255,   256,
     258,   259,   261,   263,   269,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,    76,    78,    79,     0,
       0,    68,    69,    70,     0,    73,     0,     0,    77,     0,
       0,     0,    74,     0,     0,     0,     0,     3,     4,     0,
       0,     0,    31,    32,     5,    33,    46,    38,    45,    37,
      39,    40,    41,    42,    34,    35,    43,    44,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     8,     7,     0,
      21,    20,    22,    24,    64,   220,     0,    67,    71,     0,
      75,   221,   222,    23,    65,    66,    72,     1,     2,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    10,
       9,    11,     0,     0,     0,    83,     0,   191,     0,    88,
       0,   174,     0,   178,     0,   183,     0,   197,     0,   200,
       0,   203,     0,   206,     0,   209,     0,   213,     0,   216,
       0,     0,   219,     0,     0,   194,     0,   186,     0,   189,
       0,   225,     0,     0,     0,     0,    25,    82,     0,     0,
       0,    47,    93,    94,    95,    96,   190,     0,     0,     0,
      26,    87,    84,    85,    86,     0,     0,    50,   172,   173,
      97,    98,     0,    51,   175,   176,   177,    99,     0,    52,
     179,   180,   181,   182,     0,    55,   195,   196,   117,     0,
       0,     0,    56,   198,   199,   118,   119,   120,     0,     0,
       0,    57,   201,   202,   123,   121,   122,     0,     0,    58,
     204,   205,   124,   125,     0,     0,     0,     0,     0,    59,
     207,   208,   127,   128,   129,   130,   126,     0,    60,   210,
     211,   212,   131,     0,     0,    62,   214,   215,   132,   133,
      63,     0,     0,     0,    61,   217,   218,   135,   136,   134,
      48,     0,     0,     0,     0,    49,   192,   193,   113,   114,
     115,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,   111,   184,   185,   104,   105,   108,   106,
     107,   109,   110,   102,   103,     0,    54,   187,   188,     0,
     223,   224,    15,    16,    17,    18,    19,     0,     0,   228,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   229,
       0,     0,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
      90,    91,     0,    28,     0,     0,   156,     0,   101,   100,
     147,   163,     0,   150,   164,     0,   144,   161,     0,   157,
       0,   139,   140,   141,   143,   159,     0,   162,     0,   137,
     160,     0,   146,   149,   158,     0,   145,   148,   151,   154,
     152,   155,   153,    92,   112,     0,     0,    13,    12,    29,
      27,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   226,     0,     0,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,    14,   165,   170,   171,
     169,   142,   167,   138,   168,   166
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -310,  -310,   209,    39,  -309,  -310,  -310,    -3,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,   -66,    12,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,   167,  -111,    -4,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,   198,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,   236,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,   242,
    -310,  -310,  -310,  -310,  -310,  -310,  -310
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    26,    27,   360,   361,    28,   307,    72,    29,    30,
      31,    32,    33,   412,   171,   121,   162,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   173,   174,   116,
     120,   163,   164,   165,   283,   178,   179,   186,   193,   187,
     285,   298,   267,   197,   204,   213,   221,   231,   241,   247,
     256,   257,   258,   232,   233,   234,   235,   242,   214,   286,
     268,   198,   287,   269,   205,   288,   289,   290,   291,   292,
     180,   236,   293,   248,   270,   222,   259,   206,   215,   181,
     294,   249,   271,   223,   207,   216,   122,   124,   126,   148,
     150,   118,   146,   128,   130,   132,   134,   136,   138,   140,
     143,    65,    66,   152,   301,    67,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,    74,    75,   362,   363,    70,    71,    77,    70,    71,
     299,    78,    34,   185,    80,   191,    81,    82,    83,    69,
      84,    85,    86,   115,   117,   119,    76,   123,   125,   127,
     129,   131,   133,   135,   137,   139,   139,   142,    34,   145,
     147,   149,   151,    87,   109,   110,   111,   153,   407,   300,
      79,     1,     2,     3,    70,    71,   302,   303,   304,   305,
     306,    89,     4,    90,   309,    70,    71,   459,     5,    91,
       6,     7,    92,   113,   456,   457,   114,    93,    94,     8,
      95,     9,    10,    11,    12,    96,    13,    14,    97,    98,
      99,    15,    16,    17,   100,    18,    19,    20,   101,    21,
      22,   102,   358,    23,    24,    25,   462,   359,   112,   103,
     154,   155,   104,   472,   105,   106,   107,   108,   311,   312,
     313,   314,   192,     2,     3,   315,   316,   317,   157,   318,
     319,   320,   172,     4,   158,   159,   160,   272,   273,   321,
     322,     6,     7,   274,   275,   276,   277,   278,   279,   280,
       8,   308,   310,    10,    11,    12,   323,    13,    14,   324,
     325,   326,    15,   327,    17,   328,    18,   329,   330,   281,
      21,    22,     2,     3,    23,    24,    25,   357,   331,   282,
     332,   333,     4,   158,   159,   160,   224,   225,   334,   335,
       6,     7,   336,   337,   338,   339,   340,   341,   342,     8,
     343,   344,    10,    11,    12,   345,    13,    14,   226,   227,
     228,    15,   346,    17,   347,    18,   348,   349,   350,    21,
      22,   237,   351,    23,    24,    25,     2,     3,   238,   352,
     409,   353,   354,   355,   356,    88,     4,   158,   159,   160,
     224,   225,   410,   411,     6,     7,   416,   418,   419,   420,
     421,   423,   424,     8,   426,   427,    10,    11,    12,   429,
      13,    14,   226,   227,   228,    15,   431,    17,   432,    18,
     433,   434,   435,    21,    22,   437,   439,    23,    24,    25,
     440,   442,   229,   443,   444,   166,   446,   447,   448,   449,
     450,   184,   451,   190,   452,   196,   453,   203,   413,   212,
     454,   220,   461,   230,   475,   239,   485,   246,   246,   486,
     255,   364,   487,   266,   367,   284,   369,   297,   488,   372,
     489,   490,   375,   491,   492,   378,   493,   380,   494,   382,
     383,   384,   385,   386,   495,   388,   240,   390,   391,     0,
     144,     0,   395,     0,   141,     0,     0,     0,     0,     0,
       0,   404,   405,   406,   365,   366,     0,   368,     0,   370,
     371,     0,   373,   374,     0,   376,   377,     0,   379,     0,
     381,     0,     0,     0,     0,     0,   387,     0,   389,     0,
       0,   392,   393,   394,     0,   396,   397,   398,   399,   400,
     401,   402,   403,     0,     0,     0,     0,     0,     0,   408,
       0,     0,     0,   455,   414,   415,     0,   417,     0,   460,
       0,     0,   422,     0,     0,   425,     0,     0,   428,     0,
     430,     0,     0,     0,     0,     0,   436,     0,   438,     0,
       0,   441,     0,     0,     0,   445,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   458,     0,     0,
       0,     0,   473,     0,     0,     0,   463,     0,     0,     0,
       0,   464,     0,     0,   465,     0,     0,   466,     0,   467,
       0,     0,     0,     0,     0,   468,     0,   469,     0,     0,
     470,     0,     0,     0,   471,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,     0,     0,     0,     0,
       0,     0,   476,   477,   478,   479,   480,   481,   482,   483,
     484,     2,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     4,   158,   159,   160,   175,   176,     0,     0,     6,
       7,     0,     0,     0,     0,     0,     0,     0,     8,     0,
       0,    10,    11,    12,     0,    13,    14,     0,     0,     0,
      15,     0,    17,     0,    18,     0,     0,     0,    21,    22,
     182,   188,    23,    24,    25,     2,     3,   189,     0,     0,
       0,     0,     0,     0,     0,     4,   158,   159,   160,   261,
     262,     0,     0,     6,     7,   263,   264,     0,     0,     0,
       0,     0,     8,     0,     0,    10,    11,    12,     0,    13,
      14,     0,     0,     0,    15,     0,    17,     0,    18,     0,
       0,     0,    21,    22,     2,     3,    23,    24,    25,     0,
       0,   265,     0,     0,     4,   158,   159,   160,   175,   176,
       0,     0,     6,     7,     0,     0,     0,     0,     0,     0,
       0,     8,     0,     0,    10,    11,    12,     0,    13,    14,
       0,     0,     0,    15,     0,    17,     0,    18,     0,     0,
       0,    21,    22,   182,     0,    23,    24,    25,     2,     3,
     183,     0,     0,     0,     0,     0,     0,     0,     4,   158,
     159,   160,   199,   200,     0,     0,     6,     7,     0,   201,
       0,     0,     0,     0,     0,     8,     0,     0,    10,    11,
      12,     0,    13,    14,     0,     0,     0,    15,     0,    17,
       0,    18,     0,     0,     0,    21,    22,     2,     3,    23,
      24,    25,     0,     0,   202,     0,     0,     4,   158,   159,
     160,   208,   209,     0,     0,     6,     7,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     0,    10,    11,    12,
     210,    13,    14,     0,     0,     0,    15,     0,    17,     0,
      18,     0,     0,     0,    21,    22,     2,     3,    23,    24,
      25,     0,     0,   211,     0,     0,     4,   158,   159,   160,
     251,   252,     0,     0,     6,     7,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,    10,    11,    12,     0,
      13,    14,     0,     0,     0,    15,     0,    17,   253,    18,
       0,     0,     0,    21,    22,     2,     3,    23,    24,    25,
       0,     0,   254,     0,     0,     4,   158,   159,   160,   175,
     176,     0,     0,     6,     7,     0,     0,     0,     0,     0,
       0,     0,     8,     0,     0,    10,    11,    12,     0,    13,
      14,     0,     0,     0,    15,     0,    17,     0,    18,     0,
       0,     0,    21,    22,     2,     3,    23,    24,    25,     0,
       0,   177,     0,     0,     4,   158,   159,   160,   217,   218,
       0,     0,     6,     7,     0,     0,     0,     0,     0,     0,
       0,     8,     0,     0,    10,    11,    12,     0,    13,    14,
       0,     0,     0,    15,     0,    17,     0,    18,     0,     0,
       0,    21,    22,     2,     3,    23,    24,    25,     0,     0,
     219,     0,     0,     4,   158,   159,   160,   243,   244,     0,
       0,     6,     7,     0,     0,     0,     0,     0,     0,     0,
       8,     0,     0,    10,    11,    12,     0,    13,    14,     0,
       0,     0,    15,     0,    17,     0,    18,     0,     0,     0,
      21,    22,     2,     3,    23,    24,    25,     0,     0,   245,
       0,     0,     4,   158,   159,   160,   243,   244,     0,     0,
       6,     7,     0,     0,     0,     0,     0,     0,     0,     8,
       0,     0,    10,    11,    12,     0,    13,    14,     0,     0,
       0,    15,     0,    17,     0,    18,     0,     0,     0,    21,
      22,     2,     3,    23,    24,    25,     0,     0,   250,     0,
       0,     4,   158,   159,   160,   175,   176,     0,     0,     6,
       7,     0,     0,     0,     0,     0,     0,     0,     8,     0,
       0,    10,    11,    12,     0,    13,    14,     0,     0,     0,
      15,     0,    17,     0,    18,     0,     0,     0,    21,    22,
       2,     3,    23,    24,    25,     0,     0,   260,     0,     0,
       4,   158,   159,   160,     0,     0,     0,     0,     6,     7,
     194,     0,     0,     0,     0,     0,     0,     8,     0,     0,
      10,    11,    12,     0,    13,    14,     0,     0,     0,    15,
       0,    17,     0,    18,     0,     0,     0,    21,    22,     2,
       3,    23,    24,    25,     0,     0,   195,     0,     0,     4,
     158,   159,   160,     0,     0,     0,     0,     6,     7,     0,
       0,     0,     0,     0,     0,     0,     8,   295,     0,    10,
      11,    12,     0,    13,    14,     0,     0,     0,    15,     0,
      17,     0,    18,     0,     0,     0,    21,    22,     2,     3,
      23,    24,    25,     0,     0,   296,     0,     0,     4,   158,
     159,   160,     0,     0,     0,     0,     6,     7,     0,     0,
       0,     0,     0,     0,     0,     8,     0,     0,    10,    11,
      12,     0,    13,    14,     2,     3,   167,    15,     0,    17,
       0,    18,   168,   169,     4,    21,    22,     0,     0,    23,
      24,    25,     6,     7,   161,     0,     0,     0,     0,     0,
       0,     8,     0,     0,    10,    11,    12,     0,    13,    14,
       2,     3,     0,    15,     0,    17,     0,    18,     0,     0,
       4,    21,    22,     0,     0,    23,    24,    25,     6,     7,
     170,     0,     0,     0,     0,     0,     0,     8,     0,     0,
      10,    11,    12,     0,    13,    14,     0,     0,     0,    15,
       0,    17,     0,    18,     1,     2,     3,    21,    22,     0,
       0,    23,    24,    25,     0,     4,   156,     0,     0,     0,
       0,     5,     0,     6,     7,     0,     0,     0,     0,     0,
       0,     0,     8,     0,     9,    10,    11,    12,     0,    13,
      14,     0,     0,     0,    15,    16,    17,     0,    18,    19,
      20,     0,    21,    22,     0,     0,    23,    24,    25
};

static const yytype_int16 yycheck[] =
{
       3,     4,     5,   312,   313,     6,     7,    10,     6,     7,
      26,    14,     0,   124,    17,   126,    19,    20,    21,    63,
      23,    24,    25,    89,    90,    91,    63,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    26,   105,
     106,   107,   108,     0,     3,     4,     5,    64,   357,    65,
      63,     8,     9,    10,     6,     7,    12,    13,    14,    15,
      16,    63,    19,    63,    65,     6,     7,    65,    25,    63,
      27,    28,    63,    76,    64,    65,    79,    63,    63,    36,
      63,    38,    39,    40,    41,    63,    43,    44,    63,    63,
      63,    48,    49,    50,    63,    52,    53,    54,    63,    56,
      57,    63,    65,    60,    61,    62,   415,    65,    69,    63,
     113,   114,    63,    65,    63,    63,    63,    63,    63,    63,
      63,    63,   126,     9,    10,    63,    63,    63,   116,    63,
      63,    63,   120,    19,    20,    21,    22,    23,    24,    63,
      63,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,   154,   155,    39,    40,    41,    63,    43,    44,    63,
      63,    63,    48,    63,    50,    63,    52,    63,    63,    55,
      56,    57,     9,    10,    60,    61,    62,    64,    63,    65,
      63,    63,    19,    20,    21,    22,    23,    24,    63,    63,
      27,    28,    63,    63,    63,    63,    63,    63,    63,    36,
      63,    63,    39,    40,    41,    63,    43,    44,    45,    46,
      47,    48,    63,    50,    63,    52,    63,    63,    63,    56,
      57,    58,    63,    60,    61,    62,     9,    10,    65,    63,
      65,    63,    63,    63,    63,    26,    19,    20,    21,    22,
      23,    24,    65,    65,    27,    28,    65,    65,    65,    65,
      65,    65,    65,    36,    65,    65,    39,    40,    41,    65,
      43,    44,    45,    46,    47,    48,    65,    50,    65,    52,
      65,    65,    65,    56,    57,    65,    65,    60,    61,    62,
      65,    65,    65,    65,    65,   118,    65,    65,    65,    65,
      65,   124,    65,   126,    65,   128,    65,   130,   364,   132,
      65,   134,    65,   136,    65,   138,    65,   140,   141,    65,
     143,   314,    65,   146,   317,   148,   319,   150,    65,   322,
      65,    65,   325,    65,    65,   328,    65,   330,    65,   332,
     333,   334,   335,   336,    65,   338,   138,   340,   341,    -1,
     104,    -1,   345,    -1,   102,    -1,    -1,    -1,    -1,    -1,
      -1,   354,   355,   356,   315,   316,    -1,   318,    -1,   320,
     321,    -1,   323,   324,    -1,   326,   327,    -1,   329,    -1,
     331,    -1,    -1,    -1,    -1,    -1,   337,    -1,   339,    -1,
      -1,   342,   343,   344,    -1,   346,   347,   348,   349,   350,
     351,   352,   353,    -1,    -1,    -1,    -1,    -1,    -1,   360,
      -1,    -1,    -1,   406,   365,   366,    -1,   368,    -1,   412,
      -1,    -1,   373,    -1,    -1,   376,    -1,    -1,   379,    -1,
     381,    -1,    -1,    -1,    -1,    -1,   387,    -1,   389,    -1,
      -1,   392,    -1,    -1,    -1,   396,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,    -1,    -1,
      -1,    -1,   455,    -1,    -1,    -1,   417,    -1,    -1,    -1,
      -1,   422,    -1,    -1,   425,    -1,    -1,   428,    -1,   430,
      -1,    -1,    -1,    -1,    -1,   436,    -1,   438,    -1,    -1,
     441,    -1,    -1,    -1,   445,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,    -1,    -1,
      -1,    -1,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    50,    -1,    52,    -1,    -1,    -1,    56,    57,
      58,    59,    60,    61,    62,     9,    10,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    39,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    50,    -1,    52,    -1,
      -1,    -1,    56,    57,     9,    10,    60,    61,    62,    -1,
      -1,    65,    -1,    -1,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    50,    -1,    52,    -1,    -1,
      -1,    56,    57,    58,    -1,    60,    61,    62,     9,    10,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    28,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    50,
      -1,    52,    -1,    -1,    -1,    56,    57,     9,    10,    60,
      61,    62,    -1,    -1,    65,    -1,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,
      52,    -1,    -1,    -1,    56,    57,     9,    10,    60,    61,
      62,    -1,    -1,    65,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    50,    51,    52,
      -1,    -1,    -1,    56,    57,     9,    10,    60,    61,    62,
      -1,    -1,    65,    -1,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    39,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    50,    -1,    52,    -1,
      -1,    -1,    56,    57,     9,    10,    60,    61,    62,    -1,
      -1,    65,    -1,    -1,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    50,    -1,    52,    -1,    -1,
      -1,    56,    57,     9,    10,    60,    61,    62,    -1,    -1,
      65,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    39,    40,    41,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    50,    -1,    52,    -1,    -1,    -1,
      56,    57,     9,    10,    60,    61,    62,    -1,    -1,    65,
      -1,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    50,    -1,    52,    -1,    -1,    -1,    56,
      57,     9,    10,    60,    61,    62,    -1,    -1,    65,    -1,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    50,    -1,    52,    -1,    -1,    -1,    56,    57,
       9,    10,    60,    61,    62,    -1,    -1,    65,    -1,    -1,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    50,    -1,    52,    -1,    -1,    -1,    56,    57,     9,
      10,    60,    61,    62,    -1,    -1,    65,    -1,    -1,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,    39,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      50,    -1,    52,    -1,    -1,    -1,    56,    57,     9,    10,
      60,    61,    62,    -1,    -1,    65,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    39,    40,
      41,    -1,    43,    44,     9,    10,    11,    48,    -1,    50,
      -1,    52,    17,    18,    19,    56,    57,    -1,    -1,    60,
      61,    62,    27,    28,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    39,    40,    41,    -1,    43,    44,
       9,    10,    -1,    48,    -1,    50,    -1,    52,    -1,    -1,
      19,    56,    57,    -1,    -1,    60,    61,    62,    27,    28,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    50,    -1,    52,     8,     9,    10,    56,    57,    -1,
      -1,    60,    61,    62,    -1,    19,    65,    -1,    -1,    -1,
      -1,    25,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    38,    39,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    49,    50,    -1,    52,    53,
      54,    -1,    56,    57,    -1,    -1,    60,    61,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    10,    19,    25,    27,    28,    36,    38,
      39,    40,    41,    43,    44,    48,    49,    50,    52,    53,
      54,    56,    57,    60,    61,    62,    67,    68,    71,    74,
      75,    76,    77,    78,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   187,   188,   191,   192,    63,
       6,     7,    73,    73,    73,    73,    63,    73,    73,    63,
      73,    73,    73,    73,    73,    73,    73,     0,    68,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,     3,
       4,     5,    69,    73,    73,    81,   115,    81,   177,    81,
     116,    81,   172,    81,   173,    81,   174,    81,   179,    81,
     180,    81,   181,    81,   182,    81,   183,    81,   184,    81,
     185,   185,    81,   186,   172,    81,   178,    81,   175,    81,
     176,    81,   189,    64,    73,    73,    65,    82,    20,    21,
      22,    65,    82,   117,   118,   119,   121,    11,    17,    18,
      65,    80,    82,   113,   114,    23,    24,    65,   121,   122,
     156,   165,    58,    65,   121,   122,   123,   125,    59,    65,
     121,   122,   123,   124,    29,    65,   121,   129,   147,    23,
      24,    30,    65,   121,   130,   150,   163,   170,    23,    24,
      42,    65,   121,   131,   144,   164,   171,    23,    24,    65,
     121,   132,   161,   169,    23,    24,    45,    46,    47,    65,
     121,   133,   139,   140,   141,   142,   157,    58,    65,   121,
     133,   134,   143,    23,    24,    65,   121,   135,   159,   167,
      65,    23,    24,    51,    65,   121,   136,   137,   138,   162,
      65,    23,    24,    29,    30,    65,   121,   128,   146,   149,
     160,   168,    23,    24,    29,    30,    31,    32,    33,    34,
      35,    55,    65,   120,   121,   126,   145,   148,   151,   152,
     153,   154,   155,   158,   166,    37,    65,   121,   127,    26,
      65,   190,    12,    13,    14,    15,    16,    72,    73,    65,
      73,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    64,    65,    65,
      69,    70,    70,    70,    73,    69,    69,    73,    69,    73,
      69,    69,    73,    69,    69,    73,    69,    69,    73,    69,
      73,    69,    73,    73,    73,    73,    73,    69,    73,    69,
      73,    73,    69,    69,    69,    73,    69,    69,    69,    69,
      69,    69,    69,    69,    73,    73,    73,    70,    69,    65,
      65,    65,    79,    81,    69,    69,    65,    69,    65,    65,
      65,    65,    69,    65,    65,    69,    65,    65,    69,    65,
      69,    65,    65,    65,    65,    65,    69,    65,    69,    65,
      65,    69,    65,    65,    65,    69,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    73,    64,    65,    69,    65,
      73,    65,    70,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    65,    73,    69,    65,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    67,    68,    68,    68,    68,    68,    69,
      69,    69,    70,    71,    71,    72,    72,    72,    72,    72,
      73,    73,    74,    75,    76,    77,    78,    79,    79,    80,
      81,    82,    82,    82,    82,    82,    82,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    84,    85,    86,
      87,    87,    87,    88,    89,    90,    91,    92,    93,    94,
      94,    95,    96,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   115,   116,   116,   116,   116,   116,   117,
     118,   119,   120,   121,   121,   121,   121,   122,   122,   123,
     124,   125,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   127,   128,   128,   128,   128,   129,   130,   130,
     130,   131,   131,   131,   132,   132,   133,   133,   133,   133,
     133,   134,   135,   135,   136,   136,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   172,   172,   173,   173,   173,   173,   174,
     174,   174,   174,   174,   175,   175,   175,   176,   176,   176,
     177,   177,   178,   178,   178,   179,   179,   179,   180,   180,
     180,   181,   181,   181,   182,   182,   182,   183,   183,   183,
     184,   184,   184,   184,   185,   185,   185,   186,   186,   186,
     187,   187,   187,   188,   189,   189,   190,   190,   191,   191,
     192
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     8,    10,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     4,     4,     2,     1,     5,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     2,     2,     2,     2,     1,     1,
       1,     2,     2,     1,     1,     2,     1,     1,     1,     1,
       5,     6,     2,     1,     2,     2,     2,     2,     1,     4,
       4,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     7,     4,
       4,     4,     7,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     7,     7,     7,     7,     7,
       7,     7,     2,     2,     1,     2,     2,     2,     1,     2,
       2,     2,     2,     1,     2,     2,     1,     2,     2,     1,
       2,     1,     2,     2,     1,     2,     2,     1,     2,     2,
       1,     2,     2,     1,     2,     2,     1,     2,     2,     1,
       2,     2,     2,     1,     2,     2,     1,     2,     2,     1,
       2,     2,     2,     4,     2,     1,     5,     6,     5,     6,
       6
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 9: /* number: UNSIGNED_INTEGER  */
#line 193 "dna.yxx"
{
  (yyval.u.real) = (double)(yyvsp[0].u.uint64);
}
#line 1916 "dna_yxx.cxx"
    break;

  case 10: /* number: SIGNED_INTEGER  */
#line 197 "dna.yxx"
{
  (yyval.u.real) = (double)(yyvsp[0].u.int64);
}
#line 1924 "dna_yxx.cxx"
    break;

  case 11: /* number: FLOAT_REAL  */
#line 201 "dna.yxx"
{
  (yyval.u.real) = (yyvsp[0].u.real);
}
#line 1932 "dna_yxx.cxx"
    break;

  case 12: /* lpoint3f: number number number  */
#line 206 "dna.yxx"
{
  LPoint3f p((yyvsp[-2].u.real), (yyvsp[-1].u.real), (yyvsp[0].u.real));
  (yyval.point3) = p;
}
#line 1941 "dna_yxx.cxx"
    break;

  case 13: /* suitpoint: STORE_SUIT_POINT '[' number ',' suitpointtype ',' lpoint3f ']'  */
#line 212 "dna.yxx"
{
  PT(DNASuitPoint) point = new DNASuitPoint((yyvsp[-5].u.real), (DNASuitPoint::PointType)(yyvsp[-3].u.uint64), (yyvsp[-1].point3));
  _store->store_suit_point(point);
}
#line 1950 "dna_yxx.cxx"
    break;

  case 14: /* suitpoint: STORE_SUIT_POINT '[' number ',' suitpointtype ',' lpoint3f ',' number ']'  */
#line 217 "dna.yxx"
{
  PT(DNASuitPoint) point = new DNASuitPoint((yyvsp[-7].u.real), (DNASuitPoint::PointType)(yyvsp[-5].u.uint64), (yyvsp[-3].point3), (yyvsp[-1].u.real));
  _store->store_suit_point(point);
}
#line 1959 "dna_yxx.cxx"
    break;

  case 15: /* suitpointtype: DNA_STREET_POINT  */
#line 223 "dna.yxx"
{
  #undef DNA_STREET_POINT
  (yyval.u.uint64) = (uint64_t)DNASuitPoint::STREET_POINT;
}
#line 1968 "dna_yxx.cxx"
    break;

  case 16: /* suitpointtype: DNA_FRONT_DOOR_POINT  */
#line 228 "dna.yxx"
{
  #undef DNA_FRONT_DOOR_POINT
  (yyval.u.uint64) = (uint64_t)DNASuitPoint::FRONT_DOOR_POINT;
}
#line 1977 "dna_yxx.cxx"
    break;

  case 17: /* suitpointtype: DNA_SIDE_DOOR_POINT  */
#line 233 "dna.yxx"
{
  #undef DNA_SIDE_DOOR_POINT
  (yyval.u.uint64) = (uint64_t)DNASuitPoint::SIDE_DOOR_POINT;
}
#line 1986 "dna_yxx.cxx"
    break;

  case 18: /* suitpointtype: DNA_COGHQ_IN_POINT  */
#line 238 "dna.yxx"
{
  #undef DNA_COGHQ_IN_POINT
  (yyval.u.uint64) = (uint64_t)DNASuitPoint::COGHQ_IN_POINT;
}
#line 1995 "dna_yxx.cxx"
    break;

  case 19: /* suitpointtype: DNA_COGHQ_OUT_POINT  */
#line 243 "dna.yxx"
{
  #undef DNA_COGHQ_OUT_POINT
  (yyval.u.uint64) = (uint64_t)DNASuitPoint::COGHQ_OUT_POINT;
}
#line 2004 "dna_yxx.cxx"
    break;

  case 20: /* string: QUOTED_STRING  */
#line 249 "dna.yxx"
{
  (yyval.str) = (yyvsp[0].str);
}
#line 2012 "dna_yxx.cxx"
    break;

  case 21: /* string: UNQUOTED_STRING  */
#line 253 "dna.yxx"
{
  (yyval.str) = (yyvsp[0].str);
}
#line 2020 "dna_yxx.cxx"
    break;

  case 22: /* dnagroupdef: GROUP string  */
#line 258 "dna.yxx"
{
  PT(DNAGroup) g = new DNAGroup((yyvsp[0].str));
  g->set_parent(_cur_comp);
  g->set_vis_group(_cur_comp->get_vis_group());
  _cur_comp->add(g);
  _cur_comp = g;
}
#line 2032 "dna_yxx.cxx"
    break;

  case 23: /* dnanodedef: NODE string  */
#line 267 "dna.yxx"
{
  PT(DNAGroup) g = new DNANode((yyvsp[0].str));
  g->set_parent(_cur_comp);
  g->set_vis_group(_cur_comp->get_vis_group());
  _cur_comp->add(g);
  _cur_comp = g;
}
#line 2044 "dna_yxx.cxx"
    break;

  case 24: /* visgroupdef: VISGROUP string  */
#line 276 "dna.yxx"
{
  PT(DNAGroup) g = new DNAVisGroup((yyvsp[0].str));
  g->set_parent(_cur_comp);
  _cur_comp->add(g);
  _cur_comp = g;
  _store->store_DNA_vis_group(DCAST(DNAVisGroup, g));
}
#line 2056 "dna_yxx.cxx"
    break;

  case 25: /* dnagroup: dnagroupdef '[' subgroup_list ']'  */
#line 285 "dna.yxx"
{
  _cur_comp = _cur_comp->get_parent();
}
#line 2064 "dna_yxx.cxx"
    break;

  case 26: /* visgroup: visgroupdef '[' subvisgroup_list ']'  */
#line 290 "dna.yxx"
{
  _cur_comp = _cur_comp->get_parent();
}
#line 2072 "dna_yxx.cxx"
    break;

  case 27: /* string_opt_list: string_opt_list string  */
#line 295 "dna.yxx"
{
  (yyvsp[-1].str_vec).push_back((yyvsp[0].str));
  (yyval.str_vec) = (yyvsp[-1].str_vec);
}
#line 2081 "dna_yxx.cxx"
    break;

  case 28: /* string_opt_list: empty  */
#line 300 "dna.yxx"
{
  (yyval.str_vec) = {};
}
#line 2089 "dna_yxx.cxx"
    break;

  case 29: /* vis: VIS '[' string string_opt_list ']'  */
#line 305 "dna.yxx"
{
  DCAST(DNAVisGroup, _cur_comp)->add_visible((yyvsp[-2].str));
  for (auto& vis : (yyvsp[-1].str_vec))
    DCAST(DNAVisGroup, _cur_comp)->add_visible(vis);
}
#line 2099 "dna_yxx.cxx"
    break;

  case 47: /* dnanode_grp: dnanodedef '[' subdnanode_list ']'  */
#line 335 "dna.yxx"
{
  _cur_comp = _cur_comp->get_parent();
}
#line 2107 "dna_yxx.cxx"
    break;

  case 48: /* sign: signdef '[' subprop_list ']'  */
#line 340 "dna.yxx"
{
  _cur_comp = _cur_comp->get_parent();
}
#line 2115 "dna_yxx.cxx"
    break;

  case 49: /* signgraphic: signgraphicdef '[' subsigngraphic_list ']'  */
#line 345 "dna.yxx"
{
  _cur_comp = _cur_comp->get_parent();
}
#line 2123 "dna_yxx.cxx"
    break;

  case 50: /* prop: propdef '[' subprop_list ']'  */
#line 350 "dna.yxx"
{
  _cur_comp = _cur_comp->get_parent();
}
#line 2131 "dna_yxx.cxx"
    break;

  case 51: /* prop: animpropdef '[' subanimprop_list ']'  */
#line 354 "dna.yxx"
{
  _cur_comp = _cur_comp->get_parent();
}
#line 2139 "dna_yxx.cxx"
    break;

  case 52: /* prop: interactivepropdef '[' subinteractiveprop_list ']'  */
#line 358 "dna.yxx"
{
  _cur_comp = _cur_comp->get_parent();
}
#line 2147 "dna_yxx.cxx"
    break;

  case 53: /* signbaseline: baselinedef '[' subbaseline_list ']'  */
#line 363 "dna.yxx"
{
  _cur_comp = _cur_comp->get_parent();
}
#line 2155 "dna_yxx.cxx"
    break;

  case 55: /* flatbuilding: flatbuildingdef '[' subflatbuilding_list ']'  */
#line 371 "dna.yxx"
{
  _cur_comp = _cur_comp->get_parent();
}
#line 2163 "dna_yxx.cxx"
    break;

  case 56: /* wall: walldef '[' subwall_list ']'  */
#line 376 "dna.yxx"
{
  _cur_comp = _cur_comp->get_parent();
}
#line 2171 "dna_yxx.cxx"
    break;

  case 57: /* windows: windowsdef '[' subwindows_list ']'  */
#line 381 "dna.yxx"
{
  _cur_comp = _cur_comp->get_parent();
}
#line 2179 "dna_yxx.cxx"
    break;

  case 58: /* cornice: cornicedef '[' subcornice_list ']'  */
#line 386 "dna.yxx"
{
  _cur_comp = _cur_comp->get_parent();
}
#line 2187 "dna_yxx.cxx"
    break;

  case 59: /* landmarkbuilding: landmarkbuildingdef '[' sublandmarkbuilding_list ']'  */
#line 391 "dna.yxx"
{
  _cur_comp = _cur_comp->get_parent();
}
#line 2195 "dna_yxx.cxx"
    break;

  case 60: /* landmarkbuilding: animbuildingdef '[' subanimbuilding_list ']'  */
#line 395 "dna.yxx"
{
  _cur_comp = _cur_comp->get_parent();
}
#line 2203 "dna_yxx.cxx"
    break;

  case 61: /* street: streetdef '[' substreet_list ']'  */
#line 400 "dna.yxx"
{
  _cur_comp = _cur_comp->get_parent();
}
#line 2211 "dna_yxx.cxx"
    break;

  case 62: /* door: doordef '[' subdoor_list ']'  */
#line 405 "dna.yxx"
{
  _cur_comp = _cur_comp->get_parent();
}
#line 2219 "dna_yxx.cxx"
    break;

  case 63: /* door: flatdoordef '[' subdoor_list ']'  */
#line 409 "dna.yxx"
{
  _cur_comp = _cur_comp->get_parent();
}
#line 2227 "dna_yxx.cxx"
    break;

  case 64: /* propdef: PROP string  */
#line 414 "dna.yxx"
{
  PT(DNAGroup) g = new DNAProp((yyvsp[0].str));
  g->set_parent(_cur_comp);
  g->set_vis_group(_cur_comp->get_vis_group());
  _cur_comp->add(g);
  _cur_comp = g;
}
#line 2239 "dna_yxx.cxx"
    break;

  case 65: /* animpropdef: ANIM_PROP string  */
#line 423 "dna.yxx"
{
  PT(DNAGroup) g = new DNAAnimProp((yyvsp[0].str));
  g->set_parent(_cur_comp);
  g->set_vis_group(_cur_comp->get_vis_group());
  _cur_comp->add(g);
  _cur_comp = g;
}
#line 2251 "dna_yxx.cxx"
    break;

  case 66: /* interactivepropdef: INTERACTIVE_PROP string  */
#line 432 "dna.yxx"
{
  PT(DNAGroup) g = new DNAInteractiveProp((yyvsp[0].str));
  g->set_parent(_cur_comp);
  g->set_vis_group(_cur_comp->get_vis_group());
  _cur_comp->add(g);
  _cur_comp = g;
}
#line 2263 "dna_yxx.cxx"
    break;

  case 67: /* flatbuildingdef: FLAT_BUILDING string  */
#line 441 "dna.yxx"
{
  PT(DNAGroup) g = new DNAFlatBuilding((yyvsp[0].str));
  g->set_parent(_cur_comp);
  g->set_vis_group(_cur_comp->get_vis_group());
  _cur_comp->add(g);
  _cur_comp = g;
}
#line 2275 "dna_yxx.cxx"
    break;

  case 68: /* walldef: WALL  */
#line 450 "dna.yxx"
{
  PT(DNAGroup) g = new DNAWall("wall");
  g->set_parent(_cur_comp);
  g->set_vis_group(_cur_comp->get_vis_group());
  _cur_comp->add(g);
  _cur_comp = g;
}
#line 2287 "dna_yxx.cxx"
    break;

  case 69: /* windowsdef: WINDOWS  */
#line 459 "dna.yxx"
{
  PT(DNAGroup) g = new DNAWindows("windows");
  g->set_parent(_cur_comp);
  g->set_vis_group(_cur_comp->get_vis_group());
  _cur_comp->add(g);
  _cur_comp = g;
}
#line 2299 "dna_yxx.cxx"
    break;

  case 70: /* cornicedef: CORNICE  */
#line 468 "dna.yxx"
{
  PT(DNAGroup) g = new DNACornice("cornice");
  g->set_parent(_cur_comp);
  g->set_vis_group(_cur_comp->get_vis_group());
  _cur_comp->add(g);
  _cur_comp = g;
}
#line 2311 "dna_yxx.cxx"
    break;

  case 71: /* landmarkbuildingdef: LANDMARK_BUILDING string  */
#line 477 "dna.yxx"
{
  PT(DNAGroup) g = new DNALandmarkBuilding((yyvsp[0].str));
  g->set_parent(_cur_comp);
  g->set_vis_group(_cur_comp->get_vis_group());
  _cur_comp->add(g);
  _cur_comp = g;

  block_number_t block_number = atoi(_store->get_block((yyvsp[0].str)).c_str());
  zone_id_t zone_id = _get_visgroup_zoneid(g);
  _store->store_block_number(block_number);
  _store->store_block_zone(block_number, zone_id);
}
#line 2328 "dna_yxx.cxx"
    break;

  case 72: /* animbuildingdef: ANIM_BUILDING string  */
#line 491 "dna.yxx"
{
  PT(DNAGroup) g = new DNAAnimBuilding((yyvsp[0].str));
  g->set_parent(_cur_comp);
  g->set_vis_group(_cur_comp->get_vis_group());
  _cur_comp->add(g);
  _cur_comp = g;

  block_number_t block_number = atoi(_store->get_block((yyvsp[0].str)).c_str());
  zone_id_t zone_id = _get_visgroup_zoneid(g);
  _store->store_block_number(block_number);
  _store->store_block_zone(block_number, zone_id);
}
#line 2345 "dna_yxx.cxx"
    break;

  case 73: /* doordef: DOOR  */
#line 505 "dna.yxx"
{
  PT(DNAGroup) g = new DNADoor("door");
  g->set_parent(_cur_comp);
  g->set_vis_group(_cur_comp->get_vis_group());
  _cur_comp->add(g);
  _cur_comp = g;
}
#line 2357 "dna_yxx.cxx"
    break;

  case 74: /* flatdoordef: FLAT_DOOR  */
#line 514 "dna.yxx"
{
  PT(DNAGroup) g = new DNAFlatDoor("flat_door");
  g->set_parent(_cur_comp);
  g->set_vis_group(_cur_comp->get_vis_group());
  _cur_comp->add(g);
  DCAST(DNAFlatBuilding, _cur_comp->get_parent())->set_has_door(true);
  _cur_comp = g;
}
#line 2370 "dna_yxx.cxx"
    break;

  case 75: /* streetdef: STREET string  */
#line 524 "dna.yxx"
{
  PT(DNAGroup) g = new DNAStreet((yyvsp[0].str));
  g->set_parent(_cur_comp);
  g->set_vis_group(_cur_comp->get_vis_group());
  _cur_comp->add(g);
  _cur_comp = g;
}
#line 2382 "dna_yxx.cxx"
    break;

  case 76: /* signdef: SIGN  */
#line 533 "dna.yxx"
{
  PT(DNAGroup) g = new DNASign("sign");
  g->set_parent(_cur_comp);
  g->set_vis_group(_cur_comp->get_vis_group());
  _cur_comp->add(g);
  _cur_comp = g;
}
#line 2394 "dna_yxx.cxx"
    break;

  case 77: /* signgraphicdef: GRAPHIC  */
#line 542 "dna.yxx"
{
  PT(DNAGroup) g = new DNASignGraphic("graphic");
  g->set_parent(_cur_comp);
  g->set_vis_group(_cur_comp->get_vis_group());
  _cur_comp->add(g);
  _cur_comp = g;
}
#line 2406 "dna_yxx.cxx"
    break;

  case 78: /* baselinedef: BASELINE  */
#line 551 "dna.yxx"
{
  PT(DNAGroup) g = new DNASignBaseline("baseline");
  g->set_parent(_cur_comp);
  g->set_vis_group(_cur_comp->get_vis_group());
  _cur_comp->add(g);
  _cur_comp = g;
  _sign_text = nullptr; 
}
#line 2419 "dna_yxx.cxx"
    break;

  case 79: /* textdef: TEXT  */
#line 561 "dna.yxx"
{
  if (!_sign_text) {
	PT(DNAGroup) g = new DNASignText("text");
	g->set_parent(_cur_comp);
	g->set_vis_group(_cur_comp->get_vis_group());
	_cur_comp->add(g);
	_sign_text = g;
	}
}
#line 2433 "dna_yxx.cxx"
    break;

  case 80: /* suitedge: SUIT_EDGE '[' number number ']'  */
#line 572 "dna.yxx"
{
  PT(DNASuitEdge) edge = _store->store_suit_edge((yyvsp[-2].u.real), (yyvsp[-1].u.real), atoi(_cur_comp->get_name().c_str()));
  if (!edge) {
    dnayyerror("store_suit_edge failed");
  }
  DCAST(DNAVisGroup, _cur_comp)->add_suit_edge(edge);
}
#line 2445 "dna_yxx.cxx"
    break;

  case 81: /* battlecell: BATTLE_CELL '[' number number lpoint3f ']'  */
#line 581 "dna.yxx"
{
  PT(DNABattleCell) cell = new DNABattleCell((yyvsp[-3].u.real), (yyvsp[-2].u.real), (yyvsp[-1].point3));
  DCAST(DNAVisGroup, _cur_comp)->add_battle_cell(cell);
}
#line 2454 "dna_yxx.cxx"
    break;

  case 89: /* pos: POS '[' lpoint3f ']'  */
#line 598 "dna.yxx"
{
  DCAST(DNANode, _cur_comp)->set_pos((yyvsp[-1].point3));
}
#line 2462 "dna_yxx.cxx"
    break;

  case 90: /* hpr: HPR '[' lpoint3f ']'  */
#line 603 "dna.yxx"
{
  DCAST(DNANode, _cur_comp)->set_hpr((yyvsp[-1].point3));
}
#line 2470 "dna_yxx.cxx"
    break;

  case 91: /* scale: SCALE '[' lpoint3f ']'  */
#line 608 "dna.yxx"
{
  DCAST(DNANode, _cur_comp)->set_scale((yyvsp[-1].point3));
}
#line 2478 "dna_yxx.cxx"
    break;

  case 92: /* flags: FLAGS '[' string ']'  */
#line 613 "dna.yxx"
{
  DCAST(DNASignBaseline, _cur_comp)->set_flags((yyvsp[-1].str));
}
#line 2486 "dna_yxx.cxx"
    break;

  case 100: /* dnainteractiveprop_sub: CELL_ID '[' number ']'  */
#line 631 "dna.yxx"
{
  DCAST(DNAInteractiveProp, _cur_comp)->set_cell_id((yyvsp[-1].u.real));
}
#line 2494 "dna_yxx.cxx"
    break;

  case 101: /* anim: ANIM '[' string ']'  */
#line 636 "dna.yxx"
{
  DCAST(DNAAnimProp, _cur_comp)->set_anim_name((yyvsp[-1].str));
}
#line 2502 "dna_yxx.cxx"
    break;

  case 112: /* text_sub: LETTERS '[' string ']'  */
#line 653 "dna.yxx"
{
  DCAST(DNASignText, _sign_text)->m_letters += (yyvsp[-1].str);
}
#line 2510 "dna_yxx.cxx"
    break;

  case 137: /* texture: TEXTURE '[' string ']'  */
#line 700 "dna.yxx"
{
  DCAST(DNAStreet, _cur_comp)->set_texture((yyvsp[-1].str));
}
#line 2518 "dna_yxx.cxx"
    break;

  case 138: /* street_color: COLOR '[' number number number number ']'  */
#line 705 "dna.yxx"
{
  LVecBase4f color((yyvsp[-4].u.real), (yyvsp[-3].u.real), (yyvsp[-2].u.real), (yyvsp[-1].u.real));
  DCAST(DNAStreet, _cur_comp)->set_color(color);
}
#line 2527 "dna_yxx.cxx"
    break;

  case 139: /* title: TITLE '[' string ']'  */
#line 711 "dna.yxx"
{
  DCAST(DNALandmarkBuilding, _cur_comp)->set_title((yyvsp[-1].str));
  block_number_t block_number = atoi(_store->get_block(_cur_comp->get_name()).c_str());
  _store->store_block_title(block_number, (yyvsp[-1].str));
}
#line 2537 "dna_yxx.cxx"
    break;

  case 140: /* article: ARTICLE '[' string ']'  */
#line 718 "dna.yxx"
{
  DCAST(DNALandmarkBuilding, _cur_comp)->set_article((yyvsp[-1].str));
  block_number_t block_number = atoi(_store->get_block(_cur_comp->get_name()).c_str());
  _store->store_block_article(block_number, (yyvsp[-1].str));
}
#line 2547 "dna_yxx.cxx"
    break;

  case 141: /* building_type: BUILDING_TYPE '[' string ']'  */
#line 725 "dna.yxx"
{
  DCAST(DNALandmarkBuilding, _cur_comp)->set_building_type((yyvsp[-1].str));
  block_number_t block_number = atoi(_store->get_block(_cur_comp->get_name()).c_str());
  _store->store_block_building_type(block_number, (yyvsp[-1].str));
}
#line 2557 "dna_yxx.cxx"
    break;

  case 142: /* lb_wall_color: COLOR '[' number number number number ']'  */
#line 732 "dna.yxx"
{
  LVecBase4f color((yyvsp[-4].u.real), (yyvsp[-3].u.real), (yyvsp[-2].u.real), (yyvsp[-1].u.real));
  DCAST(DNALandmarkBuilding, _cur_comp)->set_wall_color(color);
}
#line 2566 "dna_yxx.cxx"
    break;

  case 143: /* ab_anim: ANIM '[' string ']'  */
#line 738 "dna.yxx"
{
  DCAST(DNAAnimBuilding, _cur_comp)->set_anim_name((yyvsp[-1].str));
}
#line 2574 "dna_yxx.cxx"
    break;

  case 144: /* windowcount: COUNT '[' number ']'  */
#line 743 "dna.yxx"
{
  DCAST(DNAWindows, _cur_comp)->set_window_count((yyvsp[-1].u.real));
}
#line 2582 "dna_yxx.cxx"
    break;

  case 145: /* baseline_width: WIDTH '[' number ']'  */
#line 748 "dna.yxx"
{
  DCAST(DNASignBaseline, _cur_comp)->set_width((yyvsp[-1].u.real));
}
#line 2590 "dna_yxx.cxx"
    break;

  case 146: /* signgraphic_width: WIDTH '[' number ']'  */
#line 753 "dna.yxx"
{
  DCAST(DNASignGraphic, _cur_comp)->set_width((yyvsp[-1].u.real));
}
#line 2598 "dna_yxx.cxx"
    break;

  case 147: /* flatbuilding_width: WIDTH '[' number ']'  */
#line 758 "dna.yxx"
{
  DCAST(DNAFlatBuilding, _cur_comp)->set_width((yyvsp[-1].u.real));
}
#line 2606 "dna_yxx.cxx"
    break;

  case 148: /* baseline_height: HEIGHT '[' number ']'  */
#line 763 "dna.yxx"
{
  DCAST(DNASignBaseline, _cur_comp)->set_height((yyvsp[-1].u.real));
}
#line 2614 "dna_yxx.cxx"
    break;

  case 149: /* signgraphic_height: HEIGHT '[' number ']'  */
#line 768 "dna.yxx"
{
  DCAST(DNASignGraphic, _cur_comp)->set_height((yyvsp[-1].u.real));
}
#line 2622 "dna_yxx.cxx"
    break;

  case 150: /* wall_height: HEIGHT '[' number ']'  */
#line 773 "dna.yxx"
{
  DCAST(DNAWall, _cur_comp)->set_height((yyvsp[-1].u.real));
}
#line 2630 "dna_yxx.cxx"
    break;

  case 151: /* stomp: STOMP '[' number ']'  */
#line 778 "dna.yxx"
{
  DCAST(DNASignBaseline, _cur_comp)->set_stomp((yyvsp[-1].u.real));
}
#line 2638 "dna_yxx.cxx"
    break;

  case 152: /* indent: INDENT '[' number ']'  */
#line 783 "dna.yxx"
{
  DCAST(DNASignBaseline, _cur_comp)->set_indent((yyvsp[-1].u.real));
}
#line 2646 "dna_yxx.cxx"
    break;

  case 153: /* kern: KERN '[' number ']'  */
#line 788 "dna.yxx"
{
  DCAST(DNASignBaseline, _cur_comp)->set_kern((yyvsp[-1].u.real));
}
#line 2654 "dna_yxx.cxx"
    break;

  case 154: /* stumble: STUMBLE '[' number ']'  */
#line 793 "dna.yxx"
{
  DCAST(DNASignBaseline, _cur_comp)->set_stumble((yyvsp[-1].u.real));
}
#line 2662 "dna_yxx.cxx"
    break;

  case 155: /* wiggle: WIGGLE '[' number ']'  */
#line 798 "dna.yxx"
{
  DCAST(DNASignBaseline, _cur_comp)->set_wiggle((yyvsp[-1].u.real));
}
#line 2670 "dna_yxx.cxx"
    break;

  case 156: /* prop_code: CODE '[' string ']'  */
#line 803 "dna.yxx"
{
  DCAST(DNAProp, _cur_comp)->set_code((yyvsp[-1].str));
}
#line 2678 "dna_yxx.cxx"
    break;

  case 157: /* landmarkbuilding_code: CODE '[' string ']'  */
#line 808 "dna.yxx"
{
  DCAST(DNALandmarkBuilding, _cur_comp)->set_code((yyvsp[-1].str));
}
#line 2686 "dna_yxx.cxx"
    break;

  case 158: /* baseline_code: CODE '[' string ']'  */
#line 813 "dna.yxx"
{
  DCAST(DNASignBaseline, _cur_comp)->set_code((yyvsp[-1].str));
}
#line 2694 "dna_yxx.cxx"
    break;

  case 159: /* door_code: CODE '[' string ']'  */
#line 818 "dna.yxx"
{
  DCAST(DNADoor, _cur_comp)->set_code((yyvsp[-1].str));
}
#line 2702 "dna_yxx.cxx"
    break;

  case 160: /* signgraphic_code: CODE '[' string ']'  */
#line 823 "dna.yxx"
{
  DCAST(DNASignGraphic, _cur_comp)->set_code((yyvsp[-1].str));
}
#line 2710 "dna_yxx.cxx"
    break;

  case 161: /* cornice_code: CODE '[' string ']'  */
#line 828 "dna.yxx"
{
  DCAST(DNACornice, _cur_comp)->set_code((yyvsp[-1].str));
}
#line 2718 "dna_yxx.cxx"
    break;

  case 162: /* street_code: CODE '[' string ']'  */
#line 833 "dna.yxx"
{
  DCAST(DNAStreet, _cur_comp)->set_code((yyvsp[-1].str));
}
#line 2726 "dna_yxx.cxx"
    break;

  case 163: /* wall_code: CODE '[' string ']'  */
#line 838 "dna.yxx"
{
  DCAST(DNAWall, _cur_comp)->set_code((yyvsp[-1].str));
}
#line 2734 "dna_yxx.cxx"
    break;

  case 164: /* windows_code: CODE '[' string ']'  */
#line 843 "dna.yxx"
{
  DCAST(DNAWindows, _cur_comp)->set_code((yyvsp[-1].str));
}
#line 2742 "dna_yxx.cxx"
    break;

  case 165: /* prop_color: COLOR '[' number number number number ']'  */
#line 848 "dna.yxx"
{
  LVecBase4f color((yyvsp[-4].u.real), (yyvsp[-3].u.real), (yyvsp[-2].u.real), (yyvsp[-1].u.real));
  DCAST(DNAProp, _cur_comp)->set_color(color);
}
#line 2751 "dna_yxx.cxx"
    break;

  case 166: /* baseline_color: COLOR '[' number number number number ']'  */
#line 854 "dna.yxx"
{
  LVecBase4f color((yyvsp[-4].u.real), (yyvsp[-3].u.real), (yyvsp[-2].u.real), (yyvsp[-1].u.real));
  DCAST(DNASignBaseline, _cur_comp)->set_color(color);
}
#line 2760 "dna_yxx.cxx"
    break;

  case 167: /* door_color: COLOR '[' number number number number ']'  */
#line 860 "dna.yxx"
{
  LVecBase4f color((yyvsp[-4].u.real), (yyvsp[-3].u.real), (yyvsp[-2].u.real), (yyvsp[-1].u.real));
  DCAST(DNADoor, _cur_comp)->set_color(color);
}
#line 2769 "dna_yxx.cxx"
    break;

  case 168: /* signgraphic_color: COLOR '[' number number number number ']'  */
#line 866 "dna.yxx"
{
  LVecBase4f color((yyvsp[-4].u.real), (yyvsp[-3].u.real), (yyvsp[-2].u.real), (yyvsp[-1].u.real));
  DCAST(DNASignGraphic, _cur_comp)->set_color(color);
}
#line 2778 "dna_yxx.cxx"
    break;

  case 169: /* cornice_color: COLOR '[' number number number number ']'  */
#line 872 "dna.yxx"
{
  LVecBase4f color((yyvsp[-4].u.real), (yyvsp[-3].u.real), (yyvsp[-2].u.real), (yyvsp[-1].u.real));
  DCAST(DNACornice, _cur_comp)->set_color(color);
}
#line 2787 "dna_yxx.cxx"
    break;

  case 170: /* wall_color: COLOR '[' number number number number ']'  */
#line 878 "dna.yxx"
{
  LVecBase4f color((yyvsp[-4].u.real), (yyvsp[-3].u.real), (yyvsp[-2].u.real), (yyvsp[-1].u.real));
  DCAST(DNAWall, _cur_comp)->set_color(color);
}
#line 2796 "dna_yxx.cxx"
    break;

  case 171: /* windows_color: COLOR '[' number number number number ']'  */
#line 884 "dna.yxx"
{
  LVecBase4f color((yyvsp[-4].u.real), (yyvsp[-3].u.real), (yyvsp[-2].u.real), (yyvsp[-1].u.real));
  DCAST(DNAWindows, _cur_comp)->set_color(color);
}
#line 2805 "dna_yxx.cxx"
    break;

  case 220: /* modeldef: MODEL string  */
#line 968 "dna.yxx"
{
  _model_type = "model";
  _model_name = (yyvsp[0].str);
}
#line 2814 "dna_yxx.cxx"
    break;

  case 221: /* modeldef: HOODMODEL string  */
#line 973 "dna.yxx"
{
  _model_type = "hood_model";
  _model_name = (yyvsp[0].str);
}
#line 2823 "dna_yxx.cxx"
    break;

  case 222: /* modeldef: PLACEMODEL string  */
#line 978 "dna.yxx"
{
  _model_type = "place_model";
  _model_name = (yyvsp[0].str);
}
#line 2832 "dna_yxx.cxx"
    break;

  case 226: /* node: STORE_NODE '[' string string ']'  */
#line 991 "dna.yxx"
{
  _store_model((yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[-1].str));
}
#line 2840 "dna_yxx.cxx"
    break;

  case 227: /* node: STORE_NODE '[' string string string ']'  */
#line 995 "dna.yxx"
{
  _store_model((yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str));
}
#line 2848 "dna_yxx.cxx"
    break;

  case 228: /* store_texture: STORE_TEXTURE '[' string string ']'  */
#line 1000 "dna.yxx"
{
  _store->store_texture((yyvsp[-2].str), TexturePool::load_texture((yyvsp[-1].str)));
}
#line 2856 "dna_yxx.cxx"
    break;

  case 229: /* store_texture: STORE_TEXTURE '[' string string string ']'  */
#line 1004 "dna.yxx"
{
  _store->store_catalog_code((yyvsp[-3].str), (yyvsp[-2].str));
  _store->store_texture((yyvsp[-2].str), TexturePool::load_texture((yyvsp[-1].str)));
}
#line 2865 "dna_yxx.cxx"
    break;

  case 230: /* font: STORE_FONT '[' string string string ']'  */
#line 1010 "dna.yxx"
{
  _store->store_catalog_code((yyvsp[-3].str), (yyvsp[-2].str));

  Filename filename((yyvsp[-1].str));
  if (!filename.get_extension().size())
    filename.set_extension("bam");

  _store->store_font((yyvsp[-2].str), FontPool::load_font(filename), filename);
}
#line 2879 "dna_yxx.cxx"
    break;


#line 2883 "dna_yxx.cxx"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

