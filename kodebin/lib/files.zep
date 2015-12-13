namespace Kodebin\Lib;
 
class Files {
 
	public static function create(string! location, string! content) {
	var file;
    let file = fopen(location,"w");
    fwrite(file, content);
    fclose(file);
	}
	
	public static function read(string! location) {
	return file_get_contents(location, true);
	}
	
	public static function extension(string! location) {
	return pathinfo(location, PATHINFO_EXTENSION);
	}
	
	public static function replace(string! now, string! contentnew, string! output) {
	var file;
	var content;
	var file_output;
    
    let file = fopen(now,"r");
    let content = fread(file,filesize(now));

    let content = str_replace(content, contentnew, content);

    let file_output = fopen(output,"w");
    fwrite(file_output,content);
    fclose(file_output);
	}
 
}
