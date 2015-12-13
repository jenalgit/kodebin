namespace Kodebin\Security;
 
class Password {
 
	public static function md5_api(string! md5) -> string {
	string salt;
	string md5_api;
    let salt    = md5(rand());
    let md5_api = md5(md5 . salt);
    return md5_api;
	}
	
	public static function md5_10(string! str) {
	var md5;
	var salt;
	var md5_secure;
	let md5 = hash("md5", str); //dapatkan MD5 dari string
    let salt = substr(md5, 7, 3); //generate salt key (ambil char ke 3 dari char 7)
    let md5_secure = strrev(md5); //balik MD5
    let md5_secure = substr(md5_secure, 0, -10); //hilangkan 10 char
    let md5_secure = substr(salt . md5_secure, 0, 10); //gabungkan salt dengan md5 yg terpotong
    return md5_secure;
	}
 
}
