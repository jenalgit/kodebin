
extern zend_class_entry *kodebin_security_patch_ce;

ZEPHIR_INIT_CLASS(Kodebin_Security_Patch);

PHP_METHOD(Kodebin_Security_Patch, xss_escape);
PHP_METHOD(Kodebin_Security_Patch, lfi_escape);
PHP_METHOD(Kodebin_Security_Patch, sql_escape);

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_security_patch_xss_escape, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_security_patch_lfi_escape, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_kodebin_security_patch_sql_escape, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(kodebin_security_patch_method_entry) {
	PHP_ME(Kodebin_Security_Patch, xss_escape, arginfo_kodebin_security_patch_xss_escape, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Kodebin_Security_Patch, lfi_escape, arginfo_kodebin_security_patch_lfi_escape, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Kodebin_Security_Patch, sql_escape, arginfo_kodebin_security_patch_sql_escape, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
