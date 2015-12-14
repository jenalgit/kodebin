
extern zend_class_entry *kodebin_lib_curl_ce;

ZEPHIR_INIT_CLASS(Kodebin_Lib_Curl);

PHP_METHOD(Kodebin_Lib_Curl, post);
PHP_METHOD(Kodebin_Lib_Curl, get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_lib_curl_post, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_lib_curl_get, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(kodebin_lib_curl_method_entry) {
	PHP_ME(Kodebin_Lib_Curl, post, arginfo_kodebin_lib_curl_post, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Kodebin_Lib_Curl, get, arginfo_kodebin_lib_curl_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
