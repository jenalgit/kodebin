
extern zend_class_entry *kodebin_security_password_ce;

ZEPHIR_INIT_CLASS(Kodebin_Security_Password);

PHP_METHOD(Kodebin_Security_Password, md5_api);
PHP_METHOD(Kodebin_Security_Password, md5_10);

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_security_password_md5_api, 0, 0, 1)
	ZEND_ARG_INFO(0, md5)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_security_password_md5_10, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(kodebin_security_password_method_entry) {
	PHP_ME(Kodebin_Security_Password, md5_api, arginfo_kodebin_security_password_md5_api, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Kodebin_Security_Password, md5_10, arginfo_kodebin_security_password_md5_10, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
