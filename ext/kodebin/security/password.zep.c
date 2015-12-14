
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Kodebin_Security_Password) {

	ZEPHIR_REGISTER_CLASS(Kodebin\\Security, Password, kodebin, security_password, kodebin_security_password_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Kodebin_Security_Password, md5_api) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *md5_param = NULL, *_0 = NULL;
	zval *md5 = NULL, *salt = NULL, *md5_api = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &md5_param);

	if (unlikely(Z_TYPE_P(md5_param) != IS_STRING && Z_TYPE_P(md5_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'md5' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(md5_param) == IS_STRING)) {
		zephir_get_strval(md5, md5_param);
	} else {
		ZEPHIR_INIT_VAR(md5);
		ZVAL_EMPTY_STRING(md5);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "rand", NULL, 18);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(salt);
	zephir_md5(salt, _0);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, md5, salt);
	ZEPHIR_INIT_VAR(md5_api);
	zephir_md5(md5_api, _1);
	RETURN_CTOR(md5_api);

}

PHP_METHOD(Kodebin_Security_Password, md5_10) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *md5 = NULL, *salt = NULL, *md5_secure = NULL, _0 = zval_used_for_init, _1, _2, _3, *_4, *_5, _6, _7;
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


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "md5", 0);
	ZEPHIR_CALL_FUNCTION(&md5, "hash", NULL, 19, &_0, str);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 7);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 3);
	ZEPHIR_INIT_VAR(salt);
	zephir_substr(salt, md5, 7 , 3 , 0);
	ZEPHIR_CALL_FUNCTION(&md5_secure, "strrev", NULL, 20, md5);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, -10);
	ZEPHIR_INIT_VAR(_4);
	zephir_substr(_4, md5_secure, 0 , -10 , 0);
	ZEPHIR_CPY_WRT(md5_secure, _4);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VV(_5, salt, md5_secure);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 10);
	ZEPHIR_INIT_NVAR(md5_secure);
	zephir_substr(md5_secure, _5, 0 , 10 , 0);
	RETURN_CCTOR(md5_secure);

}

