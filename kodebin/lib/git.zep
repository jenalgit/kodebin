namespace Kodebin\Lib;
 
class Git {
 
	public static function clone_repo(url, location) {
	var git;
	let git = exec("git clone ".url." ".location);
	if(!git){
	return "Failed clone repository";
	}
	}
 
}
