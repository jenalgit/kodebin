
extern zend_class_entry *kodebin_lib_folder_ce;

ZEPHIR_INIT_CLASS(Kodebin_Lib_Folder);

PHP_METHOD(Kodebin_Lib_Folder, create);

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_lib_folder_create, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(kodebin_lib_folder_method_entry) {
	PHP_ME(Kodebin_Lib_Folder, create, arginfo_kodebin_lib_folder_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
