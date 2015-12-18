namespace Kodebin\Security;
 
class Firewall {
 
	public static function bruteforce(){
	var limit;
	var hashing;
	var file_temp;
	var time_now;
	var latest_req;
	var time_limit;
	let limit = 2;
	let hashing = sha1($_SERVER["HTTP_USER_AGENT"].$_SERVER["REMOTE_ADDR"]);
	let file_temp = sys_get_temp_dir() ."/flood_".hashing; // Create file cache
	let time_now = microtime(true);

		if(file_exists(file_temp)) {
    		let latest_req = file_get_contents(file_temp);
			}else{
    		let latest_req = microtime() + 3600 ;
			}
    		let time_limit = time_now - latest_req;
    		file_put_contents(file_temp,time_now);

		if(time_limit <= limit) {
    		header("HTTP/1.1 403 Forbidden");
    		header("Date: ".date("D, d M Y h:i:s T"));
			header("Content-Type: text/html; charset=iso-8859-1");
    		header("X-Powered-By: Kodebin");
    		die("<html><h3>Brute force detected</h3></html>");
		}
	
	}
	
 
}
