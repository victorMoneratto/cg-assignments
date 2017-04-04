#pragma once

#include <defer.hpp>

////////////////////
// Debugging
////////////////////
#ifndef NDEBUG
#define DEBUGGING true
#else 
#define DEBUGGING false
#endif

#ifdef _MSC_VER
#define MSVC
#endif

#ifdef MSVC
#include <Windows.h>
#define RaiseBreakpoint() do {if(IsDebuggerPresent()) { DebugBreak(); }} while(0)
#else
#include <csignal>
#define RaiseBreakpoint() std::raise(SIGINT) // NOTE: Maybe use __asm__("int $3") intead for x86?
#endif

#include <cstdio>
#define Assert(Exp) do {if(!(Exp)) { fprintf(stderr, "Assertion Failed: (%s) on %s:%d\n", #Exp, __FILE__, __LINE__); RaiseBreakpoint(); }} while(0)

#define StaticAssert(...) static_assert(__VA_ARGS__, #__VA_ARGS__)

////////////////////
// Numbers
////////////////////
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

// Signed integers
typedef glm::int8  int8;
typedef glm::int16 int16;
typedef glm::int32 int32;
typedef glm::int64 int64;

typedef int8  i8;
typedef int16 i16;
typedef int32 i32;
typedef int64 i64;

// Unsigned integers
typedef glm::uint	uint;
typedef glm::uint8	uint8;
typedef glm::uint16 uint16;
typedef glm::uint32 uint32;
typedef glm::uint64 uint64;

typedef uint8	u8;
typedef uint16 u16;
typedef uint32 u32;
typedef uint64 u64;

// Boolean
typedef i8 bool8;
typedef bool8 b8;
typedef i32 bool32;
typedef bool32 b32;

// Real numbers
typedef glm::float32 f32;
typedef glm::float64 f64;

// Memory
typedef glm::length_t size; 

// Constants
#include <glm/gtc/constants.hpp>
constexpr f32 Pi = glm::pi<f32>();

////////////////////
// String
////////////////////
#include <string>

/************************************************/
/* TYPE INFORMATION								*/
/************************************************/
#include <cstddef>
#define OffsetOf(type, Member) (offsetof(type, Member))
#define SizeOf(exp) (sizeof(exp))
#define AlignOf(exp) (alignof(exp))
#define ArraySize(array) (SizeOf(array)/SizeOf(*array))

#define Unused(Var) (void)Var

////////////////////
// Input/Output
////////////////////

// Printf version
#define LogError(...) fprintf(stderr, __VA_ARGS__)

#if 0
// Cout version
#include <iostream>
void Log() {
	std::cout << "\n";
}

template <typename t, typename... t_others>
void Log (const t& Value, const t_others& ... Others) {
	std::cout << Value;
	Log(Others...);
}
#endif

// Filename Max Size
#define FilenameMax FILENAME_MAX

