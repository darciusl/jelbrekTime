#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>             // uint*_t

#define LOG(str, args...) do { NSLog(@str "\n", ##args); } while(0)
#ifdef __LP64__
#   define ADDR                 "0x%016llx"
#   define MACH_HEADER_MAGIC    MH_MAGIC_64
#   define MACH_LC_SEGMENT      LC_SEGMENT_64
    typedef struct mach_header_64 mach_hdr_t;
    typedef struct segment_command_64 mach_seg_t;
    typedef uint64_t kptr_t;
#else
#   define ADDR                 "0x%08x"
#   define MACH_HEADER_MAGIC    MH_MAGIC
#   define MACH_LC_SEGMENT      LC_SEGMENT
    typedef struct mach_header mach_hdr_t;
    typedef struct segment_command mach_seg_t;
    typedef uint32_t kptr_t;
#endif
typedef struct load_command mach_lc_t;

#endif
