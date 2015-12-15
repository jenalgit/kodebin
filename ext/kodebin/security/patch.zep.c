
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Kodebin_Security_Patch) {

	ZEPHIR_REGISTER_CLASS(Kodebin\\Security, Patch, kodebin, security_patch, kodebin_security_patch_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Kodebin_Security_Patch, xss_escape) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	if (unlikely(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(str, str_param);
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}


	ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars", NULL, 18, str);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Kodebin_Security_Patch, lfi_escape) {

	zval *str_param = NULL, *_0, _1, _2, *_3, _4, _5;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	if (unlikely(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(str, str_param);
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "..", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "", 0);
	zephir_fast_str_replace(&_0, &_1, &_2, str TSRMLS_CC);
	zephir_get_strval(str, _0);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "./", 0);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "", 0);
	zephir_fast_str_replace(&_3, &_4, &_5, str TSRMLS_CC);
	zephir_get_strval(str, _3);
	RETURN_CTOR(str);

}

PHP_METHOD(Kodebin_Security_Patch, sql_escape) {

	zval *str_param = NULL, *_0, _1, _2, *_3, _4, _5, *_6, _7, _8;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	if (unlikely(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(str, str_param);
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "%", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "", 0);
	zephir_fast_str_replace(&_0, &_1, &_2, str TSRMLS_CC);
	zephir_get_strval(str, _0);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, ";", 0);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "", 0);
	zephir_fast_str_replace(&_3, &_4, &_5, str TSRMLS_CC);
	zephir_get_strval(str, _3);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "'", 0);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, "", 0);
	zephir_fast_str_replace(&_6, &_7, &_8, str TSRMLS_CC);
	zephir_get_strval(str, _6);
	RETURN_CTOR(str);

}

