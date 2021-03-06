#ifndef __L4_COMPILER_H__ 
#define __L4_COMPILER_H__ 

#ifndef __ASSEMBLY__

#ifndef __GNUC__
#error "The libl4sys library must be used with Gcc."
#endif

#ifndef __cplusplus
# ifdef __OPTIMIZE__
#  define L4_INLINE extern __inline__
# else /* ! __OPTIMIZE__ */
#  define L4_INLINE static
# endif /* ! __OPTIMIZE__ */
#else /* __cplusplus */
# define L4_INLINE inline
#endif /* __cplusplus */

#define L4_NORETURN __attribute__((noreturn))

#endif /* !__ASSEMBLY__ */

#include "linkage.h"

#endif
