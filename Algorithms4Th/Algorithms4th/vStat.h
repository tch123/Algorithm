/****************************** Module Header ******************************\
Filename:		vStat.h
Project:		Vonng::Math
Digest:		    Statistic Util
Author:			Feng Ruohang
Create:			2014/12/11
LastModify:		2014/12/11
\****************************** Module Header ******************************/


#ifndef _V_STAT
#define _V_STAT

#ifdef NDEBUG
#define _V_DISABLE_DEBUG
#endif

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS


#include "vBasic.h"
#include <vector>

namespace Vonng
{
	namespace Stat
	{
		auto max(const vint data[], vint size)->vint;
		auto max(const double data[], double size)->double;
		
		//auto max(std::iterator begin,std::iterator end)->double;
		

		
	}
}






#endif