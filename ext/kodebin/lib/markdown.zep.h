
extern zend_class_entry *kodebin_lib_markdown_ce;

ZEPHIR_INIT_CLASS(Kodebin_Lib_Markdown);

PHP_METHOD(Kodebin_Lib_Markdown, Markdown);

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_lib_markdown_markdown, 0, 0, 2)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(kodebin_lib_markdown_method_entry) {
	PHP_ME(Kodebin_Lib_Markdown, Markdown, arginfo_kodebin_lib_markdown_markdown, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
