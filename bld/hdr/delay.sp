#ifndef _DELAY_DEFINED
#define _DELAY_DEFINED
:segment QNX | LINUX
_WCRTLINK extern unsigned delay(unsigned int __milliseconds);
:elsesegment
_WCRTLINK extern void    delay(unsigned int __milliseconds);
:endsegment
#endif
