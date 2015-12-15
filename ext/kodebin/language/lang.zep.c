
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Kodebin_Language_Lang) {

	ZEPHIR_REGISTER_CLASS(Kodebin\\Language, Lang, kodebin, language_lang, kodebin_language_lang_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Kodebin_Language_Lang, template) {

	zval *text = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *content, *_SERVER, *bahasa = NULL, *app = NULL, *_0, _1, _2, *_5, *_3$$3 = NULL, *_4$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &content);



	zephir_array_fetch_string(&_0, _SERVER, SL("HTTP_ACCEPT_LANGUAGE"), PH_NOISY | PH_READONLY, "kodebin/language/lang.zep", 9 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 2);
	ZEPHIR_INIT_VAR(bahasa);
	zephir_substr(bahasa, _0, 0 , 2 , 0);
	ZEPHIR_INIT_VAR(app);
	object_init_ex(app, kodebin_language_lang_ce);
	if (zephir_has_constructor(app TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, app, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_STRING(bahasa, "indonesia")) {
	} else {
		ZEPHIR_INIT_VAR(text);
		zephir_create_array(text, 61, 0 TSRMLS_CC);
		add_assoc_stringl_ex(text, SS("home"), SL("Home"), 1);
		add_assoc_stringl_ex(text, SS("explore"), SL("Explore"), 1);
		add_assoc_stringl_ex(text, SS("notification"), SL("Notifications"), 1);
		add_assoc_stringl_ex(text, SS("myprofile"), SL("My profile"), 1);
		add_assoc_stringl_ex(text, SS("settings"), SL("Account settings"), 1);
		add_assoc_stringl_ex(text, SS("create_repo"), SL("Create repository"), 1);
		add_assoc_stringl_ex(text, SS("help"), SL("Help center"), 1);
		add_assoc_stringl_ex(text, SS("logout"), SL("Logout"), 1);
		add_assoc_stringl_ex(text, SS("login"), SL("Sign in"), 1);
		add_assoc_stringl_ex(text, SS("register"), SL("Sign up"), 1);
		add_assoc_stringl_ex(text, SS("about"), SL("About"), 1);
		add_assoc_stringl_ex(text, SS("team"), SL("Team"), 1);
		add_assoc_stringl_ex(text, SS("blog"), SL("Blog"), 1);
		add_assoc_stringl_ex(text, SS("api"), SL("API"), 1);
		add_assoc_stringl_ex(text, SS("explore_des"), SL("Search other open source project based on the available categories."), 1);
		add_assoc_stringl_ex(text, SS("latest"), SL("Latest"), 1);
		add_assoc_stringl_ex(text, SS("popular"), SL("Popular"), 1);
		add_assoc_stringl_ex(text, SS("create_repo_des"), SL("Create new repository, or clone from Github and Bitbucket."), 1);
		add_assoc_stringl_ex(text, SS("repo_name"), SL("Repository name"), 1);
		add_assoc_stringl_ex(text, SS("repo_des"), SL("Description"), 1);
		add_assoc_stringl_ex(text, SS("repo_clone"), SL("Clone from git"), 1);
		add_assoc_stringl_ex(text, SS("repo_cat"), SL("Category"), 1);
		add_assoc_stringl_ex(text, SS("repo_lang"), SL("Language"), 1);
		add_assoc_stringl_ex(text, SS("repo_license"), SL("License"), 1);
		add_assoc_stringl_ex(text, SS("guide"), SL("Guide"), 1);
		add_assoc_stringl_ex(text, SS("guide_new_repo"), SL("Create repository"), 1);
		add_assoc_stringl_ex(text, SS("guide_mg_repo"), SL("Manage repositories"), 1);
		add_assoc_stringl_ex(text, SS("guide_cr"), SL("Contribution project"), 1);
		add_assoc_stringl_ex(text, SS("guide_work"), SL("Work with team"), 1);
		add_assoc_stringl_ex(text, SS("latest_activity"), SL("Latest activity"), 1);
		add_assoc_stringl_ex(text, SS("all"), SL("All"), 1);
		add_assoc_stringl_ex(text, SS("following"), SL("Following"), 1);
		add_assoc_stringl_ex(text, SS("your_repo"), SL("Your repositories"), 1);
		add_assoc_stringl_ex(text, SS("create_new_repo"), SL("Create new repository"), 1);
		add_assoc_stringl_ex(text, SS("joined"), SL("Joined on"), 1);
		add_assoc_stringl_ex(text, SS("followers"), SL("Followers"), 1);
		add_assoc_stringl_ex(text, SS("activity"), SL("Public activity"), 1);
		add_assoc_stringl_ex(text, SS("contribution"), SL("Contribution"), 1);
		add_assoc_stringl_ex(text, SS("repository"), SL("Repositories"), 1);
		add_assoc_stringl_ex(text, SS("download_zip"), SL("Download ZIP"), 1);
		add_assoc_stringl_ex(text, SS("new_folder"), SL("New folder"), 1);
		add_assoc_stringl_ex(text, SS("name_folder"), SL("Folder name"), 1);
		add_assoc_stringl_ex(text, SS("make_folder"), SL("Create folder"), 1);
		add_assoc_stringl_ex(text, SS("new_file"), SL("New file"), 1);
		add_assoc_stringl_ex(text, SS("name_file"), SL("Filename"), 1);
		add_assoc_stringl_ex(text, SS("make_file"), SL("Create file"), 1);
		add_assoc_stringl_ex(text, SS("new_pull"), SL("New pull requests"), 1);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_STRING(_4$$3, "Login success, you will redirect to panel.", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3$$3, app, "success_msg", NULL, 1, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		zephir_array_update_string(&text, SL("login_success"), &_3$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_STRING(_4$$3, "Username or password incorrect.", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3$$3, app, "error_msg", NULL, 2, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		zephir_array_update_string(&text, SL("login_error_1"), &_3$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_STRING(_4$$3, "Register success, login to your account.", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3$$3, app, "success_msg", NULL, 1, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		zephir_array_update_string(&text, SL("register_success"), &_3$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_STRING(_4$$3, "Register failed, try again!", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3$$3, app, "error_msg", NULL, 2, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		zephir_array_update_string(&text, SL("register_error_1"), &_3$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_STRING(_4$$3, "Username or email already exist.", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3$$3, app, "error_msg", NULL, 2, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		zephir_array_update_string(&text, SL("register_error_2"), &_3$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_STRING(_4$$3, "File has been created.", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3$$3, app, "success_msg", NULL, 1, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		zephir_array_update_string(&text, SL("add_file_success"), &_3$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_STRING(_4$$3, "Please input filename!", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3$$3, app, "error_msg", NULL, 2, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		zephir_array_update_string(&text, SL("add_file_error"), &_3$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_STRING(_4$$3, "Folder has been created.", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3$$3, app, "success_msg", NULL, 1, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		zephir_array_update_string(&text, SL("add_folder_success"), &_3$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_STRING(_4$$3, "Please input folder name!", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3$$3, app, "error_msg", NULL, 2, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		zephir_array_update_string(&text, SL("add_folder_error"), &_3$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_STRING(_4$$3, "Repository has been created.", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3$$3, app, "success_msg", NULL, 1, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		zephir_array_update_string(&text, SL("create_repo_success"), &_3$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_STRING(_4$$3, "Repository already exist.", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3$$3, app, "error_msg", NULL, 2, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		zephir_array_update_string(&text, SL("create_repo_error_1"), &_3$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_STRING(_4$$3, "Please input description.", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3$$3, app, "error_msg", NULL, 2, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		zephir_array_update_string(&text, SL("create_repo_error_2"), &_3$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_STRING(_4$$3, "Please input repository name.", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3$$3, app, "error_msg", NULL, 2, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		zephir_array_update_string(&text, SL("create_repo_error_3"), &_3$$3, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(text, SS("create_repo_mode"), SL("create new a repository "), 1);
	}
	zephir_array_fetch(&_5, text, content, PH_NOISY | PH_READONLY, "kodebin/language/lang.zep", 89 TSRMLS_CC);
	zend_print_zval(_5, 0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Kodebin_Language_Lang, error_msg) {

	zval *content;

	zephir_fetch_params(0, 1, 0, &content);



	ZEPHIR_CONCAT_SVS(return_value, "<div class='alert alert-danger' id='success-alert'>\n\t        <a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a>\n          <strong>Failed!</strong> ", content, "\n\t        </div>");
	return;

}

PHP_METHOD(Kodebin_Language_Lang, success_msg) {

	zval *content;

	zephir_fetch_params(0, 1, 0, &content);



	ZEPHIR_CONCAT_SVS(return_value, "<div class='alert alert-success' id='success-alert'>\n\t        <a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a>\n          <strong>Success!</strong> ", content, "\n\t        </div>");
	return;

}

