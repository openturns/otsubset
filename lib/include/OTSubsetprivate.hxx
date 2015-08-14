
#ifndef OTSUBSET_PRIVATE_HXX
#define OTSUBSET_PRIVATE_HXX

/* From http://gcc.gnu.org/wiki/Visibility */
/* Generic helper definitions for shared library support */
#if defined _WIN32 || defined __CYGWIN__
#define OTSUBSET_HELPER_DLL_IMPORT __declspec(dllimport)
#define OTSUBSET_HELPER_DLL_EXPORT __declspec(dllexport)
#define OTSUBSET_HELPER_DLL_LOCAL
#else
#if __GNUC__ >= 4
#define OTSUBSET_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
#define OTSUBSET_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
#define OTSUBSET_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#else
#define OTSUBSET_HELPER_DLL_IMPORT
#define OTSUBSET_HELPER_DLL_EXPORT
#define OTSUBSET_HELPER_DLL_LOCAL
#endif
#endif

/* Now we use the generic helper definitions above to define OTSUBSET_API and OTSUBSET_LOCAL.
 * OTSUBSET_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
 * OTSUBSET_LOCAL is used for non-api symbols. */

#ifndef OTSUBSET_STATIC /* defined if OT is compiled as a DLL */
#ifdef OTSUBSET_DLL_EXPORTS /* defined if we are building the OT DLL (instead of using it) */
#define OTSUBSET_API OTSUBSET_HELPER_DLL_EXPORT
#else
#define OTSUBSET_API OTSUBSET_HELPER_DLL_IMPORT
#endif /* OTSUBSET_DLL_EXPORTS */
#define OTSUBSET_LOCAL OTSUBSET_HELPER_DLL_LOCAL
#else /* OTSUBSET_STATIC is defined: this means OT is a static lib. */
#define OTSUBSET_API
#define OTSUBSET_LOCAL
#endif /* !OTSUBSET_STATIC */


#endif // OTSUBSET_PRIVATE_HXX

