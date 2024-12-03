#pragma once

#ifndef PROJECT_HYDROGEN_PLATFORM_PLATFORM_H
#define PROJECT_HYDROGEN_PLATFORM_PLATFORM_H

// Windows platform checks
#ifdef _WIN32
#ifdef _WIN64
#define PROJECT_HYDROGEN_PLATFORM_WINDOWS_64
#else
#error "Only 64-bit Windows is supported"
#endif

// Linux platform checks
#elif defined(__linux__)
#if defined(__x86_64__) || defined(__ppc64__)
// 64-bit Linux, do nothing
#elif defined(__i386__) || defined(__arm__)
#error "Only 64-bit Linux is supported. Get a 64-bit system, please."
#else
#error "Unknown Linux architecture. Only 64-bit Linux is supported."
#endif

// macOS platform check
#elif defined(__APPLE__) && defined(__MACH__)
#error "macOS? Please buy real hardware."

// Error for unsupported platforms
#else
#error "Unsupported platform. Only Windows, Linux, and macOS are supported."
#endif

#endif // PROJECT_HYDROGEN_PLATFORM_PLATFORM_H
