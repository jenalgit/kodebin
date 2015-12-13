
extern zend_class_entry *kodebin_lib_files_ce;

ZEPHIR_INIT_CLASS(Kodebin_Lib_Files);

PHP_METHOD(Kodebin_Lib_Files, create);
PHP_METHOD(Kodebin_Lib_Files, read);
PHP_METHOD(Kodebin_Lib_Files, extension);
PHP_METHOD(Kodebin_Lib_Files, replace);

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_lib_files_create, 0, 0, 2)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_lib_files_read, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_lib_files_extension, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_lib_files_replace, 0, 0, 3)
	ZEND_ARG_INFO(0, now)
	ZEND_ARG_INFO(0, contentnew)
	ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(kodebin_lib_files_method_entry) {
	PHP_ME(Kodebin_Lib_Files, create, arginfo_kodebin_lib_files_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Kodebin_Lib_Files, read, arginfo_kodebin_lib_files_read, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Kodebin_Lib_Files, extension, arginfo_kodebin_lib_files_extension, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Kodebin_Lib_Files, replace, arginfo_kodebin_lib_files_replace, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
