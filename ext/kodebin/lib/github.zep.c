
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


ZEPHIR_INIT_CLASS(Kodebin_Lib_Github) {

	ZEPHIR_REGISTER_CLASS(Kodebin\\Lib, Github, kodebin, lib_github, kodebin_lib_github_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Kodebin_Lib_Github, markdown) {

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *content, *ch = NULL, *result = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content);



	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "https://api.github.com/markdown", 0);
	ZEPHIR_CALL_FUNCTION(&ch, "curl_init", NULL, 1, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
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

