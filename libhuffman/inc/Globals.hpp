#ifndef GLOBALS_HPP
#define GLOBALS_HPP

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <unordered_map>
#include <list>
#include <cstddef>
#include <bitset>
#include <set>
#define ASCII_SIZE 256
#define READMAX 1<<15

typedef unsigned long long ulong_64;
typedef unsigned char uchar;

#define TEST if(1) {
#define END }

#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif
#define  chk_err(M, ...) fprintf(stderr, "[ERROR] in function %s \n(%s:%d: errno: %s) " M "\n", __PRETTY_FUNCTION__ ,__FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)
#define clean_errno() (errno == 0 ? "None" : strerror(errno))
#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)
#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)
#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }
#define sentinel(M, ...)  { log_err(M, ##__VA_ARGS__); errno=0; goto error; }
#define check_mem(A) check((A), "Out of memory.")
#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }

#endif /* end of include guard: GLOBALS_HPP */
