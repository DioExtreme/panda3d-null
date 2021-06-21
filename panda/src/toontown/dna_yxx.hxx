/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_DNAYY_DNA_YXX_HXX_INCLUDED
# define YY_DNAYY_DNA_YXX_HXX_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int dnayydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SIGNED_INTEGER = 258,          /* SIGNED_INTEGER  */
    UNSIGNED_INTEGER = 259,        /* UNSIGNED_INTEGER  */
    FLOAT_REAL = 260,              /* FLOAT_REAL  */
    UNQUOTED_STRING = 261,         /* UNQUOTED_STRING  */
    QUOTED_STRING = 262,           /* QUOTED_STRING  */
    STORE_SUIT_POINT = 263,        /* STORE_SUIT_POINT  */
    GROUP = 264,                   /* GROUP  */
    VISGROUP = 265,                /* VISGROUP  */
    VIS = 266,                     /* VIS  */
    DNA_STREET_POINT = 267,        /* DNA_STREET_POINT  */
    DNA_FRONT_DOOR_POINT = 268,    /* DNA_FRONT_DOOR_POINT  */
    DNA_SIDE_DOOR_POINT = 269,     /* DNA_SIDE_DOOR_POINT  */
    DNA_COGHQ_IN_POINT = 270,      /* DNA_COGHQ_IN_POINT  */
    DNA_COGHQ_OUT_POINT = 271,     /* DNA_COGHQ_OUT_POINT  */
    SUIT_EDGE = 272,               /* SUIT_EDGE  */
    BATTLE_CELL = 273,             /* BATTLE_CELL  */
    PROP = 274,                    /* PROP  */
    POS = 275,                     /* POS  */
    HPR = 276,                     /* HPR  */
    SCALE = 277,                   /* SCALE  */
    CODE = 278,                    /* CODE  */
    COLOR = 279,                   /* COLOR  */
    MODEL = 280,                   /* MODEL  */
    STORE_NODE = 281,              /* STORE_NODE  */
    SIGN = 282,                    /* SIGN  */
    BASELINE = 283,                /* BASELINE  */
    WIDTH = 284,                   /* WIDTH  */
    HEIGHT = 285,                  /* HEIGHT  */
    STOMP = 286,                   /* STOMP  */
    STUMBLE = 287,                 /* STUMBLE  */
    INDENT = 288,                  /* INDENT  */
    WIGGLE = 289,                  /* WIGGLE  */
    KERN = 290,                    /* KERN  */
    TEXT = 291,                    /* TEXT  */
    LETTERS = 292,                 /* LETTERS  */
    STORE_FONT = 293,              /* STORE_FONT  */
    FLAT_BUILDING = 294,           /* FLAT_BUILDING  */
    WALL = 295,                    /* WALL  */
    WINDOWS = 296,                 /* WINDOWS  */
    COUNT = 297,                   /* COUNT  */
    CORNICE = 298,                 /* CORNICE  */
    LANDMARK_BUILDING = 299,       /* LANDMARK_BUILDING  */
    TITLE = 300,                   /* TITLE  */
    ARTICLE = 301,                 /* ARTICLE  */
    BUILDING_TYPE = 302,           /* BUILDING_TYPE  */
    DOOR = 303,                    /* DOOR  */
    STORE_TEXTURE = 304,           /* STORE_TEXTURE  */
    STREET = 305,                  /* STREET  */
    TEXTURE = 306,                 /* TEXTURE  */
    GRAPHIC = 307,                 /* GRAPHIC  */
    HOODMODEL = 308,               /* HOODMODEL  */
    PLACEMODEL = 309,              /* PLACEMODEL  */
    FLAGS = 310,                   /* FLAGS  */
    NODE = 311,                    /* NODE  */
    FLAT_DOOR = 312,               /* FLAT_DOOR  */
    ANIM = 313,                    /* ANIM  */
    CELL_ID = 314,                 /* CELL_ID  */
    ANIM_PROP = 315,               /* ANIM_PROP  */
    INTERACTIVE_PROP = 316,        /* INTERACTIVE_PROP  */
    ANIM_BUILDING = 317            /* ANIM_BUILDING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define SIGNED_INTEGER 258
#define UNSIGNED_INTEGER 259
#define FLOAT_REAL 260
#define UNQUOTED_STRING 261
#define QUOTED_STRING 262
#define STORE_SUIT_POINT 263
#define GROUP 264
#define VISGROUP 265
#define VIS 266
#define DNA_STREET_POINT 267
#define DNA_FRONT_DOOR_POINT 268
#define DNA_SIDE_DOOR_POINT 269
#define DNA_COGHQ_IN_POINT 270
#define DNA_COGHQ_OUT_POINT 271
#define SUIT_EDGE 272
#define BATTLE_CELL 273
#define PROP 274
#define POS 275
#define HPR 276
#define SCALE 277
#define CODE 278
#define COLOR 279
#define MODEL 280
#define STORE_NODE 281
#define SIGN 282
#define BASELINE 283
#define WIDTH 284
#define HEIGHT 285
#define STOMP 286
#define STUMBLE 287
#define INDENT 288
#define WIGGLE 289
#define KERN 290
#define TEXT 291
#define LETTERS 292
#define STORE_FONT 293
#define FLAT_BUILDING 294
#define WALL 295
#define WINDOWS 296
#define COUNT 297
#define CORNICE 298
#define LANDMARK_BUILDING 299
#define TITLE 300
#define ARTICLE 301
#define BUILDING_TYPE 302
#define DOOR 303
#define STORE_TEXTURE 304
#define STREET 305
#define TEXTURE 306
#define GRAPHIC 307
#define HOODMODEL 308
#define PLACEMODEL 309
#define FLAGS 310
#define NODE 311
#define FLAT_DOOR 312
#define ANIM 313
#define CELL_ID 314
#define ANIM_PROP 315
#define INTERACTIVE_PROP 316
#define ANIM_BUILDING 317

/* Value type.  */


extern YYSTYPE dnayylval;

int dnayyparse (void);

#endif /* !YY_DNAYY_DNA_YXX_HXX_INCLUDED  */
