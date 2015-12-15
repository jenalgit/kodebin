
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Kodebin_Lib_Git) {

	ZEPHIR_REGISTER_CLASS(Kodebin\\Lib, Git, kodebin, lib_git, kodebin_lib_git_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Kodebin_Lib_Git, clone_repo) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *url, *location, *git = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &url, &location);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVSV(_0, "git clone ", url, " ", location);
	ZEPHIR_CALL_FUNCTION(&git, "exec", NULL, 20, _0);
	zephir_check_call_status();
	if (!zephir_is_true(git)) {
		RETURN_MM_STRING("Failed clone repository", 1);
	}
	ZEPHIR_MM_RESTORE();

}

