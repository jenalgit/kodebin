namespace Kodebin\Lib;
 
class Github {
 
	public static function markdown(content) {
	var ch;
	var result;
	let ch = curl_init("https://api.github.com/markdown");
    curl_setopt(ch, CURLOPT_CUSTOMREQUEST, "POST");
    curl_setopt(ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt(ch, CURLOPT_POSTFIELDS, content);
    curl_setopt(ch, CURLOPT_FOLLOWLOCATION, 1);
    curl_setopt(ch, CURLOPT_USERAGENT,"Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.13) Gecko/20080311 Firefox/2.0.0.13");
    let result = curl_exec(ch);
    curl_close(ch);
    return result;
	}
 
}
