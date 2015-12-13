namespace Kodebin\Security;
 
class Patch {
 
	public static function xss_escape(string! str) -> string {
 	return htmlspecialchars(str);
	}
	
	public static function lfi_escape(string! str) -> string {
	let str = str_replace("..", "", str);
	let str = str_replace("./", "", str);
 	return str;
	}
	
	public static function sql_escape(string! str) -> string {
	let str = str_replace("%", "", str);
	let str = str_replace(";", "", str);
	let str = str_replace("'", "", str);
 	return str;
	}
 
}
