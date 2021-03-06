/*********************************************************************
 *                
 * Copyright (C) 1999, 2000, 2001,  Karlsruhe University
 *                
 * File path:     l4ms/x86/compiler.h
 * Description:   compiler helpers - not adopted yet
 *                
 * @LICENSE@
 *                
 * $Id: compiler.h,v 1.2 2001/12/13 08:47:30 uhlig Exp $
 *                
 ********************************************************************/

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

#include <linux/linkage.h>

#endif
