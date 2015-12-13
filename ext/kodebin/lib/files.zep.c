
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Kodebin_Lib_Files) {

	ZEPHIR_REGISTER_CLASS(Kodebin\\Lib, Files, kodebin, lib_files, kodebin_lib_files_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Kodebin_Lib_Files, create) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, *content_param = NULL, *file = NULL, _0;
	zval *location = NULL, *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &location_param, &content_param);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(location, location_param);
	} else {
		ZEPHIR_INIT_VAR(location);
		ZVAL_EMPTY_STRING(location);
	}
	if (unlikely(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(content, content_param);
	} else {
		ZEPHIR_INIT_VAR(content);
		ZVAL_EMPTY_STRING(content);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "w", 0);
	ZEPHIR_CALL_FUNCTION(&file, "fopen", NULL, 5, location, &_0);
	zephir_check_call_status();
	zephir_fwrite(NULL, file, content TSRMLS_CC);
	zephir_fclose(file TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Kodebin_Lib_Files, read) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL;
	zval *location = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location_param);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(location, location_param);
	} else {
		ZEPHIR_INIT_VAR(location);
		ZVAL_EMPTY_STRING(location);
	}


	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 6, location, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Kodebin_Lib_Files, extension) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, _0;
	zval *location = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location_param);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(location, location_param);
	} else {
		ZEPHIR_INIT_VAR(location);
		ZVAL_EMPTY_STRING(location);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_RETURN_CALL_FUNCTION("pathinfo", NULL, 7, location, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Kodebin_Lib_Files, replace) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *now_param = NULL, *contentnew_param = NULL, *output_param = NULL, *file = NULL, *content = NULL, *file_output = NULL, _0 = zval_used_for_init, *_2 = NULL, *_3;
	zval *now = NULL, *contentnew = NULL, *output = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &now_param, &contentnew_param, &output_param);

	if (unlikely(Z_TYPE_P(now_param) != IS_STRING && Z_TYPE_P(now_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'now' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(now_param) == IS_STRING)) {
		zephir_get_strval(now, now_param);
	} else {
		ZEPHIR_INIT_VAR(now);
		ZVAL_EMPTY_STRING(now);
	}
	if (unlikely(Z_TYPE_P(contentnew_param) != IS_STRING && Z_TYPE_P(contentnew_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'contentnew' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(contentnew_param) == IS_STRING)) {
		zephir_get_strval(contentnew, contentnew_param);
	} else {
		ZEPHIR_INIT_VAR(contentnew);
		ZVAL_EMPTY_STRING(contentnew);
	}
	if (unlikely(Z_TYPE_P(output_param) != IS_STRING && Z_TYPE_P(output_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'output' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(output_param) == IS_STRING)) {
		zephir_get_strval(output, output_param);
	} else {
		ZEPHIR_INIT_VAR(output);
		ZVAL_EMPTY_STRING(output);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "r", 0);
	ZEPHIR_CALL_FUNCTION(&file, "fopen", &_1, 5, now, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "filesize", NULL, 8, now);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&content, "fread", NULL, 9, file, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	zephir_fast_str_replace(&_3, content, contentnew, content TSRMLS_CC);
	ZEPHIR_CPY_WRT(content, _3);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "w", 0);
	ZEPHIR_CALL_FUNCTION(&file_output, "fopen", &_1, 5, output, &_0);
	zephir_check_call_status();
	zephir_fwrite(NULL, file_output, content TSRMLS_CC);
	zephir_fclose(file_output TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

