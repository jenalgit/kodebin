
extern zend_class_entry *kodebin_security_firewall_ce;

ZEPHIR_INIT_CLASS(Kodebin_Security_Firewall);

PHP_METHOD(Kodebin_Security_Firewall, bruteforce);

ZEPHIR_INIT_FUNCS(kodebin_security_firewall_method_entry) {
	PHP_ME(Kodebin_Security_Firewall, bruteforce, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
