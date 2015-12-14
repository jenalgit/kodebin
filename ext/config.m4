PHP_ARG_ENABLE(kodebin, whether to enable kodebin, [ --enable-kodebin   Enable Kodebin])

if test "$PHP_KODEBIN" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, KODEBIN_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_KODEBIN, 1, [Whether you have Kodebin])
	kodebin_sources="kodebin.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c kodebin/lib/curl.zep.c
	kodebin/lib/dir.zep.c
	kodebin/lib/files.zep.c
	kodebin/lib/folder.zep.c
	kodebin/security/password.zep.c
	kodebin/security/patch.zep.c "
	PHP_NEW_EXTENSION(kodebin, $kodebin_sources, $ext_shared,, )
	PHP_SUBST(KODEBIN_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([kodebin], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([kodebin], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/kodebin], [php_KODEBIN.h])

fi
