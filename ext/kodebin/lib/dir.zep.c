
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
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Kodebin_Lib_Dir) {

	ZEPHIR_REGISTER_CLASS(Kodebin\\Lib, Dir, kodebin, lib_dir, kodebin_lib_dir_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Kodebin_Lib_Dir, tree) {

	zend_bool recursive = 0, skipByExclude = 0, _0$$4;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *dir, *dir_, *files_, *listDirs = NULL, *listFiles = NULL, *exclude = NULL, *arrayItems = NULL, *handle = NULL, *skip = NULL, *file = NULL, *_1$$5 = NULL, *_2$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &dir, &dir_, &files_);



	recursive = 0;
	ZEPHIR_CPY_WRT(listDirs, dir_);
	ZEPHIR_CPY_WRT(listFiles, files_);
	ZEPHIR_INIT_VAR(exclude);
	ZVAL_STRING(exclude, "", 1);
	skipByExclude = 0;
	ZEPHIR_CALL_FUNCTION(&handle, "opendir", NULL, 5, dir);
	zephir_check_call_status();
	if (zephir_is_true(handle)) {
		ZEPHIR_CALL_FUNCTION(&file, "readdir", NULL, 6, handle);
		zephir_check_call_status();
		while (1) {
			if (!(!ZEPHIR_IS_FALSE_IDENTICAL(file))) {
				break;
			}
			if (zephir_is_true(exclude)) {
			}
			_0$$4 = !zephir_is_true(skip);
			if (_0$$4) {
				_0$$4 = !skipByExclude;
			}
			if (_0$$4) {
				ZEPHIR_INIT_LNVAR(_1$$5);
				ZEPHIR_CONCAT_VSV(_1$$5, dir, "/", file);
				ZEPHIR_CALL_FUNCTION(&_2$$5, "is_dir", &_3, 7, _1$$5);
				zephir_check_call_status();
				if (zephir_is_true(_2$$5)) {
					if (recursive) {
					}
					if (zephir_is_true(listDirs)) {
						ZEPHIR_INIT_NVAR(arrayItems);
						zephir_create_array(arrayItems, 1, 0 TSRMLS_CC);
						zephir_array_fast_append(arrayItems, file);
					}
				} else {
					if (zephir_is_true(listFiles)) {
						ZEPHIR_INIT_NVAR(arrayItems);
						zephir_create_array(arrayItems, 1, 0 TSRMLS_CC);
						zephir_array_fast_append(arrayItems, file);
					}
				}
			}
		}
		ZEPHIR_CALL_FUNCTION(NULL, "closedir", NULL, 8, handle);
		zephir_check_call_status();
	}
	RETURN_CCTOR(arrayItems);

}

