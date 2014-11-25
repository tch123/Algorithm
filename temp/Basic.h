/****************************** Module Header ******************************\
Filename:		V_Type.h
Project:		Vonng
Digest:			Basic data type and useful contant definiation
Author:			Feng Ruohang
Create:			2014/11/18 23:23
LastModify:		2014/11/18 23:36

Comment:		Reference: Vczh Library++ 2.0
\****************************** Module Header ******************************/

#ifndef _V_TYPE
#define _V_TYPE

#ifdef NDEBUG
#define __V_DISABLE_ALL_DEBUG_MARCO__
#endif

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#ifdef _WIN64
#define VONNG_64
#endif


namespace Vonng
{

    /* 32/64 Compatible */
#ifdef VCZH_64
    typedef __int64					vint;
    typedef signed __int64			vsint;
    typedef unsigned __int64		vuint;
#else
    typedef __int32					vint;
    typedef signed __int32			vsint;
    typedef unsigned __int32		vuint;
#endif

    //Nickname

    //int
    typedef unsigned	__int8		vuint8;	
    typedef signed		__int8		vint8 ;
    typedef unsigned	__int16		vuint16;
    typedef signed		__int16		vint16;
    typedef unsigned	__int32		vuint32;
    typedef signed		__int32		vint32;	
    typedef unsigned	__int64		vuint64;
    typedef signed		__int64		vint64;

    typedef unsigned char			vbyte;
    typedef vbyte*					vbuffer;
    typedef const char*             cstr;
    typedef __int64					vsize;

}
#endif