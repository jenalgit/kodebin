
extern zend_class_entry *kodebin_lib_github_ce;

ZEPHIR_INIT_CLASS(Kodebin_Lib_Github);

PHP_METHOD(Kodebin_Lib_Github, markdown);

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_lib_github_markdown, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(kodebin_lib_github_method_entry) {
	PHP_ME(Kodebin_Lib_Github, markdown, arginfo_kodebin_lib_github_markdown, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
