#pragma once

#if defined _WIN32 || _WIN64
void usleep(__int64 usec);

#elif __APPLE__
#	include <unistd.h>
#endif /* _WIN32 || _WIN64 */
