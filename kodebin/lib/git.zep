namespace Kodebin\Lib;
 
class Git {

	public static function create_repo(name, location) {
	var git;
	let git = exec("git init --bare ".location.name.".git");
	}
	
	public static function clone_repo(url, location) {
	var git;
	let git = exec("git clone ".url." ".location);
	if(!git){
	return "Failed clone repository";
	}
	}
 
}
