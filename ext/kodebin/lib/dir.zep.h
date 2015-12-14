
extern zend_class_entry *kodebin_lib_dir_ce;

ZEPHIR_INIT_CLASS(Kodebin_Lib_Dir);

PHP_METHOD(Kodebin_Lib_Dir, tree);

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_lib_dir_tree, 0, 0, 3)
	ZEND_ARG_INFO(0, dir)
	ZEND_ARG_INFO(0, dir_)
	ZEND_ARG_INFO(0, files_)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(kodebin_lib_dir_method_entry) {
	PHP_ME(Kodebin_Lib_Dir, tree, arginfo_kodebin_lib_dir_tree, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
