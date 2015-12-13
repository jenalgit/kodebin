namespace Kodebin\Lib;
 
class Folder {
 
	public static function create(string! name) {
	var folder;
    let folder = htmlspecialchars(name);
    mkdir(folder, 0700);
	}
 
}
