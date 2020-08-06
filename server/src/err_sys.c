#include "err_sys.h"

void err_sys(const char* str,int nstate)
{
	perror(str);
	exit(nstate);
}
