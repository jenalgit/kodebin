
extern zend_class_entry *kodebin_lib_git_ce;

ZEPHIR_INIT_CLASS(Kodebin_Lib_Git);

PHP_METHOD(Kodebin_Lib_Git, create_repo);
PHP_METHOD(Kodebin_Lib_Git, clone_repo);

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_lib_git_create_repo, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_lib_git_clone_repo, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(kodebin_lib_git_method_entry) {
	PHP_ME(Kodebin_Lib_Git, create_repo, arginfo_kodebin_lib_git_create_repo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Kodebin_Lib_Git, clone_repo, arginfo_kodebin_lib_git_clone_repo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
