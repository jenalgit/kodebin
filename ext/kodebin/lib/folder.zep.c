
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


ZEPHIR_INIT_CLASS(Kodebin_Lib_Folder) {

	ZEPHIR_REGISTER_CLASS(Kodebin\\Lib, Folder, kodebin, lib_folder, kodebin_lib_folder_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Kodebin_Lib_Folder, create) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *folder = NULL, _0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_CALL_FUNCTION(&folder, "htmlspecialchars", NULL, 18, name);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0700);
	ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 19, folder, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

