
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/time.h"
#include "kernel/file.h"
#include "kernel/operators.h"
#include "kernel/exit.h"


ZEPHIR_INIT_CLASS(Kodebin_Security_Firewall) {

	ZEPHIR_REGISTER_CLASS(Kodebin\\Security, Firewall, kodebin, security_firewall, kodebin_security_firewall_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Kodebin_Security_Firewall, bruteforce) {

	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, limit = 0;
	zval *_SERVER, *hashing = NULL, *file_temp = NULL, *time_now = NULL, *latest_req = NULL, *time_limit = NULL, *_0, *_1, *_2, *_3 = NULL, *_4$$4, _5$$5 = zval_used_for_init, *_7$$5 = NULL, *_8$$5;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	limit = 2;
	zephir_array_fetch_string(&_0, _SERVER, SL("HTTP_USER_AGENT"), PH_NOISY | PH_READONLY, "kodebin/security/firewall.zep", 13 TSRMLS_CC);
	zephir_array_fetch_string(&_1, _SERVER, SL("REMOTE_ADDR"), PH_NOISY | PH_READONLY, "kodebin/security/firewall.zep", 13 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, _0, _1);
	ZEPHIR_CALL_FUNCTION(&hashing, "sha1", NULL, 21, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "sys_get_temp_dir", NULL, 22);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(file_temp);
	ZEPHIR_CONCAT_VSV(file_temp, _3, "/flood_", hashing);
	ZEPHIR_INIT_VAR(time_now);
	zephir_microtime(time_now, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	if ((zephir_file_exists(file_temp TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(latest_req);
		zephir_file_get_contents(latest_req, file_temp TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_4$$4);
		zephir_microtime(_4$$4, NULL TSRMLS_CC);
		ZEPHIR_INIT_NVAR(latest_req);
		ZVAL_LONG(latest_req, (zephir_get_numberval(_4$$4) + 3600));
	}
	ZEPHIR_INIT_VAR(time_limit);
	zephir_sub_function(time_limit, time_now, latest_req);
	zephir_file_put_contents(NULL, file_temp, time_now TSRMLS_CC);
	if (ZEPHIR_LE_LONG(time_limit, limit)) {
		ZEPHIR_SINIT_VAR(_5$$5);
		ZVAL_STRING(&_5$$5, "HTTP/1.1 403 Forbidden", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_6, 23, &_5$$5);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_5$$5);
		ZVAL_STRING(&_5$$5, "D, d M Y h:i:s T", 0);
		ZEPHIR_CALL_FUNCTION(&_7$$5, "date", NULL, 14, &_5$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_8$$5);
		ZEPHIR_CONCAT_SV(_8$$5, "Date: ", _7$$5);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_6, 23, _8$$5);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_5$$5);
		ZVAL_STRING(&_5$$5, "Content-Type: text/html; charset=iso-8859-1", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_6, 23, &_5$$5);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_5$$5);
		ZVAL_STRING(&_5$$5, "X-Powered-By: Kodebin", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_6, 23, &_5$$5);
		zephir_check_call_status();
		ZEPHIR_MM_RESTORE();
		ZEPHIR_SINIT_NVAR(_5$$5);
		ZVAL_STRING(&_5$$5, "<html><h3>Brute force detected</h3></html>", 0);
		zephir_exit(&_5$$5);
	}
	ZEPHIR_MM_RESTORE();

}

