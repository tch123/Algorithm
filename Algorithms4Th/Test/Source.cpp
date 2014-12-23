#include<cstdio>

inline __int64 GetCPUTickCount()
{
	_asm
	{
		rdtsc;
	}
}

int main()
{
	auto z = GetCPUTickCount();
	printf("%d", z);

}
