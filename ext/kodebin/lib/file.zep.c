
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


ZEPHIR_INIT_CLASS(Kodebin_Lib_File) {

	ZEPHIR_REGISTER_CLASS(Kodebin\\Lib, File, kodebin, lib_file, kodebin_lib_file_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Kodebin_Lib_File, create) {

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

PHP_METHOD(Kodebin_Lib_File, replace) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *now_param = NULL, *content_new_param = NULL, *output_param = NULL, *file = NULL, *content = NULL, *file_output = NULL, _0 = zval_used_for_init, *_2 = NULL, *_3;
	zval *now = NULL, *content_new = NULL, *output = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &now_param, &content_new_param, &output_param);

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
	if (unlikely(Z_TYPE_P(content_new_param) != IS_STRING && Z_TYPE_P(content_new_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content_new' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(content_new_param) == IS_STRING)) {
		zephir_get_strval(content_new, content_new_param);
	} else {
		ZEPHIR_INIT_VAR(content_new);
		ZVAL_EMPTY_STRING(content_new);
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
	ZEPHIR_CALL_FUNCTION(&_2, "filesize", NULL, 6, now);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&content, "fread", NULL, 7, file, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	zephir_fast_str_replace(&_3, content, content_new, content TSRMLS_CC);
	ZEPHIR_CPY_WRT(content, _3);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "w", 0);
	ZEPHIR_CALL_FUNCTION(&file_output, "fopen", &_1, 5, output, &_0);
	zephir_check_call_status();
	zephir_fwrite(NULL, file_output, content TSRMLS_CC);
	zephir_fclose(file_output TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

