#pragma once

#ifndef PROJECT_HYDROGEN_PLATFROM_PLATFORM_HH
#define PROJECT_HYDROGEN_PLATFROM_PLATFORM_HH

#ifdef _WIN32

#ifdef _WIN64
#define PROJECT_HYDROGEN_PLATFORM_WINDOWS_64
#else
#error "Only 64-bit Windows is supported"
#endif

#else

#error "Only Windows is supported"

#endif // _WIN32

#endif // PROJECT_HYDROGEN_PLATFROM_PLATFORM_HH
