
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
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/math.h"
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
	ZEPHIR_CALL_FUNCTION(&file, "fopen", NULL, 9, location, &_0);
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


	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 10, location, ZEPHIR_GLOBAL(global_true));
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
	ZEPHIR_RETURN_CALL_FUNCTION("pathinfo", NULL, 11, location, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Kodebin_Lib_Files, time) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *format_param = NULL, *location_param = NULL, *_0;
	zval *format = NULL, *location = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &format_param, &location_param);

	if (unlikely(Z_TYPE_P(format_param) != IS_STRING && Z_TYPE_P(format_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'format' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(format_param) == IS_STRING)) {
		zephir_get_strval(format, format_param);
	} else {
		ZEPHIR_INIT_VAR(format);
		ZVAL_EMPTY_STRING(format);
	}
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


	ZEPHIR_INIT_VAR(_0);
	zephir_filemtime(_0, location TSRMLS_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("date", NULL, 12, format, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Kodebin_Lib_Files, size) {

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


	ZEPHIR_RETURN_CALL_FUNCTION("filesize", NULL, 13, location);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Kodebin_Lib_Files, size_format) {

	zval *type = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, *size = NULL, *base = NULL, *_0 = NULL, _1, *_2$$3, *_3$$3, _4$$3, _5$$3, _6$$3, *_7$$3;
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


	ZEPHIR_INIT_VAR(type);
	zephir_create_array(type, 5, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, " bytes", 1);
	zephir_array_fast_append(type, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, " KB", 1);
	zephir_array_fast_append(type, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, " MB", 1);
	zephir_array_fast_append(type, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, " GB", 1);
	zephir_array_fast_append(type, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, " TB", 1);
	zephir_array_fast_append(type, _0);
	ZEPHIR_CALL_FUNCTION(&size, "filesize", NULL, 13, location);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 1024);
	ZEPHIR_CALL_FUNCTION(&base, "log", NULL, 14, size, &_1);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(base, 0)) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_SINIT_VAR(_4$$3);
		ZVAL_LONG(&_4$$3, 1024);
		ZEPHIR_SINIT_VAR(_5$$3);
		ZVAL_DOUBLE(&_5$$3, (zephir_get_numberval(base) - zephir_floor(base TSRMLS_CC)));
		zephir_pow_function(_3$$3, &_4$$3, &_5$$3);
		ZEPHIR_SINIT_VAR(_6$$3);
		ZVAL_LONG(&_6$$3, 2);
		zephir_round(_2$$3, _3$$3, &_6$$3, NULL TSRMLS_CC);
		zephir_array_fetch(&_7$$3, type, base, PH_NOISY | PH_READONLY, "kodebin/lib/files.zep", 36 TSRMLS_CC);
		ZEPHIR_CONCAT_VV(return_value, _2$$3, _7$$3);
		RETURN_MM();
	} else {
		RETURN_MM_STRING("0 bytes", 1);
	}

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
	ZEPHIR_CALL_FUNCTION(&file, "fopen", &_1, 9, now, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "filesize", NULL, 13, now);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&content, "fread", NULL, 15, file, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	zephir_fast_str_replace(&_3, content, contentnew, content TSRMLS_CC);
	ZEPHIR_CPY_WRT(content, _3);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "w", 0);
	ZEPHIR_CALL_FUNCTION(&file_output, "fopen", &_1, 9, output, &_0);
	zephir_check_call_status();
	zephir_fwrite(NULL, file_output, content TSRMLS_CC);
	zephir_fclose(file_output TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

