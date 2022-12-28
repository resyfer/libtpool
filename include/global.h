#ifndef __LIBTPOOL_GLOBAL_H
#define __LIBTPOOL_GLOBAL_H

#ifndef OS
	#ifdef __unix__
		#ifdef __linux__
			#define OS "Linux"
		#else
			#define OS "Unix"
		#endif
	#elif __APPLE__
		#define OS "Darwin"
	#elif _WIN32
		#define OS "Win32"
	#endif
#endif

#endif