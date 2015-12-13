
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_KODEBIN_H
#define PHP_KODEBIN_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_KODEBIN_NAME        "kodebin"
#define PHP_KODEBIN_VERSION     "0.0.1"
#define PHP_KODEBIN_EXTNAME     "kodebin"
#define PHP_KODEBIN_AUTHOR      ""
#define PHP_KODEBIN_ZEPVERSION  "0.9.1a-dev"
#define PHP_KODEBIN_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(kodebin)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(kodebin)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(kodebin)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(kodebin_globals_id, zend_kodebin_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (kodebin_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_kodebin_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(kodebin_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(kodebin_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def kodebin_globals
#define zend_zephir_globals_def zend_kodebin_globals

extern zend_module_entry kodebin_module_entry;
#define phpext_kodebin_ptr &kodebin_module_entry

#endif
