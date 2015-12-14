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
	
	public static function time(string! format, string! location) {
	return date(format, filemtime(location));
	}
	
	public static function size(string! location) {
	return filesize(location);
	}
	
	public static function size_format(string! location) {
	var size;
	var base;
	array type;
	let type = [" bytes", " KB", " MB", " GB", " TB"];
	let size = filesize(location);
	let base = log(size, 1024);
    if(base > 0){
    return round(pow(1024, base - floor(base)), 2) . type[base];
    }else{
    return "0 bytes";
    }
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
