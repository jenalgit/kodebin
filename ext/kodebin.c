
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "kodebin.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *kodebin_lib_curl_ce;
zend_class_entry *kodebin_lib_dir_ce;
zend_class_entry *kodebin_lib_files_ce;
zend_class_entry *kodebin_lib_folder_ce;
zend_class_entry *kodebin_security_password_ce;
zend_class_entry *kodebin_security_patch_ce;

ZEND_DECLARE_MODULE_GLOBALS(kodebin)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(kodebin)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(Kodebin_Lib_Curl);
	ZEPHIR_INIT(Kodebin_Lib_Dir);
	ZEPHIR_INIT(Kodebin_Lib_Files);
	ZEPHIR_INIT(Kodebin_Lib_Folder);
	ZEPHIR_INIT(Kodebin_Security_Password);
	ZEPHIR_INIT(Kodebin_Security_Patch);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(kodebin)
{

	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_kodebin_globals *kodebin_globals TSRMLS_DC)
{
	kodebin_globals->initialized = 0;

	/* Memory options */
	kodebin_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	kodebin_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	kodebin_globals->cache_enabled = 1;

	/* Recursive Lock */
	kodebin_globals->recursive_lock = 0;

	/* Static cache */
	memset(kodebin_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

static PHP_RINIT_FUNCTION(kodebin)
{

	zend_kodebin_globals *kodebin_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(kodebin_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(kodebin_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(kodebin)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(kodebin)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_KODEBIN_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_KODEBIN_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_KODEBIN_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_KODEBIN_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_KODEBIN_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(kodebin)
{
	php_zephir_init_globals(kodebin_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(kodebin)
{

}


zend_function_entry php_kodebin_functions[] = {
ZEND_FE_END

};

zend_module_entry kodebin_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_KODEBIN_EXTNAME,
	php_kodebin_functions,
	PHP_MINIT(kodebin),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(kodebin),
#else
	NULL,
#endif
	PHP_RINIT(kodebin),
	PHP_RSHUTDOWN(kodebin),
	PHP_MINFO(kodebin),
	PHP_KODEBIN_VERSION,
	ZEND_MODULE_GLOBALS(kodebin),
	PHP_GINIT(kodebin),
	PHP_GSHUTDOWN(kodebin),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_KODEBIN
ZEND_GET_MODULE(kodebin)
#endif
