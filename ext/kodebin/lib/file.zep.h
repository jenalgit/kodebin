
extern zend_class_entry *kodebin_lib_file_ce;

ZEPHIR_INIT_CLASS(Kodebin_Lib_File);

PHP_METHOD(Kodebin_Lib_File, create);

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_lib_file_create, 0, 0, 2)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(kodebin_lib_file_method_entry) {
	PHP_ME(Kodebin_Lib_File, create, arginfo_kodebin_lib_file_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
