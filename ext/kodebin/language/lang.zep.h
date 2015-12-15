
extern zend_class_entry *kodebin_language_lang_ce;

ZEPHIR_INIT_CLASS(Kodebin_Language_Lang);

PHP_METHOD(Kodebin_Language_Lang, template);
PHP_METHOD(Kodebin_Language_Lang, error_msg);
PHP_METHOD(Kodebin_Language_Lang, success_msg);

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_language_lang_template, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_language_lang_error_msg, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_language_lang_success_msg, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(kodebin_language_lang_method_entry) {
	PHP_ME(Kodebin_Language_Lang, template, arginfo_kodebin_language_lang_template, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Kodebin_Language_Lang, error_msg, arginfo_kodebin_language_lang_error_msg, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Kodebin_Language_Lang, success_msg, arginfo_kodebin_language_lang_success_msg, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
