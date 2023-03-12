#ifndef GLOBAL_MACROS_DEF_H

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
# define RESTRICT restrict
#elif defined(__GNUC__) || defined(__clang__)
# define RESTRICT __restrict__
#elif defined(_MSC_VER)
# define RESTRICT __restrict
#else
# define RESTRICT
#endif

#if defined(__GNUC__) || defined(__clang__)
    #define ALWAYS_INLINE __attribute__((always_inline)) inline
#elif defined(_MSC_VER)
    #define ALWAYS_INLINE __forceinline inline
#else
    #define ALWAYS_INLINE inline
#endif

#if defined(__PRETTY_FUNCTION__)
	#define CURR_FUNC __PRETTY_FUNCTION__
#elif defined(__FUNCTION__)
	#define CURR_FUNC __FUNCTION__
#elif defined(__func__)
	#define CURR_FUNC __func__
#else
	#define CURR_FUNC ""
#endif

#if (defined(__GNUC__) && (__GNUC__ >= 3)) || (defined(__clang__) && __has_builtin(__builtin_expect))
  #define likely(x) __builtin_expect(!!(x), 1)
  #define unlikely(x) __builtin_expect(!!(x), 0)
#else
  #define likely(x) (x)
  #define unlikely(x) (x)
#endif

#if defined(__GNUC__) || defined(__clang__)
    #if __has_attribute(pure)
        #define PURE __attribute__((pure))
    #else
        #define PURE
    #endif

    #if __has_attribute(const)
        #define CONST __attribute__((const))
    #else
        #define CONST
    #endif

    #if __has_attribute(flatten)
        #define FLATTEN __attribute__((flatten))
    #else
        #define FLATTEN
    #endif
#elif defined(_MSC_VER)
    #define PURE __declspec(noalias)
    #define CONST __declspec(restrict)
    #define FLATTEN
#else
    #define PURE
    #define CONST
    #define FLATTEN
#endif

#define pp_cout(x) _Generic((x),   \
	char: printf("%c\n", x),   \
	char*: printf("%s\n", x),  \
	int: printf("%d\n", x),    \
	double: printf("%f\n", x), \
	float: printf("%f\n", x),  \
	void*: printf("%p\n", x)   \
	)

#define CASE_VOWEL_LOWER case 'a': case 'i': case 'u': case 'e': case 'o':
#define CASE_VOWEL_UPPER case 'A': case 'I': case 'U': case 'E': case 'O':
#define CASE_VOWEL CASE_VOWEL_UPPER CASE_VOWEL_LOWER

#define CASE_CONSONANT_LOWER case 'b': case 'c': case 'd': case 'f': case 'g': case 'h': case 'j': case 'k': case 'l': case 'm': case 'n': case 'p': case 'q': case 'r': case 's': case 't': case 'v': case 'w': case 'x': case 'y': case 'z':
#define CASE_CONSONANT_UPPER case 'B': case 'C': case 'D': case 'F': case 'G': case 'H': case 'J': case 'K': case 'L': case 'M': case 'N': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'V': case 'W': case 'X': case 'Y': case 'Z':
#define CASE_CONSONANT CASE_CONSONANT_UPPER CASE_CONSONANT_LOWER

#define CASE_DIGIT case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
#define CASE_LOWER case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
#define CASE_UPPER case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z':

#define CASE_ALPHA CASE_LOWER CASE_UPPER
#define CASE_ALPHANUM CASE_DIGIT CASE_ALPHA

