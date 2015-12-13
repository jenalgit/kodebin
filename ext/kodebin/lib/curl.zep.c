
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
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Kodebin_Lib_Curl) {

	ZEPHIR_REGISTER_CLASS(Kodebin\\Lib, Curl, kodebin, lib_curl, kodebin_lib_curl_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Kodebin_Lib_Curl, post) {

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *content, *ch = NULL, *result = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &url_param, &content);

	if (unlikely(Z_TYPE_P(url_param) != IS_STRING && Z_TYPE_P(url_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'url' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(url_param) == IS_STRING)) {
		zephir_get_strval(url, url_param);
	} else {
		ZEPHIR_INIT_VAR(url);
		ZVAL_EMPTY_STRING(url);
	}


	ZEPHIR_CALL_FUNCTION(&ch, "curl_init", NULL, 1, url);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 10036);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "POST", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 2, ch, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 19913);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 2, ch, &_0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 10015);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 2, ch, &_0, content);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 52);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 2, ch, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 10018);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.13) Gecko/20080311 Firefox/2.0.0.13", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 2, ch, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "curl_exec", NULL, 3, ch);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 4, ch);
	zephir_check_call_status();
	RETURN_CCTOR(result);

}