/* switch (cond) { */
/* 	case 'a': p = 97; */
/* 	case 'b': p = 98; */
/* 	case 'c': p = 99; */
/* 	case 'd': p = 100; */
/* 	case 'e': p = 101; */
/* 	case 'f': p = 102; */
/* 	case 'g': p = 103; */
/* 	case 'h': p = 104; */
/* 	case 'i': p = 105; */
/* 	case 'j': p = 106; */
/* 	case 'k': p = 107; */
/* 	case 'l': p = 108; */
/* 	case 'm': p = 109; */
/* 	case 'n': p = 110; */
/* 	case 'o': p = 111; */
/* 	case 'p': p = 112; */
/* 	case 'q': p = 113; */
/* 	case 'r': p = 114; */
/* 	case 's': p = 115; */
/* 	case 't': p = 116; */
/* 	case 'u': p = 117; */
/* 	case 'v': p = 118; */
/* 	case 'w': p = 119; */
/* 	case 'x': p = 120; */
/* 	case 'y': p = 121; */
/* 	case 'z': p = 122; */
/* 	case 'A': p = 65; */
/* 	case 'B': p = 66; */
/* 	case 'C': p = 67; */
/* 	case 'D': p = 68; */
/* 	case 'E': p = 69; */
/* 	case 'F': p = 70; */
/* 	case 'G': p = 71; */
/* 	case 'H': p = 72; */
/* 	case 'I': p = 73; */
/* 	case 'J': p = 74; */
/* 	case 'K': p = 75; */
/* 	case 'L': p = 76; */
/* 	case 'M': p = 77; */
/* 	case 'N': p = 78; */
/* 	case 'O': p = 79; */
/* 	case 'P': p = 80; */
/* 	case 'Q': p = 81; */
/* 	case 'R': p = 82; */
/* 	case 'S': p = 83; */
/* 	case 'T': p = 84; */
/* 	case 'U': p = 85; */
/* 	case 'V': p = 86; */
/* 	case 'W': p = 87; */
/* 	case 'X': p = 88; */
/* 	case 'Y': p = 89; */
/* 	case 'Z': p = 90; */
/* } */

/* 	switch (*start) { */
/* 	case 'a': p = dict[97 - 72]; break; */
/* 	case 'b': p = dict[98 - 72]; break; */
/* 	case 'c': p = dict[99 - 72]; break; */
/* 	case 'd': p = dict[100 - 72]; break; */
/* 	case 'e': p = dict[101 - 72]; break; */
/* 	case 'f': p = dict[102 - 72]; break; */
/* 	case 'g': p = dict[103 - 72]; break; */
/* 	case 'h': p = dict[104 - 72]; break; */
/* 	case 'i': p = dict[105 - 72]; break; */
/* 	case 'j': p = dict[106 - 72]; break; */
/* 	case 'k': p = dict[107 - 72]; break; */
/* 	case 'l': p = dict[108 - 72]; break; */
/* 	case 'm': p = dict[109 - 72]; break; */
/* 	case 'n': p = dict[110 - 72]; break; */
/* 	case 'o': p = dict[111 - 72]; break; */
/* 	case 'p': p = dict[112 - 72]; break; */
/* 	case 'q': p = dict[113 - 72]; break; */
/* 	case 'r': p = dict[114 - 72]; break; */
/* 	case 's': p = dict[115 - 72]; break; */
/* 	case 't': p = dict[116 - 72]; break; */
/* 	case 'u': p = dict[117 - 72]; break; */
/* 	case 'v': p = dict[118 - 72]; break; */
/* 	case 'w': p = dict[119 - 72]; break; */
/* 	case 'x': p = dict[120 - 72]; break; */
/* 	case 'y': p = dict[121 - 72]; break; */
/* 	case 'z': p = dict[122 - 72]; break; */
/* 	case 'A': p = dict[65 - 65]; break; */
/* 	case 'B': p = dict[66 - 65]; break; */
/* 	case 'C': p = dict[67 - 65]; break; */
/* 	case 'D': p = dict[68 - 65]; break; */
/* 	case 'E': p = dict[69 - 65]; break; */
/* 	case 'F': p = dict[70 - 65]; break; */
/* 	case 'G': p = dict[71 - 65]; break; */
/* 	case 'H': p = dict[72 - 65]; break; */
/* 	case 'I': p = dict[73 - 65]; break; */
/* 	case 'J': p = dict[74 - 65]; break; */
/* 	case 'K': p = dict[75 - 65]; break; */
/* 	case 'L': p = dict[76 - 65]; break; */
/* 	case 'M': p = dict[77 - 65]; break; */
/* 	case 'N': p = dict[78 - 65]; break; */
/* 	case 'O': p = dict[79 - 65]; break; */
/* 	case 'P': p = dict[80 - 65]; break; */
/* 	case 'Q': p = dict[81 - 65]; break; */
/* 	case 'R': p = dict[82 - 65]; break; */
/* 	case 'S': p = dict[83 - 65]; break; */
/* 	case 'T': p = dict[84 - 65]; break; */
/* 	case 'U': p = dict[85 - 65]; break; */
/* 	case 'V': p = dict[86 - 65]; break; */
/* 	case 'W': p = dict[87 - 65]; break; */
/* 	case 'X': p = dict[88 - 65]; break; */
/* 	case 'Y': p = dict[89 - 65]; break; */
/* 	case 'Z': p = dict[90 - 65]; break; */
/* 	} */

#endif
